// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <gfx/sequencer_bg.h>
#include <src/gba/all.h>
#include <src/lib/all.h>
#include <src/scenes/panel/main.h>
#include <src/scenes/panel/modules/common.h>

#define BG_MAP        (const Uint16*)&sequencer_bg_Map
#define FONT_TILES    (INDEX_2D(0, 29, 32, BG_MAP) bitand TME_TILE_ID_MASK)
#define DIAL_TILES    (INDEX_2D(7, 20, 32, BG_MAP) bitand TME_TILE_ID_MASK)
#define WAVE_TILES    (INDEX_2D(7 + 16, 20, 32, BG_MAP) bitand TME_TILE_ID_MASK)

#define X             1
#define Y             4

#define SELECT_X      0
#define SELECT_Y      28
#define WAVE_X        0
#define WAVE_Y        22
#define RATE_X        0
#define RATE_Y        23
#define MIN_X         0
#define MIN_Y         26
#define MAX_X         0
#define MAX_Y         27

#define KEYS_INC      (INPUT_KEY_A | INPUT_KEY_RIGHT)
#define KEYS_DEC      (INPUT_KEY_B | INPUT_KEY_LEFT)

LFONum lfo_selected[SEQUENCER_TRACK_COUNT];

void lfo_select_tick(Bool active, SequencerTrack track){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS_INC)){
    lfo_selected[track] = wrap_index_next(LFO_NUM_COUNT, lfo_selected[track]);
  } else if (input_key_hit(KEYS_DEC)){
    lfo_selected[track] = wrap_index_prev(LFO_NUM_COUNT, lfo_selected[track]);
  }
}

void lfo_select_draw(Bool active, SequencerTrack track){
  Uint16 palbank = active ? 1 : 0;
  Uint16* mem = PANEL_HUD_MAPMEM;
  tme_cp_tile(SELECT_X + 0, SELECT_Y, BG_MAP, X + 0, Y + 0, mem, 0, 0, palbank);
  tme_cp_tile(SELECT_X + 1, SELECT_Y, BG_MAP, X + 1, Y + 0, mem, 0, 0, palbank);

  SUPPRESS_UNUSED(track);
  // TODO value
}

void lfo_wave_tick(Bool active, SequencerTrack track){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS_INC)){
    lfo_wave_inc(track, lfo_selected[track]);
  } else if (input_key_hit(KEYS_DEC)){
    lfo_wave_dec(track, lfo_selected[track]);
  }
}

void lfo_wave_draw(Bool active, SequencerTrack track){
  Uint16 palbank = active ? 1 : 0;
  Uint16* mem = PANEL_HUD_MAPMEM;
  tme_cp_tile(WAVE_X + 0, WAVE_Y, BG_MAP, X + 0, Y + 1, mem, 0, 0, palbank);
  tme_cp_tile(WAVE_X + 1, WAVE_Y, BG_MAP, X + 1, Y + 1, mem, 0, 0, palbank);

  SUPPRESS_UNUSED(track);
  // TODO value
}

void lfo_rate_tick(Bool active, SequencerTrack track){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS_INC)){
    lfo_rate_inc(track, lfo_selected[track]);
  } else if (input_key_hit(KEYS_DEC)){
    lfo_rate_dec(track, lfo_selected[track]);
  }
}

void lfo_rate_draw(Bool active, SequencerTrack track){
  Uint16 palbank = active ? 1 : 0;
  Uint16* mem = PANEL_HUD_MAPMEM;
  tme_cp_tile(RATE_X + 0, RATE_Y, BG_MAP, X + 0, Y + 2, mem, 0, 0, palbank);
  tme_cp_tile(RATE_X + 1, RATE_Y, BG_MAP, X + 1, Y + 2, mem, 0, 0, palbank);

  SUPPRESS_UNUSED(track);
  // TODO value
}

void lfo_min_tick(Bool active, SequencerTrack track){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS_INC)){
    lfo_min_inc(track, lfo_selected[track]);
  } else if (input_key_hit(KEYS_DEC)){
    lfo_min_dec(track, lfo_selected[track]);
  }
}

void lfo_min_draw(Bool active, SequencerTrack track){
  Uint16 palbank = active ? 1 : 0;
  Uint16* mem = PANEL_HUD_MAPMEM;
  tme_cp_tile(MIN_X + 0, MIN_Y, BG_MAP, X + 0, Y + 3, mem, 0, 0, palbank);
  tme_cp_tile(MIN_X + 1, MIN_Y, BG_MAP, X + 1, Y + 3, mem, 0, 0, palbank);

  SUPPRESS_UNUSED(track);
  // TODO value
}

void lfo_max_tick(Bool active, SequencerTrack track){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS_INC)){
    lfo_max_inc(track, lfo_selected[track]);
  } else if (input_key_hit(KEYS_DEC)){
    lfo_max_dec(track, lfo_selected[track]);
  }
}

void lfo_max_draw(Bool active, SequencerTrack track){
  Uint16 palbank = active ? 1 : 0;
  Uint16* mem = PANEL_HUD_MAPMEM;
  tme_cp_tile(MAX_X + 0, MAX_Y, BG_MAP, X + 0, Y + 4, mem, 0, 0, palbank);
  tme_cp_tile(MAX_X + 1, MAX_Y, BG_MAP, X + 1, Y + 4, mem, 0, 0, palbank);

  SUPPRESS_UNUSED(track);
  // TODO value
}

void module_lfo_select_sqr1_tick(Bool active){ lfo_select_tick(active, SQR1); } 
void module_lfo_select_sqr1_draw(Bool active){ lfo_select_draw(active, SQR1); } 
void module_lfo_select_sqr2_tick(Bool active){ lfo_select_tick(active, SQR2); } 
void module_lfo_select_sqr2_draw(Bool active){ lfo_select_draw(active, SQR2); } 
void module_lfo_select_wave_tick(Bool active){ lfo_select_tick(active, WAVE); } 
void module_lfo_select_wave_draw(Bool active){ lfo_select_draw(active, WAVE); } 
void module_lfo_select_noise_tick(Bool active){ lfo_select_tick(active, NOISE); } 
void module_lfo_select_noise_draw(Bool active){ lfo_select_draw(active, NOISE); } 
void module_lfo_select_smpl1_tick(Bool active){ lfo_select_tick(active, SMPL1); } 
void module_lfo_select_smpl1_draw(Bool active){ lfo_select_draw(active, SMPL1); } 
void module_lfo_select_smpl2_tick(Bool active){ lfo_select_tick(active, SMPL2); } 
void module_lfo_select_smpl2_draw(Bool active){ lfo_select_draw(active, SMPL2); } 

void module_lfo_wave_sqr1_tick(Bool active){ lfo_wave_tick(active, SQR1); } 
void module_lfo_wave_sqr1_draw(Bool active){ lfo_wave_draw(active, SQR1); } 
void module_lfo_wave_sqr2_tick(Bool active){ lfo_wave_tick(active, SQR2); } 
void module_lfo_wave_sqr2_draw(Bool active){ lfo_wave_draw(active, SQR2); } 
void module_lfo_wave_wave_tick(Bool active){ lfo_wave_tick(active, WAVE); } 
void module_lfo_wave_wave_draw(Bool active){ lfo_wave_draw(active, WAVE); } 
void module_lfo_wave_noise_tick(Bool active){ lfo_wave_tick(active, NOISE); } 
void module_lfo_wave_noise_draw(Bool active){ lfo_wave_draw(active, NOISE); } 
void module_lfo_wave_smpl1_tick(Bool active){ lfo_wave_tick(active, SMPL1); } 
void module_lfo_wave_smpl1_draw(Bool active){ lfo_wave_draw(active, SMPL1); } 
void module_lfo_wave_smpl2_tick(Bool active){ lfo_wave_tick(active, SMPL2); } 
void module_lfo_wave_smpl2_draw(Bool active){ lfo_wave_draw(active, SMPL2); } 

void module_lfo_rate_sqr1_tick(Bool active){ lfo_rate_tick(active, SQR1); } 
void module_lfo_rate_sqr1_draw(Bool active){ lfo_rate_draw(active, SQR1); } 
void module_lfo_rate_sqr2_tick(Bool active){ lfo_rate_tick(active, SQR2); } 
void module_lfo_rate_sqr2_draw(Bool active){ lfo_rate_draw(active, SQR2); } 
void module_lfo_rate_wave_tick(Bool active){ lfo_rate_tick(active, WAVE); } 
void module_lfo_rate_wave_draw(Bool active){ lfo_rate_draw(active, WAVE); } 
void module_lfo_rate_noise_tick(Bool active){ lfo_rate_tick(active, NOISE); } 
void module_lfo_rate_noise_draw(Bool active){ lfo_rate_draw(active, NOISE); } 
void module_lfo_rate_smpl1_tick(Bool active){ lfo_rate_tick(active, SMPL1); } 
void module_lfo_rate_smpl1_draw(Bool active){ lfo_rate_draw(active, SMPL1); } 
void module_lfo_rate_smpl2_tick(Bool active){ lfo_rate_tick(active, SMPL2); } 
void module_lfo_rate_smpl2_draw(Bool active){ lfo_rate_draw(active, SMPL2); } 

void module_lfo_min_sqr1_tick(Bool active){ lfo_min_tick(active, SQR1); } 
void module_lfo_min_sqr1_draw(Bool active){ lfo_min_draw(active, SQR1); } 
void module_lfo_min_sqr2_tick(Bool active){ lfo_min_tick(active, SQR2); } 
void module_lfo_min_sqr2_draw(Bool active){ lfo_min_draw(active, SQR2); } 
void module_lfo_min_wave_tick(Bool active){ lfo_min_tick(active, WAVE); } 
void module_lfo_min_wave_draw(Bool active){ lfo_min_draw(active, WAVE); } 
void module_lfo_min_noise_tick(Bool active){ lfo_min_tick(active, NOISE); } 
void module_lfo_min_noise_draw(Bool active){ lfo_min_draw(active, NOISE); } 
void module_lfo_min_smpl1_tick(Bool active){ lfo_min_tick(active, SMPL1); } 
void module_lfo_min_smpl1_draw(Bool active){ lfo_min_draw(active, SMPL1); } 
void module_lfo_min_smpl2_tick(Bool active){ lfo_min_tick(active, SMPL2); } 
void module_lfo_min_smpl2_draw(Bool active){ lfo_min_draw(active, SMPL2); } 

void module_lfo_max_sqr1_tick(Bool active){ lfo_max_tick(active, SQR1); } 
void module_lfo_max_sqr1_draw(Bool active){ lfo_max_draw(active, SQR1); } 
void module_lfo_max_sqr2_tick(Bool active){ lfo_max_tick(active, SQR2); } 
void module_lfo_max_sqr2_draw(Bool active){ lfo_max_draw(active, SQR2); } 
void module_lfo_max_wave_tick(Bool active){ lfo_max_tick(active, WAVE); } 
void module_lfo_max_wave_draw(Bool active){ lfo_max_draw(active, WAVE); } 
void module_lfo_max_noise_tick(Bool active){ lfo_max_tick(active, NOISE); } 
void module_lfo_max_noise_draw(Bool active){ lfo_max_draw(active, NOISE); } 
void module_lfo_max_smpl1_tick(Bool active){ lfo_max_tick(active, SMPL1); } 
void module_lfo_max_smpl1_draw(Bool active){ lfo_max_draw(active, SMPL1); } 
void module_lfo_max_smpl2_tick(Bool active){ lfo_max_tick(active, SMPL2); } 
void module_lfo_max_smpl2_draw(Bool active){ lfo_max_draw(active, SMPL2); } 


