// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_SEQUENCER_CLOCK_H
#define LIB_SEQUENCER_CLOCK_H

#include <src/lib/sequencer/sequence.h>

#define LFO_BEAT_SYNC      TODO

#define LFO_WAVE_SINE      TODO
#define LFO_WAVE_SQUARE    TODO
#define LFO_WAVE_TRIANGLE  TODO
#define LFO_WAVE_SAW_INC   TODO
#define LFO_WAVE_SAW_DEC   TODO

typedef struct {
  Uint8 flags;
  Uint8 frequency;
} LFO;


void   sequencer_tick();

Uint32 sequencer_bpm_get();
void   sequencer_bpm_set(Uint32 value);
void   sequencer_bpm_inc();
void   sequencer_bpm_dec();


#endif
