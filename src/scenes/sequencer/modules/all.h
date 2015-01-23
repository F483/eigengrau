// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef SCENES_SEQUENCER_MODULES_ALL_H
#define SCENES_SEQUENCER_MODULES_ALL_H


/////////
// BPM //
/////////

void module_bpm_tick(Bool active);
void module_bpm_draw(Bool active);


/////////////////
// fm_ctrl_dir //
/////////////////

void module_fm_ctrl_dir_sqr1_init();
void module_fm_ctrl_dir_sqr1_tick(Bool active);
void module_fm_ctrl_dir_sqr1_draw(Bool active);

void module_fm_ctrl_dir_sqr2_init();
void module_fm_ctrl_dir_sqr2_tick(Bool active);
void module_fm_ctrl_dir_sqr2_draw(Bool active);

void module_fm_ctrl_dir_noise_init();
void module_fm_ctrl_dir_noise_tick(Bool active);
void module_fm_ctrl_dir_noise_draw(Bool active);


//////////////////
// fm_ctrl_duty //
//////////////////

void module_fm_ctrl_duty_sqr1_init();
void module_fm_ctrl_duty_sqr1_tick(Bool active);
void module_fm_ctrl_duty_sqr1_draw(Bool active);

void module_fm_ctrl_duty_sqr2_init();
void module_fm_ctrl_duty_sqr2_tick(Bool active);
void module_fm_ctrl_duty_sqr2_draw(Bool active);

void module_fm_ctrl_duty_noise_init();
void module_fm_ctrl_duty_noise_tick(Bool active);
void module_fm_ctrl_duty_noise_draw(Bool active);


//////////////////
// fm_ctrl_ivol //
//////////////////

void module_fm_ctrl_ivol_sqr1_init();
void module_fm_ctrl_ivol_sqr1_tick(Bool active);
void module_fm_ctrl_ivol_sqr1_draw(Bool active);

void module_fm_ctrl_ivol_sqr2_init();
void module_fm_ctrl_ivol_sqr2_tick(Bool active);
void module_fm_ctrl_ivol_sqr2_draw(Bool active);

void module_fm_ctrl_ivol_noise_init();
void module_fm_ctrl_ivol_noise_tick(Bool active);
void module_fm_ctrl_ivol_noise_draw(Bool active);


/////////////////
// fm_ctrl_len //
/////////////////

void module_fm_ctrl_len_sqr1_init();
void module_fm_ctrl_len_sqr1_tick(Bool active);
void module_fm_ctrl_len_sqr1_draw(Bool active);

void module_fm_ctrl_len_sqr2_init();
void module_fm_ctrl_len_sqr2_tick(Bool active);
void module_fm_ctrl_len_sqr2_draw(Bool active);

void module_fm_ctrl_len_noise_init();
void module_fm_ctrl_len_noise_tick(Bool active);
void module_fm_ctrl_len_noise_draw(Bool active);


///////////////////
// fm_ctrl_steps //
///////////////////

void module_fm_ctrl_steps_sqr1_init();
void module_fm_ctrl_steps_sqr1_tick(Bool active);
void module_fm_ctrl_steps_sqr1_draw(Bool active);

void module_fm_ctrl_steps_sqr2_init();
void module_fm_ctrl_steps_sqr2_tick(Bool active);
void module_fm_ctrl_steps_sqr2_draw(Bool active);

void module_fm_ctrl_steps_noise_init();
void module_fm_ctrl_steps_noise_tick(Bool active);
void module_fm_ctrl_steps_noise_draw(Bool active);


#endif

