#ifndef VICTORY_SCREEN_H
#define VICTORY_SCREEN_H
#include"raylib.h"
#include<stdlib.h>

static int show_buttons = 0;
static int kitten_x = 405;
static int counter = 0;
static short turn_counter = 0;
static short choose_o = 0;
static void null_victory_screen();

static void process_kitten();
static void draw_animation();

extern void process_victory_screen(int* state);
extern void draw_victory_screen();

#endif
