// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/scenes/panel/group.h>
#include <src/scenes/panel/modules/all.h>


const Module modules_lfo_sqr1[5] = {
  { &module_lfo_select_sqr1_tick ,  &module_lfo_select_sqr1_draw },
  { &module_lfo_wave_sqr1_tick ,    &module_lfo_wave_sqr1_draw },
  { &module_lfo_rate_sqr1_tick ,    &module_lfo_rate_sqr1_draw },
  { &module_lfo_min_sqr1_tick ,     &module_lfo_min_sqr1_draw },
  { &module_lfo_max_sqr1_tick ,     &module_lfo_max_sqr1_draw }
};
Group group_lfo_sqr1 = { 5, 0, modules_lfo_sqr1 };


const Module modules_lfo_sqr2[5] = {
  { &module_lfo_select_sqr2_tick ,  &module_lfo_select_sqr2_draw },
  { &module_lfo_wave_sqr2_tick ,    &module_lfo_wave_sqr2_draw },
  { &module_lfo_rate_sqr2_tick ,    &module_lfo_rate_sqr2_draw },
  { &module_lfo_min_sqr2_tick ,     &module_lfo_min_sqr2_draw },
  { &module_lfo_max_sqr2_tick ,     &module_lfo_max_sqr2_draw }
};
Group group_lfo_sqr2 = { 5, 0, modules_lfo_sqr2 };


const Module modules_lfo_wave[5] = {
  { &module_lfo_select_wave_tick ,  &module_lfo_select_wave_draw },
  { &module_lfo_wave_wave_tick ,    &module_lfo_wave_wave_draw },
  { &module_lfo_rate_wave_tick ,    &module_lfo_rate_wave_draw },
  { &module_lfo_min_wave_tick ,     &module_lfo_min_wave_draw },
  { &module_lfo_max_wave_tick ,     &module_lfo_max_wave_draw }
};
Group group_lfo_wave = { 5, 0, modules_lfo_wave };


const Module modules_lfo_noise[5] = {
  { &module_lfo_select_noise_tick ,  &module_lfo_select_noise_draw },
  { &module_lfo_wave_noise_tick ,    &module_lfo_wave_noise_draw },
  { &module_lfo_rate_noise_tick ,    &module_lfo_rate_noise_draw },
  { &module_lfo_min_noise_tick ,     &module_lfo_min_noise_draw },
  { &module_lfo_max_noise_tick ,     &module_lfo_max_noise_draw }
};
Group group_lfo_noise = { 5, 0, modules_lfo_noise };


const Module modules_lfo_smpl1[5] = {
  { &module_lfo_select_smpl1_tick ,  &module_lfo_select_smpl1_draw },
  { &module_lfo_wave_smpl1_tick ,    &module_lfo_wave_smpl1_draw },
  { &module_lfo_rate_smpl1_tick ,    &module_lfo_rate_smpl1_draw },
  { &module_lfo_min_smpl1_tick ,     &module_lfo_min_smpl1_draw },
  { &module_lfo_max_smpl1_tick ,     &module_lfo_max_smpl1_draw }
};
Group group_lfo_smpl1 = { 5, 0, modules_lfo_smpl1 };


const Module modules_lfo_smpl2[5] = {
  { &module_lfo_select_smpl2_tick ,  &module_lfo_select_smpl2_draw },
  { &module_lfo_wave_smpl2_tick ,    &module_lfo_wave_smpl2_draw },
  { &module_lfo_rate_smpl2_tick ,    &module_lfo_rate_smpl2_draw },
  { &module_lfo_min_smpl2_tick ,     &module_lfo_min_smpl2_draw },
  { &module_lfo_max_smpl2_tick ,     &module_lfo_max_smpl2_draw }
};
Group group_lfo_smpl2 = { 5, 0, modules_lfo_smpl2 };


