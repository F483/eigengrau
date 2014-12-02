// Copyright (c) 2014 Fabian Barkhau <fabian.barkhau@gmail.com> 
// License: MIT (see LICENSE.TXT file)  

#ifndef LIB_SCENE_H
#define LIB_SCENE_H

#include <src/lib/common.h>

//////////////////////
// SCENE TRANSITION //
//////////////////////

#define SCENE_TRANS(draw, lock, time)  { draw, lock, time, time }
#define SCENE_TRANS_NONE               SCENE_TRANS(NULL, false, 0)

typedef void (*TransDrawFunc)(Uint32 time, Uint32 ttl);

typedef struct {
  TransDrawFunc draw; // draw func (called after scene.draw)
  Bool          lock; // disable user input while transitoning
  Uint32        time; // total time in frames
  Uint32        ttl;  // remaning time in frames
} SceneTrans;


///////////
// SCENE //
///////////

typedef void  (*SceneLoad)();
typedef void  (*SceneTick)();
typedef void  (*SceneDraw)();

typedef struct {
  Bool        reset;  // reset snd and gfx to defaults before loading
  SceneLoad   load;   // load scene data (called before transition draw)
  SceneTick   tick;   // update scene state
  SceneDraw   draw;   // draw scene state
  SceneTrans  enter;  // enter scene transition
  SceneTrans  exit;   // exit scene transition
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
