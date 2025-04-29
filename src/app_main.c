/**
  ******************************************************************************
  * @file           : app_main.c
  * @brief          : Main source file
  * @author         : Julien Cruvieux
  * @date           : 2025/04/21
  ******************************************************************************
  */

/* General interfaces --------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* Used interfaces (dependencies includes) -----------------------------------*/
#include "app_spi.h"
#include "app_s2lp.h"

/* Associated interfaces -----------------------------------------------------*/
#include "app_main.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
static char g_acBuffer[50] = {0};

/* Private function prototypes -----------------------------------------------*/

/* Public functions ----------------------------------------------------------*/
int main(void) {
  vAPP_SPI_init();

  uint8_t l_u8DevicePN = S2LPGeneralGetDevicePN();
  uint8_t l_u8S2LPVersion = S2LPGeneralGetVersion();

  printf("S2LP Device part number: %d\n", l_u8DevicePN);
  printf("S2LP version: %d\n", l_u8S2LPVersion);

  vAPP_S2LP_init();

  while (1) {
    printf("Enter a message to send >\n");
    
    if (fgets(g_acBuffer, sizeof(g_acBuffer), stdin)) {
      uint16_t l_u16Size = strcspn(g_acBuffer, "\n");
      g_acBuffer[l_u16Size] = '\0';
      vAPP_S2LP_sendMessage(g_acBuffer, l_u16Size);
    }
    else {
      //Nothing
    }
  }

  return 0;
}

/* Private functions ---------------------------------------------------------*/

/* ISR and Event handlers ----------------------------------------------------*/
