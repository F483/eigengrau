// Copyright (c) 2014 Fabian Barkhau <fabian.barkhau@gmail.com> 
// License: MIT (see LICENSE.TXT file)  

#include <gfx/bg_company.h>
#include <src/gbx.h>
#include <src/scenes.h>

// memory setup
#define BG_TILEBANK       0
#define BG_MAPBANK        31

// source tiles and maps
#define BG_TILESLEN       bg_company_TilesLen
#define BG_TILES          (Tile8*)&bg_company_Tiles
#define BG_MAPLEN         bg_company_MapLen
#define BG_MAP            (Uint16*)&bg_company_Map
#define BG_PALETTE        (Uint16*)&bg_company_Pal

// Player input
#define NEXT_KEYS         (INPUT_KEY_START | INPUT_KEY_SELECT | \
                           INPUT_KEY_A | INPUT_KEY_B)

#define DISPLAY_DURATION  (60 * 5)

Uint32 company_ttl;

static void load(){
  company_ttl = DISPLAY_DURATION;
  gfx_reg_display = GFX_DISPLAY_MODE0 | GFX_DISPLAY_BG0;
  gfx_reg_bg0 = GFX_BG_TILE_MEM(BG_TILEBANK) | GFX_BG_MAP_MEM(BG_MAPBANK) | 
                GFX_BG_REG_32x32 | GFX_BG_8BPP;

  // copy tiles, map and palette
  memcpy(tile_bank_mem_8bpp(BG_TILEBANK), BG_TILES, BG_TILESLEN);
  memcpy(map_bank_mem(BG_MAPBANK), BG_MAP, BG_MAPLEN);
  pal_set_bg(BG_PALETTE);
}

static void tick(){
  if (!company_ttl or input_key_down(NEXT_KEYS)){
    scene_set(NULL);
  } 
  company_ttl--;
}

static void draw(){
  //
}

const Scene company = {true, true, &load, &tick, &draw};

