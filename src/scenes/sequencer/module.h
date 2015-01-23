// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#ifndef SCENES_SEQUENCER_MODULE_H
#define SCENES_SEQUENCER_MODULE_H

#include <src/lib/all.h>

typedef void  (*ModuleTick)(Bool active);
typedef void  (*ModuleDraw)(Bool active);

#define MODULE_GROUP_KEYS_NEXT      INPUT_KEY_DOWN
#define MODULE_GROUP_KEYS_PREV      INPUT_KEY_UP

typedef struct {
  ModuleTick   tick;
  ModuleDraw   draw;
} Module;

typedef struct {
  Uint16  size;
  Uint16  selected;
  const Module* modules;
} ModuleGroup;

inline void module_group_draw(ModuleGroup* group){
  for(int i = 0; i < group->size; i++){
    group->modules[i].draw(i == group->selected);
  }
}

inline void module_group_tick(ModuleGroup* group){
  if(input_key_hit(MODULE_GROUP_KEYS_NEXT)){
    group->selected = wrap_index_next(group->size, group->selected);
  } else if (input_key_hit(MODULE_GROUP_KEYS_PREV)){
    group->selected = wrap_index_prev(group->size, group->selected);
  }
  for(int i = 0; i < group->size; i++){
    group->modules[i].tick(i == group->selected);
  }
}

#endif
