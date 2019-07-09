/*
 * matrix_key.c
 *
 *  Created on: 2019��5��18��
 *      Author: 10786
 */
#include"DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "matrix_key.h"
#include <string.h>
#define  L_O_V_I()     EALLOW;                             \
                       GpioCtrlRegs.GPADIR.bit.GPIO8 = 1; \
                       GpioDataRegs.GPADAT.bit.GPIO8 = 0; DELAY_US(1);\
                       GpioCtrlRegs.GPADIR.bit.GPIO9 = 1; \
                       GpioDataRegs.GPADAT.bit.GPIO9 = 0; DELAY_US(1);\
                       GpioCtrlRegs.GPADIR.bit.GPIO10 = 1; \
                       GpioDataRegs.GPADAT.bit.GPIO10 = 0; DELAY_US(1);\
                       GpioCtrlRegs.GPADIR.bit.GPIO11 = 1; \
                       GpioDataRegs.GPADAT.bit.GPIO11 = 0; DELAY_US(1);\
                       GpioCtrlRegs.GPADIR.bit.GPIO12 = 0; \
                       GpioDataRegs.GPADAT.bit.GPIO12 = 0; DELAY_US(1);\
                       GpioCtrlRegs.GPADIR.bit.GPIO13 = 0; \
                       GpioDataRegs.GPADAT.bit.GPIO13 = 0; DELAY_US(1);\
                       GpioCtrlRegs.GPADIR.bit.GPIO14 = 0; \
                       GpioDataRegs.GPADAT.bit.GPIO14 = 0; DELAY_US(1);\
                       GpioCtrlRegs.GPADIR.bit.GPIO15 = 0; \
                       GpioDataRegs.GPADAT.bit.GPIO15 = 0; DELAY_US(1);\
                       EDIS;
#define  L_I_V_O()     EALLOW;                             \
                       GpioCtrlRegs.GPADIR.bit.GPIO12 = 1; \
                       GpioDataRegs.GPADAT.bit.GPIO12 = 0; DELAY_US(1);\
                       GpioCtrlRegs.GPADIR.bit.GPIO13 = 1; \
                       GpioDataRegs.GPADAT.bit.GPIO13 = 0; DELAY_US(1);\
                       GpioCtrlRegs.GPADIR.bit.GPIO14 = 1; \
                       GpioDataRegs.GPADAT.bit.GPIO14 = 0; DELAY_US(1);\
                       GpioCtrlRegs.GPADIR.bit.GPIO15 = 1; \
                       GpioDataRegs.GPADAT.bit.GPIO15 = 0; DELAY_US(1);\
                       GpioCtrlRegs.GPADIR.bit.GPIO8 = 0; \
                       GpioDataRegs.GPADAT.bit.GPIO8 = 0; DELAY_US(1);\
                       GpioCtrlRegs.GPADIR.bit.GPIO9 = 0; \
                       GpioDataRegs.GPADAT.bit.GPIO9 = 0; DELAY_US(1);\
                       GpioCtrlRegs.GPADIR.bit.GPIO10 = 0; \
                       GpioDataRegs.GPADAT.bit.GPIO10 = 0; DELAY_US(1);\
                       GpioCtrlRegs.GPADIR.bit.GPIO11 = 0; \
                       GpioDataRegs.GPADAT.bit.GPIO11 = 0; DELAY_US(1);\
                       EDIS;
#define   V1    GpioDataRegs.GPADAT.bit.GPIO12
#define   V2    GpioDataRegs.GPADAT.bit.GPIO13
#define   V3    GpioDataRegs.GPADAT.bit.GPIO14
#define   V4    GpioDataRegs.GPADAT.bit.GPIO15
#define   L1    GpioDataRegs.GPADAT.bit.GPIO8
#define   L2    GpioDataRegs.GPADAT.bit.GPIO9
#define   L3    GpioDataRegs.GPADAT.bit.GPIO10
#define   L4    GpioDataRegs.GPADAT.bit.GPIO11
#define   uchar     unsigned char
void delay(Uint16 t)
{
	Uint16 i;
	while (t--)
	{
		for (i = 0; i < 125; i++);
	}
}
unsigned char Scan_Button(void)
{
	unsigned char i = 0, x = 0, y = 0;
	unsigned char str = '\0';
	i = V1 & V2 & V3 & V4; //����ж�ȡ���е͵�ƽ˵���а�������
	if (i == 0)
	{
		DELAY_US(50);//��ʱ����
		i = V1 & V2 & V3 & V4;
		if (i == 0)    //����ж�ȡ����Ȼ�е͵�ƽ˵���а�������
		{
			if (!V1) x = 0x10;
			if (!V2) x = 0x20;
			if (!V3) x = 0x30;
			if (!V4) x = 0x40;
			L_I_V_O();
			DELAY_US(50); //���������������ת
			if (!L2) y = 0x02;
			if (!L3) y = 0x03;
			if (!L4) y = 0x04;
			if (!L1) y = 0x01;
			x |= y;
			L_O_V_I();
			switch (x)
			{
			case 0x11:
				str = '1';
				break;
			case 0x12:
				str = '2';
				break;
			case 0x13:
				str = '3';
				break;
			case 0x14:
				str = 'A';
				break;
			case 0x21:
				str = '4';
				break;
			case 0x22:
				str = '5';
				break;
			case 0x23:
				str = '6';
				break;
			case 0x24:
				str = 'B';
				break;
			case 0x31:
				str = '7';
				break;
			case 0x32:
				str = '8';
				break;
			case 0x33:
				str = '9';
				break;
			case 0x34:
				str = 'C';
				break;
			case 0x41:
				str = '*';
				break;
			case 0x42:
				str = '0';
				break;
			case 0x43:
				str = '#';
				break;
			case 0x44:
				str = 'D';
				break;
			default:
				str = '\0';
			}
		}
	}
	return str;
}
void Configio_Button(void)
{
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 0;
//    GpioCtrlRegs.GPBDIR.bit.GPIO48 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 0;
//  GpioCtrlRegs.GPBDIR.bit.GPIO49 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 0;
//  GpioCtrlRegs.GPBDIR.bit.GPIO52 = 0;10
	GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 0;
//  GpioCtrlRegs.GPBDIR.bit.GPIO53 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 0;
//  GpioCtrlRegs.GPBDIR.bit.GPIO54 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 0;
//  GpioCtrlRegs.GPBDIR.bit.GPIO55 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 0;
//  GpioCtrlRegs.GPBDIR.bit.GPIO56 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 0;
//  GpioCtrlRegs.GPBDIR.bit.GPIO57 = 0;
	GpioCtrlRegs.GPAPUD.all = 0;
	EDIS;
	L_O_V_I();  //������Ϊ���������͵�ƽ��������Ϊ����
}
float get_number(void)
{
}



