#ifndef ROBOT_H
#define ROBOT_H
#include"raylib.h"
#include"MACRO.h"
#include"map.h"
#include<stdio.h>

static Vector robot_pos;
extern void init_robot();
extern void draw_robot();

#define MOVE_DOWN (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
#define MOVE_UP   (IsKeyPressed(KEY_UP)   || IsKeyPressed(KEY_W))
#define MOVE_LEFT (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
#define MOVE_RIGHT (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))

extern int move_robot(Vector* target_pos);
extern Vector* get_robot_pos();

extern void move_from_dead_cell();
#endif
