// Copyright (c) 2014 Fabian Barkhau <fabian.barkhau@gmail.com> 
// License: MIT (see LICENSE.TXT file)  

#ifndef LIB_MATH_H
#define LIB_MATH_H

#include <src/lib/common.h>
#include <src/gba/bios.h>

#define PI            3.14159265358979323846

#define SQUARED(n)    ((n) * (n))

inline Sint32 rescale(Sint32 num, Sint32 old_min, Sint32 old_max,
                      Sint32 new_min, Sint32 new_max){
  // normalize
  Sint32 old_len = old_max - old_min;
  Sint32 new_len = new_max - new_min;
  Sint32 old_pos = num - old_min;

  // calculate relative position
  Sint32 new_pos = 0;
  if (old_len != 0){ // avoid division by zero
    new_pos = (new_len * old_pos) / old_len;
  } 

  // denormalize
  return new_pos + new_min;
}

inline Uint32 isqrt(Uint32 n){
  return Sqrt(n);
}

#endif // LIB_MATH_H
