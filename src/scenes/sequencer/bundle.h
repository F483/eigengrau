// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef SCENES_SEQUENCER_BUNDLE_H
#define SCENES_SEQUENCER_BUNDLE_H

#include <src/lib/sequencer/tracks.h>
#include <src/scenes/sequencer/group.h>

typedef struct {
  Uint32  size;
  Uint32  selected;
  Group** groups;
} Bundle;

void bundle_draw(Bundle* bundle);
void bundle_tick(Bundle* bundle);

extern Bundle bundles[SEQUENCER_TRACK_CNT];

#endif
