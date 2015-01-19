// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_SEQUENCER_TRACK_H
#define LIB_SEQUENCER_TRACK_H

typedef enum SequencerTrack {
  SQR1 = 0,
  SQR2 = 1,
  WAVE = 2,
  NOISE = 3,
  SMPL1 = 4,
  SMPL2 = 5
} SequencerTrack;

#define SEQUENCER_TRACK_CNT   6

#endif
