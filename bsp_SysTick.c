  

#include "core_cm3.h"

void SysTick_Init(void){
	// SystemFrequency / 1000    1ms
	// SystemFrequency / 100000	 10us
	// SystemFrequency / 1000000 1us

	if (SysTick_Config(SystemCoreClock / 100000)){ 
		// Error :-(
		while (1);
	}
}

void SysTick_Delay_Us( __IO uint32_t us){
	uint32_t i;
	SysTick_Config(SystemCoreClock/1000000);
	
	for(i=0;i<us;i++){
		while( !((SysTick->CTRL)&(1<<16)) );
	}
	SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
}

void SysTick_Delay_Ms( __IO uint32_t ms){
	uint32_t i;	
	SysTick_Config(SystemCoreClock/1000);
	
	for(i=0;i<ms;i++){
		while( !((SysTick->CTRL)&(1<<16)) );
	}
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
}

