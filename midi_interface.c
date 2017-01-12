#include "usb.h"
#include "usb_device_midi.h"

static USB_AUDIO_MIDI_EVENT_PACKET midiData;
static USB_HANDLE USBTxHandle;

void sendMidiNoteOn(char cc, char velocity, char channel) {
    if (!USBHandleBusy(USBTxHandle)) {
        midiData.Val = 0;   //must set all unused values to 0 so go ahead
        midiData.CableNumber = 0;
        midiData.CodeIndexNumber = MIDI_CIN_NOTE_ON;
        midiData.DATA_0 = 0x90;         //Note On
        midiData.DATA_1 = cc;         
        midiData.DATA_2 = velocity;  

        USBTxHandle = USBTxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT, (uint8_t*)&midiData, 4);
    }
}

void sendMidiNoteOff(char cc, char velocity, char channel) {
    if (!USBHandleBusy(USBTxHandle)) {
        midiData.Val = 0;   //must set all unused values to 0 so go ahead
        midiData.CableNumber = 0;
        midiData.CodeIndexNumber = MIDI_CIN_NOTE_OFF;
        midiData.DATA_0 = 0x80;         //Note Off
        midiData.DATA_1 = cc;         
        midiData.DATA_2 = velocity;  

        USBTxHandle = USBTxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT, (uint8_t*)&midiData, 4);
    }
}

void sendMidiControlChange(char cc, char velocity, char channel) {
    if (!USBHandleBusy(USBTxHandle)) {
        midiData.Val = 0;   //must set all unused values to 0 so go ahead
        midiData.CableNumber = 0;
        midiData.CodeIndexNumber = MIDI_CIN_CONTROL_CHANGE;
        midiData.DATA_0 = 0xB0;         //Control Change
        midiData.DATA_1 = cc;         
        midiData.DATA_2 = velocity;  

        USBTxHandle = USBTxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT, (uint8_t*)&midiData, 4);
    }
}
