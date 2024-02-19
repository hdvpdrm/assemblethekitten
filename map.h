#ifndef MAP_H
#define MAP_H
#include"raylib.h"
#include"vector.h"
#include"MACRO.h"
#include"random.h"
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define CHARS "$%&03456789<>ABCDEFGHKLMNOPQRSUVWXYZ"
#define CHARS_LEN strlen(CHARS)

static const char* _CHARS = CHARS;

static int map[6][6];

static int left_border  = 0;
static int right_border = 6;

static Vector kitten_pos;

extern void init_map();

extern int compute_free_space();

extern int compute_free_cells(Vector** cells, int* cells_number, Vector* robot_pos);
extern int generate_random_objects(int amount, Vector* robot_pos);

extern short is_free_to_move(int x,int y);
extern short is_free(int x, int y);
extern short is_dead_cell(int x, int y);

extern void draw_objects();
extern void make_cell_dead(int x, int y);
extern void cut_map();
extern short is_kitten(int x, int y);

extern void draw_map();
#endif
