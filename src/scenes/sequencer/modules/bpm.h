// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef SCENES_SEQUENCER_MODULES_BPM_H
#define SCENES_SEQUENCER_MODULES_BPM_H

#include <src/scenes/sequencer/module.h>

void module_bpm_init();
void module_bpm_tick(Bool selected);
void module_bpm_draw(Bool selected);

#endif

