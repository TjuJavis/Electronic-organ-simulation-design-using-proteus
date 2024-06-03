#include <REGX52.H>
#include "LCD1602.H"
#include "MatrixKey.H"
#include "Delay.h"
sbit speaker=P2^7;
unsigned int Freq=0,flag=0,tone_up=0,degrees=0;   
unsigned int sound_play[]={7646,6812,6068,5727,5102,4545,4050,3822};
unsigned int sound_play_up[]={7215,6427,5727,5102,5405,4814,3822,3607};
void Timer0Init()
{
	TMOD=0X01;
	TL0 = 0x18;		
	TH0 = 0xFC;		  
	ET0=1;
	EA=1;
	TR0=1;	
}                            
                            
void main()
{
    unsigned char KeyNum;
    unsigned char KeyValue;
    Timer0Init();  
	LCD_Init();    
	LCD_ShowString(1,1,"TUNE:");
	while(1)
	{
        KeyNum=MatrixKey();
        KeyValue=key();
        if(KeyValue==1){degrees++;if(degrees>1){degrees=0;}}
        if(KeyValue==2){tone_up++;if(tone_up>1){tone_up=0;}}

        if(degrees==0&&tone_up==0)
        {    
           LCD_ShowString(1,8,"C");
		     if(KeyNum==1){LCD_Clear_2L();LCD_ShowNum(2,8,1,2);Freq=sound_play[0];}
           if(KeyNum==2){LCD_Clear_2L();LCD_ShowNum(2,8,2,2);Freq=sound_play[1];}
           if(KeyNum==3){LCD_Clear_2L();LCD_ShowNum(2,8,3,2);Freq=sound_play[2];}
           if(KeyNum==4){LCD_Clear_2L();LCD_ShowNum(2,8,4,2);Freq=sound_play[3];}
           if(KeyNum==5){LCD_Clear_2L();LCD_ShowNum(2,8,5,2);Freq=sound_play[4];}
           if(KeyNum==6){LCD_Clear_2L();LCD_ShowNum(2,8,6,2);Freq=sound_play[5];}
           if(KeyNum==7){LCD_Clear_2L();LCD_ShowNum(2,8,7,2);Freq=sound_play[6];}   
           if(KeyNum==8){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,1,2);Freq=sound_play[7];}
           if(KeyNum==9){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,1,2);Freq=sound_play[0]/2;}
           if(KeyNum==10){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,2,2);Freq=sound_play[1]/2;}
           if(KeyNum==11){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,3,2);Freq=sound_play[2]/2;}
           if(KeyNum==12){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,4,2);Freq=sound_play[3]/2;}
           if(KeyNum==13){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,5,2);Freq=sound_play[4]/2;}
           if(KeyNum==14){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,6,2);Freq=sound_play[5]/2;}
           if(KeyNum==15){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,7,2);Freq=sound_play[6]/2;}
           if(KeyNum==16){LCD_Clear_2L();LCD_ShowString(2,6,"**");LCD_ShowNum(2,8,1,2);Freq=sound_play[7]/2;}
        }
         if(degrees==1&&tone_up==0)
        {   
            LCD_ShowString(1,8,"D");
		     if(KeyNum==1){LCD_Clear_2L();LCD_ShowNum(2,8,1,2);Freq=sound_play[0]/4;}
           if(KeyNum==2){LCD_Clear_2L();LCD_ShowNum(2,8,2,2);Freq=sound_play[1]/4;}
           if(KeyNum==3){LCD_Clear_2L();LCD_ShowNum(2,8,3,2);Freq=sound_play[2]/4;}
           if(KeyNum==4){LCD_Clear_2L();LCD_ShowNum(2,8,4,2);Freq=sound_play[3]/4;}
           if(KeyNum==5){LCD_Clear_2L();LCD_ShowNum(2,8,5,2);Freq=sound_play[4]/4;}
           if(KeyNum==6){LCD_Clear_2L();LCD_ShowNum(2,8,6,2);Freq=sound_play[5]/4;}
           if(KeyNum==7){LCD_Clear_2L();LCD_ShowNum(2,8,7,2);Freq=sound_play[6]/4;}   
           if(KeyNum==8){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,1,2);Freq=sound_play[7]/4;}
           if(KeyNum==9){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,1,2);Freq=sound_play[0]/8;}
           if(KeyNum==10){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,2,2);Freq=sound_play[1]/8;}
           if(KeyNum==11){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,3,2);Freq=sound_play[2]/8;}
           if(KeyNum==12){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,4,2);Freq=sound_play[3]/8;}
           if(KeyNum==13){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,5,2);Freq=sound_play[4]/8;}
           if(KeyNum==14){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,6,2);Freq=sound_play[5]/8;}
           if(KeyNum==15){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,7,2);Freq=sound_play[6]/8;}
           if(KeyNum==16){LCD_Clear_2L();LCD_ShowString(2,6,"**");LCD_ShowNum(2,8,1,2);Freq=sound_play[7]/8;}    
        }
        if(degrees==0&&tone_up==1)
        {
            LCD_ShowString(1,8,"# C");
		   if(KeyNum==1){LCD_Clear_2L();LCD_ShowNum(2,8,1,2);Freq=sound_play_up[0];}
           if(KeyNum==2){LCD_Clear_2L();LCD_ShowNum(2,8,2,2);Freq=sound_play_up[1];}
           if(KeyNum==3){LCD_Clear_2L();LCD_ShowNum(2,8,3,2);Freq=sound_play_up[2];}
           if(KeyNum==4){LCD_Clear_2L();LCD_ShowNum(2,8,4,2);Freq=sound_play_up[3];}
           if(KeyNum==5){LCD_Clear_2L();LCD_ShowNum(2,8,5,2);Freq=sound_play_up[4];}
           if(KeyNum==6){LCD_Clear_2L();LCD_ShowNum(2,8,6,2);Freq=sound_play_up[5];}
           if(KeyNum==7){LCD_Clear_2L();LCD_ShowNum(2,8,7,2);Freq=sound_play_up[6];}   
           if(KeyNum==8){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,1,2);Freq=sound_play_up[7];}
           if(KeyNum==9){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,1,2);Freq=sound_play_up[0]/2;}
           if(KeyNum==10){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,2,2);Freq=sound_play_up[1]/2;}
           if(KeyNum==11){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,3,2);Freq=sound_play_up[2]/2;}
           if(KeyNum==12){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,4,2);Freq=sound_play_up[3]/2;}
           if(KeyNum==13){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,5,2);Freq=sound_play_up[4]/2;}
           if(KeyNum==14){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,6,2);Freq=sound_play_up[5]/2;}
           if(KeyNum==15){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,7,2);Freq=sound_play_up[6]/2;}
           if(KeyNum==16){LCD_Clear_2L();LCD_ShowString(2,6,"**");LCD_ShowNum(2,8,1,2);Freq=sound_play_up[7]/2;}    
        }
        if(degrees==1&&tone_up==1) 
        {
          LCD_ShowString(1,8,"# D");
           if(KeyNum==1){LCD_Clear_2L();LCD_ShowNum(2,8,1,2);Freq=sound_play_up[0]/4;}
           if(KeyNum==2){LCD_Clear_2L();LCD_ShowNum(2,8,2,2);Freq=sound_play_up[1]/4;}
           if(KeyNum==3){LCD_Clear_2L();LCD_ShowNum(2,8,3,2);Freq=sound_play_up[2]/4;}
           if(KeyNum==4){LCD_Clear_2L();LCD_ShowNum(2,8,4,2);Freq=sound_play_up[3]/4;}
           if(KeyNum==5){LCD_Clear_2L();LCD_ShowNum(2,8,5,2);Freq=sound_play_up[4]/4;}
           if(KeyNum==6){LCD_Clear_2L();LCD_ShowNum(2,8,6,2);Freq=sound_play_up[5]/4;}
           if(KeyNum==7){LCD_Clear_2L();LCD_ShowNum(2,8,7,2);Freq=sound_play_up[6]/4;}   
           if(KeyNum==8){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,1,2);Freq=sound_play_up[7]/4;}
           if(KeyNum==9){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,1,2);Freq=sound_play_up[0]/8;}
           if(KeyNum==10){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,2,2);Freq=sound_play_up[1]/8;}
           if(KeyNum==11){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,3,2);Freq=sound_play_up[2]/8;}
           if(KeyNum==12){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,4,2);Freq=sound_play_up[3]/8;}
           if(KeyNum==13){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,5,2);Freq=sound_play_up[4]/8;}
           if(KeyNum==14){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,6,2);Freq=sound_play_up[5]/8;}
           if(KeyNum==15){LCD_Clear_2L();LCD_ShowChar(2,7,'*');LCD_ShowNum(2,8,7,2);Freq=sound_play_up[6]/8;}
           if(KeyNum==16){LCD_Clear_2L();LCD_ShowString(2,6,"**");LCD_ShowNum(2,8,1,2);Freq=sound_play_up[7]/8;} 
        }
        if(Freq)
			{
				TH0=(65536-Freq)/256;
				TL0=(65536-Freq)&256;
				TR0=1;
				speaker=0;
				while(Freq);
			}
	}
}

void Timer0() interrupt 1
{
	TH0=(65536-Freq)/256;
	TL0=(65536-Freq)&256;
   if(Freq==0)
   {
      flag=0;
   }
   else{
	speaker=~speaker;
	flag++;
	if(flag==70)
	{
		Freq=0;
		TR0=0;
		flag=0;
	}
   }
}