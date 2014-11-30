// Copyright (c) 2014 Fabian Barkhau <fabian.barkhau@gmail.com> 
// License: MIT (see LICENSE.TXT file)  

#include <src/gbx.h>
#include <src/scenes.h>

int main(){
  sav_init(0xFABE0002); // init with nonce for sperotactics
  scene_set(&company);
  scene_run();
  return 0;
}
