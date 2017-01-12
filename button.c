#include "button.h"

Bbutton newButton(char b, char cc) {
    Bbutton button;
    button.Bit = b;
    button.CC = cc;
    button.Velocity = 0x7a;
    button.State = 0;
    button.PreviousState = 0;
    button.Toggle = 0;
    button.Momentary = 0;
    
    return button;
}

