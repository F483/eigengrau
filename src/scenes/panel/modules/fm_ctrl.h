// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef PANEL_MODULES_FM_CTRL_H
#define PANEL_MODULES_FM_CTRL_H

#include <src/lib/common.h>

void module_fm_ctrl_dir_sqr1_tick(Bool active);
void module_fm_ctrl_dir_sqr1_draw(Bool active);
void module_fm_ctrl_dir_sqr2_tick(Bool active);
void module_fm_ctrl_dir_sqr2_draw(Bool active);
void module_fm_ctrl_dir_noise_tick(Bool active);
void module_fm_ctrl_dir_noise_draw(Bool active);

void module_fm_ctrl_duty_sqr1_tick(Bool active);
void module_fm_ctrl_duty_sqr1_draw(Bool active);
void module_fm_ctrl_duty_sqr2_tick(Bool active);
void module_fm_ctrl_duty_sqr2_draw(Bool active);
void module_fm_ctrl_duty_noise_tick(Bool active);
void module_fm_ctrl_duty_noise_draw(Bool active);

void module_fm_ctrl_ivol_sqr1_tick(Bool active);
void module_fm_ctrl_ivol_sqr1_draw(Bool active);
void module_fm_ctrl_ivol_sqr2_tick(Bool active);
void module_fm_ctrl_ivol_sqr2_draw(Bool active);
void module_fm_ctrl_ivol_noise_tick(Bool active);
void module_fm_ctrl_ivol_noise_draw(Bool active);

void module_fm_ctrl_len_sqr1_tick(Bool active);
void module_fm_ctrl_len_sqr1_draw(Bool active);
void module_fm_ctrl_len_sqr2_tick(Bool active);
void module_fm_ctrl_len_sqr2_draw(Bool active);
void module_fm_ctrl_len_noise_tick(Bool active);
void module_fm_ctrl_len_noise_draw(Bool active);

void module_fm_ctrl_steps_sqr1_tick(Bool active);
void module_fm_ctrl_steps_sqr1_draw(Bool active);
void module_fm_ctrl_steps_sqr2_tick(Bool active);
void module_fm_ctrl_steps_sqr2_draw(Bool active);
void module_fm_ctrl_steps_noise_tick(Bool active);
void module_fm_ctrl_steps_noise_draw(Bool active);

#endif

