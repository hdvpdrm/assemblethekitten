#ifndef MAP_H
#define MAP_H
#include"raylib.h"
#include"vector.h"
#include"MACRO.h"
#include<stdlib.h>
#include<string.h>

#define CHARS "$%&/03456789<>@ABCDEFGHKLMNOPQRSUVWXYZ^"
#define CHARS_LEN strlen(CHARS)

static const char* _CHARS = CHARS;

static int map[6][6];

static int left_border  = 0;
static int right_border = 6;

extern void init_map();
extern int compute_free_space();

extern int compute_free_cells(Vector** cells, int* cells_number);
extern int generate_random_objects(int amount);

extern short is_free(int x, int y);

extern void draw_objects();
#endif
