// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef GBA_MAP_H
#define GBA_MAP_H

#include <src/lib/common.h>
#include <src/gba/gfx.h>


////////////////////////////////////////////////////////////////////////////////
//                        MEMORY LAYOUT                                       //
//                                                                            //
// gfx_mem_vram + 0x0000 0x4000 0x8000 0xC000 0x10000 0x14000                 //
// TILE_MEM       0      1      2      3      OBJ     OBJM3                   //
// MAP_MEM        0....7 8...15 16..23 24..31                                 //
////////////////////////////////////////////////////////////////////////////////

#define MAP_BANK_COUNT    32
#define MAP_BANK_SIZE     0x0800 // bytes (2kb)
#define MAP_BANK_MEM(i)   (&gfx_mem_vram[((MAP_BANK_SIZE/2)*(i))])

inline Uint16* map_bank_mem(Uint16 i){
  return MAP_BANK_MEM(i);
}


////////////////////////////////////////////////////////////////////////////////
//                        TILE MAP ENTRIES                                    //
//                                                                            //
// BITS NAME              DESCRIPTION                                         //
// 0-9  TME_TILE_ID(n)    Tile index.                                         //
// A    TME_HFLIP         Horizontal flip.                                    //
// B    TME_VFLIP         Vertical flip.                                      //
// C-F  TME_PALBANK(n)    Palette bank index for 4bpp tiles.                  //
////////////////////////////////////////////////////////////////////////////////

#define TME_TILE_ID_MASK  0x03FF

#define TME_HFLIP         0x0400  // Horizontal flip
#define TME_VFLIP         0x0800  // Vertical flip

#define TME_PALBANK_MASK  0xF000
#define TME_PALBANK_SHIFT 12
#define TME_PALBANK(n)    ((n) << TME_PALBANK_SHIFT)

inline Uint16 tme_build(Uint16 tileid, Uint16 hflip,
                        Uint16 vflip, Uint16 palbank){
  return tileid bitor hflip bitor vflip bitor (palbank << TME_PALBANK_SHIFT);
}

#endif
