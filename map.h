#ifndef MAP_H
#define MAP_H
#include"raylib.h"

static int map[6][6];

extern void init_map();
extern int compute_free_space();
#endif
