/********************************************
[PannelName]
43D
[PannelType]
D_RGB888
[PannelResolution]
 800
 480
1056
 525
  20
  10
  46
  23
 210
  22
  -1
  -1
1200
 650
  40
  20
  46
  23
 354
 147
  -1
  -1
 862
 510
   1
   1
  46
  23
  16
   7
Update date:Friday, March 27, 2015
Update time:17:58:14
History:








********************************************/

typedef struct _PanlstaticPara
{
    unsigned int addr;
    unsigned char dat;
}PanlstaticPara;

typedef struct _PanlPosDynPara
{
    unsigned int addr;
    unsigned char dat_posDyn[6];
}PanlPosDynPara;

typedef struct _PanlSysDynPara
{
    unsigned int addr;
    unsigned char dat_sysDyn[8];
}PanlSysDynPara;



/*==============start===============*/
/*AV1
[VideoChannel]
AV1
[VideoType]
CVBS
[VideoPI]
VIDEO_P
[VideoPicSys]
NTSC
[VideoData]
13500000
 690
 232
 858
 262

Update date:Friday, March 27, 2015
Update time:17:58:14
*/
PanlstaticPara code AV1_staticPara[]=
{
//GLOBAL
    {0XFD0D,0XF0}, 
    {0XFD0F,0X09}, 
    {0XFD14,0X02}, 
    {0XFD15,0X04}, 
    {0XFD16,0X0A}, 
    {0XFD1A,0X08}, 
//DECODER
    {0XFE83,0XFE}, 
//VP
    {0XFFB0,0X27}, 
    {0XFFB1,0X0F}, 
    {0XFFB2,0X0A}, 
    {0XFFB3,0X15}, 
    {0XFFB4,0X0A}, 
    {0XFFF0,0X4D}, 
    {0XFFF1,0XD0}, 
    {0XFFF2,0XE0}, 
    {0XFFF3,0XD7}, 
    {0XFFF4,0XFD}, 
    {0XFFF5,0X40}, 
    {0XFFF6,0XE9}, 
    {0XFFF7,0XED}, 
    {0XFFF8,0XE9}, 
    {0XFFF9,0XFD}, 
    {0XFFFA,0X2B}, 
    {0XFFFB,0X81}, 
//TCON
    {0XFC00,0X00}, 
//SCALE
    {0XFC90,0X02}, 
    {0XFC91,0X01}, 
    {0XFC92,0X00}, 
    {0XFC93,0X00}, 
    {0XFC98,0X5A}, 
    {0XFC99,0X03}, 
    {0XFC9A,0XF2}, 
    {0XFC9B,0X01}, 
    {0XFC9C,0X01}, 
    {0XFC9D,0X00}, 
    {0XFC9E,0X06}, 
    {0XFC9F,0X00}, 
    {0XFCA0,0X06}, 
    {0XFCA1,0X00}, 
    {0XFCA2,0X08}, 
    {0XFCA3,0X02}, 
    {0XFCA4,0X02}, 
    {0XFCA5,0X00}, 
    {0XFCA6,0X05}, 
    {0XFCA7,0X00}, 
    {0XFCA8,0X16}, 
    {0XFCA9,0X00}, 
    {0XFCAA,0X26}, 
    {0XFCAB,0X01}, 
    {0XFCB7,0X73}, 
    {0XFCB8,0X02}, 
    {0XFCBB,0X35}, 
    {0XFCBC,0X01}, 
    {0XFCBD,0X01}, 
    {0XFCBE,0X00}, 
    {0XFCBF,0X00}, 
    {0XFCC4,0X09}, 
    {0XFCC5,0X04}, 
    {0XFCC6,0X54}, 
    {0XFCC7,0X02}, 
    {0XFCC8,0X03}, 
    {0XFCC9,0X00}, 
    {0XFCCA,0X0D}, 
    {0XFCCB,0X00}, 
    {0XFCCC,0X24}, 
    {0XFCCD,0X00}, 
    {0XFCCE,0X0D}, 
    {0XFCCF,0X02}, 
    {0XFCD1,0X00}, 
    {0XFCD2,0X07}, 
    {0XFCD3,0X00}, 
    {0XFCD4,0X12}, 
    {0XFCD5,0X00}, 
    {0XFCD6,0X22}, 
    {0XFCD7,0X01}, 
    {0XFCD0,0X04}, 
    {0XFCE2,0X02}, 
    {0XFCB6,0X02}, 
    {0XFB35,0X00}, 
    {0XFB89,0X01}, 
//GAMMA
    {0XFF00,0X03}, 
    {0XFF01,0X03}, 
    {0XFF02,0X08}, 
    {0XFF03,0X0D}, 
    {0XFF04,0X14}, 
    {0XFF05,0X1B}, 
    {0XFF06,0X24}, 
    {0XFF07,0X2F}, 
    {0XFF08,0X39}, 
    {0XFF09,0X45}, 
    {0XFF0A,0X50}, 
    {0XFF0B,0X5B}, 
    {0XFF0C,0X65}, 
    {0XFF0D,0X70}, 
    {0XFF0E,0X7A}, 
    {0XFF0F,0X84}, 
    {0XFF10,0X8E}, 
    {0XFF11,0X99}, 
    {0XFF12,0XA3}, 
    {0XFF13,0XAD}, 
    {0XFF14,0XB6}, 
    {0XFF15,0XBF}, 
    {0XFF16,0XC8}, 
    {0XFF17,0XD0}, 
    {0XFF18,0XD7}, 
    {0XFF19,0XDD}, 
    {0XFF1A,0XE3}, 
    {0XFF1B,0XE8}, 
    {0XFF1C,0XED}, 
    {0XFF1D,0XF2}, 
    {0XFF1E,0XF6}, 
    {0XFF1F,0XFB}, 
    {0XFF20,0X03}, 
    {0XFF21,0X08}, 
    {0XFF22,0X0D}, 
    {0XFF23,0X14}, 
    {0XFF24,0X1B}, 
    {0XFF25,0X24}, 
    {0XFF26,0X2F}, 
    {0XFF27,0X39}, 
    {0XFF28,0X45}, 
    {0XFF29,0X50}, 
    {0XFF2A,0X5B}, 
    {0XFF2B,0X65}, 
    {0XFF2C,0X70}, 
    {0XFF2D,0X7A}, 
    {0XFF2E,0X84}, 
    {0XFF2F,0X8E}, 
    {0XFF30,0X99}, 
    {0XFF31,0XA3}, 
    {0XFF32,0XAD}, 
    {0XFF33,0XB6}, 
    {0XFF34,0XBF}, 
    {0XFF35,0XC8}, 
    {0XFF36,0XD0}, 
    {0XFF37,0XD7}, 
    {0XFF38,0XDD}, 
    {0XFF39,0XE3}, 
    {0XFF3A,0XE8}, 
    {0XFF3B,0XED}, 
    {0XFF3C,0XF2}, 
    {0XFF3D,0XF6}, 
    {0XFF3E,0XFB}, 
    {0XFF3F,0X03}, 
    {0XFF40,0X08}, 
    {0XFF41,0X0D}, 
    {0XFF42,0X14}, 
    {0XFF43,0X1B}, 
    {0XFF44,0X24}, 
    {0XFF45,0X2F}, 
    {0XFF46,0X39}, 
    {0XFF47,0X45}, 
    {0XFF48,0X50}, 
    {0XFF49,0X5B}, 
    {0XFF4A,0X65}, 
    {0XFF4B,0X70}, 
    {0XFF4C,0X7A}, 
    {0XFF4D,0X84}, 
    {0XFF4E,0X8E}, 
    {0XFF4F,0X99}, 
    {0XFF50,0XA3}, 
    {0XFF51,0XAD}, 
    {0XFF52,0XB6}, 
    {0XFF53,0XBF}, 
    {0XFF54,0XC8}, 
    {0XFF55,0XD0}, 
    {0XFF56,0XD7}, 
    {0XFF57,0XDD}, 
    {0XFF58,0XE3}, 
    {0XFF59,0XE8}, 
    {0XFF5A,0XED}, 
    {0XFF5B,0XF2}, 
    {0XFF5C,0XF6}, 
    {0XFF5D,0XFB}, 
};
PanlPosDynPara code AV1_posDynPara[]=
{
//dispmode:  16:9  4:3  DM_EX0  DM_EX1  DM_EX2  DM_EX3
//GLOBAL
//PAD MUX
//PWM
//GPIO
//DECODER
//VP
//TCON
//SCALE
    {0XFC96,{0XA8,0X70,0X70,0X70,0X70,0X70}},
    {0XFC97,{0X05,0X03,0X03,0X03,0X03,0X03}},
    {0XFCAC,{0X18,0X1D,0X1D,0X1D,0X1D,0X1D}},
    {0XFCAD,{0X00,0X00,0X00,0X00,0X00,0X00}},
    {0XFCAE,{0X00,0X00,0X00,0X00,0X00,0X00}},
    {0XFCAF,{0X00,0X00,0X00,0X00,0X00,0X00}},
    {0XFCB0,{0X00,0X00,0X00,0X00,0X00,0X00}},
    {0XFCC2,{0XAD,0X7A,0X7A,0X7A,0X7A,0X7A}},
    {0XFCC3,{0X05,0X03,0X03,0X03,0X03,0X03}},
    {0XFCD8,{0X0C,0X08,0X08,0X08,0X08,0X08}},
    {0XFCD9,{0X00,0X02,0X02,0X02,0X02,0X02}},
    {0XFCDA,{0X00,0X00,0X00,0X00,0X00,0X00}},
    {0XFCDB,{0X00,0X00,0X00,0X00,0X00,0X00}},
    {0XFCDC,{0X00,0X00,0X00,0X00,0X00,0X00}},
//GAMMA
};
PanlSysDynPara code AV1_sysDynPara[]=
{
//picSys:   PAL  PAL-N  PAL-M  NTSC SECAM PAL-60 NTSC-J NTSC-4.43
//GLOBAL
    {0XFD0A,{0XC5, 0XA4, 0XA4, 0XC8, 0XA4, 0XA4, 0XA4, 0XA4}},
//PAD MUX
//PWM
//GPIO
//DECODER
//VP
    {0XFFD3,{0X84, 0X80, 0X80, 0X84, 0X80, 0X80, 0X80, 0X80}},
    {0XFFD4,{0X80, 0X80, 0X80, 0X80, 0X80, 0X80, 0X80, 0X80}},
    {0XFFD5,{0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00}},
    {0XFFD6,{0X30, 0X36, 0X36, 0X30, 0X36, 0X36, 0X36, 0X36}},
//TCON
//SCALE
//GAMMA
};
/*============== end ===============*/



/*点屏 PAD MUX 参数*/
PanlstaticPara code AMT_PadMuxStaticPara[]=
{
//PAD MUX
    {0XFD32,0X11}, 
    {0XFD33,0X11}, 
    {0XFD34,0X22}, 
    {0XFD35,0X22}, 
    {0XFD36,0X22}, 
    {0XFD37,0X22}, 
    {0XFD38,0X22}, 
    {0XFD39,0X22}, 
    {0XFD3A,0X22}, 
    {0XFD3B,0X22}, 
    {0XFD3C,0X22}, 
    {0XFD3D,0X22}, 
    {0XFD3E,0X22}, 
    {0XFD3F,0X22}, 
    {0XFD40,0X22}, 
    {0XFD41,0X22}, 
    {0XFD44,0X01}, 
    {0XFD45,0X00}, 
    {0XFD46,0X00}, 
    {0XFD47,0X00}, 
    {0XFD48,0X00}, 
    {0XFD49,0X00}, 
    {0XFD4A,0X00}, 
    {0XFD4B,0X00}, 
    {0XFD50,0X0F}, 
};



/*屏参参数相关的结构体*/
typedef struct _PannelPara
{
   PanlstaticPara  *pVideoStaicPara;
   PanlPosDynPara *pVideoPosDynPara;
   PanlSysDynPara  *pVideoSysDynPara;
}PannelPara;
typedef struct _VideoChannel
{
   unsigned char INPUT_ID;
   PannelPara    VideoPara;
}VideoChannel;
/*不同通道屏参的定义、初始化*/
VideoChannel code VideoChannelPara[]=
{
{ INPUT_AV1,{AV1_staticPara,AV1_posDynPara,AV1_sysDynPara}},
};
#define STATIC_NUM 174
#define POS_DYN_NUM 14
#define SYS_DYN_NUM 5
#define PAD_MUX_NUM 25
#define VCOM_AC_Def 0X00
#define VCOM_DC_Def 0X00
#define PWMA_VAL 0X0000
#define PWMB_VAL 0X0000


