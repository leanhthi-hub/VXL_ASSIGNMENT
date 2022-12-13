/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "scheduler.h"
#include "global.h"
//#include "input_processing.h"
#include "input_reading.h"
//#include "updateClockBuffer.h"
//#include "Update7Seg.h"
#include "timer.h"
#include "fsm.h"
#include <stdio.h>

const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4];
int second,second1;

int status1 = Waiting;
int status2 = Waiting;
int status4 = Waiting;
int status3 = INIT;
int RED_TIME=1000;
int timer=0;
int GREEN_TIME=700;
int timer2=0;
int YELLOW_TIME=300;
int timer3=0;
int TIME_OUT=1000;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
void Print_HELLO()
{
	char str[30];
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "HELLO\r"), 1000);
}
void Toggle_led()
{
	HAL_GPIO_TogglePin(GPIOA, Led_1_Pin);
}
void Print_TimeOut(int abc){
	char str[30];
	int temp;
	temp=abc;
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "timeout: %d\r", temp), 1000);
}
void Print_TimeP(int abc){
	char str[30];
	int temp;
	temp=abc;
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "time_P: %d\r", temp), 1000);
}
void Print_Mode(int abc){
	char str[30];
	int temp;
	temp=abc;
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "Mode: %d\r", temp), 1000);
}
void Print_Time(int abc){
	char str[30];
	int temp;
	temp=abc;
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "time: %d\r", temp), 1000);
}
void Print_Time1(int abc){
	char str[30];
	int temp;
	temp=abc;
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "time_1: %d\r", temp), 1000);
}
void Print_Time2(int abc){
	char str[30];
	int temp;
	temp=abc;
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "time_2: %d\r", temp), 1000);
}
//void Print_Time()
//{
//	char str[30];
//	int temp;
//	temp=timer;
//	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "time1: %d\r", temp), 1000);
//	temp = timer2;
//	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "time2: %d\r", temp), 1000);
//	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "-----\r"), 1000);
//	HAL_UART_Transmit(&huart2, (void*)str, sprintf("%c%c%c%c",0x1B,0x5B,0x32,0x4A), 1000);

//}
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  MX_GPIO_Init ();
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
//  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  HAL_TIM_Base_Start_IT (& htim2 ) ;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//  HAL_GPIO_WritePin(GPIOB, ledpa_Pin|led1b_Pin|led2b_Pin|led2a_Pin, GPIO_PIN_RESET);
//  HAL_GPIO_WritePin(GPIOA, ledpb_Pin|led1a_Pin, GPIO_PIN_RESET);\char str[30];

//  Print_HELLO();
  SCH_Init();
//  Print_HELLO();
//  SCH_Add_Task(Toggle_led, 10, 500);
//  SCH_Add_Task(Print_HELLO, 10, 1000);
  setTimer0(100);
//  setTimer1(2);
//  setTimer2(3);
//  setTimer3(4);
//  setTimerOut1(1);
//  setTimerOut1(2);


  SCH_Add_Task(timerRun0, 20, 10);
//  SCH_Add_Task(timerRun1, 20, 10);
//  SCH_Add_Task(timerRun2, 20, 10);
//  SCH_Add_Task(timerRun3, 20, 10);

  SCH_Add_Task(timerOut1, 20, 10);
  SCH_Add_Task(timerOut2, 20, 10);

//  SCH_Add_Task(Print_Time, 10, 990);

  SCH_Add_Task(button_reading, 10, 10);

  SCH_Add_Task(fsm_automatic_run1, 20, 10);
  SCH_Add_Task(fsm_automatic_run2, 20, 10);
  SCH_Add_Task(fsm_automatic_run3, 20, 10);
  SCH_Add_Task(fsm_p, 20, 10);


//  SCH_Add_Task(timerRun0, 0, 10);
//  SCH_Add_Task(timerRun0, 0, 10);
  while (1)
  {
//		 fsm_automatic_run1();
//		 fsm_automatic_run2();
//		 fsm_automatic_run3();
	  SCH_Dispatch_Tasks();

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Led_1_Pin|ledpb_Pin|led1a_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, ledpa_Pin|led1b_Pin|led2b_Pin|led2a_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : button_1_Pin button_2_Pin */
  GPIO_InitStruct.Pin = button_1_Pin|button_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Led_1_Pin ledpb_Pin led1a_Pin */
  GPIO_InitStruct.Pin = Led_1_Pin|ledpb_Pin|led1a_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : button_3_Pin button_p_Pin */
  GPIO_InitStruct.Pin = button_3_Pin|button_p_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : ledpa_Pin led1b_Pin led2b_Pin led2a_Pin */
  GPIO_InitStruct.Pin = ledpa_Pin|led1b_Pin|led2b_Pin|led2a_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim ){
	if( htim -> Instance == TIM2 ){
		SCH_Update();
//		button_reading () ;
		}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
