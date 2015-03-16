// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_SEQUENCER_CLOCK_H
#define LIB_SEQUENCER_CLOCK_H

#include <src/lib/sequencer/sequence.h>

void   sequencer_tick();
Uint32 sequencer_current_step();
Uint32 sequencer_bpm_get();
void   sequencer_bpm_inc();
void   sequencer_bpm_dec();

#endif
