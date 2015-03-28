// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/scenes/panel/group.h>
#include <src/scenes/panel/modules/all.h>


const Module modules_lfo[5] = {
  { &module_lfo_select_tick ,  &module_lfo_select_draw },
  { &module_lfo_wave_tick ,    &module_lfo_wave_draw },
  { &module_lfo_rate_tick ,    &module_lfo_rate_draw },
  { &module_lfo_min_tick ,     &module_lfo_min_draw },
  { &module_lfo_max_tick ,     &module_lfo_max_draw }
};
Group group_lfo = { 5, 0, modules_lfo };


