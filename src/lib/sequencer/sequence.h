// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_SEQUENCER_SEQUENCE_H
#define LIB_SEQUENCER_SEQUENCE_H

#include <src/lib/common.h>

#define SEQUENCE_STEP_SND_CUSTOM_SOUND    BIT_NUM(0)
#define SEQUENCE_STEP_SND_FM_FREQ_TIMED   SND_FREQ_TIMED // BIT 14
#define SEQUENCE_STEP_SND_FM_FREQ_RESET   SND_FREQ_RESET // BIT 15

typedef struct {
  Uint16          flags;
  Uint16          fm_sweep;
  Uint16          fm_ctrl;
} SequenceStepSnd;

typedef struct {
  Uint16          fm_rate;
  //SequenceStepSnd sound;
} SequenceStep;

typedef struct {
  SequenceStep    steps[64];
  SequenceStepSnd standard;
} Sequence;



#endif
