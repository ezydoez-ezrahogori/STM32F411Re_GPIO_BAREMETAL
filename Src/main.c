#include  "stm32f4xx.h"

//PA5


//AHB1


//set bit0 in RCC_AHB1ENR to 1
#define GPIOAEN   (1<<0)
//set bit 10 to 1 and bit11 to 0 in GPIOA_MODER
#define MODER_5_OUT     (1<<10)
//write 1 to GPIOA_ODR bit 5 to set PA5 on and write o to set it off.
#define   ODR_5_SET     (1<<5)
#define   ODR_5_RESET   (0<<5)


#define   LED_PIN       (1<<5)
int main(void)
{

	RCC->AHB1ENR |=GPIOAEN;
	GPIOA->MODER |=MODER_5_OUT;
	while(1)
	{
        for(int i=0; i<900000; i++ ){}
		GPIOA->ODR ^= ODR_5_SET;
	}
}
