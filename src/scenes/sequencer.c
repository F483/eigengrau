// Copyright (c) 2014 Fabian Barkhau <fabian.barkhau@gmail.com> 
// License: MIT (see LICENSE.TXT file)  

#include <gfx/sequencer_bg.h>
#include <src/lib/all.h>
#include <src/gba/all.h>
#include <src/scenes/all.h>

// memory setup
#define BG_TILEBANK       0
#define BG_MAPBANK        31

// source tiles and maps
#define BG_TILESLEN       sequencer_bg_TilesLen
#define BG_TILES          (Tile8*)&sequencer_bg_Tiles
#define BG_MAPLEN         sequencer_bg_MapLen
#define BG_MAP            (Uint16*)&sequencer_bg_Map
#define BG_PALETTE        (Uint16*)&sequencer_bg_Pal

static void load(){
  gfx_reg_display = GFX_DISPLAY_MODE0 | GFX_DISPLAY_BG0;
  gfx_reg_bg0 = GFX_BG_TILE_MEM(BG_TILEBANK) | GFX_BG_MAP_MEM(BG_MAPBANK) | 
                GFX_BG_REG_32x32 | GFX_BG_8BPP;

  // copy tiles, map and palette
  memcpy(tile_bank_mem_8bpp(BG_TILEBANK), BG_TILES, BG_TILESLEN);
  memcpy(map_bank_mem(BG_MAPBANK), BG_MAP, BG_MAPLEN);
  pal_set_bg(BG_PALETTE);
}

const Scene sequencer = { true, &load, NULL, NULL, SCENE_TRANS_NONE, SCENE_TRANS_NONE };
