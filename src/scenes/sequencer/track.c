// Copyright (c) 2014 Fabian Barkhau <fabian.barkhau@gmail.com> 
// License: MIT (see LICENSE.TXT file)  

#include <src/lib/all.h>
#include <src/gba/all.h>

SequencerTrack scene_sequencer_track_selected = SQR1;

void scene_sequencer_track_tick(){
  SequencerTrack selected = scene_sequencer_track_selected;
  SequencerTrack previous = scene_sequencer_track_selected;
  if(input_key_hit(INPUT_KEY_SELECT)){
    selected = wrap_index_prev(SEQUENCER_TRACK_CNT, selected);
  }
  if(input_key_hit(INPUT_KEY_START)){
    selected = wrap_index_next(SEQUENCER_TRACK_CNT, selected);
  }
  if(selected != previous){
    // TODO clear previous

    // TODO set current
    
    scene_sequencer_track_selected = selected;
  }
}
