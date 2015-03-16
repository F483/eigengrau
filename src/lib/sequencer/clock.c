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

void sequencer_bpm_inc(){
  bpm_next++;
}

void sequencer_bpm_dec(){
  bpm_next--;
}

inline void play_notes(Uint32 index){
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

Uint32 sequencer_current_step(){
  return steps_played % 64;
}

inline Uint32 next_step(){
  return (steps_played + 1) % 64;
}

inline void update_clock(){
  if (bpm_curr != bpm_next){ // change bpm if needed
    bpm_curr = bpm_next;
    steps_played = sequencer_current_step(); // reset steps_played
    time_passed = ((steps_played) * 3600) / (bpm_curr * 4); // reset time_passed
  }
  next_step_time = ((steps_played + 1) * 3600) / (bpm_curr * 4);
  steps_played++;
}

inline void play_step(Uint32 index){

  // copy sound config
  snd_reg_c1_ctrl = sequence_tracks_active[SQR1].normal.fm_ctrl;
  snd_reg_c2_ctrl = sequence_tracks_active[SQR2].normal.fm_ctrl;
  snd_reg_c4_ctrl = sequence_tracks_active[NOISE].normal.fm_ctrl;

  play_notes(index);
}

void sequencer_tick(){
  if(next_step_time <= time_passed){
    play_step(next_step());
    update_clock();
  }
  time_passed++;
}

