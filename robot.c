#include"robot.h"

void init_robot()
{
  vector_init(&robot_pos);
  robot_pos.x = GetRandomValue(0,6);
  robot_pos.y = GetRandomValue(0,6);
}
void draw_robot()
{
  int x = COMP_X_POS(robot_pos.x)+3;
  int y = COMP_Y_POS(robot_pos.y)-2;
  DrawText("#",x,y,40,RAYWHITE);
}


#define MOVE_DOWN (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
#define MOVE_UP   (IsKeyPressed(KEY_UP)   || IsKeyPressed(KEY_W))
#define MOVE_LEFT (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
#define MOVE_RIGHT (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
void move_robot()
{
  if(MOVE_DOWN && robot_pos.y + 1 < 6)
    robot_pos.y += 1;
  
  if(MOVE_UP && robot_pos.y - 1 > -1)
    robot_pos.y -= 1;

  if(MOVE_LEFT && robot_pos.x -1 > -1)
    robot_pos.x -= 1;

  if(MOVE_RIGHT && robot_pos.x + 1 < 6)
    robot_pos.x += 1;
}
