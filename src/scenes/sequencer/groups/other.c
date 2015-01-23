// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/scenes/sequencer/group.h>
#include <src/scenes/sequencer/modules/all.h>


const Module modules_bpm[1] = {
  { &module_bpm_tick ,   &module_bpm_draw }
};

Group group_bpm = { 1, 0, modules_bpm };


