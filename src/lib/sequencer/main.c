// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/gba/all.h>
#include <src/lib/all.h>

void sequencer_init(){

  // init sequences
  memset(&sequence_tracks_active,  0, sizeof(Sequence) * SEQUENCER_TRACK_CNT);
  memset(&sequence_tracks_queued,  0, sizeof(Sequence) * SEQUENCER_TRACK_CNT);

  // enable sound
  snd_reg_status = SND_STATUS_ENABLE;

  // setup channels
  snd_reg_fm = snd_fm_build_lr(SND_FM_C1 | SND_FM_C2 | SND_FM_C4, 7);
}

