// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef SCENES_SEQUENCER_MODULES_FM_CTRL_IVOL_H
#define SCENES_SEQUENCER_MODULES_FM_CTRL_IVOL_H

#include <src/lib/common.h>

void module_fm_ctrl_ivol_sqr1_init();
void module_fm_ctrl_ivol_sqr1_tick(Bool active);
void module_fm_ctrl_ivol_sqr1_draw(Bool active);

void module_fm_ctrl_ivol_sqr2_init();
void module_fm_ctrl_ivol_sqr2_tick(Bool active);
void module_fm_ctrl_ivol_sqr2_draw(Bool active);

void module_fm_ctrl_ivol_noise_init();
void module_fm_ctrl_ivol_noise_tick(Bool active);
void module_fm_ctrl_ivol_noise_draw(Bool active);

#endif

