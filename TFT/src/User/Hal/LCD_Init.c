#include "LCD_Init.h"
#include "GPIO_Init.h"
#include "includes.h"


#ifdef LCD_LED_PIN
void LCD_LED_On()
{
  GPIO_SetLevel(LCD_LED_PIN, 1);
}
void LCD_LED_Off()
{
  GPIO_SetLevel(LCD_LED_PIN, 0);
}

void LCD_LED_Init(void)
{
  LCD_LED_Off();
  GPIO_InitSet(LCD_LED_PIN, MGPIO_MODE_OUT_PP, 0);
}
#endif

#if defined(MKS_32_V1_4)  || defined(MKS_28_Clone_V1_0)

void LCD_init_RGB(void) 
{
  Delay_ms(50); // delay 50 ms 
  
 LCD_WR_REG(0xFE);                     // 
 LCD_WR_REG(0xEF);
 LCD_WR_REG(0x3A);
 LCD_WR_DATA(5);
 LCD_WR_REG(0X36);
LCD_WR_DATA(0x64);
      LCD_WR_REG(0xE8);
      LCD_WR_DATA(0x12);
      LCD_WR_DATA(0x22);
      LCD_WR_REG(0xE3);
      LCD_WR_DATA(1);
      LCD_WR_DATA(4);
      LCD_WR_REG(0xA5);
      LCD_WR_DATA(0x40);
      LCD_WR_DATA(0x40);
      LCD_WR_REG(0xA4);
      LCD_WR_DATA(0x44);
      LCD_WR_DATA(0x44);
      LCD_WR_REG(0xAB);
      LCD_WR_DATA(8);
      LCD_WR_REG(0xAA);
      LCD_WR_DATA(0x88);
      LCD_WR_DATA(0x88);
      LCD_WR_REG(0xAE);
      LCD_WR_DATA(0xB);
      LCD_WR_REG(0xAC);
      LCD_WR_DATA(0);
      LCD_WR_REG(0xAF);
      LCD_WR_DATA(0x77);
      LCD_WR_REG(0xAD);
      LCD_WR_DATA(0x77);
      
      LCD_WR_REG(0x2A);
      LCD_WR_DATA(0);
      LCD_WR_DATA(0);
      LCD_WR_DATA(0);
      LCD_WR_DATA(0xEF);
      LCD_WR_REG(0x2B);
      LCD_WR_DATA(0);
      LCD_WR_DATA(0);
      LCD_WR_DATA(1);
      LCD_WR_DATA(0x3F);
      
      LCD_WR_REG(0x2C);
      
      LCD_WR_REG(0xF0);
      LCD_WR_DATA(2);
      LCD_WR_DATA(0);
      LCD_WR_DATA(0);
      LCD_WR_DATA(1);
      LCD_WR_DATA(1);
      LCD_WR_DATA(7);
      
      LCD_WR_REG(0xF1);
      LCD_WR_DATA(1);
      LCD_WR_DATA(3);
      LCD_WR_DATA(0);
      LCD_WR_DATA(0x36);
      LCD_WR_DATA(41);
      LCD_WR_DATA(0x13);
      
      LCD_WR_REG(0xF2);
      LCD_WR_DATA(8);
      LCD_WR_DATA(6);
      LCD_WR_DATA(0x24);
      LCD_WR_DATA(3);
      LCD_WR_DATA(5);
      LCD_WR_DATA(0x34);
      
      LCD_WR_REG(0xF3);
      LCD_WR_DATA(0x16);
      LCD_WR_DATA(0xC);
      LCD_WR_DATA(0x5A);
      LCD_WR_DATA(4);
      LCD_WR_DATA(3);
      LCD_WR_DATA(0x69);
      
      LCD_WR_REG(0xF4);
      LCD_WR_DATA(0xD);
      LCD_WR_DATA(0x18);
      LCD_WR_DATA(0x15);
      LCD_WR_DATA(5);
      LCD_WR_DATA(5);
      LCD_WR_DATA(0);
      
      LCD_WR_REG(0xF5);
      LCD_WR_DATA(0xD);
      LCD_WR_DATA(0x18);
      LCD_WR_DATA(0x17);
      LCD_WR_DATA(0x35);
      LCD_WR_DATA(0x39);
      LCD_WR_DATA(0);
      LCD_WR_REG(0x11);
	
	    Delay_ms(150);
      LCD_WR_REG(0x29);
      LCD_WR_REG(0x2C);
}


#endif

u16 LCD_ReadID(void)
{
  u16 id = 0;
  LCD_WR_REG(0XD3);				   
  id = LCD_RD_DATA();	//dummy read 	
  id = LCD_RD_DATA();
  id = LCD_RD_DATA();
  id <<= 8;
  id |= LCD_RD_DATA();
  return id;
}

void LCD_RefreshDirection(void)
{
  if(infoSettings.rotate_ui)
  {
    LCD_WR_REG(0X36);
    #ifdef RM68042
      LCD_WR_DATA(0X2B);
    #endif
    #ifdef ILI9488
      LCD_WR_DATA(0XE8);
    #endif
    #ifdef ILI9341
      LCD_WR_DATA(0XA8);
    #endif  
    #ifdef HX8558
     LCD_WR_DATA(0XA4);
    // LCD_WR_DATA(0X64);
    #endif
  }
  else
  {
    LCD_WR_REG(0X36);
    #ifdef RM68042
      LCD_WR_DATA(0X28);
    #endif
    #ifdef ILI9488
      LCD_WR_DATA(0X28);
    #endif
    #ifdef ILI9341
      LCD_WR_DATA(0X68);
    #endif
    #ifdef HX8558
     //LCD_WR_DATA(0x64);
     LCD_WR_DATA(0xA4);
    #endif  
  }
}

void LCD_Init(void)
{
  LCD_HardwareConfig();
  LCD_init_RGB();
  GUI_Clear(BLACK);
  Delay_ms(20);
  
#ifdef LCD_LED_PIN
  LCD_LED_Init();
  LCD_LED_On();
#endif
  
#ifdef STM32_HAS_FSMC
  LCD_DMA_Config();  //spi flash to fsmc lcd DMA channel configuration
#endif
}
