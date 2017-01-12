#line 1 "C:/Users/matth/MPLABXProjects/Oscar.X/system.c"
#line 1 "c:/users/matth/mplabxprojects/oscar.x/system.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdbool.h"



 typedef char _Bool;
#line 1 "c:/users/matth/mplabxprojects/oscar.x/usb_config.h"
#line 36 "c:/users/matth/mplabxprojects/oscar.x/system.h"
typedef enum
{
 SYSTEM_STATE_USB_START,
 SYSTEM_STATE_USB_SUSPEND,
 SYSTEM_STATE_USB_RESUME
} SYSTEM_STATE;
#line 55 "c:/users/matth/mplabxprojects/oscar.x/system.h"
void SYSTEM_Initialize( SYSTEM_STATE state );
#pragma config WDTEN = OFF
#pragma config PLLDIV = 4
#pragma config STVREN = ON
#pragma config XINST = OFF
#pragma config CPUDIV = OSC1
#pragma config CP0 = OFF
#pragma config OSC = HSPLL
#pragma config FCMEN = OFF
#pragma config IESO = OFF
#pragma config WDTPS = 32768
#pragma config DSWDTOSC = INTOSCREF
#pragma config RTCOSC = T1OSCREF
#pragma config DSBOREN = OFF
#pragma config DSWDTEN = OFF
#pragma config DSWDTPS = 8192
#pragma config IOL1WAY = OFF
#pragma config MSSP7B_EN = MSK7
#pragma config WPFP = PAGE_1
#pragma config WPEND = PAGE_0
#pragma config WPCFG = OFF
#pragma config WPDIS = OFF
#pragma config CFGPLLEN = ON
#line 58 "C:/Users/matth/MPLABXProjects/Oscar.X/system.c"
void SYSTEM_Initialize( SYSTEM_STATE state )
{
 switch(state)
 {
 case SYSTEM_STATE_USB_START:






 {
 unsigned int pll_startup_counter = 600;
 OSCTUNEbits.PLLEN = 1;
 while(pll_startup_counter--);
 }




 break;
 case SYSTEM_STATE_USB_SUSPEND:
 break;

 case SYSTEM_STATE_USB_RESUME:
 OSCCON = 0x70;





 {
 unsigned int pll_startup_counter = 800;
 while(pll_startup_counter--);
 }
 break;
 }
}
#line 107 "C:/Users/matth/MPLABXProjects/Oscar.X/system.c"
 void YourHighPriorityISRCode();
 void YourLowPriorityISRCode();
#pragma code REMAPPED_HIGH_INTERRUPT_VECTOR = REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS
#line 147 "C:/Users/matth/MPLABXProjects/Oscar.X/system.c"
 void Remapped_High_ISR (void)
 {
 _asm goto YourHighPriorityISRCode _endasm
 }
#pragma code REMAPPED_LOW_INTERRUPT_VECTOR = REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS
#line 152 "C:/Users/matth/MPLABXProjects/Oscar.X/system.c"
 void Remapped_Low_ISR (void)
 {
 _asm goto YourLowPriorityISRCode _endasm
 }
#pragma code
#pragma interrupt YourHighPriorityISRCode
#line 192 "C:/Users/matth/MPLABXProjects/Oscar.X/system.c"
 void YourHighPriorityISRCode()
 {
#line 202 "C:/Users/matth/MPLABXProjects/Oscar.X/system.c"
 }
#pragma interruptlow YourLowPriorityISRCode
#line 204 "C:/Users/matth/MPLABXProjects/Oscar.X/system.c"
 void YourLowPriorityISRCode()
 {





 }
