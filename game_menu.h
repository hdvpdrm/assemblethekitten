#ifndef GAME_MENU_H
#define GAME_MENU_H
#include"robot.h"
#include<string.h>
#include<time.h>

//head, tail, body
static int elements[] = {0,0,0};

static int prev_ttmp_state = 2;
static int turns_till_map_cut = 2;

static short choose = 0;
static short option_to_choose = 0; //0 - kitten, 1 - no kitten

static int compute_kitten();


static void draw_design_stuff();
static void draw_stat();

static Vector next_pos;
static void draw_option();
static int process_option_choosing();

static void process_object_interaction();
extern void process_game(int* state);

extern void draw_game();
extern void init_game();
static void null_state();

#endif
