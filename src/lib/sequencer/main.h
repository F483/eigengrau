// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_SEQUENCER_MAIN_H
#define LIB_SEQUENCER_MAIN_H

#include <src/lib/sequencer/sequence.h>

Uint32 sequencer_get_bpm();
void   sequencer_set_bpm(Uint32 value);
void   sequencer_init();
void   sequencer_tick();

#endif
