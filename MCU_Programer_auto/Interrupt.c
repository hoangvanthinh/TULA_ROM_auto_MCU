#include "General.h"

void TMR0_IRQHandler(void)
{
			Timer1_Tick_Counter++;
			
			TIMER_ClearIntFlag(TIMER0); // Clear Timer0 time-out interrupt flag
      PetitModBus_TimerValues();
}
void TMR1_IRQHandler(void)
{
			if(X.PUL)
			{      
        if((X.Show_cood <= MAX_X && dirX == _TIEN) || (X.Show_cood >= 100 && dirX == _LUI && !_ORG) || _ORG)
        {
					//X.run = 1;         
	        X_scale ++;
          if(X_scale == X_scale_speed)
          {
            X_scale = 0;
            
              if(X.RF == 0)
              {
                  X.RF = 1; 
                  pX=1; 
              }
              else  
              {
                  X.RF = 0; 
                  pX=0; 
                  X.PUL--; 
                  if(dirX == _TIEN)
                    X.Show_cood++;
                  else
                    X.Show_cood--;
                  
              }
          }
        }
			}
			else
			{
					X.run = 0;
					TIMER_Stop(TIMER1);
				
			}
			TIMER_ClearIntFlag(TIMER1);
	
}
void TMR2_IRQHandler(void)
{
   
			if(Z.PUL)
			{
        //if((Z.Show_cood <= MAX_Z && dirZ == _TIEN) || (Z.Show_cood >= 5 && dirZ == _LUI && !_ORG) || _ORG)
        if(( Z.Show_cood <= MAX_Z && dirZ == _TIEN) || (Z.Show_cood >= 5 && dirZ == _LUI && !_ORG) || _ORG)
        
        {
          
					//Z.run = 1;
          
          Z_scale ++;
          if(Z_scale == Z_scale_speed)
          {
            Z_scale = 0;
            if(Z.RF == 0) 
            {
                Z.RF = 1; 
                pZ=1; 
            }
            else  
            {
                Z.RF = 0; 
                pZ=0; 
                Z.PUL--; 
              if(dirZ ==  _TIEN)
                Z.Show_cood++;
              else
                Z.Show_cood--;
              
            }
          }
        }
			}
      else if(_PUL_R1)
      {
					_runR1 = 1;
        R1_scale++;
        if(R1_scale == 10)
        {
          R1_scale = 0;
					if(_RFR1 == 0) 
					{
							_RFR1 = 1; 
							pR1=1; 
					}
					else  
					{
			
            _RFR1 = 0; 
							pR1=0; 
							_PUL_R1--; 
            if(dirR1 ==  _TIEN)
              show_cood_R1++;
            else
              show_cood_R1--;
						
					}
        }
      }
//      else if(_PUL_R2)
//      {
// 					_runR2 = 1;
//        R2_scale++;
//        if(R2_scale == 10)
//        {
//          R2_scale = 0;
//					if(_RFR2 == 0) 
//					{
//							_RFR2 = 1; 
//							pR2=1; 
//					}
//					else  
//					{
//							_RFR2 = 0; 
//							pR2=0; 
//							_PUL_R2--; 
//            if(dirR2 ==  _TIEN)
//              show_cood_R2++;
//            else
//              show_cood_R2--;
//						
//					} 
//        }          
//      }
			else
			{
					Z.run = 0;
          _runR1 = 0;
          _runR2 = 0;
					TIMER_Stop(TIMER2);
			}
			TIMER_ClearIntFlag(TIMER2); 
}
void TMR3_IRQHandler(void)
{
      if(Y.PUL)
			{
        if((Y.Show_cood <= MAX_Y && dirY == _TIEN) || (Y.Show_cood >= 100 && dirY == _LUI && !_ORG) || _ORG)
        {
					//Y.run = 1;
          Y_scale ++;
          if(Y_scale == Y_scale_speed)
          {
              Y_scale = 0;     
              if(Y.RF == 0) 
              {
                  Y.RF = 1; 
                  pY=1; 
              }
              else  
              {
                  Y.RF = 0; 
                  pY=0; 
                  Y.PUL--; 
                if(dirY == _TIEN)
                  Y.Show_cood++;
                else 
                  Y.Show_cood--;
              }
           }
        }

			}
			else
			{
					Y.run = 0;
					TIMER_Stop(TIMER3);
			}

      TIMER_ClearIntFlag(TIMER3); 
}
//void UART1_IRQHandler(void)
//{   
//    if(UART_IS_RX_READY(UART1)) 
//		{			
//				ReceiveInterrupt(UART1->RBR);
//    }
//}
void UART02_IRQHandler(void)
{   
    if(UART_IS_RX_READY(UART0)) 
		{			
				ReceiveInterrupt(UART0->RBR);
    }
}
void GPCDEF_IRQHandler(void)
{
    if (PC->ISRC & BIT7) {        // check if PB12 interrupt occurred
        PC->ISRC |= BIT7;         // clear PB12 interrupt status
      TIMER_Stop(TIMER3); //  ORIGIN TRUC Y
      Y.run = 0;		                
    } 
    else if (PC->ISRC & BIT15) { // check if Pb13 interrupt occurred
        PC->ISRC |= BIT15;         // clear PB13 interrupt status  
             
      TIMER_Stop(TIMER1); // ORIGIN TRUC X
      X.run = 0;
    } 
    else if (PD->ISRC & BIT5) { // check if PB14 interrupt occurred
        PD->ISRC |= BIT5;         // clear PB14 interrupt status 
      TIMER_Stop(TIMER2); // TRUC Z TIMER3
      Z.run = 0;   
    } 
    else if (PB->ISRC & BIT11) { // check if PB14 interrupt occurred
        PB->ISRC |= BIT11;       
      	             		
		} 
    else if (PB->ISRC & BIT9) { // check if PB14 interrupt occurred
				PB->ISRC |= BIT9;         // clear PB14 interrupt status  
			  	
    } 
    else {                      // else it is unexpected interrupts
        PB->ISRC = PB->ISRC;	      // clear all GPB pins
    }
		
		//H_LED1  = ~ H_LED1;

}
