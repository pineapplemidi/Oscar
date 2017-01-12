#include "button.h"

#ifndef __MIDI_INTERFACE_
#define __MIDI_INTERFACE_

void sendMidiNoteOn(char cc, char velocity, char channel);
void sendMidiNoteOff(char cc, char velocity, char channel);
void sendMidiControlChange(char cc, char velocity, char channel);

#endif

