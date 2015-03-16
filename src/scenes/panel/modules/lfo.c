// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <gfx/sequencer_bg.h>
#include <src/gba/all.h>
#include <src/lib/all.h>
#include <src/scenes/panel/main.h>

#define BG_MAP        (const Uint16*)&sequencer_bg_Map
#define FONT_TILES    (INDEX_2D(0, 29, 32, BG_MAP) bitand TME_TILE_ID_MASK)
#define DIAL_TILES    (INDEX_2D(7, 20, 32, BG_MAP) bitand TME_TILE_ID_MASK)
#define WAVE_TILES    (INDEX_2D(7 + 16, 20, 32, BG_MAP) bitand TME_TILE_ID_MASK) #define POS_X         24
#define POS_Y         1

#define KEY_RATE_INC  INPUT_KEY_RIGHT
#define KEY_RATE_DEC  INPUT_KEY_LEFT
#define KEY_WAVE_INC  INPUT_KEY_A
#define KEY_WAVE_DEC  INPUT_KEY_B

#define LFO_A         0
#define LFO_B         1

void module_lfo_a_tick(Bool active){
  SUPPRESS_UNUSED(active); // TODO
}

void module_lfo_b_tick(Bool active){
  SUPPRESS_UNUSED(active); // TODO
}

inline void module_lfo_draw(Bool active, Uint32 num){
  Uint8 rate = 12; // TODO get rate
  Uint8 wave = 0;  // TODO get wave

  Uint16 palbank = active ? 1 : 0;
  Font font_char = { FONT_TILES, palbank, PANEL_HUD_MAPMEM };
  Font font_dial = { DIAL_TILES, palbank, PANEL_HUD_MAPMEM };
  Font font_wave = { WAVE_TILES, palbank, PANEL_HUD_MAPMEM };

  Uint16 dest_y = POS_Y + num;
  font_print(&font_char, POS_X, dest_y, num ? "B" : "A");   // draw label
  font_print_dial(&font_wave, POS_X + 1, dest_y, wave);     // draw wave
  font_print_dial(&font_dial, POS_X + 2, dest_y, rate);     // draw rate
}

void module_lfo_a_draw(Bool active){
  module_lfo_draw(active, LFO_A);
}

void module_lfo_b_draw(Bool active){
  module_lfo_draw(active, LFO_B);
}

