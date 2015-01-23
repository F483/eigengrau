// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef SCENES_SEQUENCER_MODULE_H
#define SCENES_SEQUENCER_MODULE_H

#include <src/lib/all.h>

typedef void  (*ModuleTick)(Bool active);
typedef void  (*ModuleDraw)(Bool active);

typedef struct {
  ModuleTick   tick;
  ModuleDraw   draw;
} Module;

#endif
