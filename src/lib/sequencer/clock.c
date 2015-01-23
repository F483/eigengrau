// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/gba/all.h>
#include <src/lib/all.h>

Uint32 bpm = 120;
Uint32 play_time = 0; // in frames
Uint32 next_step_time = 0; // play_time frame
Uint32 steps_played = 0;

Uint32 sequencer_bpm_get(){
  return bpm;
}

void sequencer_bpm_set(Uint32 value){
  bpm = value;
}

void sequencer_bpm_inc(){
  sequencer_bpm_set(bpm + 1);
}

void sequencer_bpm_dec(){
  sequencer_bpm_set(bpm - 1);
}

void play_notes(Uint16 index){
  // XXX play note
  if(index % 2 == 1){
    synth_play_channel1(index % 8, SYNTH_OCTAVE_C3);
  }
  if(index % 2 == 0){
    synth_play_channel2(index % 8, SYNTH_OCTAVE_C3);
  }
  if(index % 4 == 0){
    synth_play_channel4(index % 4, SYNTH_OCTAVE_C0);
  }
}

void play_step(Uint16 index){

  // copy sound config
  snd_reg_c1_ctrl = sequence_tracks_active[SQR1].normal.fm_ctrl;
  snd_reg_c2_ctrl = sequence_tracks_active[SQR2].normal.fm_ctrl;
  snd_reg_c4_ctrl = sequence_tracks_active[NOISE].normal.fm_ctrl;

  play_notes(index);

  // update clock
  next_step_time = ((steps_played + 1) * 3600) / (bpm * 4);
  steps_played++;
}

Uint16 sequencer_this_step_index(){
  return steps_played % 64;
}

Uint16 sequencer_next_step_index(){
  return (steps_played + 1) % 64;
}

void sequencer_tick(){
  if(next_step_time <= play_time){
    play_step(sequencer_next_step_index());
  }
  play_time++;
}

