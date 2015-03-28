// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef PANEL_BUNDLE_H
#define PANEL_BUNDLE_H

#include <src/lib/all.h>
#include <src/scenes/panel/group.h>

typedef struct {
  Uint32  size;
  Uint32  selected;
  Group** groups;
} Bundle;

void bundle_draw(Bundle* bundle);
void bundle_tick(Bundle* bundle);

extern Bundle bundles[SEQUENCER_TRACK_COUNT];

#endif
