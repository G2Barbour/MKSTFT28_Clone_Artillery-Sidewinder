#include "includes.h"

HOST  infoHost;  // Information interaction with Marlin
MENU  infoMenu;  // Menu structure


//Setup all GPIO not just LCD based ones -- darkspr1te 

void Hardware_GenericInit(void)
{
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  Delay_init(F_CPUM);  
  OS_TimerInit(9999, F_CPUM-1);  // System clock timer, cycle 10ms
  
#ifdef DISABLE_DEBUG 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE);
  GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE); //disable JTAG & SWD
#endif
  
 
#ifdef DISABLE_JTAG
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE);
  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
#endif



 //GPIO_Remap_USART2 
RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
GPIO_PinRemapConfig(GPIO_Remap_USART2, ENABLE);

  XPT2046_Init();
  W25Qxx_Init();
  LCD_Init();
  readStoredPara();
  LCD_RefreshDirection();  //refresh display direction after reading settings
  GUI_Clear(BLACK);
  GUI_DispString(100, 0, (u8*)"System Start");
  Delay_ms(500);
  scanUpdates();
  //causes a hang but no code is executed , bug 
  //SD_DeInit();

#if LCD_ENCODER_SUPPORT
  LCD_EncoderInit();
#endif

#ifdef PS_ON_PIN
  PS_ON_Init();
#endif

#ifdef FIL_RUNOUT_PIN
  FIL_Runout_Init();
#endif
//storePara();
  if(readStoredPara() == false) // Read settings parameter
  {    
   TSC_Calibration();
   storePara();
  }
    
 
  infoMenuSelect();
}

int main(void)
{

  SCB->VTOR = VECT_TAB_FLASH;
 
  Hardware_GenericInit();
  
  for(;;)
  {
    (*infoMenu.menu[infoMenu.cur])();
  }
}
