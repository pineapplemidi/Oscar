#ifndef __BUTTON_
#define __BUTTON_

typedef struct {
    char Bit;
    char CC;
    char Velocity;
    char State;
    char PreviousState;
    char Toggle;
    char Momentary;
} Button;

Button newButton(char b, char cc);

#endif

