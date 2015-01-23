// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <gfx/sequencer_bg.h>
#include <src/lib/all.h>
#include <src/gba/all.h>
#include <src/scenes/all.h>
#include <src/scenes/sequencer/main.h>
#include <src/scenes/sequencer/track.h>
#include <src/scenes/sequencer/modules/all.h>

// memory setup
#define BG_TILEBANK       0
#define BG_MAPBANK        30

// source tiles and maps
#define BG_TILESLEN       sequencer_bg_TilesLen
#define BG_TILES          (Tile4*)&sequencer_bg_Tiles
#define BG_MAPLEN         sequencer_bg_MapLen
#define BG_MAP            (Uint16*)&sequencer_bg_Map
#define BG_PALETTE        (Uint16*)&sequencer_bg_Pal


static void init_gfx(){

  // setup display
  gfx_reg_display = GFX_DISPLAY_MODE0 | GFX_DISPLAY_BG0 | GFX_DISPLAY_BG1;

  // setup background
  gfx_reg_bg0 = GFX_BG_TILE_MEM(BG_TILEBANK) | GFX_BG_REG_32x32 | GFX_BG_4BPP |
                GFX_BG_MAP_MEM(BG_MAPBANK) | GFX_BG_PRIO(3);

  // setup hud
  gfx_reg_bg1 = GFX_BG_TILE_MEM(BG_TILEBANK) | GFX_BG_REG_32x32 | GFX_BG_4BPP |
                GFX_BG_MAP_MEM(SCENES_SEQUENCER_HUD_MAPBANK);

  // copy background tiles, map and palette
  memcpy(tile_bank_mem_4bpp(BG_TILEBANK), BG_TILES, BG_TILESLEN);
  memcpy(map_bank_mem(BG_MAPBANK), BG_MAP, BG_MAPLEN);
  pal_set_bg(BG_PALETTE);
}

static void init_hud(){
  scenes_sequencer_track_init();
}

static void init(){
  init_gfx();
  init_hud();
  sequencer_init();
}

static void tick(){
  sequencer_tick();
  scenes_sequencer_track_tick();

  // XXX
  module_bpm_tick(false);
  module_fm_ctrl_len_sqr2_tick(false);
  module_fm_ctrl_duty_sqr2_tick(false);
  module_fm_ctrl_steps_sqr2_tick(true);
}

static void draw(){
  scenes_sequencer_track_draw();

  // XXX
  module_bpm_draw(false);
  module_fm_ctrl_len_sqr2_draw(false);
  module_fm_ctrl_duty_sqr2_draw(false);
  module_fm_ctrl_steps_sqr2_draw(true);
}

const Scene scenes_sequencer = { true, &init, &tick, &draw };

