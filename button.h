#ifndef __BUTTON_
#define __BUTTON_

typedef struct {
    unsigned char CC;
    unsigned char Velocity;
    char State;
    char PreviousState;
    char Flags; // toggle state / .. / .. / .. || .. / control change / momentary / toggle
} Button;

Button newButton(char b, char cc);

#endif

