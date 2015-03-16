// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/scenes/panel/group.h>
#include <src/scenes/panel/modules/all.h>


/////////
// BPM //
/////////

const Module modules_bpm[1] = {
  { &module_bpm_tick ,   &module_bpm_draw }
};

Group group_bpm = { 1, 0, modules_bpm };


/////////
// LFO //
/////////

const Module modules_lfo[2] = {
  { &module_lfo_a_tick ,   &module_lfo_a_draw },
  { &module_lfo_b_tick ,   &module_lfo_b_draw }
};

Group group_lfo = { 2, 0, modules_lfo };
