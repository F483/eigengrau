// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef PANEL_MODULES_ALL_H
#define PANEL_MODULES_ALL_H


/////////
// BPM //
/////////

void module_bpm_tick(Bool active);
void module_bpm_draw(Bool active);


/////////
// LFO //
/////////

void module_lfo_sqr1_a_tick(Bool active);
void module_lfo_sqr1_a_draw(Bool active);
void module_lfo_sqr1_b_tick(Bool active);
void module_lfo_sqr1_b_draw(Bool active);

void module_lfo_sqr2_a_tick(Bool active);
void module_lfo_sqr2_a_draw(Bool active);
void module_lfo_sqr2_b_tick(Bool active);
void module_lfo_sqr2_b_draw(Bool active);

void module_lfo_wave_a_tick(Bool active);
void module_lfo_wave_a_draw(Bool active);
void module_lfo_wave_b_tick(Bool active);
void module_lfo_wave_b_draw(Bool active);

void module_lfo_noise_a_tick(Bool active);
void module_lfo_noise_a_draw(Bool active);
void module_lfo_noise_b_tick(Bool active);
void module_lfo_noise_b_draw(Bool active);

void module_lfo_smpl1_a_tick(Bool active);
void module_lfo_smpl1_a_draw(Bool active);
void module_lfo_smpl1_b_tick(Bool active);
void module_lfo_smpl1_b_draw(Bool active);

void module_lfo_smpl2_a_tick(Bool active);
void module_lfo_smpl2_a_draw(Bool active);
void module_lfo_smpl2_b_tick(Bool active);
void module_lfo_smpl2_b_draw(Bool active);


/////////////////
// fm_ctrl_dir //
/////////////////

void module_fm_ctrl_dir_sqr1_tick(Bool active);
void module_fm_ctrl_dir_sqr1_draw(Bool active);

void module_fm_ctrl_dir_sqr2_tick(Bool active);
void module_fm_ctrl_dir_sqr2_draw(Bool active);

void module_fm_ctrl_dir_noise_tick(Bool active);
void module_fm_ctrl_dir_noise_draw(Bool active);


//////////////////
// fm_ctrl_duty //
//////////////////

void module_fm_ctrl_duty_sqr1_tick(Bool active);
void module_fm_ctrl_duty_sqr1_draw(Bool active);

void module_fm_ctrl_duty_sqr2_tick(Bool active);
void module_fm_ctrl_duty_sqr2_draw(Bool active);

void module_fm_ctrl_duty_noise_tick(Bool active);
void module_fm_ctrl_duty_noise_draw(Bool active);


//////////////////
// fm_ctrl_ivol //
//////////////////

void module_fm_ctrl_ivol_sqr1_tick(Bool active);
void module_fm_ctrl_ivol_sqr1_draw(Bool active);

void module_fm_ctrl_ivol_sqr2_tick(Bool active);
void module_fm_ctrl_ivol_sqr2_draw(Bool active);

void module_fm_ctrl_ivol_noise_tick(Bool active);
void module_fm_ctrl_ivol_noise_draw(Bool active);


/////////////////
// fm_ctrl_len //
/////////////////

void module_fm_ctrl_len_sqr1_tick(Bool active);
void module_fm_ctrl_len_sqr1_draw(Bool active);

void module_fm_ctrl_len_sqr2_tick(Bool active);
void module_fm_ctrl_len_sqr2_draw(Bool active);

void module_fm_ctrl_len_noise_tick(Bool active);
void module_fm_ctrl_len_noise_draw(Bool active);


///////////////////
// fm_ctrl_steps //
///////////////////

void module_fm_ctrl_steps_sqr1_tick(Bool active);
void module_fm_ctrl_steps_sqr1_draw(Bool active);

void module_fm_ctrl_steps_sqr2_tick(Bool active);
void module_fm_ctrl_steps_sqr2_draw(Bool active);

void module_fm_ctrl_steps_noise_tick(Bool active);
void module_fm_ctrl_steps_noise_draw(Bool active);


#endif

