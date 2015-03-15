// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/gba/all.h>
#include <src/lib/all.h>

Uint32 bpm_curr = 120;
Uint32 bpm_next = 120;
Uint32 time_passed = 0; // in frames
Uint32 next_step_time = 0; // time_passed in frames
Uint32 steps_played = 0;

Uint32 sequencer_bpm_get(){
  return bpm_curr;
}

void sequencer_bpm_set(Uint32 value){
  bpm_next = value;
}

void sequencer_bpm_inc(){
  sequencer_bpm_set(bpm_curr + 1);
}

void sequencer_bpm_dec(){
  sequencer_bpm_set(bpm_curr - 1);
}

void play_notes(Uint16 index){
  // XXX play note
  if(index % 2 == 0){
    synth_play_channel1(index % 4, SYNTH_OCTAVE_C3);
  }
  if(index % 2 == 1){
    synth_play_channel2(index % 4, SYNTH_OCTAVE_C2);
  }
  if(index % 4 == 0){
    synth_play_channel4(index % 4, SYNTH_OCTAVE_C1);
  }
}

Uint16 sequencer_this_step_index(){
  return steps_played % 64;
}

Uint16 sequencer_next_step_index(){
  return (steps_played + 1) % 64;
}

void update_clock(){
  if (bpm_curr != bpm_next){ // change bpm if needed
    bpm_curr = bpm_next;
    steps_played = sequencer_this_step_index(); // reset steps_played
    time_passed = ((steps_played) * 3600) / (bpm_curr * 4); // reset time_passed
  }
  next_step_time = ((steps_played + 1) * 3600) / (bpm_curr * 4);
  steps_played++;
}

void play_step(Uint16 index){

  // copy sound config
  snd_reg_c1_ctrl = sequence_tracks_active[SQR1].normal.fm_ctrl;
  snd_reg_c2_ctrl = sequence_tracks_active[SQR2].normal.fm_ctrl;
  snd_reg_c4_ctrl = sequence_tracks_active[NOISE].normal.fm_ctrl;

  play_notes(index);
}

void sequencer_tick(){
  if(next_step_time <= time_passed){
    play_step(sequencer_next_step_index());
    update_clock();
  }
  time_passed++;
}

