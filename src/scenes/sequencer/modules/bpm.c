// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <gfx/sequencer_bg.h>
#include <src/gba/all.h>
#include <src/lib/all.h>
#include <src/scenes/sequencer/main.h>
#include <src/scenes/sequencer/modules/all.h>

#define BG_MAP        (const Uint16*)&sequencer_bg_Map
#define FONT_TILES    (INDEX_2D(0, 29, 32, BG_MAP) bitand TME_TILE_ID_MASK)

#define KEYS_INC      (INPUT_KEY_A | INPUT_KEY_RIGHT)
#define KEYS_DEC      (INPUT_KEY_B | INPUT_KEY_LEFT)

#define KEYS_UP       INPUT_KEY_UP
#define KEYS_DOWN     INPUT_KEY_DOWN

typedef enum {
  BPM = 0,
  TAP = 1
} InputModes;

#define INPUT_MODES_CNT   2

InputModes selection = BPM;

void module_bpm_init(){
  //
}

void module_bpm_tick(Bool active){
  if(!active){
    return;
  }

  // change input mode
  if(input_key_hit(KEYS_UP | KEYS_DOWN)){
    if(input_key_hit(KEYS_UP)){
      selection = wrap_index_prev(INPUT_MODES_CNT, selection);
    } else { // KEYS_DOWN
      selection = wrap_index_next(INPUT_MODES_CNT, selection);
    }
  } 
  
  // change bpm directly
  else if(selection == BPM){
    if(input_key_hit(KEYS_INC)){
      sequencer_bpm_inc();
    } else if (input_key_hit(KEYS_DEC)){
      sequencer_bpm_dec();
    }
  }
  
  // change bpm by tap
  else if(selection == TAP){
    // TODO tap
  } 
}

void module_bpm_draw(Bool active){
  Uint16  bpm = sequencer_bpm_get();
  Font font_inactive = { FONT_TILES, 0, SCENES_SEQUENCER_HUD_MAPMEM };
  Font font_active = { FONT_TILES, 1, SCENES_SEQUENCER_HUD_MAPMEM };

  if(active){
    if(selection == BPM){
      font_print_i3(&font_active, 19, 1, bpm);
      font_print(&font_inactive, 19, 2, "TAP");
    } else { // TAP
      font_print_i3(&font_inactive, 19, 1, bpm);
      font_print(&font_active, 19, 2, "TAP");
    }
  } else {
    font_print_i3(&font_inactive, 19, 1, bpm);
    font_print(&font_inactive, 19, 2, "TAP");
  }
}

