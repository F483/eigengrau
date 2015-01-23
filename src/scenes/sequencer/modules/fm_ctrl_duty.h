// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef SCENES_SEQUENCER_MODULES_FM_CTRL_DUTY_H
#define SCENES_SEQUENCER_MODULES_FM_CTRL_DUTY_H

#include <src/scenes/sequencer/module.h>

void module_fm_ctrl_duty_sqr1_init();
void module_fm_ctrl_duty_sqr1_tick(Bool active);
void module_fm_ctrl_duty_sqr1_draw(Bool active);

void module_fm_ctrl_duty_sqr2_init();
void module_fm_ctrl_duty_sqr2_tick(Bool active);
void module_fm_ctrl_duty_sqr2_draw(Bool active);

void module_fm_ctrl_duty_noise_init();
void module_fm_ctrl_duty_noise_tick(Bool active);
void module_fm_ctrl_duty_noise_draw(Bool active);

#endif

