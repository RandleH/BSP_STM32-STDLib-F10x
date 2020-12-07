#ifndef __GPIO_H
#define	__GPIO_H


#define	digitalHi(p,i)		 {p->BSRR=i;}			
#define digitalLo(p,i)		 {p->BRR=i;}	
#define digitalToggle(p,i)   {p->ODR ^=i;} 

void GPIO_Config(void);

#endif 
