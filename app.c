#include <stdint.h>
#include <stdbool.h>
#include "system.h"
#include "usb.h"
#include "usb_device_midi.h"
#include "buttons.h"
#include "midi_interface.h"

#if defined(FIXED_ADDRESS_MEMORY)
    #if defined(COMPILER_MPLAB_C18)
        #pragma udata DEVICE_AUDIO_MIDI_RX_DATA_BUFFER=DEVCE_AUDIO_MIDI_RX_DATA_BUFFER_ADDRESS
            static uint8_t ReceivedDataBuffer[64];
        #pragma udata DEVICE_AUDIO_MIDI_EVENT_DATA_BUFFER=DEVCE_AUDIO_MIDI_EVENT_DATA_BUFFER_ADDRESS
            static USB_AUDIO_MIDI_EVENT_PACKET midiData;
        #pragma udata
    #elif defined(__XC8)
        static uint8_t ReceivedDataBuffer[64] @ DEVCE_AUDIO_MIDI_RX_DATA_BUFFER_ADDRESS;
        static USB_AUDIO_MIDI_EVENT_PACKET midiData @ DEVCE_AUDIO_MIDI_EVENT_DATA_BUFFER_ADDRESS;
    #endif
#else
    static uint8_t ReceivedDataBuffer[64];
    static USB_AUDIO_MIDI_EVENT_PACKET midiData;
#endif

static USB_HANDLE USBRxHandle;

void APP_DeviceAudioMIDIInitialize() {
    USBRxHandle = NULL;
    USBEnableEndpoint(USB_DEVICE_AUDIO_MIDI_ENDPOINT,USB_OUT_ENABLED|USB_IN_ENABLED|USB_HANDSHAKE_ENABLED|USB_DISALLOW_SETUP); //enable the HID endpoint
    USBRxHandle = USBRxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT,(uint8_t*)&ReceivedDataBuffer,64); //Re-arm the OUT endpoint for the next packet
    
    initButtons();
}

void APP_DeviceAudioMIDISOFHandler() {}

void APP_DeviceAudioMIDITasks() {
    if ((USBGetDeviceState() < CONFIGURED_STATE) || // If the device is not configured yet, or the device is suspended, then
        (USBIsDeviceSuspended() == true)) {         // we don't need to run the demo since we can't send any data.
        return;
    }

    handleMidi();
    scanButtonsHardware();
    handleButtons();
}