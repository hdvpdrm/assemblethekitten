#ifndef START_MENU_H
#define START_MENU_H
#include"raylib.h"
#include"whoami.h"

static short switch_state = 0;

extern void process_help_menu(int* outer_state);
extern void process_start_menu(int* outer_state);
extern void draw_start_menu(void);
extern void draw_help_menu(void);

static const char *getUserName();
#endif
