/**
  ******************************************************************************
  * @file           : app_spi.h
  * @brief          : Header file for SPI abstraction layer
  * @author         : Julien Cruvieux
  * @date           : 2025/04/23
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __APP_SPI_H
#define __APP_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include <stdint.h>

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void vAPP_SPI_init(void);
void vAPP_SPI_transmitReceive(const uint8_t* p_pu8DataTx, uint8_t* p_pu8DataRx, uint16_t p_u16Size);

/* Private defines -----------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __APP_SPI_H */
