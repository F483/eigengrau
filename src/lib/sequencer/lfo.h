// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_SEQUENCER_LFO_H
#define LIB_SEQUENCER_LFO_H

#include <src/lib/sequencer/sequence.h>
#include <src/lib/sequencer/tracks.h>

////////////////////////////////////////////////////////////////////////////////
//                      Low Frequency Oscillator                              //
//                                                                            //
// BITS  NAME           DESCRIPTION                                           //
// 0-3   LFO_A_RATE_*   Rate of lfo a.                                        //
// 4-7   LFO_A_WAVE_*   Wave form of lfo a.                                   //
// 8-11  LFO_B_RATE_*   Rate of lfo b.                                        //
// 12-15 LFO_B_WAVE_*   Wave form of lfo b.                                   //
////////////////////////////////////////////////////////////////////////////////

#define LFO_WAVE_COUNT 6
#define LFO_RATE_COUNT 16

typedef enum {
  LFO_WAVE_SINE     = 0,
  LFO_WAVE_SQUARE   = 1,
  LFO_WAVE_PULSE    = 2,
  LFO_WAVE_TRIANGLE = 3,
  LFO_WAVE_SAW_INC  = 4,
  LFO_WAVE_SAW_DEC  = 5
} LFOWave;

typedef enum {
  LFO_A  = 0,
  LFO_B  = 1,
} LFONum;

inline Uint16 _lfo_lshift(Uint16 value, LFONum lfo_num, Uint16 prop_shift){
  return value << (prop_shift + (8 * lfo_num));
}

inline Uint16 _lfo_rshift(Uint16 value, LFONum lfo_num, Uint16 prop_shift){
  return value >> (prop_shift + (8 * lfo_num));
}

inline void sequencer_lfo_wave_set(SequencerTrack track, LFONum lfo_num, 
                                   LFOWave wave){
  BIT_CLEAR(SEQUENCER_CFG_NORMAL(track).lfos, _lfo_lshift(0x000F, lfo_num, 4));
  BIT_SET(SEQUENCER_CFG_NORMAL(track).lfos, _lfo_lshift(wave, lfo_num, 4));
}

inline void sequencer_lfo_rate_set(SequencerTrack track, LFONum lfo_num,
                                   Uint16 rate){
  BIT_CLEAR(SEQUENCER_CFG_NORMAL(track).lfos, _lfo_lshift(0x000F, lfo_num, 0));
  BIT_SET(SEQUENCER_CFG_NORMAL(track).lfos, _lfo_lshift(rate, lfo_num, 0));
}

inline LFOWave sequencer_lfo_wave_get(SequencerTrack track, LFONum lfo_num){
  Uint16 bits = _lfo_rshift(SEQUENCER_CFG_NORMAL(track).lfos, lfo_num, 4);
  return BIT_GET(bits, 0x000F);
}

inline Uint16 sequencer_lfo_rate_get(SequencerTrack track, LFONum lfo_num){
  Uint16 bits = _lfo_rshift(SEQUENCER_CFG_NORMAL(track).lfos, lfo_num, 0);
  return BIT_GET(bits, 0x000F);
}

inline void sequencer_lfo_wave_next(SequencerTrack track, LFONum lfo_num){
  Uint8 wave = sequencer_lfo_wave_get(track, lfo_num);
  sequencer_lfo_wave_set(track, lfo_num, wrap_index_next(LFO_WAVE_COUNT, wave));
}

inline void sequencer_lfo_wave_prev(SequencerTrack track, LFONum lfo_num){
  Uint8 wave = sequencer_lfo_wave_get(track, lfo_num);
  sequencer_lfo_wave_set(track, lfo_num, wrap_index_prev(LFO_WAVE_COUNT, wave));
}

inline void sequencer_lfo_rate_next(SequencerTrack track, LFONum lfo_num){
  Uint8 rate = sequencer_lfo_rate_get(track, lfo_num);
  sequencer_lfo_rate_set(track, lfo_num, wrap_index_next(LFO_RATE_COUNT, rate));
}

inline void sequencer_lfo_rate_prev(SequencerTrack track, LFONum lfo_num){
  Uint8 rate = sequencer_lfo_rate_get(track, lfo_num);
  sequencer_lfo_rate_set(track, lfo_num, wrap_index_prev(LFO_RATE_COUNT, rate));
}

#endif
