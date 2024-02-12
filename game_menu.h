#ifndef GAME_MENU_H
#define GAME_MENU_H
#include"robot.h"
#include"map.h"
#include<string.h>
#include<time.h>

//head, tail, body, legs
static int elements[] = {0,0,0,0};
static int turns_till_map_cut = 2;

static int compute_kitten();

static void draw_map();
static void draw_design_stuff();
static void draw_stat();

extern void process_game();
extern void draw_game();
extern void init_game();

#endif
