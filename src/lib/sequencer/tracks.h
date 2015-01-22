// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_SEQUENCER_TRACKS_H
#define LIB_SEQUENCER_TRACKS_H

#include <src/lib/sequencer/sequence.h>

typedef enum {
  SQR1  = 0,
  SQR2  = 1,
  WAVE  = 2,
  NOISE = 3,
  SMPL1 = 4,
  SMPL2 = 5
} SequencerTrack;

#define SEQUENCER_TRACK_CNT   6

extern Sequence sequence_tracks_active[SEQUENCER_TRACK_CNT];
extern Sequence sequence_tracks_queued[SEQUENCER_TRACK_CNT];

inline void sequencer_cfg_normal_fm_ctrl_duty_set(SequencerTrack track, Sint16 duty){
  BIT_CLEAR(sequence_tracks_active[track].normal.fm_ctrl, SND_SQR_DUTY_MASK);
  BIT_SET(sequence_tracks_active[track].normal.fm_ctrl, SND_SQR_DUTY(duty));
}

inline Uint16 sequencer_cfg_normal_fm_ctrl_duty_get(SequencerTrack track){
  return SND_SQR_DUTY_READ(sequence_tracks_active[track].normal.fm_ctrl);
}

#endif

