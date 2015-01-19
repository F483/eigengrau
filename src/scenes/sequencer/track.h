// Copyright (c) 2014 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE.TXT file)

#ifndef SCENES_SEQUENCER_TRACK_H
#define SCENES_SEQUENCER_TRACK_H

#include <src/lib/all.h>
#include <src/scenes/sequencer/track.h>
#include <src/lib/sequencer/track.h>

void scenes_sequencer_track_load();
void scenes_sequencer_track_tick();
void scenes_sequencer_track_draw();

extern SequencerTrack scenes_sequencer_track_selected;

#endif
