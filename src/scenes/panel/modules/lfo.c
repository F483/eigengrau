// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <gfx/sequencer_bg.h>
#include <src/gba/all.h>
#include <src/lib/all.h>
#include <src/scenes/panel/main.h>

#define BG_MAP        (const Uint16*)&sequencer_bg_Map
#define FONT_TILES    (INDEX_2D(0, 29, 32, BG_MAP) bitand TME_TILE_ID_MASK)
#define DIAL_TILES    (INDEX_2D(7, 20, 32, BG_MAP) bitand TME_TILE_ID_MASK)
#define WAVE_TILES    (INDEX_2D(7 + 16, 20, 32, BG_MAP) bitand TME_TILE_ID_MASK)

#define POS_X         24
#define POS_Y         1

#define KEY_RATE_INC  INPUT_KEY_RIGHT
#define KEY_RATE_DEC  INPUT_KEY_LEFT
#define KEY_WAVE_INC  INPUT_KEY_A
#define KEY_WAVE_DEC  INPUT_KEY_B

#define LFO_A         0
#define LFO_B         1

inline void lfo_tick(Bool active, SequencerTrack track, Uint32 lfo_num){
  SUPPRESS_UNUSED(active);
  SUPPRESS_UNUSED(track);
  SUPPRESS_UNUSED(lfo_num);
}

inline void lfo_draw(Bool active, SequencerTrack track, Uint32 lfo_num){
  SUPPRESS_UNUSED(track);
  Uint8 rate = 12; // TODO get rate
  Uint8 wave = 0;  // TODO get wave

  Uint16 palbank = active ? 1 : 0;
  Font font_char = { FONT_TILES, palbank, PANEL_HUD_MAPMEM };
  Font font_dial = { DIAL_TILES, palbank, PANEL_HUD_MAPMEM };
  Font font_wave = { WAVE_TILES, palbank, PANEL_HUD_MAPMEM };

  Uint16 dest_y = POS_Y + lfo_num;
  font_print(&font_char, POS_X, dest_y, lfo_num ? "B" : "A");   // draw label
  font_print_dial(&font_wave, POS_X + 1, dest_y, wave);         // draw wave
  font_print_dial(&font_dial, POS_X + 2, dest_y, rate);         // draw rate
}

void module_lfo_sqr1_a_tick(Bool active){ lfo_tick(active, SQR1, LFO_A); }
void module_lfo_sqr1_a_draw(Bool active){ lfo_draw(active, SQR1, LFO_A); }
void module_lfo_sqr1_b_tick(Bool active){ lfo_tick(active, SQR1, LFO_B); }
void module_lfo_sqr1_b_draw(Bool active){ lfo_draw(active, SQR1, LFO_B); }

void module_lfo_sqr2_a_tick(Bool active){ lfo_tick(active, SQR2, LFO_A); } 
void module_lfo_sqr2_a_draw(Bool active){ lfo_draw(active, SQR2, LFO_A); }
void module_lfo_sqr2_b_tick(Bool active){ lfo_tick(active, SQR2, LFO_B); }
void module_lfo_sqr2_b_draw(Bool active){ lfo_draw(active, SQR2, LFO_B); }

void module_lfo_wave_a_tick(Bool active){ lfo_tick(active, WAVE, LFO_A); }
void module_lfo_wave_a_draw(Bool active){ lfo_draw(active, WAVE, LFO_A); }
void module_lfo_wave_b_tick(Bool active){ lfo_tick(active, WAVE, LFO_B); } 
void module_lfo_wave_b_draw(Bool active){ lfo_draw(active, WAVE, LFO_B); }

void module_lfo_noise_a_tick(Bool active){ lfo_tick(active, NOISE, LFO_A); } 
void module_lfo_noise_a_draw(Bool active){ lfo_draw(active, NOISE, LFO_A); }
void module_lfo_noise_b_tick(Bool active){ lfo_tick(active, NOISE, LFO_B); } 
void module_lfo_noise_b_draw(Bool active){ lfo_draw(active, NOISE, LFO_B); }

void module_lfo_smpl1_a_tick(Bool active){ lfo_tick(active, SMPL1, LFO_A); } 
void module_lfo_smpl1_a_draw(Bool active){ lfo_draw(active, SMPL1, LFO_A); }
void module_lfo_smpl1_b_tick(Bool active){ lfo_tick(active, SMPL1, LFO_B); } 
void module_lfo_smpl1_b_draw(Bool active){ lfo_draw(active, SMPL1, LFO_B); }

void module_lfo_smpl2_a_tick(Bool active){ lfo_tick(active, SMPL2, LFO_A); } 
void module_lfo_smpl2_a_draw(Bool active){ lfo_draw(active, SMPL2, LFO_A); }
void module_lfo_smpl2_b_tick(Bool active){ lfo_tick(active, SMPL2, LFO_B); } 
void module_lfo_smpl2_b_draw(Bool active){ lfo_draw(active, SMPL2, LFO_B); }

