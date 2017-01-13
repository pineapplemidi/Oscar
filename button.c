#include "button.h"

Button newButton(char b, char cc) {
    Button button;
    button.CC = cc;
    button.Velocity = 0x7a;
    button.State = 0;
    button.PreviousState = 0;
    button.Flags = 0x00;
    return button;
}

