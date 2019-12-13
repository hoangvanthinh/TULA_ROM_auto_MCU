#include "General.h"

volatile unsigned short Timer1_Tick_Counter;

volatile unsigned char _RFX = 0, _RFY = 0, _RFZ = 0, _RFR1 = 0, _RFR2 = 0;
volatile unsigned int   _PUL_X = 0, _PUL_Y = 0, _PUL_Z = 0, _PUL_R1 = 0 ,_PUL_R2 = 0;
volatile  char _runX = 0, _runY = 0, _runZ = 0, _runR1 = 0,_runR2 = 0;

unsigned int _reqX = 0, _reqY = 0, _reqZ = 0, _reqR1 = 0, _reqR2 = 0;
unsigned char _reqXdir = 0, _reqYdir = 0, _reqZdir = 0,_reqR1dir = 0,_reqR2dir = 0 ;
unsigned int _coodhis_X =0, _coodhis_Y =0, _coodhis_Z =0, _coodhis_R1 =800, _coodhis_R2 =0;
unsigned int show_cood_X = 0,show_cood_Y = 0, show_cood_Z = 0, show_cood_R1 = 0, show_cood_R2 = 0;
volatile char temp = 0, status_speed = 0, _step = 0;
char _ORG = 0, _Auto_Maunual = 0, _ups = 0, _truc = 0;
char set_speed = 0, _orgz_ed = 0;
//char Z_scale = 0, R1_scale, R2_scale;
int CAM_CHOICE = 0;

volatile char Z_scale = 0, Z_scale_speed = Z_SPEED_SCALE_HIGH, R1_scale, R2_scale;
volatile char X_scale = 0, X_scale_speed = X_SPEED_SCALE_HIGH;
volatile char Y_scale = 0, Y_scale_speed = Y_SPEED_SCALE_HIGH;

unsigned int Auto_speed = 0;
//======================================
volatile Axis X, Y, Z, R1, R2;


