
#include "General.h"
//

//struct Axis
//{
//  unsigned int req;
//  unsigned int Coodhis;
//  unsigned int Show_cood;
//  unsigned char run;
//  unsigned int PUL;
//  unsigned int RF;

//};

//struct Axis AX;

// update


//123312
// _____________ test1
int32_t main()
{
  
    
    SYS_Init();	
    Init_KEY();
    Init_axits();  // KHOI TAO TIMER CHO 3TRUC
    InitPetitModbus(1); // KHOI TAO GIAO THUC MODBUS

    SETUP_SYSTEM();
    while(1)
		{
      PC_SW();
      

    }
}
