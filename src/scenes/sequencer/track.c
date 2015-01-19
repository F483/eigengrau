// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/lib/all.h>
#include <src/gba/all.h>
#include <src/scenes/sequencer/main.h>

#define DEFAULT   SQR1
#define TILE_ON   77
#define TILE_OFF  0
#define POS_X     10
#define POS_Y     1

SequencerTrack scenes_sequencer_track_selected = DEFAULT;
SequencerTrack scenes_sequencer_track_previous = DEFAULT;

static inline void set_track_display(SequencerTrack track, Uint16 tile){
  Uint16* mem = map_bank_mem(SCENES_SEQUENCER_HUD_MAPBANK);
  INDEX_2D(POS_X, POS_Y + track, 32, mem) = tile;
}

void scenes_sequencer_track_load(){
  set_track_display(DEFAULT, TILE_ON);
}

void scenes_sequencer_track_draw(){
  set_track_display(scenes_sequencer_track_previous, TILE_OFF);
  set_track_display(scenes_sequencer_track_selected, TILE_ON);
}

void scenes_sequencer_track_tick(){
  Uint32 cnt = SEQUENCER_TRACK_CNT;
  SequencerTrack selected = scenes_sequencer_track_selected;
  if(input_key_hit(INPUT_KEY_START)){
    scenes_sequencer_track_previous = scenes_sequencer_track_selected;
    scenes_sequencer_track_selected = wrap_index_next(cnt, selected);
  } else if(input_key_hit(INPUT_KEY_SELECT)){
    scenes_sequencer_track_previous = scenes_sequencer_track_selected;
    scenes_sequencer_track_selected = wrap_index_prev(cnt, selected);
  }
}



