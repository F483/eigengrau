// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_FONT_H
#define LIB_FONT_H

#include <src/lib/common.h>

typedef struct {
  Uint16  tiles;
  Uint16  palbank;
  Uint16* map;
} Font;

void font_print_i3(const Font* font, Uint16 x, Uint16 y, Uint16 num);
void font_print_i2(const Font* font, Uint16 x, Uint16 y, Uint16 num);
void font_print_i1(const Font* font, Uint16 x, Uint16 y, Uint16 num);
void font_print_dial(const Font* font, Uint16 x, Uint16 y, Uint16 num);
void font_print(const Font* font, Uint16 x, Uint16 y, const char* str);
void font_printf(const Font* font, Uint16 x, Uint16 y, const char* format, ...);
void font_clear_screen(const Font* font);

#endif
