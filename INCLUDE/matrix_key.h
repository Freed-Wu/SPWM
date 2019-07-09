/*
 * matrix_key.h
 *
 *  Created on: 2019��5��18��
 *      Author: 10786
 */

#ifndef INCLUDE_MATRIX_KEY_H_
#define INCLUDE_MATRIX_KEY_H_

#include"DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
void delay(Uint16 t);
void configio(void);
void display(char *hz);
void Configio_Button(void);
unsigned char Scan_Button(void);
float get_number(void);
//#define  K0   0
//#define  K1   1
//#define  K2   2
//#define  K3   3
//#define  K4   4
//#define  K5   5
//#define  K6   6
//#define  K7   7
//#define  K8   8
//#define  K9   9
//#define  K10   10
//#define  K11   11
//#define  K12   12
//#define  K13   13
//#define  K14   14   //+
//#define  K15   15   //-
//
//#define  L_O_V_I()     EALLOW;                             \
//                       GpioCtrlRegs.GPBDIR.bit.GPIO54 = 1; \
//                       GpioDataRegs.GPBDAT.bit.GPIO54 = 0; DELAY_US(1);\
//                       GpioCtrlRegs.GPBDIR.bit.GPIO55 = 1; \
//                       GpioDataRegs.GPBDAT.bit.GPIO55 = 0; DELAY_US(1);\
//                       GpioCtrlRegs.GPBDIR.bit.GPIO56 = 1; \
//                       GpioDataRegs.GPBDAT.bit.GPIO56 = 0; DELAY_US(1);\
//                       GpioCtrlRegs.GPBDIR.bit.GPIO57 = 1; \
//                       GpioDataRegs.GPBDAT.bit.GPIO57 = 0; DELAY_US(1);\
//                       GpioCtrlRegs.GPBDIR.bit.GPIO48 = 0; \
//                       GpioDataRegs.GPBDAT.bit.GPIO48 = 0; DELAY_US(1);\
//                       GpioCtrlRegs.GPBDIR.bit.GPIO49 = 0; \
//                       GpioDataRegs.GPBDAT.bit.GPIO49 = 0; DELAY_US(1);\
//                       GpioCtrlRegs.GPBDIR.bit.GPIO52 = 0; \
//                       GpioDataRegs.GPBDAT.bit.GPIO52 = 0; DELAY_US(1);\
//                       GpioCtrlRegs.GPBDIR.bit.GPIO53 = 0; \
//                       GpioDataRegs.GPBDAT.bit.GPIO53 = 0; DELAY_US(1);\
//                       EDIS;
//#define  L_I_V_O()     EALLOW;                             \
//                       GpioCtrlRegs.GPBDIR.bit.GPIO54 = 0; \
//                       GpioDataRegs.GPBDAT.bit.GPIO54 = 0; DELAY_US(1);\
//                       GpioCtrlRegs.GPBDIR.bit.GPIO55 = 0; \
//                       GpioDataRegs.GPBDAT.bit.GPIO55 = 0; DELAY_US(1);\
//                       GpioCtrlRegs.GPBDIR.bit.GPIO56 = 0; \
//                       GpioDataRegs.GPBDAT.bit.GPIO56 = 0; DELAY_US(1);\
//                       GpioCtrlRegs.GPBDIR.bit.GPIO57 = 0; \
//                       GpioDataRegs.GPBDAT.bit.GPIO57 = 0; DELAY_US(1);\
//                       GpioCtrlRegs.GPBDIR.bit.GPIO48 = 1; \
//                       GpioDataRegs.GPBDAT.bit.GPIO48 = 0; DELAY_US(1);\
//                       GpioCtrlRegs.GPBDIR.bit.GPIO49 = 1; \
//                       GpioDataRegs.GPBDAT.bit.GPIO49 = 0; DELAY_US(1);\
//                       GpioCtrlRegs.GPBDIR.bit.GPIO52 = 1; \
//                       GpioDataRegs.GPBDAT.bit.GPIO52 = 0; DELAY_US(1);\
//                       GpioCtrlRegs.GPBDIR.bit.GPIO53 = 1; \
//                       GpioDataRegs.GPBDAT.bit.GPIO53 = 0; DELAY_US(1);\
//                       EDIS;
//
//#define   V2    GpioDataRegs.GPBDAT.bit.GPIO48
//#define   V1    GpioDataRegs.GPBDAT.bit.GPIO49
//#define   V4    GpioDataRegs.GPBDAT.bit.GPIO52
//#define   V3    GpioDataRegs.GPBDAT.bit.GPIO53
//
//#define   L1    GpioDataRegs.GPBDAT.bit.GPIO57
//#define   L2    GpioDataRegs.GPBDAT.bit.GPIO56
//#define   L3    GpioDataRegs.GPBDAT.bit.GPIO54
//#define   L4    GpioDataRegs.GPBDAT.bit.GPIO55
//#define   uchar     unsigned char

//#define     EN    GpioDataRegs.GPBDAT.bit.GPIO33
//#define     RW    GpioDataRegs.GPBDAT.bit.GPIO32
//#define     RS    GpioDataRegs.GPADAT.bit.GPIO20
/*
unsigned char const table[]={//������0~f����ܱ���
0x3f,0x06,0x5b,0x4f,     //0~3
0x66,0x6d,0x7d,0x07,    //4~7
0x7f,0x6f,0x77,0x7c,    //8~b
0x39,0x5e,0x79,0x71    //c~f
}; */
//void LCDInit(void);
//void Write_order(Uint16 order);
//void Write_data(Uint16 data);
//void delay(Uint16 t);
//void configio(void);
//void display(char *hz);
//void Configio_Button(void);

////void LCD_DATA(uchar d){
////   Uint32 i=0;
////   i = GpioDataRegs.GPADAT.all;
////   i |= (d<<6)&0x3FC0;
////   i = (~((d<<6)&0x3FC0))|(~i);
////   GpioDataRegs.GPADAT.all = ~i;
////}
////void LCDInit(void)
////{
////  delay(500);
////  Write_order(0x30);// �����趨������ָ���
////  delay(5);
////  Write_order(0x0e);//��ʾ״̬����
////  delay(5);
////  Write_order(0x01);//����
////  delay(6);
////  Write_order(0x02);//��ַ��λ��AC=0x00
////  delay(4);
////}
////
////void Write_order(Uint16 order)
////{
////   RS=0;delay(1);
////   RW=0;delay(1);
////   EN=1;delay(1);
////   LCD_DATA(order);
////   delay(10);
////   EN=0;delay(1);
////}
////
////void Write_data(Uint16 data)
////{
////   RS=1;delay(1);
////   RW=0;delay(1);
////   EN=1;delay(1);
////   LCD_DATA(data);
////   delay(10);
////   EN=0;delay(1);
////}
//
//void delay(Uint16 t)
//{
//   Uint16 i;
//   while(t--)
//    {
//      for(i=0;i<125;i++);
//    }
//}
//
////void configio(void)
////{
////    EALLOW;
////  GpioCtrlRegs.GPAMUX1.all &= 0xc03f;
////  GpioCtrlRegs.GPADIR.all |= 0x00003FC0;
////    GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 0;
////    GpioCtrlRegs.GPBDIR.bit.GPIO33 = 1;
////    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0;
////    GpioCtrlRegs.GPBDIR.bit.GPIO32 = 1;
////    GpioCtrlRegs.GPAMUX2.bit.GPIO20= 0;
////    GpioCtrlRegs.GPADIR.bit.GPIO20 = 1;
////    EDIS;
////}
//
////void display(char *hz)
////{
////   while(*hz!='\0')
////    {
////       Write_data(*hz);
////       hz++;
////       delay(2);
////    }
////}
//
//Uint16 Scan_Button(void){
//   Uint16 i=0, num=0xFFFF, x=0, y=0;
//   i = V1&V2&V3&V4;  //����ж�ȡ���е͵�ƽ˵���а�������
//   if(i == 0){
//     DELAY_US(1000);//��ʱ����
//     i = V1&V2&V3&V4;
//     if(i == 0){    //����ж�ȡ����Ȼ�е͵�ƽ˵���а�������
//        if(!V1) x= 0x10;
//        if(!V2) x= 0x20;
//        if(!V3) x= 0x30;
//        if(!V4) x= 0x40;
//        L_I_V_O();DELAY_US(200); //���������������ת
//        if(!L2) y= 0x02;
//        if(!L3) y= 0x03;
//        if(!L4) y= 0x04;
//        if(!L1) y= 0x01;
//        x |= y;
//        L_O_V_I();
//        switch(x){
//          case 0x11: num = K0;break;
//          case 0x12: num = K4;break;
//          case 0x13: num = K8;break;
//          case 0x14: num = K12;break;
//          case 0x21: num = K1;break;
//          case 0x22: num = K5;break;
//          case 0x23: num = K9;break;
//          case 0x24: num = K13;break;
//          case 0x31: num = K2;break;
//          case 0x32: num = K6;break;
//          case 0x33: num = K10;break;
//          case 0x34: num = K14;break;
//          case 0x41: num = K3;break;
//          case 0x42: num = K7;break;
//          case 0x43: num = K11;break;
//          case 0x44: num = K15;break;
//
//          default: num=0xFFFF;
//        }
//
//     }
//   }
//   return num;
//}
//
//void Configio_Button(void)
//{
//    EALLOW;
//    GpioCtrlRegs.GPBMUX2.bit.GPIO48 = 0;
////    GpioCtrlRegs.GPBDIR.bit.GPIO48 = 0;
//    GpioCtrlRegs.GPBMUX2.bit.GPIO49 = 0;
////  GpioCtrlRegs.GPBDIR.bit.GPIO49 = 0;
//    GpioCtrlRegs.GPBMUX2.bit.GPIO52 = 0;
////  GpioCtrlRegs.GPBDIR.bit.GPIO52 = 0;
//    GpioCtrlRegs.GPBMUX2.bit.GPIO53 = 0;
////  GpioCtrlRegs.GPBDIR.bit.GPIO53 = 0;
//    GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 0;
////  GpioCtrlRegs.GPBDIR.bit.GPIO54 = 0;
//    GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 0;
////  GpioCtrlRegs.GPBDIR.bit.GPIO55 = 0;
//    GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 0;
////  GpioCtrlRegs.GPBDIR.bit.GPIO56 = 0;
//    GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 0;
////  GpioCtrlRegs.GPBDIR.bit.GPIO57 = 0;
//    EDIS;
//    L_O_V_I();  //������Ϊ���������͵�ƽ��������Ϊ����
//}
//
//float get_number(void)
//{
//
//
//}


#endif /* INCLUDE_MATRIX_KEY_H_ */

