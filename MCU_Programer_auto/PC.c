#include "General.h"

// test update
void SETUP_SYSTEM(void)
{
    X.reqPul = X.reqDir = X.Coodhis = X.run = X.Show_cood = X.RF = 0;
    Y.reqPul = Y.reqDir = Y.Coodhis = Y.run = Y.Show_cood = Y.RF = 0;
    Z.reqPul = Z.reqDir = Z.Coodhis = Z.run = Z.Show_cood = Z.RF = 0;

    _ORG = 1;
    ORGIN();
    while((!ORG_X )&& (!ORG_Y) && (!ORG_Z));
  
    _XILANH_1 = 0;
    _XILANH_2 = 0;
    _LAMP = 0;
    _VACUM_1 = 0;
    _VACUM_2 = 0;
    _PUMP =  PUMP_OFF;// PUMP_ON;
    H_LED1 = 0;
    H_LED2 = 0;
    Signal_1();
  
    PetitRegisters[7].ActValue = MANUAL;
  

}
void PC_SW(void)
{
  			ProcessPetitModbus();
        PetitRegisters[1].ActValue = X.Show_cood; 
        PetitRegisters[2].ActValue = Y.Show_cood; 
        PetitRegisters[3].ActValue = Z.Show_cood; 
        PetitRegisters[4].ActValue = R1.Show_cood; 
        PetitRegisters[5].ActValue = R2.Show_cood; 
        // ---------------------- ORG ------------------------
        _ORG = PetitRegisters[6].ActValue;
        if(_ORG) 
        {
          
          ORGIN();            
          for(int i = 0; i <= 20; i++)
            PetitRegisters[i].ActValue = 0;
          
          PetitRegisters[14].ActValue = 800;
          PetitRegisters[19].ActValue = PUMP_OFF;
          PetitRegisters[10].ActValue = 10; //HIGH SPEED
        }
        //---------------------- MOVE AUTO---------------------------
        _Auto_Maunual = PetitRegisters[7].ActValue;
        Auto_speed = PetitRegisters[10].ActValue;
        
        SET_SPEED();
        //--------------------- MANUAL ---------------------------
        if(_Auto_Maunual == MANUAL)
        {           
            _ups = PetitRegisters[8].ActValue;
            _truc = PetitRegisters[9].ActValue;        
            Calib_xyzr(_truc, _ups);          
        }
        else
        {        
            //==============================================
            X.reqPul = PetitRegisters[11].ActValue;
            Y.reqPul = PetitRegisters[12].ActValue;
            Z.reqPul = PetitRegisters[13].ActValue;
            Move_X(X.reqPul);
            Move_Y(Y.reqPul);
          
            //==============================================
            if(Z.reqPul > MAX_Z)
            {              
                Z.reqPul = MAX_Z;
                PetitRegisters[13].ActValue = MAX_Z;
            }
            
            Move_Z(Z.reqPul);

            _reqR1 = PetitRegisters[14].ActValue;
            if(_reqR1 != _coodhis_R1)
            {
              if(_reqR1 > 800)
                PUL_R1(_reqR1 - 800,_TIEN);
              else
                PUL_R1(800- _reqR1,_LUI);
              _coodhis_R1 = _reqR1;
            }
        }

//        PetitRegisters[15].ActValue = _runX;
//        PetitRegisters[16].ActValue = _runY;
//        PetitRegisters[17].ActValue = _runZ;
//        PetitRegisters[18].ActValue = _runR1;
        
        _PUMP = PetitRegisters[19].ActValue;
        _VACUM_1 = PetitRegisters[20].ActValue;
        _VACUM_2 = PetitRegisters[21].ActValue;
        _LAMP = PetitRegisters[22].ActValue;    
        
        _XILANH_1 = PetitRegisters[23].ActValue;  
        _XILANH_2 = ~ _XILANH_1;
          
        CAM_CHOICE = PetitRegisters[24].ActValue; 
        if(CAM_CHOICE == 1)
          Signal_1();
        if(CAM_CHOICE == 2)
          Signal_2();
        
}
