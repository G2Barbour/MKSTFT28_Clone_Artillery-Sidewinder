#include "CustomItems.h"
#include "includes.h"

const MENUITEMS customItems_2 = {
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
