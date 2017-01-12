#line 1 "C:/Users/matth/MPLABXProjects/Oscar.X/button.c"
#line 1 "c:/users/matth/mplabxprojects/oscar.x/button.h"



typedef struct {
 char Bit;
 char CC;
 char Velocity;
 char State;
 char PreviousState;
 char Toggle;
 char Momentary;
} Bbutton;

Bbutton newButton(char b, char cc);
#line 3 "C:/Users/matth/MPLABXProjects/Oscar.X/button.c"
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
