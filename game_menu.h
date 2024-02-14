#ifndef GAME_MENU_H
#define GAME_MENU_H
#include"robot.h"
#include<string.h>
#include<time.h>

//head, tail, body, legs
static int elements[] = {0,0,0,0};
static int turns_till_map_cut = 2;

static short choose = 0;
static short option_to_choose = 0; //0 - kitten, 1 - no kitten

static int compute_kitten();

static void draw_map();
static void draw_design_stuff();
static void draw_stat();


static void draw_option();
static void process_option_choosing();

extern void process_game();
extern void draw_game();
extern void init_game();


#endif
