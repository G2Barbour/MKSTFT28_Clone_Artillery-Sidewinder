#include "MainPage.h"
#include "includes.h"

//1 title, ITEM_PER_PAGE items(icon+label) 
const MENUITEMS mainPageItems = {
// title
LABEL_READY,
// icon                       label
  #ifdef UNIFIED_MENU //if Unified menu is selected
   {{ICON_HEAT_FAN,             lABEL_UNIFIEDHEAT},
    {ICON_HOME_MOVE,            LABEL_UNIFIEDMOVE},
    {ICON_EXTRUDE,              LABEL_EXTRUDE},
    {ICON_PRINT,                LABEL_PRINT},
    {ICON_CUSTOM,                LABEL_CUSTOM},
    {ICON_STOP,                 LABEL_EMERGENCYSTOP},
    {ICON_SETTINGS,             LABEL_SETTINGS},
    {ICON_BACK,                 LABEL_BACK},}
  #else
  #ifdef STATUS_SCREEN
   {{ICON_HEAT,                 LABEL_PREHEAT},
    {ICON_MOVE,                 LABEL_MOVE},
    {ICON_HOME,                 LABEL_HOME},
    {ICON_LEVELING,             LABEL_LEVELING},
    {ICON_EXTRUDE,              LABEL_EXTRUDE},
    {ICON_FAN,                  LABEL_FAN},
    {ICON_SETTINGS,             LABEL_SETTINGS},
    {ICON_BACK,                 LABEL_BACK},}
    #else
    {{ICON_HEAT,                 LABEL_PREHEAT},
    {ICON_MOVE,                 LABEL_MOVE},
    {ICON_HOME,                 LABEL_HOME},
    {ICON_PRINT,                LABEL_PRINT},
    {ICON_EXTRUDE,              LABEL_EXTRUDE},
    {ICON_FAN,                  LABEL_FAN},
    {ICON_SETTINGS,             LABEL_SETTINGS},
    {ICON_LEVELING,             LABEL_LEVELING},}
    #endif
  #endif
};
MENUITEMS customItems_2 = {
// title
LABEL_CUSTOM,
// icon                       label
 {
   #ifdef CUSTOM_0_GCODE
    {ICON_GCODE,             LABEL_CUSTOM_0},
   #else
    {ICON_BACKGROUND,           LABEL_BACKGROUND},
   #endif
   #ifdef CUSTOM_1_GCODE
    {ICON_GCODE,             LABEL_CUSTOM_1},
   #else
    {ICON_BACKGROUND,           LABEL_BACKGROUND},
   #endif
   #ifdef CUSTOM_2_GCODE
    {ICON_GCODE,             LABEL_CUSTOM_2},
   #else
    {ICON_BACKGROUND,           LABEL_BACKGROUND},
   #endif
   #ifdef CUSTOM_3_GCODE
    {ICON_GCODE,             LABEL_CUSTOM_3},
   #else
    {ICON_BACKGROUND,           LABEL_BACKGROUND},
   #endif
   #ifdef CUSTOM_4_GCODE
    {ICON_GCODE,             LABEL_CUSTOM_4},
   #else
    {ICON_BACKGROUND,           LABEL_BACKGROUND},
   #endif
   #ifdef CUSTOM_5_GCODE
    {ICON_GCODE,             LABEL_CUSTOM_5},
   #else
    {ICON_BACKGROUND,           LABEL_BACKGROUND},
   #endif
   #ifdef CUSTOM_6_GCODE
    {ICON_CUSTOM_6,             LABEL_CUSTOM_6},
   #else
    {ICON_BACKGROUND,           LABEL_BACKGROUND},
   #endif
  {ICON_BACK,                 LABEL_BACK},}
};
void menuCustom_2(void)
{
  KEY_VALUES key_num = KEY_IDLE;

  menuDrawPage(&customItems_2,false);

  while(infoMenu.menu[infoMenu.cur] == menuCustom_2)
  {
    key_num = menuKeyGetValue();
    switch(key_num)
    {
     #ifdef CUSTOM_0_GCODE
      case KEY_ICON_0:
        storeCmd(CUSTOM_0_GCODE);
        break;
     #endif
     #ifdef CUSTOM_1_GCODE
      case KEY_ICON_1:
        storeCmd(CUSTOM_1_GCODE);
        break;
     #endif
     #ifdef CUSTOM_2_GCODE
      case KEY_ICON_2:
        storeCmd(CUSTOM_2_GCODE);
        break;
     #endif
     #ifdef CUSTOM_3_GCODE
      case KEY_ICON_3:
        storeCmd(CUSTOM_3_GCODE);
        break;
     #endif
     #ifdef CUSTOM_4_GCODE
      case KEY_ICON_4:
        storeCmd(CUSTOM_4_GCODE);
        break;
     #endif
     #ifdef CUSTOM_5_GCODE
      case KEY_ICON_5:
        storeCmd(CUSTOM_5_GCODE);
        break;
     #endif
     #ifdef CUSTOM_6_GCODE
      case KEY_ICON_6:
        storeCmd(CUSTOM_6_GCODE);
        break;
     #endif
      case KEY_ICON_7:
        infoMenu.cur--;
        break;
      
      default:
        break;
    }
    loopProcess();		
  }
}
void menuMain(void)
{
  KEY_VALUES key_num=KEY_IDLE;
  GUI_SetBkColor(ST7920_BKCOLOR);
  menuDrawPage(&mainPageItems,false);

  while(infoMenu.menu[infoMenu.cur] == menuMain)
  {
    key_num = menuKeyGetValue();
    switch(key_num)
    {
      #ifdef UNIFIED_MENU //if Unified menu is selected
        case KEY_ICON_0: infoMenu.menu[++infoMenu.cur] = menuUnifiedHeat;     break;
        case KEY_ICON_1: infoMenu.menu[++infoMenu.cur] = menuUnifiedMove;     break;      
        case KEY_ICON_2: infoMenu.menu[++infoMenu.cur] = menuExtrude;         break;
        case KEY_ICON_3: infoMenu.menu[++infoMenu.cur] = menuPrint;           break;
        case KEY_ICON_4: infoMenu.menu[++infoMenu.cur] = menuCustom_2;       break;
        case KEY_ICON_5: { 
          /*
          for(TOOL i = BED; i < HEATER_NUM; i++)
          {
            storeCmd("%s S0\n", heatCmd[i]);  disable all heaters
          }
          storeCmd("M18\n");  //disable all stepper motors
          storeCmd("M107\n"); //disable cooling fan
          */
          storeCmd("M112\n"); //Emergency Stop : Used for emergency stopping, a reset is required to return to operational mode.
                              // it may need to wait for a space to open up in the command queue.
                              // Enable EMERGENCY_PARSER in Marlin Firmware for an instantaneous M112 command.

           }
          break;
        
        case KEY_ICON_6: infoMenu.menu[++infoMenu.cur] = menuSettings;        break;
        case KEY_ICON_7: infoMenu.cur--;        break;
        default:break;
      #else
      #ifdef STATUS_SCREEN
        case KEY_ICON_0: infoMenu.menu[++infoMenu.cur] = menuPreheat;   break;
        case KEY_ICON_1: infoMenu.menu[++infoMenu.cur] = menuMove;      break;
        case KEY_ICON_2: infoMenu.menu[++infoMenu.cur] = menuHome;      break;
        case KEY_ICON_3:
          #ifdef AUTO_BED_LEVELING
            infoMenu.menu[++infoMenu.cur] = menuAutoLeveling;
          #else
            infoMenu.menu[++infoMenu.cur] = menuManualLeveling;
          #endif
          break;      
        case KEY_ICON_4: infoMenu.menu[++infoMenu.cur] = menuExtrude;   break;
        case KEY_ICON_5: infoMenu.menu[++infoMenu.cur] = menuFan;       break;
        case KEY_ICON_6: infoMenu.menu[++infoMenu.cur] = menuSettings;  break;
        case KEY_ICON_7: infoMenu.cur--;        break;
        default:break;
      #else
        case KEY_ICON_0: infoMenu.menu[++infoMenu.cur] = menuPreheat;   break;
        case KEY_ICON_1: infoMenu.menu[++infoMenu.cur] = menuMove;      break;
        case KEY_ICON_2: infoMenu.menu[++infoMenu.cur] = menuHome;      break;
        case KEY_ICON_3: infoMenu.menu[++infoMenu.cur] = menuPrint;     break;      
        case KEY_ICON_4: infoMenu.menu[++infoMenu.cur] = menuExtrude;   break;
        case KEY_ICON_5: infoMenu.menu[++infoMenu.cur] = menuFan;       break;
        case KEY_ICON_6: infoMenu.menu[++infoMenu.cur] = menuSettings;  break;
        case KEY_ICON_7:
          #ifdef AUTO_BED_LEVELING
            infoMenu.menu[++infoMenu.cur] = menuAutoLeveling;
          #else
            infoMenu.menu[++infoMenu.cur] = menuManualLeveling;
          #endif
          break;
        default:break;
      #endif
      #endif
    }		
    loopProcess();
  }
}
