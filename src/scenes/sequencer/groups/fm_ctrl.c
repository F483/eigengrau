// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/scenes/sequencer/group.h>
#include <src/scenes/sequencer/modules/all.h>


const Module modules_env_sqr1[5] = {
  { &module_fm_ctrl_duty_sqr1_tick ,   &module_fm_ctrl_duty_sqr1_draw },
  { &module_fm_ctrl_dir_sqr1_tick ,    &module_fm_ctrl_dir_sqr1_draw },
  { &module_fm_ctrl_ivol_sqr1_tick ,   &module_fm_ctrl_ivol_sqr1_draw },
  { &module_fm_ctrl_steps_sqr1_tick ,  &module_fm_ctrl_steps_sqr1_draw },
  { &module_fm_ctrl_len_sqr1_tick ,    &module_fm_ctrl_len_sqr1_draw }
};
Group group_fm_ctrl_sqr1 = { 5, 0, modules_env_sqr1 };


const Module modules_env_sqr2[5] = {
  { &module_fm_ctrl_duty_sqr2_tick ,   &module_fm_ctrl_duty_sqr2_draw },
  { &module_fm_ctrl_dir_sqr2_tick ,    &module_fm_ctrl_dir_sqr2_draw },
  { &module_fm_ctrl_ivol_sqr2_tick ,   &module_fm_ctrl_ivol_sqr2_draw },
  { &module_fm_ctrl_steps_sqr2_tick ,  &module_fm_ctrl_steps_sqr2_draw },
  { &module_fm_ctrl_len_sqr2_tick ,    &module_fm_ctrl_len_sqr2_draw }
};
Group group_fm_ctrl_sqr2 = { 5, 2, modules_env_sqr2 };


const Module modules_env_noise[5] = {
  { &module_fm_ctrl_duty_noise_tick ,   &module_fm_ctrl_duty_noise_draw },
  { &module_fm_ctrl_dir_noise_tick ,    &module_fm_ctrl_dir_noise_draw },
  { &module_fm_ctrl_ivol_noise_tick ,   &module_fm_ctrl_ivol_noise_draw },
  { &module_fm_ctrl_steps_noise_tick ,  &module_fm_ctrl_steps_noise_draw },
  { &module_fm_ctrl_len_noise_tick ,    &module_fm_ctrl_len_noise_draw }
};
Group group_fm_ctrl_noise = { 5, 0, modules_env_noise };




