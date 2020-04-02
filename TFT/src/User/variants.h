#ifndef _VARIANTS_H_
#define _VARIANTS_H_

#define USE_STDPERIPH_DRIVER
/*
* hardware source
* TIM4 for os timer
* TIM3 for buzzer timer
*/

//MCU type (STM32F103VC - HD, STM32F105 - CL, STM32F207VC)
//HSE crystal frequency

#if defined(MKS_32_V1_4) || defined(MKS_28_Clone_V1_0)
 #define SPEAKER_Pin             GPIO_Pin_2
 #define SPEAKER_GPIO_Port       GPIOA
 #define FILAMENT_DI_Pin         GPIO_Pin_0
 #define FILAMENT_DI_GPIO_Port   GPIOB
 #define POWER_DI_Pin            GPIO_Pin_1
 #define POWER_DI_GPIO_Port      GPIOB
 #define LCD_nWR_Pin             GPIO_Pin_14
 #define LCD_nWR_GPIO_Port       GPIOB
 #define LCD_RS_Pin              GPIO_Pin_13
 #define LCD_RS_GPIO_Port        GPIOD
 #define LCD_BACKLIGHT_Pin       GPIO_Pin_14
 #define LCD_BACKLIGHT_GPIO_Port GPIOD
 #define LCD_nRD_Pin             GPIO_Pin_15
 #define LCD_nRD_GPIO_Port       GPIOD
 #define LCD_nCS_Pin             GPIO_Pin_8
 #define LCD_nCS_GPIO_Port       GPIOC
 #define SDCARD_nCS_Pin          GPIO_Pin_11
 #define SDCARD_nCS_GPIO_Port    GPIOD
 #define SDCARD_DETECT_Pin       GPIO_Pin_15
 #define SDCARD_DETECT_GPIO_Port GPIOB
 #define TOUCH_DI_Pin            GPIO_Pin_5
 #define TOUCH_DI_GPIO_Port      GPIOC
 #define TOUCH_nCS_Pin           GPIO_Pin_9
 #define TOUCH_nCS_GPIO_Port     GPIOC
 #define WIFI_DI_Pin             GPIO_Pin_9
 #define WIFI_DI_GPIO_Port       GPIOA
 #define FLASH_nCS_Pin           GPIO_Pin_9
 #define FLASH_nCS_GPIO_Port     GPIOB
#endif

#if defined(MKS_32_V1_4) || defined(MKS_28_Clone_V1_0)

  #define HSE_VALUE ((uint32_t)25000000) //25Mhz XTAL
  #define F_CPUM 48
  #define STM32F10X_CL
  #include "stm32f10x.h"
#endif

//LCD interface
#if defined(MKS_32_V1_4) || defined(MKS_28_Clone_V1_0)
  #define HX8558
  #define LCD_DATA_16BIT 1
#endif

//LCD Backlight pin (PWM can adjust brightness)
#if defined(MKS_32_V1_4) || defined(MKS_28_Clone_V1_0)
 #define LCD_LED_PIN PD14
#endif

#if defined(MKS_32_V1_4) || defined(MKS_28_Clone_V1_0)
  #define SERIAL_PORT   _USART2
  #define SERIAL_PORT_2 _USART1
  #define SERIAL_PORT_3 _USART3
 // #define SERIAL_PORT_4 _UART4
#endif

//XPT2046 Software SPI Pins (touch screen ic)
//need CS/SCK/MISO/MOSI for Software SPI, and TPEN for pen interrupt
#if defined(MKS_32_V1_4) || defined(MKS_28_Clone_V1_0)
  #define XPT2046_CS    PC9
  #define XPT2046_SCK   PC10
  #define XPT2046_MISO  PC11
  #define XPT2046_MOSI  PC12
  #define XPT2046_TPEN  PC5
#else
  #error "xpt2046 need to Implement here by yourself."
#endif

//SD Card SPI pins
#if defined(MKS_32_V1_4) || defined(MKS_28_Clone_V1_0)
  #define SD_SPI_SUPPORT
  #define SD_LOW_SPEED  7
  #define SD_HIGH_SPEED 1
  #define SD_SPI        _SPI1
  #define SPI1_CS_PIN   PD11
#endif

//SD Card CD detect pin
#if defined(MKS_32_V1_4) || defined(MKS_28_Clone_V1_0)
  #define SD_CD_PIN     PB15
#endif

//W25Qxx SPI pins
#if defined(MKS_32_V1_4) || defined(MKS_28_Clone_V1_0)
  #define W25Qxx_SPEED 1
  #define W25Qxx_SPI    _SPI1
  #define W25Qxx_CS PB9
#endif

//ST7920 Simulator SPI pins
#if defined(TFT24_V1_1) || defined(TFT35_V3_0)
  #define ST7920_SPI    _SPI2
#endif

//buzzer support
#if defined(MKS_32_V1_4) || defined(MKS_28_Clone_V1_0)
  //Keep Things quiet 
  #define BUZZER_PIN    PA2
#endif

//LCD Encoder support
#if defined(MKS_32_V1_4) || defined(MKS_28_Clone_V1_0)
#define LCD_ENCODER_SUPPORT (defined(LCD_ENCA_PIN) && defined(LCD_ENCB_PIN) && defined(LCD_BTN_PIN))
#endif

//U disk support
#if defined(MKS_32_V1_4) || defined(MKS_28_Clone_V1_0)
  #define U_DISK_SUPPROT
  #define USE_USB_OTG_FS
#endif

//extend function(PS_ON, filament_detect)
#if defined(MKS_32_V1_4)  || defined(MKS_28_Clone_V1_0)
  #define PS_ON_PIN      PB0
  #define FIL_RUNOUT_PIN PB1
#endif
    
//Debug disable, free pins for other function
#if defined(TFT35_V1_0) || defined(TFT35_V1_1) || defined(TFT35_V1_2) || defined(TFT28_V1_0) || defined(TFT35_V2_0)
  #define DISABLE_JTAG    //free JTAG(PB3/PB4) for SPI3
#elif defined(TFT24_V1_1) 
  #define DISABLE_DEBUG   
#elif defined(TFT35_V3_0)
  //stm32f207 needn't this
#endif

//LCD resolution, font and icon size
#if defined(MKS_32_V1_4)  || defined(MKS_28_Clone_V1_0)
 #define LCD_WIDTH	  320
  #define LCD_HEIGHT	240


  #define BYTE_HEIGHT 16
  #define BYTE_WIDTH  (BYTE_HEIGHT/2)
  
  #define ICON_WIDTH  70
  #define ICON_HEIGHT 70
  #define TITLE_END_Y 40
  
  #define LIST_ICON_WIDTH   55
  #define LIST_ICON_HEIGHT  50
  
  #define selecticonw 70
#endif

#if defined(MKS_28_Clone_V1_0)
  #define ROOT_DIR ""  
#endif

//hardware version config
#ifndef HARDWARE_VERSION
  #if defined(MKS_28_Clone_V1_0)
    #define HARDWARE_VERSION "TFT28_V1.0 Artillery Clone"   
  #endif

#endif

#endif
