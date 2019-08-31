/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio.

    This file is part of ChibiOS.

    ChibiOS is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file    chcore_v7m.c
 * @brief   ARMv7-M architecture port code.
 *
 * @addtogroup ARMCMx_V7M_CORE
 * @{
 */

#include <string.h>

#include "ch.h"

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module interrupt handlers.                                                */
/*===========================================================================*/

#if (PORT_USE_SYSCALL == TRUE) || defined(__DOXYGEN__)
__attribute__((weak))
void port_syscall(struct port_extctx *ctxp, uint32_t n) {

  (void)ctxp;
  (void)n;

  chSysHalt("svc");
}
#endif

#if (CORTEX_SIMPLIFIED_PRIORITY == FALSE) || defined(__DOXYGEN__)
/**
 * @brief   SVC vector.
 * @details The SVC vector is used for exception mode re-entering after a
 *          context switch and, optionally, for system calls.
 * @note    The SVC vector is only used in advanced kernel mode.
 */
/*lint -save -e9075 [8.4] All symbols are invoked from asm context.*/
void SVC_Handler(void) {
/*lint -restore*/
  uint32_t control;
  uint32_t psp = __get_PSP();

  chDbgAssert(((uint32_t)__builtin_return_address(0) & 4U) == 0U,
              "not process");

#if PORT_USE_SYSCALL == TRUE
  /* Caller context.*/
  struct port_extctx *ectxp = (struct port_extctx *)psp;

  /* Checking if the SVC instruction has been used from privileged or
     non-privileged mode.*/
  control = __get_CONTROL();
  if ((control & 1U) != 0) {
    /* From non-privileged mode, it must be handled as a syscall.*/
    uint32_t n, s_psp;
    struct port_midctx *mctxp;
    struct port_extctx *newctxp;

    /* Supervisor PSP from the thread context structure.*/
    s_psp = (uint32_t)currthread->ctx.s_psp;

    /* Pushing the port_midctx into the supervisor stack.*/
    s_psp -= sizeof (struct port_midctx);
    mctxp = (struct port_midctx *)s_psp;
    mctxp->control = (regarm_t)(control = __get_CONTROL());
    mctxp->ectxp = (regarm_t)ectxp;

    /* Enforcing privileged mode before returning.*/
    __set_CONTROL(control & ~1U);

    /* Number of the SVC instruction.*/
    n = (uint32_t)*(((const uint16_t *)ectxp->pc) - 1U) & 255U;

    /* Building an artificial return context, we need to make this
       return in the syscall dispatcher in privileged mode.*/
    s_psp -= sizeof (struct port_extctx);
    __set_PSP(s_psp);
    newctxp = (struct port_extctx *)s_psp;
    newctxp->r0     = (regarm_t)ectxp;
    newctxp->r1     = (regarm_t)n;
    newctxp->pc     = (regarm_t)port_syscall;
    newctxp->xpsr   = (regarm_t)0x01000000;
#if CORTEX_USE_FPU == TRUE
    newctxp->fpscr  = (regarm_t)FPU->FPDSCR;
#endif
  }
  else
#endif
  {
    /* From privileged mode, it is used for context discarding in the
       preemption code.*/

    /* Unstacking procedure, discarding the current exception context and
       positioning the stack to point to the real one.*/
    psp += sizeof (struct port_extctx);

#if CORTEX_USE_FPU == TRUE
    /* Enforcing unstacking of the FP part of the context.*/
    FPU->FPCCR &= ~FPU_FPCCR_LSPACT_Msk;
#endif

#if PORT_USE_SYSCALL == TRUE
    {
      /* Restoring CONTROL and the original PSP position.*/
      struct port_midctx *mctxp = (struct port_midctx *)psp;
      __set_CONTROL((uint32_t)mctxp->control);
      __set_PSP((uint32_t)mctxp->ectxp);
    }
#else

    /* Restoring real position of the original stack frame.*/
    __set_PSP(psp);
#endif

    /* Restoring the normal interrupts status.*/
    port_unlock_from_isr();
  }
}
#endif /* CORTEX_SIMPLIFIED_PRIORITY == FALSE */

#if (CORTEX_SIMPLIFIED_PRIORITY == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   PendSV vector.
 * @details The PendSV vector is used for exception mode re-entering after a
 *          context switch.
 * @note    The PendSV vector is only used in compact kernel mode.
 */
/*lint -save -e9075 [8.4] All symbols are invoked from asm context.*/
void PendSV_Handler(void) {
/*lint -restore*/
  uint32_t psp = __get_PSP();

#if CORTEX_USE_FPU
  /* Enforcing unstacking of the FP part of the context.*/
  FPU->FPCCR &= ~FPU_FPCCR_LSPACT_Msk;
#endif

  /* Discarding the current exception context and positioning the stack to
     point to the real one.*/
  psp += sizeof (struct port_extctx);

#if PORT_USE_SYSCALL == TRUE
  {
    /* Restoring previous privileges by restoring CONTROL.*/
    struct port_midctx *mctxp = (struct port_midctx *)psp;
    __set_CONTROL((uint32_t)mctxp->control);
    psp += sizeof (struct port_midctx);
  }
#endif

  /* Restoring real position of the original stack frame.*/
  __set_PSP(psp);
}
#endif /* CORTEX_SIMPLIFIED_PRIORITY == TRUE */

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Port-related initialization code.
 *
 * @param[in, out] oip  pointer to the @p os_instance_t structure
 */
void port_init(os_instance_t *oip) {

  (void)oip;

  /* Starting in a known IRQ configuration.*/
  __set_BASEPRI(CORTEX_BASEPRI_DISABLED);
  __enable_irq();

  /* Initializing priority grouping.*/
  NVIC_SetPriorityGrouping(CORTEX_PRIGROUP_INIT);

  /* DWT cycle counter enable, note, the M7 requires DWT unlocking.*/
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
#if CORTEX_MODEL == 7
  DWT->LAR = 0xC5ACCE55U;
#endif
  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

  /* Initialization of the system vectors used by the port.*/
#if CORTEX_SIMPLIFIED_PRIORITY == FALSE
  NVIC_SetPriority(SVCall_IRQn, CORTEX_PRIORITY_SVCALL);
#endif
  NVIC_SetPriority(PendSV_IRQn, CORTEX_PRIORITY_PENDSV);

#if PORT_ENABLE_GUARD_PAGES == TRUE
  {
    extern stkalign_t __main_thread_stack_base__;

    /* Setting up the guard page on the main() function stack base
       initially.*/
    mpuConfigureRegion(PORT_USE_MPU_REGION,
                       &__main_thread_stack_base__,
                       MPU_RASR_ATTR_AP_NA_NA |
                       MPU_RASR_ATTR_NON_CACHEABLE |
                       MPU_RASR_SIZE_32 |
                       MPU_RASR_ENABLE);

    /* MPU is enabled.*/
    mpuEnable(MPU_CTRL_PRIVDEFENA);
  }
#endif
}

#if ((CH_DBG_ENABLE_STACK_CHECK == TRUE) &&                                 \
     (PORT_ENABLE_GUARD_PAGES == TRUE)) ||                                  \
    defined(__DOXYGEN__)
/**
 * @brief   Setting up MPU region for the current thread.
 */
void _port_set_region(void) {

  mpuSetRegionAddress(PORT_USE_MPU_REGION,
                      chThdGetSelfX()->wabase);
}
#endif

/**
 * @brief   Exception exit redirection to _port_switch_from_isr().
 */
void _port_irq_epilogue(void) {

  port_lock_from_isr();
  if ((SCB->ICSR & SCB_ICSR_RETTOBASE_Msk) != 0U) {
    struct port_extctx *ctxp;
    uint32_t s_psp;

#if CORTEX_USE_FPU == TRUE
    /* Enforcing a lazy FPU state save by accessing the FPCSR register.*/
    (void) __get_FPSCR();
#endif

#if PORT_USE_SYSCALL == TRUE
    {
      struct port_midctx *mctxp;
      uint32_t control = __get_CONTROL();

      /* Checking if the IRQ has been served in unprivileged mode.*/
      if ((control & 1U) != 0U) {
        /* Unprivileged mode, switching to privileged mode.*/
        __set_CONTROL(control & ~1U);

        /* Switching to S-PSP taking it from the thread context.*/
        s_psp = (uint32_t)currthread->ctx.s_psp;

        /* Pushing the middle context for returning to the original frame
           and mode.*/
        s_psp = s_psp - sizeof (struct port_midctx);
        mctxp = (struct port_midctx *)s_psp;
        mctxp->control = (regarm_t)control;
        mctxp->ectxp   = (struct port_extctx *)__get_PSP();
      }
      else {
        /* Privileged mode, we are already on S-PSP.*/
        uint32_t psp = __get_PSP();

        /* Pushing the middle context for returning to the original frame
           and mode.*/
        s_psp = psp - sizeof (struct port_midctx);
        mctxp = (struct port_midctx *)s_psp;
        mctxp->control = (regarm_t)control;
        mctxp->ectxp   = (struct port_extctx *)psp;
      }
    }
#else
    s_psp = __get_PSP();
#endif

    /* Adding an artificial exception return context, there is no need to
       populate it fully.*/
    s_psp -= sizeof (struct port_extctx);

    /* The port_extctx structure is pointed by the S-PSP register.*/
    ctxp = (struct port_extctx *)s_psp;

    /* Setting up a fake XPSR register value.*/
    ctxp->xpsr = (regarm_t)0x01000000;
#if CORTEX_USE_FPU == TRUE
    ctxp->fpscr = (regarm_t)FPU->FPDSCR;
#endif

    /* Writing back the modified S-PSP value.*/
    __set_PSP(s_psp);

    /* The exit sequence is different depending on if a preemption is
       required or not.*/
    if (chSchIsPreemptionRequired()) {
      /* Preemption is required we need to enforce a context switch.*/
      ctxp->pc = (regarm_t)_port_switch_from_isr;
    }
    else {
      /* Preemption not required, we just need to exit the exception
         atomically.*/
      ctxp->pc = (regarm_t)_port_exit_from_isr;
    }

    /* Note, returning without unlocking is intentional, this is done in
       order to keep the rest of the context switch atomic.*/
    return;
  }
  port_unlock_from_isr();
}

#if (PORT_USE_SYSCALL == TRUE) || defined(__DOXYGEN__)
void port_unprivileged_jump(regarm_t pc, regarm_t psp) {
  struct port_extctx *ctxp;
  struct port_midctx *mctxp;
  uint32_t s_psp   = __get_PSP();
  uint32_t control = __get_CONTROL();

  /* The current PSP position will be the supervisor PSP position on
     syscalls.*/
  currthread->ctx.s_psp = (regarm_t)s_psp;

  /* Creating a port_extctx context for user mode entry.*/
  psp -= sizeof (struct port_extctx);
  ctxp = (struct port_extctx *)psp;

  /* Initializing the user mode entry context.*/
  memset((void *)ctxp, 0, sizeof (struct port_extctx *));
  ctxp->pc    = pc;
  ctxp->xpsr  = (regarm_t)0x01000000;
#if CORTEX_USE_FPU == TRUE
  ctxp->fpscr = __get_FPSCR();
#endif

  /* Creating a middle context for user mode entry.*/
  s_psp -= sizeof (struct port_midctx);
  mctxp  = (struct port_midctx *)s_psp;

  /* CONTROL and PSP values for user mode.*/
  mctxp->control = (regarm_t)(control | 1U);
  mctxp->ectxp   = ctxp;

  asm volatile ("svc 0");

  chSysHalt("svc");
}
#endif

/** @} */
