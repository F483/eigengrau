// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_SEQUENCER_MAIN_H
#define LIB_SEQUENCER_MAIN_H

#include <src/lib/sequencer/sequence.h>

// bpm
Uint32 sequencer_bpm_get();
void   sequencer_bpm_set(Uint32 value);
void   sequencer_bpm_inc();
void   sequencer_bpm_dec();

void   sequencer_init();
void   sequencer_tick();

#endif
