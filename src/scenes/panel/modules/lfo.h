// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef PANEL_MODULES_LFO_H
#define PANEL_MODULES_LFO_H

#include <src/lib/common.h>

void module_lfo_select_sqr1_tick(Bool active);
void module_lfo_select_sqr1_draw(Bool active);
void module_lfo_select_sqr2_tick(Bool active);
void module_lfo_select_sqr2_draw(Bool active);
void module_lfo_select_wave_tick(Bool active);
void module_lfo_select_wave_draw(Bool active);
void module_lfo_select_noise_tick(Bool active);
void module_lfo_select_noise_draw(Bool active);
void module_lfo_select_smpl1_tick(Bool active);
void module_lfo_select_smpl1_draw(Bool active);
void module_lfo_select_smpl2_tick(Bool active);
void module_lfo_select_smpl2_draw(Bool active);

void module_lfo_wave_sqr1_tick(Bool active);
void module_lfo_wave_sqr1_draw(Bool active);
void module_lfo_wave_sqr2_tick(Bool active);
void module_lfo_wave_sqr2_draw(Bool active);
void module_lfo_wave_wave_tick(Bool active);
void module_lfo_wave_wave_draw(Bool active);
void module_lfo_wave_noise_tick(Bool active);
void module_lfo_wave_noise_draw(Bool active);
void module_lfo_wave_smpl1_tick(Bool active);
void module_lfo_wave_smpl1_draw(Bool active);
void module_lfo_wave_smpl2_tick(Bool active);
void module_lfo_wave_smpl2_draw(Bool active);

void module_lfo_rate_sqr1_tick(Bool active);
void module_lfo_rate_sqr1_draw(Bool active);
void module_lfo_rate_sqr2_tick(Bool active);
void module_lfo_rate_sqr2_draw(Bool active);
void module_lfo_rate_wave_tick(Bool active);
void module_lfo_rate_wave_draw(Bool active);
void module_lfo_rate_noise_tick(Bool active);
void module_lfo_rate_noise_draw(Bool active);
void module_lfo_rate_smpl1_tick(Bool active);
void module_lfo_rate_smpl1_draw(Bool active);
void module_lfo_rate_smpl2_tick(Bool active);
void module_lfo_rate_smpl2_draw(Bool active);

void module_lfo_min_sqr1_tick(Bool active);
void module_lfo_min_sqr1_draw(Bool active);
void module_lfo_min_sqr2_tick(Bool active);
void module_lfo_min_sqr2_draw(Bool active);
void module_lfo_min_wave_tick(Bool active);
void module_lfo_min_wave_draw(Bool active);
void module_lfo_min_noise_tick(Bool active);
void module_lfo_min_noise_draw(Bool active);
void module_lfo_min_smpl1_tick(Bool active);
void module_lfo_min_smpl1_draw(Bool active);
void module_lfo_min_smpl2_tick(Bool active);
void module_lfo_min_smpl2_draw(Bool active);

void module_lfo_max_sqr1_tick(Bool active);
void module_lfo_max_sqr1_draw(Bool active);
void module_lfo_max_sqr2_tick(Bool active);
void module_lfo_max_sqr2_draw(Bool active);
void module_lfo_max_wave_tick(Bool active);
void module_lfo_max_wave_draw(Bool active);
void module_lfo_max_noise_tick(Bool active);
void module_lfo_max_noise_draw(Bool active);
void module_lfo_max_smpl1_tick(Bool active);
void module_lfo_max_smpl1_draw(Bool active);
void module_lfo_max_smpl2_tick(Bool active);
void module_lfo_max_smpl2_draw(Bool active);

#endif

