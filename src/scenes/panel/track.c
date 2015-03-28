// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <gfx/sequencer_bg.h>
#include <src/lib/all.h>
#include <src/gba/all.h>
#include <src/scenes/panel/main.h>

#define BG_MAP    (Uint16*)&sequencer_bg_Map

#define DEFAULT   SQR1
#define TILE_OFF  INDEX_2D(0, 20, 32, BG_MAP)
#define TILE_ON   INDEX_2D(1, 20, 32, BG_MAP)
#define POS_X     13
#define POS_Y     1

#define KEYS_NEXT INPUT_KEY_SELECT // FIXME INPUT_KEY_L
#define KEYS_PREV 0                // FIXME INPUT_KEY_R

SequencerTrack selected = DEFAULT;
SequencerTrack previous = DEFAULT;

static inline void set_track(SequencerTrack track, Uint16 tile){
  INDEX_2D(POS_X, POS_Y + track, 32, PANEL_HUD_MAPMEM) = tile;
}

void panel_track_draw(){
  set_track(previous, TILE_OFF);
  set_track(selected, TILE_ON);
}

void panel_track_tick(){
  Uint32 cnt = SEQUENCER_TRACK_COUNT;
  if(input_key_hit(KEYS_NEXT)){
    previous = selected;
    selected = wrap_index_next(cnt, selected);
  } else if(input_key_hit(KEYS_PREV)){
    previous = selected;
    selected = wrap_index_prev(cnt, selected);
  }
}

SequencerTrack panel_track_curr(){
  return selected;
}


