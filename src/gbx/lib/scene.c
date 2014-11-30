// Copyright (c) 2014 Fabian Barkhau <fabian.barkhau@gmail.com> 
// License: MIT (see LICENSE.TXT file)  

#include <src/gbx.h>

Scene* scene_current = NULL;
Scene* scene_next = NULL;
Uint32 scene_frame = 0;
Uint32 scene_total_frames = 0;
Uint32 scene_vcount_draw = 0;
Uint32 scene_vcount_tick = 0;

void scene_set(const Scene* scene){
  scene_next = (Scene*)scene; // load in main loop to use full vblank time
}

void scene_change(){
  scene_current = scene_next;

  if(!scene_current or scene_current->reset_snd){
    snd_reset();
  }
  if(!scene_current or scene_current->reset_gfx){
    gfx_reset();
    pal_reset();
    obj_reset();
  }
  scene_frame = 0;
  scene_vcount_draw = 0;
  scene_vcount_tick = 0;

  // load scene
  if(scene_current and scene_current->load_func){
    scene_current->load_func();
  }
}

void scene_run(){
  while(scene_current or scene_next){
    gfx_vsync_busywait(); // TODO use interupts instead

    // change scene if needed
    if (scene_current != scene_next){
      scene_change();
      continue; // skip frame on change to give draw_func full vblank time
    }

    // drawing must be done in vblank phase
    scene_current->draw_func();
    scene_vcount_draw = gfx_reg_vcount;

    // updateing state can be done in vdraw phase as well
    input_poll();
    scene_current->tick_func();
    scene_vcount_tick = gfx_reg_vcount;

    scene_frame++;
    scene_total_frames++;
  }
}
