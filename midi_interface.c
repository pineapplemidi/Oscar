#include "usb.h"
#include "usb_device_midi.h"

unsigned long midiInData;
static USB_HANDLE USBTxHandle;
static USB_HANDLE USBRxHandle;
static USB_AUDIO_MIDI_EVENT_PACKET midiData;
static uint8_t ReceivedDataBuffer[64];
//unsigned long midiInData;

void handleMidi() {
    if(!USBHandleBusy(USBRxHandle)) {
        switch (ReceivedDataBuffer[1]) {
            case 0x90: // note on
                if (ReceivedDataBuffer[2]==0x00) LATEbits.LATE1 = 0; // E1; led off
                if (ReceivedDataBuffer[2]==0x01) LATEbits.LATE1 = 1; // E; led on
        }
        
        USBRxHandle = USBRxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT,(uint8_t*)&ReceivedDataBuffer,64); //Get ready for next packet (this will overwrite the old data)
    }
}

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
