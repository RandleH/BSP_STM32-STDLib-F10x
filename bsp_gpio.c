
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

void GPIO_Config(void){		
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE );
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2;	
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;    
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOC, &GPIO_InitStructure);	

	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_3;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA , ENABLE );
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0; 
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);	 

	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_13; 
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
    
	GPIO_SetBits(GPIOC, GPIO_Pin_2);
	GPIO_SetBits(GPIOC, GPIO_Pin_3);
	GPIO_ResetBits(GPIOC, GPIO_Pin_2);
	GPIO_ResetBits(GPIOC, GPIO_Pin_3);

	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_13);
}
