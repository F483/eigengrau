// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/scenes/panel/group.h>
#include <src/scenes/panel/modules/all.h>


const Module modules_lfo_sqr1[2] = {
  { &module_lfo_sqr1_a_tick ,   &module_lfo_sqr1_a_draw },
  { &module_lfo_sqr1_b_tick ,   &module_lfo_sqr1_b_draw }
};
Group group_lfo_sqr1 = { 2, 0, modules_lfo_sqr1 };


const Module modules_lfo_sqr2[2] = {
  { &module_lfo_sqr2_a_tick ,   &module_lfo_sqr2_a_draw },
  { &module_lfo_sqr2_b_tick ,   &module_lfo_sqr2_b_draw }
};
Group group_lfo_sqr2 = { 2, 0, modules_lfo_sqr2 };


const Module modules_lfo_wave[2] = {
  { &module_lfo_wave_a_tick ,   &module_lfo_wave_a_draw },
  { &module_lfo_wave_b_tick ,   &module_lfo_wave_b_draw }
};
Group group_lfo_wave = { 2, 0, modules_lfo_wave };


const Module modules_lfo_noise[2] = {
  { &module_lfo_noise_a_tick ,   &module_lfo_noise_a_draw },
  { &module_lfo_noise_b_tick ,   &module_lfo_noise_b_draw }
};
Group group_lfo_noise = { 2, 0, modules_lfo_noise };


const Module modules_lfo_smpl1[2] = {
  { &module_lfo_smpl1_a_tick ,   &module_lfo_smpl1_a_draw },
  { &module_lfo_smpl1_b_tick ,   &module_lfo_smpl1_b_draw }
};
Group group_lfo_smpl1 = { 2, 0, modules_lfo_smpl1 };


const Module modules_lfo_smpl2[2] = {
  { &module_lfo_smpl2_a_tick ,   &module_lfo_smpl2_a_draw },
  { &module_lfo_smpl2_b_tick ,   &module_lfo_smpl2_b_draw }
};
Group group_lfo_smpl2 = { 2, 0, modules_lfo_smpl2 };


