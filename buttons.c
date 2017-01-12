#include "buttons.h"
#include "button.h"
#include "usb.h"
#include "usb_device_midi.h"
#include "spi_interface.h"

static USB_AUDIO_MIDI_EVENT_PACKET midiData;
static USB_HANDLE USBTxHandle;

char rx;
unsigned char data;
char k;

void initButtons() {
    for (k=0; k<8; k++) {
        Button button = newButton(k, k + 60);
        Buttons[k] = button;
    }
}

void scanButtonsHardware() {    
    LATCbits.LATC0 = 0; // shift register load
    LATCbits.LATC0 = 1; // ..
    
    LATCbits.LATC1 = 0; // enable slave
    rx = SPIReadWrite(0); // read button states
    LATCbits.LATC1 = 1; // disable slave
    
    char states = rx; 
    for (k=0; k<8; k++) {
        Buttons[k].PreviousState = Buttons[k].State;
        Buttons[k].State = states & 0b00000001;
        states = states >> 1;
    }
    
//    initButtonsMemory(); // Writing to EEPROM is not working
//    readButtonsMemory(); // right now nothing is valid in the EEPROM..
}

void handleButtons() {
    for (k=0; k<8; k++) {
        if (Buttons[k].State != Buttons[k].PreviousState) {
//            if (Buttons[k].Toggle) { // still need to implement the toggle algorithm
////                sendMidiControlChange(Buttons[k].CC, Buttons[k].Velocity, 0x00);
//            } else if (Buttons[k].Momentary) { //sends state as control change on every button push and button release
//                sendMidiControlChange(Buttons[k].CC, Buttons[k].Velocity, 0x00);
//            } else { //sends state as control change on every button push
//                if (Buttons[k].State != 0x00) {
//                    sendMidiControlChange(Buttons[k].CC, Buttons[k].Velocity, 0x00);
//                }
//            }
            if (Buttons[k].State != 0x00) {
                sendMidiNoteOn(Buttons[k].CC, Buttons[k].Velocity, 0x00);
                
            } else {
                sendMidiNoteOff(Buttons[k].CC, Buttons[k].Velocity, 0x00);
            }
        }
    }
}

// Could definitely save space and use 1 byte (the bits) as the flags
void readButtonsMemory() {
    for (k=0; k<8; k++) {
        data = eeprom_read(k);
        Buttons[k].CC = data;
        
        data = eeprom_read(k+8);
        Buttons[k].Velocity = data;
        
        data = eeprom_read(k+16);
        Buttons[k].Toggle = data & 0x00000001; // Toggle flag is the bit 0
        Buttons[k].Momentary = (data & 0x00000010) >> 1; // Momentary flag is the bit 1 
    }   
}

void writeToButtonsMemory(char addr, char data) {
    if (addr >= 0 && addr < 24) {
            eeprom_write(addr, data);
    }
}

void initButtonsMemory() {
    for (k=0; k<8; k++) {
        writeToButtonsMemory(k, k);
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