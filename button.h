#ifndef __BUTTON_
#define __BUTTON_

typedef struct {
    char CC;
    char Velocity;
    char State;
    char PreviousState;
    char Flags; // .. / .. / .. / .. || .. / .. / momentary / toggle
} Button;

Button newButton(char b, char cc);

#endif

