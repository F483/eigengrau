// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <gfx/sequencer_bg.h>
#include <src/gba/all.h>
#include <src/lib/all.h>
#include <src/scenes/panel/main.h>

#define BG_MAP    (const Uint16*)&sequencer_bg_Map
#define X         1
#define Y         5
#define LABEL_X   0
#define LABEL_Y   24
#define VAL_X     5
#define VAL_Y     20

#define KEYS      (INPUT_KEY_A | INPUT_KEY_RIGHT | INPUT_KEY_B | INPUT_KEY_LEFT)

static void draw(Bool active, SequencerTrack track){
  Uint16 val = sequencer_cfg_fm_ctrl_dir_get(track);
  Uint16 palbank = active ? 1 : 0;
  Uint16* mem = PANEL_HUD_MAPMEM;

  tme_cp_tile(LABEL_X + 0, LABEL_Y, BG_MAP, X + 0, Y, mem, 0, 0, palbank);
  tme_cp_tile(LABEL_X + 1, LABEL_Y, BG_MAP, X + 1, Y, mem, 0, 0, palbank);
  tme_cp_tile(LABEL_X + 2, LABEL_Y, BG_MAP, X + 2, Y, mem, 0, 0, palbank);
  tme_cp_tile(VAL_X + val, VAL_Y,   BG_MAP, X + 3, Y, mem, 0, 0, palbank);
}

static void tick(Bool active, SequencerTrack track){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS)){
    Uint16 value = sequencer_cfg_fm_ctrl_dir_get(track);
    sequencer_cfg_fm_ctrl_dir_set(track, wrap_index_next(2, value));
  }
}

void module_fm_ctrl_dir_sqr1_tick(Bool active){
  tick(active, SQR1);
}

void module_fm_ctrl_dir_sqr1_draw(Bool active){
  draw(active, SQR1);
}

void module_fm_ctrl_dir_sqr2_tick(Bool active){
  tick(active, SQR2);
}

void module_fm_ctrl_dir_sqr2_draw(Bool active){
  draw(active, SQR2);
}

void module_fm_ctrl_dir_noise_tick(Bool active){
  tick(active, NOISE);
}

void module_fm_ctrl_dir_noise_draw(Bool active){
  draw(active, NOISE);
}

