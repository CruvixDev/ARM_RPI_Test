/**
* @file    S2LP_CORE_SPI.h
* @author  LowPower RF BU - AMG
* @version 2.0.0
* @date    March, 2020
* @brief   This file provides all the low level API to manage SPI interface for eval board.
* @details
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*
* THIS SOURCE CODE IS PROTECTED BY A LICENSE.
* FOR MORE INFORMATION PLEASE CAREFULLY READ THE LICENSE AGREEMENT FILE LOCATED
* IN THE ROOT DIRECTORY OF THIS FIRMWARE PACKAGE.
*
* <h2><center>&copy; COPYRIGHT 2020 STMicroelectronics</center></h2>
*/


/* Includes ------------------------------------------------------------------*/
#include <stdint.h>


/**
 * @brief  Configures SPI interface
 * @param  baudrate: SPI clock frequency
 * @retval None.
 */
void S2LPSpiInit(uint32_t baudrate);

/**
* @brief  Deinitializes the SPI
* @param  None
* @retval None
*/
void SdkEvalSpiDeinit(void);

/**
 * @brief  SPI function to read registers from a slave device
 * @param  RegisterAddr: register address
 * @param  NumByteToRead: number of byte to read
 * @param  pBuffer: buffer to retrieve data from a slave
 * @retval ErrorStatus: error status @ref ErrorStatus
 *         This parameter can be: SUCCESS or ERROR.
 */
uint16_t S2LPSpiReadRegisters(uint8_t RegisterAddr, uint8_t NumByteToRead, uint8_t* pBuffer);

/**
 * @brief  SPI function to write registers of a slave device
 * @param  RegisterAddr: register address
 * @param  NumByteToRead: number of byte to write
 * @param  pBuffer: buffer contains data to write
 * @retval ErrorStatus: error status @ref ErrorStatus
 *         This parameter can be: SUCCESS or ERROR.
 */
uint16_t S2LPSpiWriteRegisters(uint8_t RegisterAddr, uint8_t NumByteToRead, uint8_t* pBuffer);

uint16_t S2LPSpiCommandStrobes(uint8_t command);

uint16_t S2LPSpiReadFifo(uint8_t n_bytes, uint8_t* buffer);

uint16_t S2LPSpiWriteFifo(uint8_t n_bytes, uint8_t* buffer);

void S2LPSetSpiInUse(uint8_t state);

uint8_t S2LPGetSpiInUse(void);

void SpiRawTransaction(uint8_t *tx_buffer, uint8_t *rx_buffer, uint16_t length, uint8_t *tx_buffer2, uint8_t *rx_buffer2, uint16_t length2, uint32_t cs);

void S2LPSpiRaw(uint8_t n_bytes, uint8_t* in_buffer, uint8_t* out_buffer, uint8_t can_return_bef_tx);


/******************* (C) COPYRIGHT 2020 STMicroelectronics *****END OF FILE****/
