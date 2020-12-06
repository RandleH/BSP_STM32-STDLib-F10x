
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_clkconfig.h"
#include "bsp_mcooutput.h"

int main(void)
{	

	HSI_SetSysClock(RCC_PLLMul_16);
	
	MCO_GPIO_Config();//Only on PA8.
	
//  RCC_MCOConfig(RCC_MCO_HSE);	             	        
//  RCC_MCOConfig(RCC_MCO_HSI);	                   
//  RCC_MCOConfig(RCC_MCO_PLLCLK_Div2);    	
	RCC_MCOConfig(RCC_MCO_SYSCLK);		      
	
	while (1){
		
	}
}




