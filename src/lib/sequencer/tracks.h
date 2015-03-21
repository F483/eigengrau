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

#define SEQUENCER_TRACK_COUNT         6
#define SEQUENCER_CFG_NORMAL(track) (sequence_tracks_active[(track)].normal)

extern Sequence sequence_tracks_active[SEQUENCER_TRACK_COUNT];
extern Sequence sequence_tracks_queued[SEQUENCER_TRACK_COUNT];

inline void sequencer_cfg_fm_ctrl_duty_set(SequencerTrack track, Sint16 duty){
  BIT_CLEAR(SEQUENCER_CFG_NORMAL(track).fm_ctrl, SND_SQR_DUTY_MASK);
  BIT_SET(SEQUENCER_CFG_NORMAL(track).fm_ctrl, SND_SQR_DUTY(duty));
}

inline Uint16 sequencer_cfg_fm_ctrl_duty_get(SequencerTrack track){
  return SND_SQR_DUTY_READ(SEQUENCER_CFG_NORMAL(track).fm_ctrl);
}

inline void sequencer_cfg_fm_ctrl_len_set(SequencerTrack track, Sint16 len){
  BIT_CLEAR(SEQUENCER_CFG_NORMAL(track).fm_ctrl, SND_SQR_LEN_MASK);
  BIT_SET(SEQUENCER_CFG_NORMAL(track).fm_ctrl, SND_SQR_LEN(len));
}

inline Uint16 sequencer_cfg_fm_ctrl_len_get(SequencerTrack track){
  return SND_SQR_LEN_READ(SEQUENCER_CFG_NORMAL(track).fm_ctrl);
}

inline void sequencer_cfg_fm_ctrl_steps_set(SequencerTrack track, Sint16 steps){
  BIT_CLEAR(SEQUENCER_CFG_NORMAL(track).fm_ctrl, SND_SQR_STEPS_MASK);
  BIT_SET(SEQUENCER_CFG_NORMAL(track).fm_ctrl, SND_SQR_STEPS(steps));
}

inline Uint16 sequencer_cfg_fm_ctrl_steps_get(SequencerTrack track){
  return SND_SQR_STEPS_READ(SEQUENCER_CFG_NORMAL(track).fm_ctrl);
}

inline void sequencer_cfg_fm_ctrl_dir_set(SequencerTrack track, Sint16 dir){
  BIT_CLEAR(SEQUENCER_CFG_NORMAL(track).fm_ctrl, SND_SQR_DIR_MASK);
  BIT_SET(SEQUENCER_CFG_NORMAL(track).fm_ctrl, SND_SQR_DIR(dir));
}

inline Uint16 sequencer_cfg_fm_ctrl_dir_get(SequencerTrack track){
  return SND_SQR_DIR_READ(SEQUENCER_CFG_NORMAL(track).fm_ctrl);
}

inline void sequencer_cfg_fm_ctrl_ivol_set(SequencerTrack track, Sint16 ivol){
  BIT_CLEAR(SEQUENCER_CFG_NORMAL(track).fm_ctrl, SND_SQR_IVOL_MASK);
  BIT_SET(SEQUENCER_CFG_NORMAL(track).fm_ctrl, SND_SQR_IVOL(ivol));
}

inline Uint16 sequencer_cfg_fm_ctrl_ivol_get(SequencerTrack track){
  return SND_SQR_IVOL_READ(SEQUENCER_CFG_NORMAL(track).fm_ctrl);
}

#endif

