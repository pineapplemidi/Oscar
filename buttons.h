#include "button.h"

#ifndef __BUTTONS_
#define __BUTTONS_

#define BUTTON_VELOCITY = 100;
#define BUTTON_CHANNEL = 100;
#define SLAVE_ENABLE = LATCbits.LATC1; 

char k; 
Button Buttons[8];

void initButtons(void);
void scanButtonsHardware(void);
void handleButtons(void);
void readButtonsMemory(void);
void writeToButtonsMemory(char addr, char data);
void initButtonsMemory(void);

#endif
