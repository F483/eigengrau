// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef PANEL_MODULES_ALL_H
#define PANEL_MODULES_ALL_H

#include <src/lib/common.h>
#include <src/scenes/panel/modules/lfo.h>
#include <src/scenes/panel/modules/fm_ctrl.h>

/////////
// BPM //
/////////

void module_bpm_tick(Bool active);
void module_bpm_draw(Bool active);

#endif

