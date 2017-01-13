#include "buttons.h"
#include "button.h"
#include "usb.h"
#include "usb_device_midi.h"
#include "spi_interface.h"
#include "midi_interface.h"

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
            if (Buttons[k].Flags && 0x01 == 1) { // toggle flag set
//                sendMidiControlChange(Buttons[k].CC, Buttons[k].Velocity, 0x00);
            } else if (Buttons[k].Flags && 0x02 == 1) { // momentary flag set
                sendMidiControlChange(Buttons[k].CC, Buttons[k].Velocity, 0x00);
            } else if (Buttons[k].Flags && 0x04 == 1) { // control change flag set
                if (Buttons[k].State != 0x00) {
                    sendMidiControlChange(Buttons[k].CC, Buttons[k].Velocity, 0x00);
                }
            } else { // no flags; sends note on and off
                if (Buttons[k].State != 0x00) {
                    sendMidiNoteOn(Buttons[k].CC, Buttons[k].Velocity, 0x00);
                } else {
                    sendMidiNoteOff(Buttons[k].CC, Buttons[k].Velocity, 0x00);
            
                }
            }
        }
    }
}

void readButtonsMemory() {
    for (k=0; k<8; k++) {
        data = eeprom_read(k);
        Buttons[k].CC = data;
        
        data = eeprom_read(k+8);
        Buttons[k].Velocity = data;
        
        data = eeprom_read(k+16);
        Buttons[k].Flags = data;
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