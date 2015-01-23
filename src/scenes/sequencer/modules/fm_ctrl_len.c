// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <gfx/sequencer_bg.h>
#include <src/gba/all.h>
#include <src/lib/all.h>
#include <src/scenes/sequencer/main.h>
#include <src/scenes/sequencer/modules/all.h>

#define BG_MAP        (const Uint16*)&sequencer_bg_Map
#define FONT_TILES    (INDEX_2D(0, 29, 32, BG_MAP) bitand TME_TILE_ID_MASK)
#define X             1
#define Y             4
#define LABEL_X       0
#define LABEL_Y       21

#define KEYS_INC      (INPUT_KEY_A | INPUT_KEY_RIGHT)
#define KEYS_DEC      (INPUT_KEY_B | INPUT_KEY_LEFT)

static void draw(Bool active, SequencerTrack track){
  Uint16* mem = SCENES_SEQUENCER_HUD_MAPMEM;
  Uint16 palbank = active ? 1 : 0;
  Font font = { FONT_TILES, palbank, mem };

  tme_cp_tile(LABEL_X + 0, LABEL_Y, BG_MAP, X + 0, Y, mem, 0, 0, palbank);
  tme_cp_tile(LABEL_X + 1, LABEL_Y, BG_MAP, X + 1, Y, mem, 0, 0, palbank);

  Uint16 value = sequencer_cfg_fm_ctrl_len_get(track);
  font_print_i2(&font, X + 2, Y, value);
}

static void tick(Bool active, SequencerTrack track){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS_INC)){
    Uint16 value = sequencer_cfg_fm_ctrl_len_get(track);
    sequencer_cfg_fm_ctrl_len_set(track, wrap_index_next(64, value));
  } else if (input_key_hit(KEYS_DEC)){
    Uint16 value = sequencer_cfg_fm_ctrl_len_get(track);
    sequencer_cfg_fm_ctrl_len_set(track, wrap_index_prev(64, value));
  }
}

void module_fm_ctrl_len_sqr1_tick(Bool active){
  tick(active, SQR1);
}

void module_fm_ctrl_len_sqr1_draw(Bool active){
  draw(active, SQR1);
}

void module_fm_ctrl_len_sqr2_tick(Bool active){
  tick(active, SQR2);
}

void module_fm_ctrl_len_sqr2_draw(Bool active){
  draw(active, SQR2);
}

void module_fm_ctrl_len_noise_tick(Bool active){
  tick(active, NOISE);
}

void module_fm_ctrl_len_noise_draw(Bool active){
  draw(active, NOISE);
}
