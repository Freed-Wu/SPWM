#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "lcd.h"
#include "matrix_key.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
static char tempTable[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void num2char ( char* str, double number, int g, int l ) {
	int i;
	int temp = number / 1;
	double t2 = 0.0;
	for ( i = 1; i <= g; i++ ) {
		if ( temp == 0 )
			str[g - i] = tempTable[0];
		else
			str[g - i] = tempTable[temp % 10];
		temp = temp / 10;
	}
	* ( str + g ) = '.';
	temp = 0;
	t2 = number;
	for ( i = 1; i <= l; i++ ) {
		temp = t2 * 10;
		str[g + i] = tempTable[temp % 10];
		t2 = t2 * 10;
	}
	* ( str + g + l + 1 ) = '\0';
}
#define  mPI   3.1415927
extern interrupt void IntelAD_ISR ( void );
extern interrupt void User_EPWM1_INT_ISR ( void );
float gTs;
float gVm;
float gF;
float gVoltage;
unsigned int gCnt;
unsigned int gCMP_Save[200];
unsigned int gCMP_Save[200];
unsigned int gCnt_Save;
unsigned char a = 0;
float gM;
//input:��������
//disp:��Ļ��ʾ
//gVm:��ʾ������ת��Ϊ�����ѹ�����ֵ
//mode:ģʽѡ���������ѹ���룬��A�л���ѹ��Ƶ��
//load:����ѡ���������޸��أ���B�л�����
unsigned char input = '\0';
char disp[12] = "";
int mode = 0;
int load = 0;
int dot = 0;
void main ( void ) {
	InitSysCtrl( );
	InitPieCtrl( );
	InitPieVectTable( );
	InitGpio( );
	DINT;
	IER = 0x0000;
	IFR = 0x0000;
	asm ( " EALLOW" );
	PieVectTable.EPWM1_INT = &User_EPWM1_INT_ISR;
	asm ( " EDIS" );
	//InitXintf( );
	gTs = 1.0 / 200e3; //200k ����Ƶ��
	gVm = 1 ; // gVm �����Чֵ 1*1.414(����2)
	gF = 5000;// gF Ƶ��
	gCnt = 0;
	gCnt_Save = 0;
	gM = 0;
	//InitAdc( );
	InitEPwm( );
	lcd_init();
	Configio_Button();
	//InitGlobalVariable( );
	IER |= M_INT3;
	//  IER |= M_INT2;
	PieCtrlRegs.PIEIER3.bit.INTx1 = 1;
	//  PieCtrlRegs.PIEIER2.bit.INTx1 = 1;
	EINT;
	ERTM;
	while ( 1 ) {
		/********
		*  ��ʾ  *
		********/
		LCD12864_Clear();
		char show1[12] = "";
		num2char ( show1, gVm, 2, 2 );
		char show11[12]  = "��ѹ��";
		strcat ( show11, show1 );
		strcat ( show11, "V" );
		strDisp ( 1, 1, show11, 12 );
		char show2[12] = "";
		num2char ( show2, gF, 5, 0 );
		char show21[12]  = "Ƶ�ʣ�";
		strcat ( show21, show2 );
		strcat ( show21, "Hz" );
		strDisp ( 2, 1, show21, 14 );
		char show3[12] = "���룺";
		strcat ( show3, disp );
		strDisp ( 3, 1, show3, 14 );
		char show4[12] = "ģʽ��";
		if ( mode )
			strcat ( show4, "Ƶ��" );
		else
			strcat ( show4, "��ѹ" );
		if ( load )
			strcat ( show4, "*" );
		else
			strcat ( show4, " " );
		strDisp ( 4, 1, show4, 14 );
		/*DELAY_US(1000000);*/
		/**********
		*  ����ɨ��  *
		**********/
		if ( load == 1 ) gVm = gVm * 2; ////
		while ( input == '\0' || Scan_Button() != '\0' )
			input = Scan_Button();
		switch ( input ) {
			case '*':
				//ȷ��
				if ( mode )
					gF = atof ( disp );
				else
					gVm = atof ( disp );
			case 'C':
				//����ȷ����գ���Ҫ����ʾ���
				dot = 0;
				strcpy ( disp, "" );
				break;
			case '#':
				if ( strlen ( disp ) ) {
					if ( disp[strlen ( disp ) - 1] == '.' )
						dot = 0;
					disp[strlen ( disp ) - 1] = '\0';
				}
				break;
			case 'A':
				mode = !mode;
				break;
			case 'B':
				load = !load;
				break;
			case 'D':
				if ( dot == 0 ) {
					strcat ( disp, "." );
					dot = 1;
				}
				break;
			default:
				if ( strlen ( disp ) < 10 ) {
					disp[strlen ( disp ) + 1] = '\0';
					disp[strlen ( disp )] = input;
				}
		}
		input = '\0';
	}
}
extern interrupt void User_EPWM1_INT_ISR ( void ) {
	float Time, Omiga;
	unsigned int CMP;
	Time = gCnt * gTs;
	Omiga = 2.0 * mPI * gF * Time;
	gVoltage = gVm * 1.414 * cos ( Omiga ) + 15;
	//gVoltage_Save[gCnt_Save] = gVoltage;
	gCnt++;
	if ( Omiga >= 2.0 * mPI )
		gCnt = 0;
	gM = gVoltage * 0.033F;
	CMP = gM * EPwm1Regs.TBPRD;
	//gCMP_Save[gCnt_Save] = CMP;
	//gCnt_Save++;
	//if( gCnt_Save >= 200 )
	{
		gCnt_Save = 0;
	}
	EPwm1Regs.CMPA.half.CMPA = CMP;
	GpioDataRegs.GPBTOGGLE.bit.GPIO60 = 1;
	////===================================
	EPwm1Regs.ETCLR.bit.INT = 1;
	PieCtrlRegs.PIEACK.all |= PIEACK_GROUP3;
}
// =====================================================================================================
// End of file
// =====================================================================================================

