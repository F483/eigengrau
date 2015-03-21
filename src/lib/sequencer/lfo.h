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
  LFO_WAVE_TRIANGLE = 4,
  LFO_WAVE_SAW_INC  = 5,
  LFO_WAVE_SAW_DEC  = 6
} LFOWave;
#define LFO_WAVE_COUNT    7

typedef enum {
  LFO_A  = 0,
  LFO_B  = 1
} LFONum;
#define LFO_NUM_COUNT     2

inline Uint16 _lfo_get(SequencerTrack track, LFONum num, Uint16 shift){
  return BIT_GET((SEQUENCER_CFG_NORMAL(track).lfos[num]) >> shift, 0x000F);
}

inline void _lfo_set(SequencerTrack track, LFONum num, 
                     Uint16 shift, Uint16 value){
  BIT_CLEAR((SEQUENCER_CFG_NORMAL(track).lfos[num]), 0x000F << shift);
  BIT_SET((SEQUENCER_CFG_NORMAL(track).lfos[num]), value << shift);
}

inline Uint16 _lfo_inc(SequencerTrack track, LFONum num, 
                       Uint16 shift, Uint16 count){
  Uint16 value = _lfo_get(track, num, shift);
  value = wrap_index_next(count, value);
  _lfo_set(track, num, shift, value);
  return value;
}

inline Uint16 _lfo_dec(SequencerTrack track, LFONum num, 
                       Uint16 shift, Uint16 count){
  Uint16 value = _lfo_get(track, num, shift);
  value = wrap_index_prev(count, value);
  _lfo_set(track, num, shift, value);
  return value;
}

inline Uint16 lfo_rate_get(SequencerTrack track, LFONum num){
  return _lfo_get(track, num, LFO_RATE_SHIFT);
}

inline void lfo_rate_set(SequencerTrack track, LFONum num, Uint16 value){
  _lfo_set(track, num, LFO_RATE_SHIFT, value);
}

inline Uint16 lfo_rate_inc(SequencerTrack track, LFONum num){
  return _lfo_inc(track, num, LFO_RATE_SHIFT, LFO_VALUE_COUNT);
}

inline Uint16 lfo_rate_dec(SequencerTrack track, LFONum num){
  return _lfo_dec(track, num, LFO_RATE_SHIFT, LFO_VALUE_COUNT);
}

inline LFOWave lfo_wave_get(SequencerTrack track, LFONum num){
  return _lfo_get(track, num, LFO_WAVE_SHIFT);
}

inline void lfo_wave_set(SequencerTrack track, LFONum num, LFOWave value){
  _lfo_set(track, num, LFO_WAVE_SHIFT, value);
}

inline Uint16 lfo_wave_inc(SequencerTrack track, LFONum num){
  return _lfo_inc(track, num, LFO_WAVE_SHIFT, LFO_WAVE_COUNT);
}

inline Uint16 lfo_wave_dec(SequencerTrack track, LFONum num){
  return _lfo_dec(track, num, LFO_WAVE_SHIFT, LFO_WAVE_COUNT);
}

inline Uint16 lfo_min_get(SequencerTrack track, LFONum num){
  return _lfo_get(track, num, LFO_MIN_SHIFT);
}

inline void lfo_min_set(SequencerTrack track, LFONum num, Uint16 value){
  _lfo_set(track, num, LFO_MIN_SHIFT, value);
}

inline Uint16 lfo_min_inc(SequencerTrack track, LFONum num){
  return _lfo_inc(track, num, LFO_MIN_SHIFT, LFO_VALUE_COUNT);
}

inline Uint16 lfo_min_dec(SequencerTrack track, LFONum num){
  return _lfo_dec(track, num, LFO_MIN_SHIFT, LFO_VALUE_COUNT);
}

inline Uint16 lfo_max_get(SequencerTrack track, LFONum num){
  return _lfo_get(track, num, LFO_MAX_SHIFT);
}

inline void lfo_max_set(SequencerTrack track, LFONum num, Uint16 value){
  _lfo_set(track, num, LFO_MAX_SHIFT, value);
}

inline Uint16 lfo_max_inc(SequencerTrack track, LFONum num){
  return _lfo_inc(track, num, LFO_MAX_SHIFT, LFO_VALUE_COUNT);
}

inline Uint16 lfo_max_dec(SequencerTrack track, LFONum num){
  return _lfo_dec(track, num, LFO_MAX_SHIFT, LFO_VALUE_COUNT);
}

#endif
