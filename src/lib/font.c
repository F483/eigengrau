// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/gba/all.h>
#include <src/lib/all.h>
#include <stdio.h>
#include <stdarg.h>

#define FONT_NUMBERS_OFFSET 16

#define SCREEN_W            30
#define SCREEN_H            21 // +1 for \n chars
#define PRINTF_BUFFER_SIZE  (SCREEN_W * SCREEN_H)

char* printf_buffer[PRINTF_BUFFER_SIZE];


void font_print_i3(const Font* font, Uint16 x, Uint16 y, Uint16 num){

  // iter 0
  Uint16 tileid = font->tiles + FONT_NUMBERS_OFFSET + (num % 10);
  INDEX_2D(x + 2, y, 32, font->map) = tme_build(tileid, 0, 0, font->palbank);

  // iter 1
  num /= 10;
  tileid = font->tiles + FONT_NUMBERS_OFFSET + (num % 10);
  INDEX_2D(x + 1, y, 32, font->map) = tme_build(tileid, 0, 0, font->palbank);

  // iter 2
  num /= 10;
  tileid = font->tiles + FONT_NUMBERS_OFFSET + (num % 10);
  INDEX_2D(x, y, 32, font->map) = tme_build(tileid, 0, 0, font->palbank);
}

void font_print_i2(const Font* font, Uint16 x, Uint16 y, Uint16 num){

  // iter 0
  Uint16 tileid = font->tiles + FONT_NUMBERS_OFFSET + (num % 10);
  INDEX_2D(x + 1, y, 32, font->map) = tme_build(tileid, 0, 0, font->palbank);

  // iter 1
  num /= 10;
  tileid = font->tiles + FONT_NUMBERS_OFFSET + (num % 10);
  INDEX_2D(x, y, 32, font->map) = tme_build(tileid, 0, 0, font->palbank);
}

void font_print(const Font* font, Uint16 x, Uint16 y, const char* str){
  Uint16 c = 0;
  Uint16 cx = x;
  Uint16 cy = y;
  Uint16 index_offset = font->tiles - 32;
  Uint16 tme_palbank = TME_PALBANK(font->palbank);
  while((c=*str++) != '\0'){
    if (c == '\n') { // new line char
      cx = x;
      cy++;
    } else {
      INDEX_2D(cx, cy, 32, font->map) = (c + index_offset) | tme_palbank;
      cx++; // move curser
    }
  }
}

void font_printf(const Font* font, Uint16 x, Uint16 y, const char* format, ...){
  va_list args;
  va_start(args, format);
  vsnprintf((char*)&printf_buffer, PRINTF_BUFFER_SIZE, format, args);
  font_print(font, x, y, (char*)&printf_buffer);
  va_end(args);
}

void font_clear_screen(const Font* font){
  Uint32 eraser = (Uint32)font->tiles | (Uint32)font->tiles << 16;
  Uint32* mem = (Uint32*)font->map;
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


