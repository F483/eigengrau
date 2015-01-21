// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/gba/all.h>
#include <src/lib/all.h>

Uint32 bpm;
Uint32 play_time; // in frames
Uint32 next_step_time; // play_time frame
Uint32 steps_played;

Sequence active_sqr1;
Sequence active_sqr2;
Sequence active_wave;
Sequence active_noise;
Sequence active_smpl;
Sequence active_smpl;
Sequence queued_sqr1;
Sequence queued_sqr2;
Sequence queued_wave;
Sequence queued_noise;
Sequence queued_smpl;
Sequence queued_smpl;

Uint32 sequencer_bpm_get(){
  return bpm;
}

void sequencer_bpm_set(Uint32 value){
  bpm = value;
}

void sequencer_bpm_inc(){
  bpm++;
}

void sequencer_bpm_dec(){
  bpm--;
}

void sequencer_init(){

  // init timing vars
  bpm = 120;
  play_time = 0;
  next_step_time = 0;
  steps_played = 0;

  // init sequences
  memset(&active_sqr1,  0, sizeof(Sequence));
  memset(&active_sqr2,  0, sizeof(Sequence));
  memset(&active_wave,  0, sizeof(Sequence));
  memset(&active_noise, 0, sizeof(Sequence));
  memset(&active_smpl,  0, sizeof(Sequence));
  memset(&active_smpl,  0, sizeof(Sequence));
  memset(&queued_sqr1,  0, sizeof(Sequence));
  memset(&queued_sqr2,  0, sizeof(Sequence));
  memset(&queued_wave,  0, sizeof(Sequence));
  memset(&queued_noise, 0, sizeof(Sequence));
  memset(&queued_smpl,  0, sizeof(Sequence));
  memset(&queued_smpl,  0, sizeof(Sequence));

  // enable sound
  snd_reg_status = SND_STATUS_ENABLE;

  // setup channels
  snd_reg_fm = snd_fm_build_lr(SND_FM_C2, 7);
  snd_reg_c2_ctrl = snd_sqr_build(0, SND_SQR_DUTY1_4, 1, SND_SQR_ENV_DIR_DEC, 6);
}

void play_step(Uint16 index){

  synth_play_channel2(index % 4, SYNTH_OCTAVE_C0);


  next_step_time = ((steps_played + 1) * 3600) / (bpm * 4);
  steps_played++;
}

Uint16 sequencer_this_step(){
  return steps_played % 64;
}

Uint16 sequencer_next_step(){
  return (steps_played + 1) % 64;
}

void sequencer_tick(){
  if(next_step_time <= play_time){
    play_step(sequencer_next_step());
  }
  play_time++;
}

