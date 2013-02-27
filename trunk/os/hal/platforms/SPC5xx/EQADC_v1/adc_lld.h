/*
 * Licensed under ST Liberty SW License Agreement V2, (the "License");
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *        http://www.st.com/software_license_agreement_liberty_v2
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file    SPC5xx/EQADC_v1/adc_lld.c
 * @brief   SPC5xx low level ADC driver header.
 *
 * @addtogroup ADC
 * @{
 */

#ifndef _ADC_LLD_H_
#define _ADC_LLD_H_

#if HAL_USE_ADC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Internal registers indexes
 * @{
 */
#define ADC_REG_CR                  0x1
#define ADC_REG_TSCR                0x2
#define ADC_REG_TBCR                0x3
#define ADC_REG_GCCR                0x4
#define ADC_REG_OCCR                0x5
#define ADC_REG_AC1GCCR             0x31
#define ADC_REG_AC1OCCR             0x32
#define ADC_REG_AC2GCCR             0x35
#define ADC_REG_AC2OCCR             0x36
#define ADC_REG_AC1CR               0x30
#define ADC_REG_AC2CR               0x34
#define ADC_REG_AC3CR               0x38
#define ADC_REG_AC4CR               0x3C
#define ADC_REG_AC5CR               0x40
#define ADC_REG_AC6CR               0x44
#define ADC_REG_AC7CR               0x48
#define ADC_REG_AC8CR               0x4C
#define ADC_REG_PUDCR(n)            (0x70 + (n))
#define ADC_REG_PUDCR0              0x70UL
#define ADC_REG_PUDCR1              0x71UL
#define ADC_REG_PUDCR2              0x72UL
#define ADC_REG_PUDCR3              0x73UL
#define ADC_REG_PUDCR4              0x74UL
#define ADC_REG_PUDCR5              0x75UL
#define ADC_REG_PUDCR6              0x76UL
#define ADC_REG_PUDCR7              0x77UL
/** @} */

/**
 * @name    EQADC CFCR registers definitions
 * @{
 */
#define EQADC_CFCR_CFEEE0           (1U << 12)
#define EQADC_CFCR_STRME0           (1U << 11)
#define EQADC_CFCR_SSE              (1U << 10)
#define EQADC_CFCR_CFINV            (1U << 9)
#define EQADC_CFCR_MODE_MASK        (15U << 4)
#define EQADC_CFCR_MODE(n)          ((n) << 4)
#define EQADC_CFCR_MODE_DISABLED    EQADC_CFCR_MODE(0)
#define EQADC_CFCR_MODE_SWSS        EQADC_CFCR_MODE(1)
#define EQADC_CFCR_MODE_HWSS_LL     EQADC_CFCR_MODE(2)
#define EQADC_CFCR_MODE_HWSS_HL     EQADC_CFCR_MODE(3)
#define EQADC_CFCR_MODE_HWSS_FE     EQADC_CFCR_MODE(4)
#define EQADC_CFCR_MODE_HWSS_RE     EQADC_CFCR_MODE(5)
#define EQADC_CFCR_MODE_HWSS_BE     EQADC_CFCR_MODE(6)
#define EQADC_CFCR_MODE_MODE_SWCS   EQADC_CFCR_MODE(9)
#define EQADC_CFCR_MODE_HWCS_LL     EQADC_CFCR_MODE(10)
#define EQADC_CFCR_MODE_HWCS_HL     EQADC_CFCR_MODE(11)
#define EQADC_CFCR_MODE_HWCS_FE     EQADC_CFCR_MODE(12)
#define EQADC_CFCR_MODE_HWCS_RE     EQADC_CFCR_MODE(13)
#define EQADC_CFCR_MODE_HWCS_BE     EQADC_CFCR_MODE(14)
#define EQADC_CFCR_AMODE0_MASK      (15U << 0)
#define EQADC_CFCR_AMODE0(n)        ((n) << 0)
/** @} */

/**
 * @name    EQADC FISR registers definitions
 * @{
 */
#define EQADC_FISR_POPNXTPTR_MASK   (15U << 0)
#define EQADC_FISR_RFCTR_MASK       (15U << 4)
#define EQADC_FISR_TNXTPTR_MASK     (15U << 8)
#define EQADC_FISR_CFCTR_MASK       (15U << 12)
#define EQADC_FISR_RFDF             (1U << 17)
#define EQADC_FISR_RFOF             (1U << 19)
#define EQADC_FISR_CFFF             (1U << 25)
#define EQADC_FISR_SSS              (1U << 26)
#define EQADC_FISR_CFUF             (1U << 27)
#define EQADC_FISR_EOQF             (1U << 28)
#define EQADC_FISR_PF               (1U << 29)
#define EQADC_FISR_TORF             (1U << 30)
#define EQADC_FISR_NCF              (1U << 31)
#define EQADC_FISR_CLEAR_MASK       (EQADC_FISR_NCF  | EQADC_FISR_TORF |    \
                                     EQADC_FISR_PF   | EQADC_FISR_EOQF |    \
                                     EQADC_FISR_CFUF | EQADC_FISR_RFOF |    \
                                     EQADC_FISR_RFDF)
/** @} */

/**
 * @name    EQADC Conversion commands
 * @{
 */
#define EQADC_CONV_CHANNEL_MASK (0xFFU << 8)/**< @brief Channel number mask.*/
#define EQADC_CONV_CHANNEL(n)   ((n) << 8)  /**< @brief Channel number.     */
#define EQADC_CONV_FMT_RJU      (0U << 16)  /**< @brief Unsigned samples.   */
#define EQADC_CONV_FMT_RJS      (1U << 16)  /**< @brief Signed samples.     */
#define EQADC_CONV_TSR          (1U << 17)  /**< @brief Time stamp request. */
#define EQADC_CONV_LST_MASK     (3U << 18)  /**< @brief Sample time.        */
#define EQADC_CONV_LST_2        (0U << 18)  /**< @brief 2 clock cycles.     */
#define EQADC_CONV_LST_8        (1U << 18)  /**< @brief 8 clock cycles.     */
#define EQADC_CONV_LST_64       (2U << 18)  /**< @brief 64 clock cycles.    */
#define EQADC_CONV_LST_128      (3U << 18)  /**< @brief 128 clock cycles.   */
#define EQADC_CONV_MSG_MASK     (15U << 20) /**< @brief Message mask.       */
#define EQADC_CONV_MSG_RFIFO(n) ((n) << 20) /**< @brief Result in RFIFO0..5.*/
#define EQADC_CONV_MSG_NULL     (6U << 20)  /**< @brief Null message.       */
#define EQADC_CONV_CAL          (1U << 24)  /**< @brief Calibrated result.  */
#define EQADC_CONV_BN_MASK      (1U << 25)  /**< @brief Buffer number mask. */
#define EQADC_CONV_BN(n)        ((n) << 25) /**< @brief Buffer number.      */
#define EQADC_CONV_REP          (1U << 29)  /**< @brief Repeat loop flag.   */
#define EQADC_CONV_PAUSE        (1U << 30)  /**< @brief Pause flag.         */
#define EQADC_CONV_EOQ          (1U << 31)  /**< @brief End of queue flag.  */
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   ADCD10 driver enable switch.
 * @details If set to @p TRUE the support for EQADC1 queue 0 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ADC_USE_EQADC_Q0) || defined(__DOXYGEN__)
#define SPC5_ADC_USE_EQADC_Q0               FALSE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if SPC5_ADC_USE_EQADC_Q0 && !SPC5_HAS_EQADC
#error "EQADC1 not present in the selected device"
#endif

#if !SPC5_ADC_USE_EQADC_Q0
#error "ADC driver activated but no EQADC peripheral assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*!
 * @brief   FIFO unit numeric IDs.
 */
typedef enum {
  ADC_FIFO_0 = 0,
  ADC_FIFO_1 = 1,
  ADC_FIFO_2 = 2,
  ADC_FIFO_3 = 3,
  ADC_FIFO_4 = 4,
  ADC_FIFO_5 = 5
} adcfifo_t;

/**
 * @brief   ADC command data type.
 */
typedef uint32_t adccommand_t;

/**
 * @brief   ADC sample data type.
 */
typedef uint16_t adcsample_t;

/**
 * @brief   Channels number in a conversion group.
 */
typedef uint16_t adc_channels_num_t;

/**
 * @brief   Possible ADC failure causes.
 * @note    Error codes are architecture dependent and should not relied
 *          upon.
 */
typedef enum {
  ADC_ERR_DMAFAILURE = 0,                   /**< DMA operations failure.    */
  ADC_ERR_OVERFLOW = 1                      /**< ADC overflow condition.    */
} adcerror_t;

/**
 * @brief   Type of a structure representing an ADC driver.
 */
typedef struct ADCDriver ADCDriver;

/**
 * @brief   ADC notification callback type.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object triggering the
 *                      callback
 * @param[in] buffer    pointer to the most recent samples data
 * @param[in] n         number of buffer rows available starting from @p buffer
 */
typedef void (*adccallback_t)(ADCDriver *adcp, adcsample_t *buffer, size_t n);

/**
 * @brief   ADC error callback type.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object triggering the
 *                      callback
 * @param[in] err       ADC error code
 */
typedef void (*adcerrorcallback_t)(ADCDriver *adcp, adcerror_t err);

/**
 * @brief   Conversion group configuration structure.
 * @details This implementation-dependent structure describes a conversion
 *          operation.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
typedef struct {
  /**
   * @brief   Enables the circular buffer mode for the group.
   */
  bool_t                    circular;
  /**
   * @brief   Number of the analog channels belonging to the conversion group.
   */
  adc_channels_num_t        num_channels;
  /**
   * @brief   Callback function associated to the group or @p NULL.
   */
  adccallback_t             end_cb;
  /**
   * @brief   Error callback or @p NULL.
   */
  adcerrorcallback_t        error_cb;
  /* End of the mandatory fields.*/
  /**
   * @brief   Number of command iterations stored in @p commands.
   * @note    The total number of array elements must be @p num_channels *
   *          @p num_iterations.
   * @note    This fields is the upper limit of the parameter @p n that can
   *          be passed to the functions @p adcConvert() and
   *          @p adcStartConversion().
   */
  uint32_t                  num_iterations;
  /**
   * @brief   Pointer to an array of low level EQADC commands to be pushed
   *          into the CFIFO during a conversion.
   */
  const adccommand_t        *commands;
} ADCConversionGroup;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  uint32_t                  dummy;
} ADCConfig;

/**
 * @brief   Structure representing an ADC driver.
 */
struct ADCDriver {
  /**
   * @brief   Driver state.
   */
  adcstate_t                state;
  /**
   * @brief   Current configuration data.
   */
  const ADCConfig           *config;
  /**
   * @brief   Current samples buffer pointer or @p NULL.
   */
  adcsample_t               *samples;
  /**
   * @brief   Current samples buffer depth or @p 0.
   */
  size_t                    depth;
  /**
   * @brief   Current conversion group pointer or @p NULL.
   */
  const ADCConversionGroup  *grpp;
#if ADC_USE_WAIT || defined(__DOXYGEN__)
  /**
   * @brief   Waiting thread.
   */
  Thread                    *thread;
#endif
#if ADC_USE_MUTUAL_EXCLUSION || defined(__DOXYGEN__)
#if CH_USE_MUTEXES || defined(__DOXYGEN__)
  /**
   * @brief   Mutex protecting the peripheral.
   */
  Mutex                     mutex;
#elif CH_USE_SEMAPHORES
  Semaphore                 semaphore;
#endif
#endif /* ADC_USE_MUTUAL_EXCLUSION */
#if defined(ADC_DRIVER_EXT_FIELDS)
  ADC_DRIVER_EXT_FIELDS
#endif
  /* End of the mandatory fields.*/
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if SPC5_ADC_USE_EQADC_Q0 && !defined(__DOXYGEN__)
extern ADCDriver ADCD1;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void adc_lld_init(void);
  void adc_lld_start(ADCDriver *adcp);
  void adc_lld_stop(ADCDriver *adcp);
  void adc_lld_start_conversion(ADCDriver *adcp);
  void adc_lld_stop_conversion(ADCDriver *adcp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_ADC */

#endif /* _ADC_LLD_H_ */

/** @} */
