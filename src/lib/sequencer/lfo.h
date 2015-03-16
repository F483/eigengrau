// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_SEQUENCER_LFO_H
#define LIB_SEQUENCER_LFO_H

#include <src/lib/sequencer/sequence.h>

////////////////////////////////////////////////////////////////////////////////
//                      Low Frequency Oscillator                              //
//                                                                            //
// BITS  NAME           DESCRIPTION                                           //
// 0-3   LFO_RATE_*     Tone generator volume                                 //
// 4-7   LFO_WAVE_*     DMA Sound A Volume (50% | 100%)                       //
////////////////////////////////////////////////////////////////////////////////

typedef enum {
  LFO_WAVE_SINE     = 0,
  LFO_WAVE_SQUARE   = 1,
  LFO_WAVE_PULSE    = 2,
  LFO_WAVE_TRIANGLE = 3,
  LFO_WAVE_SAW_INC  = 4,
  LFO_WAVE_SAW_DEC  = 5
} LFOWave;

inline Uint8 lfo_build(Uint8 rate, LFOWave wave){
  // TODO implement
}

inline LFOWave lfo_get_wave(Uint8 lfo){
  // TODO implement
}

inline Uint8 lfo_get_rate(Uint8 lfo){
  // TODO implement
}

#endif
