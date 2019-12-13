#include "General.h"

void Init_axits(void)
{
    Init_Timer1();
		Init_Timer2();
		Init_Timer3();
  
    GPIO_SetMode(PC, (BIT2 | BIT3 | BIT4 | BIT5 ), GPIO_PMD_OUTPUT); // set LED GPIO pin
    GPIO_SetMode(PD, (BIT6 | BIT7 | BIT14 | BIT15 ), GPIO_PMD_OUTPUT); // set LED GPIO pin
    
		dirX = dirY = dirZ = dirR1= dirR2 = 0;
    pX = pY = pZ = pR1= pR2 = 0;
  
    X.Coodhis = Y.Coodhis = Z.Coodhis = 0;
    X.PUL = Y.PUL = Z.PUL = 0;
    X.Show_cood = Y.Show_cood = Z.Show_cood = 0;
    X.reqPul = Y.reqPul = Z.reqPul = 0;
    X.run = Y.run = Z.run = 0;
}

void PUL_X(unsigned int pulx, char dir)
{
    if(!X.run)
    {
        X.run = 1;
        dirX = dir;
        X.PUL = pulx;
        TIMER_Start(TIMER1);
    }
}
void Move_X(unsigned int coodinatesX)
{
    char dirx;
    unsigned int pulx;
     
    if(coodinatesX > X.Coodhis)
        dirx = _TIEN;  
    else    
        dirx = _LUI;
    if(coodinatesX != X.Coodhis)
    {
        pulx = abs((int)(coodinatesX - X.Coodhis));
        X.Coodhis = coodinatesX;
        PUL_X(pulx,dirx);
    }  
    else
    {
        X.run = 0;
    } 
}

void PUL_Y(unsigned int puly, char dir)
{
    if(!Y.run)
    {
      Y.run = 1;
      dirY = dir;
      Y.PUL = puly;
      TIMER_Start(TIMER3);
      
    }

}
void Move_Y(unsigned int coodinatesY)
{
    char diry;
    unsigned int puly;

    if(coodinatesY > Y.Coodhis)
        diry = _TIEN;  
    else    
        diry = _LUI;
    if(coodinatesY != Y.Coodhis)
    {   
        puly = abs((int)(coodinatesY - Y.Coodhis));
        Y.Coodhis = coodinatesY;
        PUL_Y(puly,diry);
    }
    else
    {
        Y.run = 0;
    }
}
void PUL_Z(unsigned int pulz, char dir)
{
    if(!Z.run)
    {
        Z.run = 1;
        dirZ = dir;
        Z.PUL = pulz;
        TIMER_Start(TIMER2);  
    }

}
void Move_Z(unsigned int coodinatesZ)
{
    char dirz;
    unsigned int pulz;  
    if(coodinatesZ > Z.Coodhis)
        dirz = _TIEN;  
    else    
        dirz = _LUI;
    if(coodinatesZ != Z.Coodhis)
    {   
        pulz = abs((int)(coodinatesZ - Z.Coodhis));
        Z.Coodhis = coodinatesZ;
        PUL_Z(pulz,dirz);
    }
    else
    {
      Z.run = 0;
    }   
}
//========================== R1=====================================


void PUL_R1(unsigned int pulr, char dir)
{
//  TIMER_Stop(TIMER2); 
//    TIMER_Open(TIMER2, TMR2_OPERATING_MODE,R12_SPEED);
  
    if(!_runR1)
    {
        dirR1 = dir;
        _PUL_R1 = pulr;
      TIMER_Start(TIMER2);
        //TIMER_Start(TIMER3);
    }

}
void Move_R1(unsigned int coodinatesR1)
{
  
    char dirr1;
    unsigned int pulr1;
    if(coodinatesR1 > 800)
      {
        dirr1 = _TIEN;  
        coodinatesR1 -= 800;
        }
    else    
      {
        dirr1 = _LUI;
        coodinatesR1 = 800 - coodinatesR1;
    }
    
    if(coodinatesR1 != _coodhis_R1)
    {   
        pulr1 = abs((int)(coodinatesR1 - _coodhis_R1));
        _coodhis_R1= coodinatesR1;
        PUL_R1(pulr1,dirr1);
    }   
//    if(coodinatesR1 > _coodhis_R1)
//        dirr1 = _TIEN;  
//    else    
//        dirr1 = _LUI;
//    if(coodinatesR1 != _coodhis_R1)
//    {   
//        pulr1 = abs((int)(coodinatesR1 - _coodhis_R1));
//        _coodhis_R1= coodinatesR1;
//        PUL_R1(pulr1,dirr1);
//    }  
}
//========================== R2 =====================================
void PUL_R2(unsigned int pulr, char dir)
{
    if(!_runR2)
    {
        dirR2 = dir;
        _PUL_R2 = pulr;
      TIMER_Start(TIMER2);
        //TIMER_Start(TIMER3);
    }

}
void Move_R2(unsigned int coodinatesR2)
{
    char dirr2;
    unsigned int pulr2;
    if(coodinatesR2 > _coodhis_R2)
        dirr2 = _TIEN;  
    else    
        dirr2 = _LUI;
    if(coodinatesR2 != _coodhis_R2)
    {   
        pulr2 = abs((int)(coodinatesR2 - _coodhis_R2));
        _coodhis_R2= coodinatesR2;
        PUL_R2(pulr2,dirr2);
    }   
}
//====================================================================
void ORGIN(void)
{
    
    TIMER_Stop(TIMER0); 

    Pause_all();
    X.PUL = Y.PUL = Z.PUL = 0;
    X.run = Y.run = Z.run = 0;
  
    Z_scale_speed = Z_SPEED_ORG;
    Y_scale_speed = Y_SPEED_ORG;
    X_scale_speed = X_SPEED_ORG;
  
    dirR2_enZ = 0; // DIS
    CLK_SysTickDelay(1000000);
    CLK_SysTickDelay(1000000);
    dirR2_enZ = 1;
//    if(!ORG_Z)
//    {
//        PUL_Z(2000,_LUI);  // orgZ = PB10
//        while(Z.PUL != 0);
//        CLK_SysTickDelay(1000000);
//         
//    }
    if(ORG_Z)// && !_orgz_ed)
    {
      _orgz_ed = 1;
        PUL_Z(100,_TIEN);
        while(Z.run);
        CLK_SysTickDelay(1000000);
        PUL_Z(200,_LUI);
        while(!ORG_Z);
        CLK_SysTickDelay(1000000);
    }
    if(!ORG_Y)
    {
        PUL_Y(MAX_Y*2,_LUI);  //  ORGY PB12   
        while(!ORG_Y);
        CLK_SysTickDelay(1000000);
      
        PUL_Y(300,_TIEN);
        while(ORG_Y);
        CLK_SysTickDelay(1000000);
      
        PUL_Y(500,_LUI);
        while(!ORG_Y);
    }
    if(!ORG_X)
    {
        PUL_X(MAX_X*2,_LUI);  // orgx = PB13
        
        while(!ORG_X);
        CLK_SysTickDelay(1000000);
        PUL_X(100,_TIEN);
      
        while(ORG_X);
        CLK_SysTickDelay(1000000);    
      
        PUL_X(500,_LUI);
        while(!ORG_X);
    }

    X.Coodhis = Y.Coodhis = Z.Coodhis = 0;
    X.PUL = Y.PUL = Z.PUL = 0;
    X.Show_cood = Y.Show_cood = Z.Show_cood = 0;
    X.reqPul = Y.reqPul = Z.reqPul = 0;
    X.run = Y.run = Z.run = 0;
    _ORG = 0;
    TIMER_Start(TIMER0);
    

}
void Pause_all(void)
{
    TIMER_Stop(TIMER1);
    TIMER_Stop(TIMER2);
    TIMER_Stop(TIMER3);
}
void Calib_xyzr(char truc, char ups)
{
    
    if(ups == STOP)
    {
        Pause_all();
        X.PUL = Y.PUL = Z.PUL = 0;
        X.run = Y.run = Z.run = 0;
    }
    else
    {
        if(truc == _X && !X.run )
        {
            if(ups == UP)
            {
              PUL_X(MAX_X,_TIEN);
            }
            else
            {
              if(!ORG_X)
              PUL_X(MAX_X,_LUI);
            }
        }
        if(truc == _Y && !Y.run )
        {
            if(ups == UP)
            {
              PUL_Y(MAX_Y,_TIEN);
            }
            else
            {
      
              if(!ORG_Y)
              PUL_Y(MAX_Y,_LUI);
        
            }
        } 
        if(truc == _Z && !Z.run )
        {
            if(ups == UP)
            {
              PUL_Z(MAX_Z,_TIEN);
            }
            else
            {
      
              if(!ORG_Z)
              PUL_Z(MAX_Z,_LUI);
            }
        }  
        if(truc == _R1 && !_runR1 )
        {
            if(ups == UP)
            {
              PUL_R1(MAX_R1,_TIEN);
            }
            else
            {
      
              //if(!ORG_Z)
              PUL_R1(MAX_R1,_LUI);
            }
        }      
        if(truc == _R2 && !_runR2 )
        {
            if(ups == UP)
            {
              PUL_R2(MAX_R2,_TIEN);
            }
            else
            {
      
              //if(!ORG_Z)
              PUL_R2(MAX_R2,_LUI);
            }
        }       
    }
    
}
void SET_SPEED(void)
{
    if(_Auto_Maunual == MANUAL)
    {
        //Auto_speed = 10;
        Z_scale_speed = 11 - Auto_speed;
        Y_scale_speed = 11 - Auto_speed;
        X_scale_speed = 11 - Auto_speed;
      
     }
    else
    {
        //if(!set_speed)
        {
          //Auto_speed = 10;
          Z_scale_speed = 11 - Auto_speed;
          Y_scale_speed = 11 - Auto_speed;
          X_scale_speed = 11 - Auto_speed;
        }
    }
    
}
void Signal_2(void)
	{
		_InhCam=1;
		_ACam=1;
		_BCam=1;
		
		
	}
void Signal_1(void)
	{
		_InhCam=1;
		_ACam=0;
		_BCam=1;
		
		
	}
  