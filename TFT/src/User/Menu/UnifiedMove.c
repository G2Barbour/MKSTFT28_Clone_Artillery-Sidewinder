#include "UnifiedMove.h"
#include "includes.h"

//1 title, ITEM_PER_PAGE items(icon + label)
const MENUITEMS UnifiedMoveItems = {
// title
LABEL_UNIFIEDMOVE,
// icon                       label
 {{ICON_HOME,                 LABEL_HOME},
  {ICON_MOVE,                 LABEL_MOVE},
  {ICON_LEVELING,             LABEL_ABL},
  {ICON_MANUAL_LEVEL,         LABEL_LEVELING},
  {ICON_EXTRUDE,           LABEL_EXTRUDE},
  {ICON_HEAT_FAN,           LABEL_HEAT},
  {ICON_BABYSTEP,           LABEL_BABYSTEP},
  {ICON_BACK,                 LABEL_BACK},}
};

void menuUnifiedMove(void)
{
  KEY_VALUES key_num = KEY_IDLE;	
  menuDrawPage(&UnifiedMoveItems,false);
  while(infoMenu.menu[infoMenu.cur] == menuUnifiedMove)
  {
    key_num = menuKeyGetValue();
    switch(key_num)
    {
      case KEY_ICON_0: infoMenu.menu[++infoMenu.cur] = menuHome; break;
      case KEY_ICON_1: infoMenu.menu[++infoMenu.cur] = menuMove; break;
      case KEY_ICON_2: infoMenu.menu[++infoMenu.cur] = menuAutoLeveling; break;
      case KEY_ICON_3: infoMenu.menu[++infoMenu.cur] = menuManualLeveling; break;
      case KEY_ICON_4: infoMenu.menu[++infoMenu.cur] = menuExtrude; break;
      case KEY_ICON_5: infoMenu.menu[++infoMenu.cur] = menuUnifiedHeat; break;
      case KEY_ICON_6: infoMenu.menu[++infoMenu.cur] = menuBabyStep; break;
      case KEY_ICON_7: infoMenu.cur--; break;
      default: break;            
    }
    loopProcess();
  }
}

