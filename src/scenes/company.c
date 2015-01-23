// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <gfx/company_bg.h>
#include <src/lib/all.h>
#include <src/gba/all.h>
#include <src/scenes/all.h>

// memory setup
#define BG_TILEBANK       0
#define BG_MAPBANK        31

// source tiles and maps
#define BG_TILESLEN       company_bg_TilesLen
#define BG_TILES          (Tile4*)&company_bg_Tiles
#define BG_MAPLEN         company_bg_MapLen
#define BG_MAP            (Uint16*)&company_bg_Map
#define BG_PALETTE        (Uint16*)&company_bg_Pal

// Player input
#define NEXT_KEYS         (INPUT_KEY_START | INPUT_KEY_SELECT | \
                           INPUT_KEY_A | INPUT_KEY_B)

#define DISPLAY_DURATION  (60 * 5)

Uint32 company_ttl;

static void init(){
  company_ttl = DISPLAY_DURATION;
  gfx_reg_display = GFX_DISPLAY_MODE0 | GFX_DISPLAY_BG0;
  gfx_reg_bg0 = GFX_BG_TILE_MEM(BG_TILEBANK) | GFX_BG_MAP_MEM(BG_MAPBANK) |
                GFX_BG_REG_32x32 | GFX_BG_4BPP;

  // copy tiles, map and palette
  memcpy(tile_bank_mem_4bpp(BG_TILEBANK), BG_TILES, BG_TILESLEN);
  memcpy(map_bank_mem(BG_MAPBANK), BG_MAP, BG_MAPLEN);
  pal_set_bg(BG_PALETTE);
}

static void tick(){
  if (!company_ttl or input_key_down(NEXT_KEYS)){
    scene_set(&scenes_panel);
  }
  company_ttl--;
}

const Scene scenes_company = { true, &init, &tick, NULL };
