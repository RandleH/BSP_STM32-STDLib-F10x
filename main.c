#include "bsp_bitband.h"

void SOFT_Delay(__IO uint32_t nCount)	
{
	for(; nCount != 0; nCount--);
}

int main(void)
{	
	// ...Init... //
	while(1){
		PBout(0)= 0;		
		SOFT_Delay(0x0FFFFF);
	
		PBout(0)= 1;
		SOFT_Delay(0x0FFFFF);		
	}
}

