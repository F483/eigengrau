// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <gfx/sequencer_bg.h>
#include <src/gba/all.h>
#include <src/lib/all.h>
#include <src/scenes/sequencer/main.h>
#include <src/scenes/sequencer/modules/all.h>

#define BG_MAP        (const Uint16*)&sequencer_bg_Map
#define FONT_TILES    (INDEX_2D(0, 29, 32, BG_MAP) bitand TME_TILE_ID_MASK)

void module_bpm_init(){
  //
}

void module_bpm_tick(Bool selected){
  SUPPRESS_UNUSED(selected); // TODO
}

void module_bpm_draw(Bool selected){
  SUPPRESS_UNUSED(selected); // TODO
  Uint16  bpm = sequencer_get_bpm();

  Font font = { FONT_TILES, 0, SCENES_SEQUENCER_HUD_MAPMEM };
  font_print_i3(&font, 19, 1, bpm);
  font_print(&font, 19, 2, "TAP");
}

