// Copyright (c) 2014 Fabian Barkhau <fabian.barkhau@gmail.com> 
// License: MIT (see LICENSE.TXT file)  

#ifndef GBX_SCENE_H
#define GBX_SCENE_H

typedef void  (*SceneLoadFunc)();
typedef void  (*SceneTickFunc)();
typedef void  (*SceneDrawFunc)();

typedef struct {
  Bool          reset_gfx; // reset gfx settings to defaults before loading
  Bool          reset_snd; // reset snd settings to defaults before loading
  SceneLoadFunc load_func; // load scene data
  SceneTickFunc tick_func; // update scene state
  SceneDrawFunc draw_func; // draw scene state
  //Transition  on_enter;
  //Transition  on_exit;
} Scene;

void scene_set(const Scene* scene); // will be loaded during next vblank
void scene_run(); // main game loop

extern Uint32 scene_frame; // incremented every frame and reset before loading
extern Uint32 scene_total_frames; // incremented every frame

extern Uint32 scene_vcount_draw; // vcount at end of draw 
extern Uint32 scene_vcount_tick; // vcount at end of tick

// TODO maybe change scene_*_frame fps to float for 0.5 fps etc

/**
 * returns true once every @param fps
 */
inline Bool scene_trigger_frame(Uint32 fps){
  return scene_frame % (60 / fps) == 0;
}


inline Uint32 scene_animation_frame(Uint32 fps, Uint32 frames){
  return (scene_frame / (60 / fps)) % frames;
}

/**
 * Toggles at the rate of @param fps.
 */
inline Bool scene_toggle_frame(Uint32 fps){
  return scene_animation_frame(fps, 2);
}

#endif
