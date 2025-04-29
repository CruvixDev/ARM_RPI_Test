/**
  ******************************************************************************
  * @file           : app_s2lp.h
  * @brief          : Header file for S2LP app layer
  * @author         : Julien Cruvieux
  * @date           : 2025/04/23
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __APP_S2LP_H
#define __APP_S2LP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include "S2LP_Config.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
#define cAPP_S2LP_BASE_FREQUENCY_Hz (uint32_t)868000000
#define cAPP_S2LP_MODULATION_SCHEME MOD_2FSK
#define cAPP_S2LP_DATARATE_bps      (uint32_t)38400
#define cAPP_S2LP_FREQ_DEVIATION_Hz (uint32_t)20000
#define cAPP_S2LP_BANDWIDTH_Hz      (uint32_t)100000
#define cAPP_S2LP_POWER_dBm         (int32_t)12

#define cAPP_S2LP_PREAMBLE_LENGTH       PREAMBLE_BYTE(4)
#define cAPP_S2LP_SYNC_LENGTH           SYNC_BYTE(4)
#define cAPP_S2LP_SYNC_WORD             0x88888888
#define cAPP_S2LP_VARIABLE_LENGTH       S_ENABLE
#define cAPP_S2LP_EXTENDED_LENGTH_FIELD S_DISABLE
#define cAPP_S2LP_CRC_MODE              PKT_CRC_MODE_8BITS
#define cAPP_S2LP_EN_ADDRESS            S_DISABLE
#define cAPP_S2LP_EN_FEC                S_DISABLE
#define cAPP_S2LP_EN_WHITENING          S_ENABLE

/* Exported macro ------------------------------------------------------------*/
#define PREAMBLE_BYTE(v) (4*v)
#define SYNC_BYTE(v)     (8*v)

/* Exported functions prototypes ---------------------------------------------*/
void vAPP_S2LP_init(void);
void vAPP_S2LP_processEvents(void);
void vAPP_S2LP_sendMessage(const char* p_pcMessage, uint16_t p_u16Size);

/* Private defines -----------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __APP_S2LP_H */
