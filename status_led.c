#include <stdint.h>
#include "system.h"
#include "usb_device.h"

void APP_LEDUpdateUSBStatus(void) {
    static uint16_t ledCount = 0;

    if(USBIsDeviceSuspended() == true) {
        LED_Off(LED_USB_DEVICE_STATE);
        return;
    }

    switch(USBGetDeviceState()) {         
        case CONFIGURED_STATE:
            /* We are configured.  Blink fast.
             * On for 75ms, off for 75ms, then reset/repeat. */
            if(ledCount == 1) {
                LED_On(LED_USB_DEVICE_STATE);
            } else if(ledCount == 75) {
                LED_Off(LED_USB_DEVICE_STATE);
            } else if(ledCount > 150) {
                ledCount = 0;
            }
            break;
        default:
            /* We aren't configured yet, but we aren't suspended so let's blink with
             * a slow pulse. On for 50ms, then off for 950ms, then reset/repeat. */
            if(ledCount == 1) {
                LED_On(LED_USB_DEVICE_STATE);
            } else if(ledCount == 50) {
                LED_Off(LED_USB_DEVICE_STATE);
            } else if(ledCount > 950) {
                ledCount = 0;
            }
            break;
    }
    ledCount++;
}

