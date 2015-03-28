// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef PANEL_MODULES_LFO_H
#define PANEL_MODULES_LFO_H

#include <src/lib/common.h>

void module_lfo_select_tick(Bool active);
void module_lfo_select_draw(Bool active);
void module_lfo_wave_tick(Bool active);
void module_lfo_wave_draw(Bool active);
void module_lfo_rate_tick(Bool active);
void module_lfo_rate_draw(Bool active);
void module_lfo_min_tick(Bool active);
void module_lfo_min_draw(Bool active);
void module_lfo_max_tick(Bool active);
void module_lfo_max_draw(Bool active);

#endif

