// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_SEQUENCER_MAIN_H
#define LIB_SEQUENCER_MAIN_H

#include <src/gba/snd.h>
#include <src/lib/common.h>

#define SEQUENCER_TRACK_COUNT         6
#define SEQUENCER_STEP_COUNT          64

typedef enum {
  SQR1  = 0,
  SQR2  = 1,
  WAVE  = 2,
  NOISE = 3,
  SMPL1 = 4,
  SMPL2 = 5
} SequencerTrack;

typedef struct {
  // Uint16            flags; // TODO
  // Uint16            fm_sweep; // TODO
  Uint16            fm_ctrl;
} SequencerSetup;

typedef struct {
  // Uint16            fm_rate; // TODO
  // SequencerSetup    custom; // TODO
} SequencerStep;

typedef struct {
  // SequencerStep     steps[SEQUENCER_STEP_COUNT]; // TODO
  SequencerSetup    normal;
} SequcencerTrack;

typedef struct {
  SequcencerTrack   tracks[SEQUENCER_TRACK_COUNT];
  Uint16            lfos[8]; // TODO use label
} Sequencer;

void sequencer_init();

extern Sequencer sequencer;

inline SequencerSetup* sequencer_active_setup(SequencerTrack track){
  return &(sequencer.tracks[track].normal); // TODO check custom step setup
}


#endif
