#ifndef DEATH_SCREEN_H
#define DEATH_SCREEN_H
#include<raylib.h>
#include<stdlib.h>

static short choice = 0; //1 quit, 0 - start over again

extern void draw_death_screen();
extern void process_death_screen(int* change);
#endif
