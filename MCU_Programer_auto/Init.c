#include "General.h"

void Init_Timer0(void)
{
		CLK_EnableModuleClock(TMR0_MODULE);
	  TIMER_Open(TIMER0, TMR0_OPERATING_MODE, TMR0_OPERATING_FREQ);
    TIMER_EnableInt(TIMER0);
    NVIC_EnableIRQ(TMR0_IRQn);
    TIMER_Start(TIMER0);	
}
void Init_Timer1(void)
{
  
	  TIMER_Open(TIMER1, TMR1_OPERATING_MODE, TMR1_OPERATING_FREQ);
    TIMER_EnableInt(TIMER1);
    NVIC_EnableIRQ(TMR1_IRQn);
    //TIMER_Start(TIMER1);	
}

void Init_Timer2(void)
{
	  TIMER_Open(TIMER2, TMR2_OPERATING_MODE, TMR2_OPERATING_FREQ);
    TIMER_EnableInt(TIMER2);
    NVIC_EnableIRQ(TMR2_IRQn);
    //TIMER_Start(TIMER2);	
}

void Init_Timer3(void)
{
	  TIMER_Open(TIMER3, TMR3_OPERATING_MODE, TMR3_OPERATING_FREQ);
    TIMER_EnableInt(TIMER3);
    NVIC_EnableIRQ(TMR3_IRQn);
    //TIMER_Start(TIMER3);	
}
//void Init_UART1(void)
//{
//    UART_Open(UART1,9600);	// enable UART1 at 9600 baudrate
//    UART_ENABLE_INT(UART1, UART_IER_RDA_IE_Msk);
//    NVIC_EnableIRQ(UART1_IRQn);	
//}
void Init_UART0(void)
{
    UART_Open(UART0,115200);	// enable UART1 at 9600 baudrate
    UART_ENABLE_INT(UART0, UART_IER_RDA_IE_Msk);
    NVIC_EnableIRQ(UART02_IRQn);	
}
void Init_KEY(void)
{
//    GPIO_SetMode(PB, (BIT11 | BIT12 | BIT13 | BIT10 | BIT9), GPIO_PMD_INPUT);
//    GPIO_EnableInt(PB, 11, GPIO_INT_RISING); 
//    GPIO_EnableInt(PB, 12, GPIO_INT_RISING);  //Y
//    GPIO_EnableInt(PB, 13, GPIO_INT_RISING); // X
//		GPIO_EnableInt(PB, 10, GPIO_INT_RISING); //Z
    GPIO_SetMode(PC, (BIT6 | BIT7 | BIT14 | BIT15 ), GPIO_MODE_INPUT);

//  
    GPIO_EnableInt(PC, 6, GPIO_INT_FALLING);
    GPIO_EnableInt(PC, 7, GPIO_INT_RISING);   //y
    GPIO_EnableInt(PC, 14, GPIO_INT_FALLING);
    GPIO_EnableInt(PC, 15, GPIO_INT_RISING);  //x
//		
    GPIO_SetMode(PD, (BIT5 ), GPIO_PMD_INPUT); 
    GPIO_EnableInt(PD, 5, GPIO_INT_RISING);   //z
  
    NVIC_EnableIRQ(GPCDEF_IRQn);   
    GPIO_SET_DEBOUNCE_TIME(GPIO_DBCLKSRC_LIRC, GPIO_DBCLKSEL_64);
    GPIO_ENABLE_DEBOUNCE(PC, (BIT6 | BIT7 | BIT14 | BIT15 ));	
    GPIO_ENABLE_DEBOUNCE(PD, BIT5);
  
  //OUTPUT
    GPIO_SetMode(PA, (BIT1 | BIT2 | BIT3 ), GPIO_MODE_OUTPUT);
    GPIO_SetMode(PC, (BIT2 | BIT3 | BIT4 | BIT5), GPIO_MODE_OUTPUT);
    GPIO_SetMode(PB, (BIT2 | BIT3 |BIT9 | BIT10| BIT11), GPIO_MODE_OUTPUT);
	  GPIO_SetMode(PD, (BIT6 | BIT7 | BIT14 | BIT15), GPIO_MODE_OUTPUT);
    GPIO_SetMode(PE, (BIT3 | BIT4 | BIT5 | BIT13 | BIT14), GPIO_MODE_OUTPUT);
    
    
}
