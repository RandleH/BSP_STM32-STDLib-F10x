
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"

void HSI_SetSysClock(uint32_t pllmul){
	__IO uint32_t HSIStartUpStatus = 0;

    RCC_DeInit();
	RCC_HSICmd(ENABLE);
	HSIStartUpStatus = RCC->CR & RCC_CR_HSIRDY;
    if (HSIStartUpStatus == RCC_CR_HSIRDY){
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
//  FLASH_Latency_X
//  0: 0 < SYSCLK <= 24M
//  1: 24< SYSCLK <= 48M
//  2: 48< SYSCLK <= 72M
        FLASH_SetLatency(FLASH_Latency_2);
//----------------------------------------------------------------------//
    // AHB    
        RCC_HCLKConfig(RCC_SYSCLK_Div1); 
    // APB2
        RCC_PCLK2Config(RCC_HCLK_Div1); 
    // APB1
        RCC_PCLK1Config(RCC_HCLK_Div2);
		
//---------------------------------------------------------------------//

        RCC_PLLConfig(RCC_PLLSource_HSI_Div2, pllmul);
//---------------------------------------------------------------------//
        
        RCC_PLLCmd(ENABLE);

        while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

        while (RCC_GetSYSCLKSource() != 0x08);
    }else{
        // Error :-(
        while(1);
    }
}


void HSE_SetSysClock(uint32_t pllmul){
    __IO uint32_t StartUpCounter = 0, HSEStartUpStatus = 0;

    RCC_DeInit();

    RCC_HSEConfig(RCC_HSE_ON);

    HSEStartUpStatus = RCC_WaitForHSEStartUp();
    
    if(HSEStartUpStatus == SUCCESS){
//----------------------------------------------------------------------//
    
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
//  FLASH_Latency_X
//  0: 0 < SYSCLK <= 24M
//  1: 24< SYSCLK <= 48M
//  2: 48< SYSCLK <= 72M
        FLASH_SetLatency(FLASH_Latency_2);
//----------------------------------------------------------------------//
    // AHB
        RCC_HCLKConfig(RCC_SYSCLK_Div1); 
    // APB2
        RCC_PCLK2Config(RCC_HCLK_Div1); 
    // APB1 
        RCC_PCLK1Config(RCC_HCLK_Div2);
        
//---------------------------------------------------------------------//
    
        RCC_PLLConfig(RCC_PLLSource_HSE_Div1, pllmul);
//------------------------------------------------------------------//

        RCC_PLLCmd(ENABLE);

        while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

        while (RCC_GetSYSCLKSource() != 0x08);
    }else{
        // Error :-(
        while(1);
    }
}

void MCO_GPIO_Config(void){
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOA, &GPIO_InitStructure);
}




