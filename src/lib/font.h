// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_FONT_H
#define LIB_FONT_H

#include <src/lib/common.h>
#include <src/gba/tile.h>
#include <src/gba/map.h>


#define FONT_NUMBERS_OFFSET 16

inline void font_print_i3(Uint16 font_tiles, Uint16 palbank, Uint16* map_mem,
                          Uint16 x, Uint16 y, Uint16 num){
  // iter 0
  Uint16 tileid = font_tiles + FONT_NUMBERS_OFFSET + (num % 10);
  INDEX_2D(x + 2, y, 32, map_mem) = tme_build(tileid, 0, 0, palbank);

  // iter 1
  num /= 10;
  tileid = font_tiles + FONT_NUMBERS_OFFSET + (num % 10);
  INDEX_2D(x + 1, y, 32, map_mem) = tme_build(tileid, 0, 0, palbank);

  // iter 2
  num /= 10;
  tileid = font_tiles + FONT_NUMBERS_OFFSET + (num % 10);
  INDEX_2D(x, y, 32, map_mem) = tme_build(tileid, 0, 0, palbank);
}

inline void font_print_i2(Uint16 font_tiles, Uint16 palbank, Uint16* map_mem,
                          Uint16 x, Uint16 y, Uint16 num){
  // iter 0
  Uint16 tileid = font_tiles + FONT_NUMBERS_OFFSET + (num % 10);
  INDEX_2D(x + 1, y, 32, map_mem) = tme_build(tileid, 0, 0, palbank);

  // iter 1
  num /= 10;
  tileid = font_tiles + FONT_NUMBERS_OFFSET + (num % 10);
  INDEX_2D(x, y, 32, map_mem) = tme_build(tileid, 0, 0, palbank);
}

inline void font_print(Uint16 font_tiles, Uint16 palbank, Uint16* map_mem,
                       Uint16 x, Uint16 y, const char* str){
  Uint16 c = 0;
  Uint16 cx = x;
  Uint16 cy = y;
  Uint16 index_offset = font_tiles - 32;
  Uint16 tme_palbank = TME_PALBANK(palbank);
  while((c=*str++) != '\0'){ // TODO faster with duff's device?
    if (c == '\n') { // new line char
      cx = x;
      cy++;
    } else {
      INDEX_2D(cx, cy, 32, map_mem) = (c + index_offset) | tme_palbank;
      cx++; // move curser
    }
  }

}

/*
inline void font_printf(Uint16 font_tiles, Uint16 palbank, Uint16* map_mem,
                        Uint16 x, Uint16 y, const char* format, ...){
  va_list args;
  va_start(args, format);
  vsnprintf((char*)&_printf_buffer, _PRINTF_BUFFER_SIZE, format, args);
  font_print(font_tiles, palbank, map_mem, x, y, (char*)&_printf_buffer);
  va_end(args);
}
*/

inline void font_clear_screen(Uint16 font_tiles, Uint16* map_mem){
  Uint32 eraser = (Uint32)font_tiles | (Uint32)font_tiles << 16;
  Uint32* mem = (Uint32*)map_mem;
  // only clear first 20 lines that can be seen
  for(int i = 0; i < (20 * 16); i += 16){
    // unroll to clear entire line at once
    mem[i +  0] = eraser; mem[i +  1] = eraser; mem[i +  2] = eraser;
    mem[i +  3] = eraser; mem[i +  4] = eraser; mem[i +  5] = eraser;
    mem[i +  6] = eraser; mem[i +  7] = eraser; mem[i +  8] = eraser;
    mem[i +  9] = eraser; mem[i + 10] = eraser; mem[i + 11] = eraser;
    mem[i + 12] = eraser; mem[i + 13] = eraser; mem[i + 14] = eraser;
    // skip last one since it can never be seen
  }
}



#endif
