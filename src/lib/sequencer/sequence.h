// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_SEQUENCER_SEQUENCE_H
#define LIB_SEQUENCER_SEQUENCE_H

#include <src/lib/common.h>

typedef struct {
  Uint8  length; // 1, 2 or 4 bars
  Uint16 rate[64];
} Sequence;

#endif
