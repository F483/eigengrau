// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <gfx/sequencer_bg.h>
#include <src/gba/all.h>
#include <src/lib/all.h>
#include <src/scenes/panel/main.h>

#define BG_MAP      (const Uint16*)&sequencer_bg_Map
#define DIAL_TILES  (INDEX_2D(11, 20, 32, BG_MAP) bitand TME_TILE_ID_MASK)

#define X           5
#define Y           1

#define DUTY_X      0
#define DUTY_Y      22
#define DUTY_VAL_X  3
#define DUTY_VAL_Y  20

#define DIR_X       0
#define DIR_Y       24
#define DIR_VAL_X   9
#define DIR_VAL_Y   20

#define IVOL_X      0
#define IVOL_Y      25

#define STEPS_X     2
#define STEPS_Y     21

#define LEN_X       0
#define LEN_Y       21

#define KEYS_INC    (INPUT_KEY_A | INPUT_KEY_RIGHT)
#define KEYS_DEC    (INPUT_KEY_B | INPUT_KEY_LEFT)
#define KEYS        (KEYS_INC | KEYS_DEC)

void duty_draw(Bool active, SequencerTrack track){
  Uint16 val = sequencer_fm_ctrl_duty_get(track);
  Uint16 palbank = active ? 1 : 0;
  Uint16* mem = PANEL_HUD_MAPMEM;
  tme_cp_tile(DUTY_X + 0, DUTY_Y, BG_MAP, X + 0, Y, mem, 0, 0, palbank);
  tme_cp_tile(DUTY_X + 1, DUTY_Y, BG_MAP, X + 1, Y, mem, 0, 0, palbank);
  tme_cp_tile(DUTY_VAL_X + val, DUTY_VAL_Y, BG_MAP,
              X + 2, Y, mem, 0, 0, palbank);
}

void duty_tick(Bool active, SequencerTrack track){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS_INC)){
    Uint16 value = sequencer_fm_ctrl_duty_get(track);
    sequencer_fm_ctrl_duty_set(track, wrap_index_next(3, value));
  } else if (input_key_hit(KEYS_DEC)){
    Uint16 value = sequencer_fm_ctrl_duty_get(track);
    sequencer_fm_ctrl_duty_set(track, wrap_index_prev(3, value));
  }
}

void dir_draw(Bool active, SequencerTrack track){
  Uint16 val = sequencer_fm_ctrl_dir_get(track);
  Uint16 palbank = active ? 1 : 0;
  Uint16* mem = PANEL_HUD_MAPMEM;
  tme_cp_tile(DIR_X + 0, DIR_Y, BG_MAP, X + 0, Y + 1, mem, 0, 0, palbank);
  tme_cp_tile(DIR_X + 1, DIR_Y, BG_MAP, X + 1, Y + 1, mem, 0, 0, palbank);
  tme_cp_tile(DIR_VAL_X + val, DIR_VAL_Y, BG_MAP,
              X + 2, Y + 1, mem, 0, 0, palbank);
}

void dir_tick(Bool active, SequencerTrack track){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS)){
    Uint16 value = sequencer_fm_ctrl_dir_get(track);
    sequencer_fm_ctrl_dir_set(track, wrap_index_next(2, value));
  }
}

void ivol_draw(Bool active, SequencerTrack track){
  Uint16* mem = PANEL_HUD_MAPMEM;
  Uint16 palbank = active ? 1 : 0;
  Font font = { DIAL_TILES, palbank, mem };

  tme_cp_tile(IVOL_X + 0, IVOL_Y, BG_MAP, X + 0, Y + 2, mem, 0, 0, palbank);
  tme_cp_tile(IVOL_X + 1, IVOL_Y, BG_MAP, X + 1, Y + 2, mem, 0, 0, palbank);

  Uint16 value = sequencer_fm_ctrl_ivol_get(track);
  font_print_dial(&font, X + 2, Y + 2, value);
}

void ivol_tick(Bool active, SequencerTrack track){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS_INC)){
    Uint16 value = sequencer_fm_ctrl_ivol_get(track);
    sequencer_fm_ctrl_ivol_set(track, wrap_index_next(16, value));
  } else if (input_key_hit(KEYS_DEC)){
    Uint16 value = sequencer_fm_ctrl_ivol_get(track);
    sequencer_fm_ctrl_ivol_set(track, wrap_index_prev(16, value));
  }
}

void steps_draw(Bool active, SequencerTrack track){
  Uint16* mem = PANEL_HUD_MAPMEM;
  Uint16 palbank = active ? 1 : 0;
  Font font = { DIAL_TILES, palbank, mem };

  tme_cp_tile(STEPS_X + 0, STEPS_Y, BG_MAP, X + 0, Y + 3, mem, 0, 0, palbank);
  tme_cp_tile(STEPS_X + 1, STEPS_Y, BG_MAP, X + 1, Y + 3, mem, 0, 0, palbank);

  Uint16 value = sequencer_fm_ctrl_steps_get(track);
  font_print_dial(&font, X + 2, Y + 3, (value * 2) + 14);
}

void steps_tick(Bool active, SequencerTrack track){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS_INC)){
    Uint16 value = sequencer_fm_ctrl_steps_get(track);
    sequencer_fm_ctrl_steps_set(track, wrap_index_next(8, value));
  } else if (input_key_hit(KEYS_DEC)){
    Uint16 value = sequencer_fm_ctrl_steps_get(track);
    sequencer_fm_ctrl_steps_set(track, wrap_index_prev(8, value));
  }
}

void len_draw(Bool active, SequencerTrack track){
  Uint16* mem = PANEL_HUD_MAPMEM;
  Uint16 palbank = active ? 1 : 0;
  Font font = { DIAL_TILES, palbank, mem };

  tme_cp_tile(LEN_X + 0, LEN_Y, BG_MAP, X + 0, Y + 4, mem, 0, 0, palbank);
  tme_cp_tile(LEN_X + 1, LEN_Y, BG_MAP, X + 1, Y + 4, mem, 0, 0, palbank);

  Uint16 value = sequencer_fm_ctrl_len_get(track);
  font_print_dial(&font, X + 2, Y + 4, (63 - value) / 4);
}

void len_tick(Bool active, SequencerTrack track){
  if(!active){
    return;
  }
  if(input_key_hit(KEYS_INC)){
    Uint16 value = sequencer_fm_ctrl_len_get(track);
    sequencer_fm_ctrl_len_set(track, wrap_index(64, value, -4));
  } else if (input_key_hit(KEYS_DEC)){
    Uint16 value = sequencer_fm_ctrl_len_get(track);
    sequencer_fm_ctrl_len_set(track, wrap_index(64, value, 4));
  }
}

void module_fm_ctrl_dir_sqr1_tick(Bool active){ dir_tick(active, SQR1); }
void module_fm_ctrl_dir_sqr1_draw(Bool active){ dir_draw(active, SQR1); }
void module_fm_ctrl_dir_sqr2_tick(Bool active){ dir_tick(active, SQR2); }
void module_fm_ctrl_dir_sqr2_draw(Bool active){ dir_draw(active, SQR2); }
void module_fm_ctrl_dir_noise_tick(Bool active){ dir_tick(active, NOISE); }
void module_fm_ctrl_dir_noise_draw(Bool active){ dir_draw(active, NOISE); }

void module_fm_ctrl_duty_sqr1_tick(Bool active){ duty_tick(active, SQR1); }
void module_fm_ctrl_duty_sqr1_draw(Bool active){ duty_draw(active, SQR1); }
void module_fm_ctrl_duty_sqr2_tick(Bool active){ duty_tick(active, SQR2); }
void module_fm_ctrl_duty_sqr2_draw(Bool active){ duty_draw(active, SQR2); }
void module_fm_ctrl_duty_noise_tick(Bool active){ duty_tick(active, NOISE); }
void module_fm_ctrl_duty_noise_draw(Bool active){ duty_draw(active, NOISE); }

void module_fm_ctrl_ivol_sqr1_tick(Bool active){ ivol_tick(active, SQR1); }
void module_fm_ctrl_ivol_sqr1_draw(Bool active){ ivol_draw(active, SQR1); }
void module_fm_ctrl_ivol_sqr2_tick(Bool active){ ivol_tick(active, SQR2); }
void module_fm_ctrl_ivol_sqr2_draw(Bool active){ ivol_draw(active, SQR2); }
void module_fm_ctrl_ivol_noise_tick(Bool active){ ivol_tick(active, NOISE); }
void module_fm_ctrl_ivol_noise_draw(Bool active){ ivol_draw(active, NOISE); }

void module_fm_ctrl_steps_sqr1_tick(Bool active){ steps_tick(active, SQR1); }
void module_fm_ctrl_steps_sqr1_draw(Bool active){ steps_draw(active, SQR1); }
void module_fm_ctrl_steps_sqr2_tick(Bool active){ steps_tick(active, SQR2); }
void module_fm_ctrl_steps_sqr2_draw(Bool active){ steps_draw(active, SQR2); }
void module_fm_ctrl_steps_noise_tick(Bool active){ steps_tick(active, NOISE); }
void module_fm_ctrl_steps_noise_draw(Bool active){ steps_draw(active, NOISE); }

void module_fm_ctrl_len_sqr1_tick(Bool active){ len_tick(active, SQR1); }
void module_fm_ctrl_len_sqr1_draw(Bool active){ len_draw(active, SQR1); }
void module_fm_ctrl_len_sqr2_tick(Bool active){ len_tick(active, SQR2); }
void module_fm_ctrl_len_sqr2_draw(Bool active){ len_draw(active, SQR2); }
void module_fm_ctrl_len_noise_tick(Bool active){ len_tick(active, NOISE); }
void module_fm_ctrl_len_noise_draw(Bool active){ len_draw(active, NOISE); }
