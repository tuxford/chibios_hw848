/*
    ChibiOS/RT - Copyright (C) 2010 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.

                                      ---

    A special exception to the GPL can be applied should you wish to distribute
    a combined work that includes ChibiOS/RT, without being obliged to provide
    the source code for any proprietary components. See the file exception.txt
    for full details of how and when the exception can be applied.
*/

/**
 * @file Win32/serial_lld.h
 * @brief Win32 low level simulated serial driver header.
 * @addtogroup WIN32_SERIAL
 * @{
 */

#ifndef _SERIAL_LLD_H_
#define _SERIAL_LLD_H_

#if CH_HAL_USE_SERIAL || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief Serial buffers size.
 * @details Configuration parameter, you can change the depth of the queue
 * buffers depending on the requirements of your application.
 */
#if !defined(SERIAL_BUFFERS_SIZE) || defined(__DOXYGEN__)
#define SERIAL_BUFFERS_SIZE 1024
#endif

/**
 * @brief SD1 driver enable switch.
 * @details If set to @p TRUE the support for SD1 is included.
 * @note The default is @p TRUE.
 */
#if !defined(USE_WIN32_SERIAL1) || defined(__DOXYGEN__)
#define USE_WIN32_SERIAL1 TRUE
#endif

/**
 * @brief SD2 driver enable switch.
 * @details If set to @p TRUE the support for SD2 is included.
 * @note The default is @p TRUE.
 */
#if !defined(USE_WIN32_SERIAL2) || defined(__DOXYGEN__)
#define USE_WIN32_SERIAL2 TRUE
#endif

/**
 * @brief Listen port for SD1.
 */
#if !defined(SD1_PORT) || defined(__DOXYGEN__)
#define SD1_PORT  29001
#endif

/**
 * @brief Listen port for SD2.
 */
#if !defined(SD2_PORT) || defined(__DOXYGEN__)
#define SD2_PORT  29002
#endif

/*===========================================================================*/
/* Unsupported event flags and custom events.                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * Serial Driver condition flags type.
 */
typedef uint32_t sdflags_t;

/**
 * @brief Generic Serial Driver configuration structure.
 * @details An instance of this structure must be passed to @p sdStart()
 *          in order to configure and start a serial driver operations.
 *
 * @note This structure content is architecture dependent, each driver
 *       implementation defines its own version and the custom static
 *       initializers.
 */
typedef struct {
} SerialConfig;

/**
 * @brief @p SerialDriver specific data.
 */
struct _serial_driver_data {
  /**
   * @brief Driver state.
   */
  sdstate_t                 state;
  /**
   * @brief Current configuration data.
   */
  const SerialConfig        *config;
  /**
   * @brief Input queue, incoming data can be read from this input queue by
   *        using the queues APIs.
   */
  InputQueue                iqueue;
  /**
   * @brief Output queue, outgoing data can be written to this output queue by
   *        using the queues APIs.
   */
  OutputQueue               oqueue;
  /**
   * @brief Status Change @p EventSource. This event is generated when one or
   *        more condition flags change.
   */
  EventSource               sevent;
  /**
   * @brief I/O driver status flags.
   */
  sdflags_t                 flags;
  /**
   * @brief Input circular buffer.
   */
  uint8_t                   ib[SERIAL_BUFFERS_SIZE];
  /**
   * @brief Output circular buffer.
   */
  uint8_t                   ob[SERIAL_BUFFERS_SIZE];
  /* End of the mandatory fields.*/
  /**
   * Listen socket for simulated serial port.
   */
  SOCKET                    com_listen;
  /**
   * Data socket for simulated serial port.
   */
  SOCKET                    com_data;
  /**
   * Port readable name.
   */
  const char                *com_name;
};

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/** @cond never*/
#if USE_WIN32_SERIAL1
extern SerialDriver SD1;
#endif
#if USE_WIN32_SERIAL2
extern SerialDriver SD2;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void sd_lld_init(void);
  void sd_lld_start(SerialDriver *sdp);
  void sd_lld_stop(SerialDriver *sdp);
  bool_t sd_lld_interrupt_pending(void);
#ifdef __cplusplus
}
#endif
/** @endcond*/

#endif /* CH_HAL_USE_SERIAL */

#endif /* _SERIAL_LLD_H_ */

/** @} */
