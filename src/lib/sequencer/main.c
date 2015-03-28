// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/gba/all.h>
#include <src/lib/all.h>

Sequencer sequencer;

void sequencer_init(){

  // init sequencer
  memset(&sequencer,  0, sizeof(Sequencer));

  // enable sound
  snd_reg_status = SND_STATUS_ENABLE;

  // setup channels
  snd_reg_fm = snd_fm_build_lr(SND_FM_C1 | SND_FM_C2 | SND_FM_C4, 7);
}

