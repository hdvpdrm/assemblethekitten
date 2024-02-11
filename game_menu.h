#ifndef GAME_MENU_H
#define GAME_MENU_H
#include"raylib.h"
#include"stdio.h"

#define CELL_MAX 6
#define CELL_SIZE 32
#define OFFSET 150
#define COMP_POS(val) OFFSET + (val*CELL_SIZE) + (val*20) //20 is distance between cells

//head, tail, body, legs
static int elements[] = {0,0,0,0};
static int compute_kitten();

static void draw_map();
static void draw_design_stuff();
static void draw_stat();
extern void draw_game();


#endif
