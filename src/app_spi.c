/**
  ******************************************************************************
  * @file           : app_spi.c
  * @brief          : Source file for SPI abstraction layer
  * @author         : Julien Cruvieux
  * @date           : 2025/04/23
  ******************************************************************************
  */

/* General interfaces --------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>

/* Used interfaces (dependencies includes) -----------------------------------*/
#include "spidev.h"
#include "fcntl.h"
#include <sys/ioctl.h>

/* Associated interfaces -----------------------------------------------------*/
#include "app_spi.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define cAPP_SPI_SPEED_Hz (uint32_t)8000000
#define cAPP_SPI_BPW      (uint8_t)8
#define cAPP_SPI_DELAY_us (uint16_t)0
#define cAPP_SPI_DEVICE   (char*)"/dev/spidev0.0"

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
static int g_iSPIFileDescriptor = 0;
static struct spi_ioc_transfer g_sSPIObject = {0};

/* Private function prototypes -----------------------------------------------*/

/* Public functions ----------------------------------------------------------*/
void vAPP_SPI_init(void) {
  g_iSPIFileDescriptor = open(cAPP_SPI_DEVICE, O_RDWR);

  if (g_iSPIFileDescriptor < 0) {
    printf("error opening %s\n", cAPP_SPI_DEVICE);
  }
  else {
    printf("Successfully open the device %s\n", cAPP_SPI_DEVICE);

    g_sSPIObject.bits_per_word = cAPP_SPI_BPW;
    g_sSPIObject.delay_usecs = cAPP_SPI_DELAY_us;
    g_sSPIObject.speed_hz = cAPP_SPI_SPEED_Hz;
  }

  uint8_t mode = SPI_MODE_0;
  ioctl(g_iSPIFileDescriptor, SPI_IOC_WR_MODE, &mode);
}

void vAPP_SPI_transmitReceive(const uint8_t* p_pu8DataTx, uint8_t* p_pu8DataRx, uint16_t p_u16Size) {
  g_sSPIObject.tx_buf = (unsigned long)p_pu8DataTx;
  g_sSPIObject.rx_buf = (unsigned long)p_pu8DataRx;
  g_sSPIObject.len = p_u16Size;

  ioctl(g_iSPIFileDescriptor, SPI_IOC_MESSAGE(1), &g_sSPIObject);
}

/* Private functions ---------------------------------------------------------*/

/* ISR and Event handlers ----------------------------------------------------*/
