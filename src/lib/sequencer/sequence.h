// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_SEQUENCER_SEQUENCE_H
#define LIB_SEQUENCER_SEQUENCE_H

#include <src/gba/snd.h>
#include <src/lib/common.h>

#define SEQUENCE_CFG_CUSTOM_SOUND    BIT_NUM(0)
#define SEQUENCE_CFG_FM_FREQ_TIMED   SND_FREQ_TIMED // BIT 14
#define SEQUENCE_CFG_FM_FREQ_RESET   SND_FREQ_RESET // BIT 15

typedef struct {
  Uint16          flags;
  Uint16          fm_sweep;
  Uint16          fm_ctrl;
  Uint16          lfos[2];
} SequenceCfg;

typedef struct {
  Uint16          fm_rate;
  //SequenceCfg   custom;
} SequenceStep;

typedef struct {
  SequenceStep    steps[64];
  SequenceCfg     normal;
} Sequence;

#endif
