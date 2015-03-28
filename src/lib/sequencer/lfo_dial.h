// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef LIB_SEQUENCER_LFO_DIAL_H
#define LIB_SEQUENCER_LFO_DIAL_H
/*
////////////////////////////////////////////////////////////////////////////////
//                      Low Frequency Oscillator                              //
//                                                                            //
// BITS  NAME               DESCRIPTION                                       //
// 0-3   LFO_DIAL_VALUE*    Value when not using lfo as source.               //
// 4     LFO_DIAL_SOURCE*   Flag where to read value from.                    //
// 5-7   LFO_DIAL_NUM*      LFO to read value from.                           //
////////////////////////////////////////////////////////////////////////////////


typedef enum {
  LFO_DIAL_VAL  = 0,
  LFO_DIAL_LFO  = 1
} LfoDialSource;
#define LFO_DIAL_SOURCE_COUNT   2

inline LfoDialSource lfo_dial_source_get(Uint8 data){
  return False; // TODO implement
}

inline Uint8 lfo_dial_source_set(Uint8, LfoDialSource source){
  return 0; // TODO implement
}

inline Uint8 lfo_dial_source_toggle(Uint8 data){
  return 0; // TODO implement
}

inline Uint8 lfo_dial_value_get(Uint8 data){
  return 0; // TODO implement
}

inline Uint8 lfo_dial_value_set(Uint8 data, Uint8 value){
  return 0; // TODO implement
}

inline Uint8 lfo_dial_num_get(Uint8 data){
  return 0; // TODO implement
}

inline Uint8 lfo_dial_num_set(Uint8 data, Uint8 value){
  return 0; // TODO implement
}

inline Uint8 lfo_dial_read(Uint8 data){
  return 0; // TODO implement
}

inline void lfo_dial_print(const Font* font_dial, const Font* font_lfo, 
                           Uint16 x, Uint16 y, Uint8 data){

  
  // font_print_dial(const Font* font, Uint16 x, Uint16 y, Uint16 num);
}
*/
#endif
