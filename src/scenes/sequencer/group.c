// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/gba/all.h>
#include <src/lib/all.h>
#include <src/scenes/sequencer/group.h>

#define GROUP_KEYS_NEXT      INPUT_KEY_DOWN
#define GROUP_KEYS_PREV      INPUT_KEY_UP

void group_draw(Group* group, Bool active){
  for(Uint32 i = 0; i < group->size; i++){
    group->modules[i].draw(active && i == group->selected);
  }
}

void group_tick(Group* group, Bool active){
  if(input_key_hit(GROUP_KEYS_NEXT)){
    group->selected = wrap_index_next(group->size, group->selected);
  } else if (input_key_hit(GROUP_KEYS_PREV)){
    group->selected = wrap_index_prev(group->size, group->selected);
  }

  for(Uint32 i = 0; i < group->size; i++){
    group->modules[i].tick(active && i == group->selected);
  }
}

