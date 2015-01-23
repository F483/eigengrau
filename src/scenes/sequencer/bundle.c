// Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
// License: MIT (see LICENSE file)

#include <src/gba/all.h>
#include <src/lib/all.h>
#include <src/scenes/sequencer/bundle.h>
#include <src/scenes/sequencer/groups/all.h>

#define BUNDLE_KEYS_NEXT      INPUT_KEY_START
#define BUNDLE_KEYS_PREV      INPUT_KEY_SELECT

void bundle_draw(Bundle* bundle){
  for(Uint32 i = 0; i < bundle->size; i++){
    group_draw(bundle->groups[i], i == bundle->selected);
  }
}

void bundle_tick(Bundle* bundle){
  if(input_key_hit(BUNDLE_KEYS_NEXT)){
    bundle->selected = wrap_index_next(bundle->size, bundle->selected);
  } else if (input_key_hit(BUNDLE_KEYS_PREV)){
    bundle->selected = wrap_index_prev(bundle->size, bundle->selected);
  }

  for(Uint32 i = 0; i < bundle->size; i++){
    group_tick(bundle->groups[i], i == bundle->selected);
  }
}


/////////////
// BUNDLES //
/////////////

Group* groups_sqr2[5] = {
  &group_bpm, 
  &group_fm_ctrl_sqr2
};

Bundle bundles[SEQUENCER_TRACK_CNT] = {
  { 0, 0, NULL },         // sqr1
  { 2, 0, groups_sqr2 },  // sqr2
  { 0, 0, NULL },         // wave
  { 0, 0, NULL },         // noise
  { 0, 0, NULL },         // smpl1
  { 0, 0, NULL },         // smpl2
};


