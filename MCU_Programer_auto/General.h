#ifndef _GENERAL_H
#define _GENERAL_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "Init.h"
#include "Interrupt.h"
#include "PetitModbus.h"
#include "control.h"
#include "PC.h"
//#include <stdio.h>


#define dirX 	PC3
#define dirY 	PC5 
#define dirZ  PD14 
#define dirR1  PD6
#define dirR2  PB2
#define dirR2_enZ  PB2

#define pX 	PC2
#define pY 	PC4
#define pZ 	PD15
#define pR1 	PD7
#define pR2 	PB3

#define ORG_X (PC15 == 1)
#define ORG_Y (PC7 == 1)
#define ORG_Z (PD5 == 1)

//#defien Limit_X PC14
//#defien Limit_Y PC6



#define _XILANH_1 PB11
#define _XILANH_2 PE5
#define _LAMP     PB10
#define _VACUM_1  PE4
#define _VACUM_2  PB9
#define _PUMP     PE3
//-------- Config CAM
#define _ACam PA1
#define _BCam PA2
#define _InhCam PA3

#define 	LED0	PC12
#define 	LED1	PC13
#define 	LED2	PC14
#define 	LED3	PC15

#define H_LED1 PE13
#define H_LED2 PE14

#define MAX_X 13000
#define MAX_Y 13000
#define MAX_Z 200
#define MAX_R1 1600
#define MAX_R2 1600

#define _TIEN 1
#define _LUI  0

#define _X 1
#define _Y 2
#define _Z 3
#define _R1 4
#define _R2 5

#define STOP 0
#define UP  1
#define DOWN 2

#define AUTO 1
#define MANUAL 0
#define LOW_SPEED   500
#define MID_SPEED   4000
#define HIGH_SPEED  10000



#define PUMP_ON  0
#define PUMP_OFF 1

//================================SPEED ===============================
#define R12_SPEED  250

#define Z_SPEED 3000
#define Z_SPEED_SCALE_LOW 30
#define Z_SPEED_SCALE_MID 10
#define Z_SPEED_ORG 2
#define Z_SPEED_SCALE_HIGH 1

#define X_SPEED 35000
#define X_SPEED_SCALE_LOW 30  
#define X_SPEED_SCALE_MID 10
#define X_SPEED_ORG 15
#define X_SPEED_SCALE_HIGH 1

#define Y_SPEED 35000
#define Y_SPEED_SCALE_LOW 30  
#define Y_SPEED_SCALE_MID 15
#define Y_SPEED_ORG 15
#define Y_SPEED_SCALE_HIGH 1
//========================================================================
typedef struct 
{
  unsigned int reqPul;
  unsigned int reqDir;
  unsigned int Coodhis;
  unsigned int Show_cood;
  unsigned char run;
  unsigned int PUL;
  unsigned int RF;
 
  
}Axis;

extern volatile unsigned short Timer1_Tick_Counter;
extern volatile unsigned char _RFX , _RFY , _RFZ, _RFR1, _RFR2 ;
extern volatile unsigned int _PUL_X , _PUL_Y , _PUL_Z , _PUL_R1, _PUL_R2;
extern volatile char _runX , _runY , _runZ , _runR1, _runR2;

extern unsigned int _reqX , _reqY , _reqZ, _reqR1, _reqR2 ;
extern unsigned char _reqXdir , _reqYdir , _reqZdir ,_reqR1dir,_reqR2dir;
extern unsigned int _coodhis_X , _coodhis_Y , _coodhis_Z , _coodhis_R1, _coodhis_R2 ;
extern unsigned int show_cood_X ,show_cood_Y , show_cood_Z , show_cood_R1, show_cood_R2 ;
extern volatile char temp, status_speed, _step;
extern char _ORG, _Auto_Maunual, _ups, _truc, set_speed, _orgz_ed;
extern int CAM_CHOICE;

//extern char Z_scale, R1_scale, R2_scale;
extern volatile Axis X, Y, Z, R1, R2;

extern volatile char Z_scale,Z_scale_speed, R1_scale, R2_scale;
extern volatile char X_scale, X_scale_speed;
extern volatile char Y_scale, Y_scale_speed;

extern unsigned int Auto_speed;
#endif 
