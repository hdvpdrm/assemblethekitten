#include"robot.h"

void init_robot()
{
  vector_init(&robot_pos);
  robot_pos.x = GetRandomValue(0,6);
  robot_pos.y = GetRandomValue(0,6);
}
