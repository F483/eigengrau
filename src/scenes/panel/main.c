// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <gfx/sequencer_bg.h>
#include <src/lib/all.h>
#include <src/gba/all.h>
#include <src/scenes/all.h>
#include <src/scenes/panel/main.h>
#include <src/scenes/panel/track.h>
#include <src/scenes/panel/bundle.h>

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
                GFX_BG_MAP_MEM(PANEL_HUD_MAPBANK);

  // copy background tiles, map and palette
  memcpy(tile_bank_mem_4bpp(BG_TILEBANK), BG_TILES, BG_TILESLEN);
  memcpy(map_bank_mem(BG_MAPBANK), BG_MAP, BG_MAPLEN);
  pal_set_bg(BG_PALETTE);
}

static void init(){
  init_gfx();
  sequencer_init();
}

static void tick(){
  sequencer_tick();
  panel_track_tick();
  bundle_tick(&bundles[panel_track_curr()]);
}

static void draw(){
  panel_track_draw();
  bundle_draw(&bundles[panel_track_curr()]);
}

const Scene scenes_panel = { true, &init, &tick, &draw };

