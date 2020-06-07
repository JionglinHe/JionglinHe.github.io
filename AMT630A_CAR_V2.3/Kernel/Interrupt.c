/*******************************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� Interrupt.c	  
*Version:      1.0
*update:       2011-12-10
*Description:
  		   ϵͳ�жϴ���
  		   
*History:  jordan.chen  2011/12/10    1.0    build  this  moudle
******************************************************************************/
#define _INTERRUPT_C_

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "Debug.h"
#include "mcu.h"
#include "MsgMap.h"
#include "Ir.h"
#include "delay.h"
#include "AMT_MCU.h"
#include "AMT_Drv.h"
#include "AMT_REG.h"
#include "BT_UartRec.h"
#include "interrupt.h"
#include "Osd_Menu.h"
#include "Osd_MenuPage.h"



void POS_IrqServerExt0(void) interrupt 0 //ext 0  IR  interrupt
{
#ifdef IrDetectEn
    /*ͨѶЭ��ѡ��*/
    #if IR_DECODE_MODE == IR_HARDWARE
    #if IR_TYPE == NEC
	g_ucRemoteKeyVal = POS_GetIrKeyVal();
	#endif
	#endif
#endif
}


void POS_IrqServerRec(void) interrupt 4  //Uart Receive interrupt
{

   #ifdef BTEn
   POS_BTUartRec();
   #endif

   #ifdef SpiInitPannelEn
   #ifdef SpiAdjRegEn
   POS_RecUartSpiInfor();
   #endif
   #endif

}

void POS_IrqServerExt2(void) interrupt 8//ext 2  ADC  interrupt
{   
	/*�ⲿ�ж�2����*/
	EXIF = EXIF&0xEF;	//IE2 = 0

    //adc status
	ADC_INT_STATUS_L =0X00;
    ADC_INT_STATUS_H =0X00;
}



void POS_IrqServerExt3(void) interrupt 9//ext 3
{   
	/*�ⲿ�ж�3����*/
	EXIF = EXIF&0xDF; //IE3 = 0
}


void POS_IrqServerExt4(void) interrupt 10//ext 4
{   
    /*�ⲿ�ж�4����*/
	EXIF = EXIF&0xBF;	//IE4 = 0
}



void POS_IrqServerExt5(void) interrupt 11//ext 5  OSD VSYN interrupt
{   

    /*�ⲿ�ж�5����*/
	EXIF = EXIF&0x7F; //IE5 = 0
}


void POS_IrqServerTimer0(void) interrupt 1  //timer 0
{   
    TR0  = OFF;
	SetTimer0(_us(560)); 
	TR0  = ON;	
}


/***********************************************************
*name:       IrqServerTimer1(void)
*input:      non
*output:     ��ϵͳ��ʵʱ�¼����м��.
*update:     2011-12-23 
*state:      try out

*description:  
         ��ϵͳ��ʵʱ�¼����м�⣬�����¼���־��
*NOTE:
         ������������Դ�0-255��Ƶ
*history:
************************************************************/
void POS_IrqServerTimer1(void) interrupt 3	   //timer 1
{  
    static UCHAR s_ucSysTimer;
	
    TR1  = OFF;
	SetTimer1(_ms(5));
	TR1  = ON;

	s_ucSysTimer++;	
	
	/**********���źŴ���*********/
	POS_VideoProcess(VdLibCmd);

	if(Is5ms(s_ucSysTimer)) 
	{
	    HFZ_LR_BLANK_WR = 0X00;
	}
	
	if(Is10ms(s_ucSysTimer)) 
	{  
	    g_bGetUserInputFlg = 1;
		g_bGetBatteryAdcFlg = 1;
	    g_bGetSignalFlg = 1;   

		#ifdef CarBackEn
		#ifdef CarReversingIODetectEn 
	    g_bGetUserDefFlg = 1;
		#endif
		#endif
	}
	
	if(Is20ms(s_ucSysTimer))
	{   
	    g_bGetColorSysFlg = 1;
		g_bGetMiscFlg = 1;
		g_bGetBTFlg = 1;
	}
	
	if(Is30ms(s_ucSysTimer))
	{
	    g_bGetTimeFlg = 1;
	}

	if(Is100ms(s_ucSysTimer))//100
	{   
		#ifdef CarBackEn
		#ifdef CarReversingSignalDetectEn
		g_bGetUserDefFlg = 1;   
        #endif
		#endif
	}
	
	/**********ͼ����ʽ��Ϣ����*********/
	if(g_bGetColorSysFlg)
	{
        #define StableTimes   5

		static UCHAR  s_ucPreSys = PAL;
		UCHAR  ucCurSys;
	
	    if(IsSignalOk()||(0XFF == g_ucColorSys))
		{
		   ucCurSys = GetSignalSys();
		   if(ucCurSys != s_ucPreSys)
	       {
	          s_ucPreSys = ucCurSys;
	          g_ucStableTime = 0;
	       }
		   else
		   {
		       if(g_ucStableTime < StableTimes)
			   {
	               if(++g_ucStableTime == StableTimes)
	               {
	                  switch(ucCurSys)
	                  {
	                      case 0X00:
						  	 ucCurSys = NTSC;
							 break;

						  case 0X01:
						  	 ucCurSys = PAL;
						  	 break;

						  default:
						  	 ucCurSys = PAL;
						  	 break;
	                  }
					 g_ucColorSys = ucCurSys;
	               }
		       }
		   }
		}
		else
		{
		   g_ucStableTime = 0X00;
		}
	}

	//#ifdef NoSignalBLOffEn
	#if 0
	if((!IsHlockOk()) || (!IsVlockOk()))
	{	
	    if(g_bBackLightFlg)
	    {
	        IrqPutstr("bl off\n");
	        #ifdef BacklightEn
			hw_clrBacklight(); 
			g_bBackLightFlg = OFF; 
			hw_clrBIASEn();
	        #endif

			CLK_GATE0_EN &=~(_BIT7|_BIT6|_BIT5);
			CLK_GATE1_EN &=~(_BIT7|_BIT6|_BIT5|_BIT3|_BIT2|_BIT1|_BIT0);
			CLK_GATE2_EN &=~(_BIT7|_BIT6|_BIT5|_BIT4|_BIT3|_BIT2|_BIT1|_BIT0);
			ENH_PLL &=~(_BIT3|_BIT2);
			VIDEO_SOG_EN &=~(_BIT1|_BIT0);
        }
	}
	#endif
}


