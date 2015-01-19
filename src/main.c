// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/lib/all.h>
#include <src/gba/all.h>
#include <src/scenes/all.h>

int main(){
  sav_init(0xFABE0003); // init with nonce for eigengrau
  scene_set(&scenes_company);
  scene_run();
  return 0;
}
