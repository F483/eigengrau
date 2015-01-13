// Copyright (c) 2014 Fabian Barkhau <fabian.barkhau@gmail.com> 
// License: MIT (see LICENSE.TXT file)  

#include <src/lib/all.h>
#include <src/gba/all.h>
#include <src/scenes/all.h>

int main(){
  sav_init(0xFABE0002); // init with nonce for sperotactics
  scene_set(&company);
  scene_run();
  return 0;
}
