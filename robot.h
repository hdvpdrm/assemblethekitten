#ifndef ROBOT_H
#define ROBOT_H
#include"vector.h"
#include"raylib.h"
#include"MACRO.h"
#include<stdio.h>

static Vector robot_pos;
extern void init_robot();
extern void draw_robot();
extern void move_robot();
#endif
