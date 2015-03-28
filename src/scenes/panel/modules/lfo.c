// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <gfx/sequencer_bg.h>
#include <src/gba/all.h>
#include <src/lib/all.h>
#include <src/scenes/panel/main.h>

#define BG_MAP        (const Uint16*)&sequencer_bg_Map
#define FONT_TILES    (INDEX_2D(0, 29, 32, BG_MAP) bitand TME_TILE_ID_MASK)
#define DIAL_TILES    (INDEX_2D(11, 20, 32, BG_MAP) bitand TME_TILE_ID_MASK)

#define X             1
#define Y             4

#define SELECT_X      0
#define SELECT_Y      28
#define SELECT_VAL_X  1
#define SELECT_VAL_Y  30

#define WAVE_X        0
#define WAVE_Y        22
#define WAVE_VAL_X    2
#define WAVE_VAL_Y    20

#define RATE_X        0
#define RATE_Y        23
#define MIN_X         0
#define MIN_Y         26
#define MAX_X         0
#define MAX_Y         27

#define KEYS_INC      (INPUT_KEY_A | INPUT_KEY_RIGHT)
#define KEYS_DEC      (INPUT_KEY_B | INPUT_KEY_LEFT)

LFONum lfo_selected;

void module_lfo_select_tick(Bool active){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS_INC)){
    lfo_selected = wrap_index_next(LFO_NUM_COUNT, lfo_selected);
  } else if (input_key_hit(KEYS_DEC)){
    lfo_selected = wrap_index_prev(LFO_NUM_COUNT, lfo_selected);
  }
}

void module_lfo_select_draw(Bool active){
  Uint16 palbank = active ? 1 : 0;
  Uint16* mem = PANEL_HUD_MAPMEM;
  tme_cp_tile(SELECT_X + 0, SELECT_Y, BG_MAP, X + 0, Y + 0, mem, 0, 0, palbank);
  tme_cp_tile(SELECT_X + 1, SELECT_Y, BG_MAP, X + 1, Y + 0, mem, 0, 0, palbank);
  tme_cp_tile(SELECT_VAL_X + lfo_selected, SELECT_VAL_Y, BG_MAP,
              X + 2, Y + 0, mem, 0, 0, palbank);
}

void module_lfo_wave_tick(Bool active){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS_INC)){
    lfo_wave_inc(lfo_selected);
  } else if (input_key_hit(KEYS_DEC)){
    lfo_wave_dec(lfo_selected);
  }
}

void module_lfo_wave_draw(Bool active){
  LFOWave value = lfo_wave_get(lfo_selected);
  Uint16 palbank = active ? 1 : 0;
  Uint16* mem = PANEL_HUD_MAPMEM;
  tme_cp_tile(WAVE_X + 0, WAVE_Y, BG_MAP, X + 0, Y + 1, mem, 0, 0, palbank);
  tme_cp_tile(WAVE_X + 1, WAVE_Y, BG_MAP, X + 1, Y + 1, mem, 0, 0, palbank);
  tme_cp_tile(WAVE_VAL_X + value, WAVE_VAL_Y, BG_MAP,
              X + 2, Y + 1, mem, 0, 0, palbank);
}

void module_lfo_rate_tick(Bool active){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS_INC)){
    lfo_rate_inc(lfo_selected);
  } else if (input_key_hit(KEYS_DEC)){
    lfo_rate_dec(lfo_selected);
  }
}

void module_lfo_rate_draw(Bool active){
  Uint16 value = lfo_rate_get(lfo_selected);
  Uint16 palbank = active ? 1 : 0;
  Uint16* mem = PANEL_HUD_MAPMEM;
  tme_cp_tile(RATE_X + 0, RATE_Y, BG_MAP, X + 0, Y + 2, mem, 0, 0, palbank);
  tme_cp_tile(RATE_X + 1, RATE_Y, BG_MAP, X + 1, Y + 2, mem, 0, 0, palbank);
  Font font = { DIAL_TILES, palbank, mem };
  font_print_dial(&font, X + 2, Y + 2, value);
}

void module_lfo_min_tick(Bool active){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS_INC)){
    lfo_min_inc(lfo_selected);
  } else if (input_key_hit(KEYS_DEC)){
    lfo_min_dec(lfo_selected);
  }
}

void module_lfo_min_draw(Bool active){
  Uint16 value = lfo_min_get(lfo_selected);
  Uint16 palbank = active ? 1 : 0;
  Uint16* mem = PANEL_HUD_MAPMEM;
  tme_cp_tile(MIN_X + 0, MIN_Y, BG_MAP, X + 0, Y + 3, mem, 0, 0, palbank);
  tme_cp_tile(MIN_X + 1, MIN_Y, BG_MAP, X + 1, Y + 3, mem, 0, 0, palbank);
  Font font = { DIAL_TILES, palbank, mem };
  font_print_dial(&font, X + 2, Y + 3, value);
}

void module_lfo_max_tick(Bool active){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS_INC)){
    lfo_max_inc(lfo_selected);
  } else if (input_key_hit(KEYS_DEC)){
    lfo_max_dec(lfo_selected);
  }
}

void module_lfo_max_draw(Bool active){
  Uint16 value = lfo_max_get(lfo_selected);
  Uint16 palbank = active ? 1 : 0;
  Uint16* mem = PANEL_HUD_MAPMEM;
  tme_cp_tile(MAX_X + 0, MAX_Y, BG_MAP, X + 0, Y + 4, mem, 0, 0, palbank);
  tme_cp_tile(MAX_X + 1, MAX_Y, BG_MAP, X + 1, Y + 4, mem, 0, 0, palbank);
  Font font = { DIAL_TILES, palbank, mem };
  font_print_dial(&font, X + 2, Y + 4, value);
}

