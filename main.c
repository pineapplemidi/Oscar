#include "system.h"
#include "app.h"
#include "status_led.h"
#include "usb_device.h"
#include "usb_device_midi.h"
#include "spi_interface.h"

#define _XTAL_FREQ 40000000L

int count;
char rx;

MAIN_RETURN main(void) {
    OSCTUNEbits.PLLEN = 1; // NEED TO FIGURE WHAT THIS IS.. FREQUENCY OF SPI??
    
    InitSPIPins(); // initializes PINS
	ConfigSPIPeriph(); // configures SPI interface 
    
    SYSTEM_Initialize(SYSTEM_STATE_USB_START);
    USBDeviceInit();
    USBDeviceAttach();
    
    count = 0;
    rx = 0xAA;
    TRISEbits.TRISE1 = 0; // e1 = led output
    
    while(1) {
        SYSTEM_Tasks();
        #if defined(USB_POLLING)
            USBDeviceTasks();
        #endif
        APP_DeviceAudioMIDITasks();
        
    }
}
