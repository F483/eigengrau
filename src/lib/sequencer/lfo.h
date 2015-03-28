// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_SEQUENCER_LFO_H
#define LIB_SEQUENCER_LFO_H

#include <src/lib/common.h>
#include <src/lib/sequencer/main.h>

////////////////////////////////////////////////////////////////////////////////
//                      Low Frequency Oscillator                              //
//                                                                            //
// BITS  NAME           DESCRIPTION                                           //
// 0-3   LFO_RATE_*     Rate of oscillation.                                  //
// 4-7   LFO_WAVE_*     Wave form of lfo.                                     //
// 8-11  LFO_MIN_*      Minimum oscillation value                             //
// 12-15 LFO_MAX_*      Maximum oscillation value                             //
////////////////////////////////////////////////////////////////////////////////

#define LFO_RATE_SHIFT    0
#define LFO_WAVE_SHIFT    4
#define LFO_MIN_SHIFT     8
#define LFO_MAX_SHIFT     12
#define LFO_VALUE_COUNT   16

typedef enum {
  LFO_WAVE_SINE     = 0,
  LFO_WAVE_SQUARE   = 1,
  LFO_WAVE_PULSE    = 2,
  LFO_WAVE_TRIGGER  = 3,
  LFO_WAVE_SAW_DEC  = 4,
  LFO_WAVE_TRIANGLE = 5,
  LFO_WAVE_SAW_INC  = 6
} LFOWave;
#define LFO_WAVE_COUNT    7

typedef enum {
  LFO_A  = 0,
  LFO_B  = 1,
  LFO_C  = 2,
  LFO_D  = 3,
  LFO_E  = 4,
  LFO_F  = 5,
  LFO_G  = 6,
  LFO_H  = 7
} LFONum;
#define LFO_NUM_COUNT     8

inline Uint16 _lfo_get(LFONum num, Uint16 shift){
  return BIT_GET(sequencer.lfos[num] >> shift, 0x000F);
}

inline void _lfo_set(LFONum num, Uint16 shift, Uint16 value){
  BIT_CLEAR(sequencer.lfos[num], 0x000F << shift);
  BIT_SET(sequencer.lfos[num], value << shift);
}

inline Uint16 _lfo_inc(LFONum num, Uint16 shift, Uint16 count){
  Uint16 value = _lfo_get(num, shift);
  value = wrap_index_next(count, value);
  _lfo_set(num, shift, value);
  return value;
}

inline Uint16 _lfo_dec(LFONum num, Uint16 shift, Uint16 count){
  Uint16 value = _lfo_get(num, shift);
  value = wrap_index_prev(count, value);
  _lfo_set(num, shift, value);
  return value;
}

inline Uint16 lfo_rate_get(LFONum num){
  return _lfo_get(num, LFO_RATE_SHIFT);
}

inline void lfo_rate_set(LFONum num, Uint16 value){
  _lfo_set(num, LFO_RATE_SHIFT, value);
}

inline Uint16 lfo_rate_inc(LFONum num){
  return _lfo_inc(num, LFO_RATE_SHIFT, LFO_VALUE_COUNT);
}

inline Uint16 lfo_rate_dec(LFONum num){
  return _lfo_dec(num, LFO_RATE_SHIFT, LFO_VALUE_COUNT);
}

inline LFOWave lfo_wave_get(LFONum num){
  return _lfo_get(num, LFO_WAVE_SHIFT);
}

inline void lfo_wave_set(LFONum num, LFOWave value){
  _lfo_set(num, LFO_WAVE_SHIFT, value);
}

inline Uint16 lfo_wave_inc(LFONum num){
  return _lfo_inc(num, LFO_WAVE_SHIFT, LFO_WAVE_COUNT);
}

inline Uint16 lfo_wave_dec(LFONum num){
  return _lfo_dec(num, LFO_WAVE_SHIFT, LFO_WAVE_COUNT);
}

inline Uint16 lfo_min_get(LFONum num){
  return _lfo_get(num, LFO_MIN_SHIFT);
}

inline void lfo_min_set(LFONum num, Uint16 value){
  _lfo_set(num, LFO_MIN_SHIFT, value);
}

inline Uint16 lfo_min_inc(LFONum num){
  return _lfo_inc(num, LFO_MIN_SHIFT, LFO_VALUE_COUNT);
}

inline Uint16 lfo_min_dec(LFONum num){
  return _lfo_dec(num, LFO_MIN_SHIFT, LFO_VALUE_COUNT);
}

inline Uint16 lfo_max_get(LFONum num){
  return _lfo_get(num, LFO_MAX_SHIFT);
}

inline void lfo_max_set(LFONum num, Uint16 value){
  _lfo_set(num, LFO_MAX_SHIFT, value);
}

inline Uint16 lfo_max_inc(LFONum num){
  return _lfo_inc(num, LFO_MAX_SHIFT, LFO_VALUE_COUNT);
}

inline Uint16 lfo_max_dec(LFONum num){
  return _lfo_dec(num, LFO_MAX_SHIFT, LFO_VALUE_COUNT);
}

#endif
