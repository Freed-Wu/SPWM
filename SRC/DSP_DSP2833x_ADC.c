//###########################################################################
//
// FILE:	DSP2833x_Adc.c
//
// TITLE:	DSP2833x ADC Initialization & Support Functions.
//
//###########################################################################
// $TI Release: F2833x/F2823x Header Files and Peripheral Examples V140 $
// $Release Date: March  4, 2015 $
// $Copyright: Copyright (C) 2007-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define ADC_usDELAY  5000L

//---------------------------------------------------------------------------
// InitAdc:
//---------------------------------------------------------------------------
// This function initializes ADC to a known state.
//
void InitAdc(void)
{
	extern void DSP28x_usDelay(Uint32 Count);


	// *IMPORTANT*
	// The ADC_cal function, which  copies the ADC calibration values from TI reserved
	// OTP into the ADCREFSEL and ADCOFFTRIM registers, occurs automatically in the
	// Boot ROM. If the boot ROM code is bypassed during the debug process, the
	// following function MUST be called for the ADC to function according
	// to specification. The clocks to the ADC MUST be enabled before calling this
	// function.
	// See the device data manual and/or the ADC Reference
	// Manual for more information.

	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1; // 使能时钟信号
	ADC_cal( );
	EDIS;

	// To powerup the ADC the ADCENCLK bit should be set first to enable
	// clocks, followed by powering up the bandgap, reference circuitry, and ADC core.
	// Before the first conversion is performed a 5ms delay must be observed
	// after power up to give all analog circuits time to power up and settle

	// Please note that for the delay function below to operate correctly the
	// CPU_RATE define statement in the DSP2833x_Examples.h file must
	// contain the correct CPU clock period in nanoseconds.

	AdcRegs.ADCTRL3.all = 0x00E0;  // Power up bandgap/reference/ADC circuits
	DELAY_US(ADC_usDELAY);         // Delay before converting ADC channels
	// Power Up finished
	//----------------------------------------------------------------------
	/*
	AdcRegs.ADCTRL1.bit.RESET = 1;
	asm(" RPT #20 || NOP");
	// Reset AD
//	AdcRegs.ADCTRL2.bit.RST_SEQ1 = 0;
//	AdcRegs.ADCTRL2.bit.RST_SEQ2 = 0;
	asm(" RPT #20 || NOP");
	AdcRegs.ADCTRL1.all = 0x02D0;
	AdcRegs.ADCTRL1.bit.ACQ_PS = 0xf;
	// Reserved = 0
	// RESET = 0
	// SUSMOD = 00
	// ACQ_PS = 0010
	// CPS = 1
	// CONT_RUN = 1
	// SEQ_OVRD = 0
	// SEQ_CASC = 1
	AdcRegs.ADCTRL2.all = 0x8900;
	AdcRegs.ADCTRL3.bit.ADCCLKPS = 0;
	AdcRegs.ADCTRL3.bit.SMODE_SEL = 0;
	AdcRegs.ADCMAXCONV.all =0x000F;
	AdcRegs.ADCST.all = 0x0030;
	AdcRegs.ADCREFSEL.bit.REF_SEL = 1;
	AdcRegs.ADCCHSELSEQ1.all = 0x3210;
	AdcRegs.ADCCHSELSEQ2.all = 0x7654;
	AdcRegs.ADCCHSELSEQ3.all = 0xBA98;
	AdcRegs.ADCCHSELSEQ4.all = 0xFEDC;
	 */
	AdcRegs.ADCTRL1.bit.ACQ_PS = 2;   // 采样窗
	AdcRegs.ADCTRL1.bit.CPS = 0;
	AdcRegs.ADCTRL3.bit.ADCCLKPS = 3;
	AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;        // 1  Cascaded mode
	AdcRegs.ADCMAXCONV.bit.MAX_CONV1 = 15;
	// AdcRegs.ADCCHSELSEQ1.all = 0x3210;
	// AdcRegs.ADCCHSELSEQ2.all = 0x7654;
	// AdcRegs.ADCCHSELSEQ3.all = 0xBA98;
	// AdcRegs.ADCCHSELSEQ4.all = 0xFEDC;

	AdcRegs.ADCCHSELSEQ1.all = 0x3210;
	AdcRegs.ADCCHSELSEQ2.all = 0x7654;
	AdcRegs.ADCCHSELSEQ3.all = 0xBA98;
	AdcRegs.ADCCHSELSEQ4.all = 0xFEDC;

	AdcRegs.ADCTRL1.bit.CONT_RUN = 0;       //
	AdcRegs.ADCTRL3.bit.ADCCLKPS = 3;
	AdcRegs.ADCREFSEL.bit.REF_SEL = 0;      // 内部参考
	AdcRegs.ADCST.all = 0x0030;
	AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 1;

	AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 = 1;
	//AdcRegs.ADCTRL2.bit.EPWM_SOCB_SEQ = 1;
}

//===========================================================================
// End of file.
//===========================================================================

