/**
  ******************************************************************************
  * File Name          : USART.c
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
#include <stdio.h>
#ifdef __GNUC__
/* 若需打印浮点数 则需要在
 * 工程属性->C/C++ Build->Settings->C Linker->Miscellaneous->Other options中添加 -u _printf_float
 * 以使能浮点打印功能，此外，使能浮点打印功能，编译后会明显增加RAM和FLASH占用
 */
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

#ifndef __MICROLIB
/* 加入以下代码，支持printf函数，而不需要选择use MicroLIB */
#pragma import(__use_no_semihosting)

/* 标准库需要的支持函数 */
struct __FILE {
    int handle;
};

/* FILE 定义在 stdio.h */
FILE __stdout;

/* 定义_sys_exit()以避免使用半主机模式 */
void _sys_exit(int x)
{
    x = x;
}
#endif
#endif /* __GNUC__ */

//#define USE_REG_FOR_PRINTF

PUTCHAR_PROTOTYPE {
#if defined(USE_REG_FOR_PRINTF)
    /* 寄存器方式 */

    /* MM32 */
//    while ((UART2->CSR & UART_FLAG_TXEMPTY) == RESET);
//    UART2->TDR = (ch & (uint16_t)0x00FF);

    /* STM32 不同型号的寄存器及相关FLAG定义有所不同，按需选择 */
#if 0
    while ((USART2->SR & USART_FLAG_TXE) == RESET);
    USART2->DR = (uint8_t)ch;
    while ((USART2->SR & USART_FLAG_TC) == RESET);
#else
    while ((USART2->ISR & USART_ISR_TXE) == RESET);
    USART2->TDR = (uint8_t)ch;
    while ((USART2->ISR & USART_ISR_TC) == RESET);
#endif

#else
#if defined(USE_STDPERIPH_DRIVER)
    /* SPL标准库方式 */
    while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
    USART_SendData(USART2, (uint8_t)ch);
    while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);
#endif

#if defined(USE_FULL_LL_DRIVER)
    /* LL库方式 */
    while (LL_USART_IsActiveFlag_TXE(USART2) == RESET);
    LL_USART_TransmitData8(USART2, ch);
    while (LL_USART_IsActiveFlag_TC(USART2) == RESET);
#endif /* USE_FULL_LL_DRIVER */

#if defined(USE_HAL_DRIVER)
    /* HAL库方式 */
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
#endif /* USE_HAL_DRIVER */

#endif /* USE_REG_FOR_PRINTF */
    return ch;
}

/* USER CODE END 0 */

UART_HandleTypeDef huart1;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();
  
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration    
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();
  
    /**USART1 GPIO Configuration    
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX 
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
