#include "button.h"

#ifndef __MIDI_INTERFACE_
#define __MIDI_INTERFACE_

void handleMidi(void);
void handleSysex(void);
void sendMidiNoteOn(char cc, char velocity, char channel);
void sendMidiNoteOff(char cc, char velocity, char channel);
void sendMidiControlChange(char cc, char velocity, char channel);

#endif

