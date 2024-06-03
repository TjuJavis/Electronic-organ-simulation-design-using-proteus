#ifndef __LCD1602_H__
#define __LCD1602_H__

void LCD_Init();
void LCD_Clear_2L();
void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char);
void LCD_ShowString(unsigned char Line,unsigned char Column,char *String);
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);

#endif
