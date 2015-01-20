// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <gfx/sequencer_bg.h>
#include <src/lib/all.h>
#include <src/gba/all.h>
#include <src/scenes/sequencer/main.h>

#define BG_MAP    (Uint16*)&sequencer_bg_Map

#define DEFAULT   SQR2
#define TILE_OFF  INDEX_2D(0, 20, 32, BG_MAP)
#define TILE_ON   INDEX_2D(1, 20, 32, BG_MAP)
#define POS_X     10
#define POS_Y     1

SequencerTrack scenes_sequencer_track_selected = DEFAULT;
SequencerTrack scenes_sequencer_track_previous = DEFAULT;

static inline void set_track(SequencerTrack track, Uint16 tile){
  INDEX_2D(POS_X, POS_Y + track, 32, SCENES_SEQUENCER_HUD_MAPMEM) = tile;
}

void scenes_sequencer_track_init(){
  set_track(DEFAULT, TILE_ON);
}

void scenes_sequencer_track_draw(){
  set_track(scenes_sequencer_track_previous, TILE_OFF);
  set_track(scenes_sequencer_track_selected, TILE_ON);
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



