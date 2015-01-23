// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef PANEL_GROUP_H
#define PANEL_GROUP_H

#include <src/scenes/panel/module.h>

typedef struct {
  Uint32        size;
  Uint32        selected;
  const Module* modules;
} Group;

void group_draw(Group* group, Bool active);
void group_tick(Group* group, Bool active);

#endif
