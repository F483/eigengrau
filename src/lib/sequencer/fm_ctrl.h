// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_SEQUENCER_FM_CTRL_H
#define LIB_SEQUENCER_FM_CTRL_H

#include <src/lib/sequencer/main.h>

inline void sequencer_fm_ctrl_duty_set(SequencerTrack track, Sint16 duty){
  BIT_CLEAR(sequencer_active_setup(track)->fm_ctrl, SND_SQR_DUTY_MASK);
  BIT_SET(sequencer_active_setup(track)->fm_ctrl, SND_SQR_DUTY(duty));
}

inline Uint16 sequencer_fm_ctrl_duty_get(SequencerTrack track){
  return SND_SQR_DUTY_READ(sequencer_active_setup(track)->fm_ctrl);
}

inline void sequencer_fm_ctrl_len_set(SequencerTrack track, Sint16 len){
  BIT_CLEAR(sequencer_active_setup(track)->fm_ctrl, SND_SQR_LEN_MASK);
  BIT_SET(sequencer_active_setup(track)->fm_ctrl, SND_SQR_LEN(len));
}

inline Uint16 sequencer_fm_ctrl_len_get(SequencerTrack track){
  return SND_SQR_LEN_READ(sequencer_active_setup(track)->fm_ctrl);
}

inline void sequencer_fm_ctrl_steps_set(SequencerTrack track, Sint16 steps){
  BIT_CLEAR(sequencer_active_setup(track)->fm_ctrl, SND_SQR_STEPS_MASK);
  BIT_SET(sequencer_active_setup(track)->fm_ctrl, SND_SQR_STEPS(steps));
}

inline Uint16 sequencer_fm_ctrl_steps_get(SequencerTrack track){
  return SND_SQR_STEPS_READ(sequencer_active_setup(track)->fm_ctrl);
}

inline void sequencer_fm_ctrl_dir_set(SequencerTrack track, Sint16 dir){
  BIT_CLEAR(sequencer_active_setup(track)->fm_ctrl, SND_SQR_DIR_MASK);
  BIT_SET(sequencer_active_setup(track)->fm_ctrl, SND_SQR_DIR(dir));
}

inline Uint16 sequencer_fm_ctrl_dir_get(SequencerTrack track){
  return SND_SQR_DIR_READ(sequencer_active_setup(track)->fm_ctrl);
}

inline void sequencer_fm_ctrl_ivol_set(SequencerTrack track, Sint16 ivol){
  BIT_CLEAR(sequencer_active_setup(track)->fm_ctrl, SND_SQR_IVOL_MASK);
  BIT_SET(sequencer_active_setup(track)->fm_ctrl, SND_SQR_IVOL(ivol));
}

inline Uint16 sequencer_fm_ctrl_ivol_get(SequencerTrack track){
  return SND_SQR_IVOL_READ(sequencer_active_setup(track)->fm_ctrl);
}

#endif

