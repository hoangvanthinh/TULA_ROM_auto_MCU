
#ifndef _CONTROL_H
#define _CONTROL_H

void Init_axits(void);
void PUL_X(unsigned int pulx, char dir);
void PUL_Y(unsigned int puly, char dir);
void PUL_Z(unsigned int pulz, char dir);
void Move_X(unsigned int coodinatesX);
void Move_Y(unsigned int coodinatesY);
void Move_Z(unsigned int coodinatesZ);
void ORGIN(void);
void Pause_all(void);
void Calib_xyzr(char truc, char ups);
void SET_SPEED(void);
void Signal_1(void);  // cam bottom
void Signal_2(void);  // cam top
void PUL_R1(unsigned int pulr, char dir);
void Move_R1(unsigned int coodinatesR1);
void PUL_R2(unsigned int pulr, char dir);
void Move_R2(unsigned int coodinatesR2);
  
#endif 
