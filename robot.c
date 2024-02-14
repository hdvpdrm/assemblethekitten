#include"robot.h"

void init_robot()
{
  vector_init(&robot_pos);

  Vector* free_cells = NULL;
  int free_cells_amount = 0;
  if(compute_free_cells(&free_cells,&free_cells_amount) == 0)
    {
      int id = GetRandomValue(0,free_cells_amount-1);
      robot_pos.x = free_cells[id].x;
      robot_pos.y = free_cells[id].y;
    }
  else
    {
      printf("%s\n", "well... everything is fucked up right now");
      exit(1);
    }
}
void draw_robot()
{
  int x = COMP_X_POS(robot_pos.x)+3;
  int y = COMP_Y_POS(robot_pos.y)-2;
  DrawText("#",x,y,40,BLACK);
}


int move_robot()
{
  if(MOVE_DOWN && robot_pos.y + 1 < 6)
    {
      int cell_state = is_free(robot_pos.x,robot_pos.y+1); 
      if(cell_state == 1)
	robot_pos.y += 1;
      else return cell_state;
    }
  
  if(MOVE_UP && robot_pos.y - 1 > -1)
    {
      int cell_state = is_free(robot_pos.x,robot_pos.y-1);
      if(cell_state == 1)
	robot_pos.y -= 1;
      else return cell_state;
    }
  
  if(MOVE_LEFT && robot_pos.x -1 > left_border-1)
    {
      int cell_state = is_free(robot_pos.x-1,robot_pos.y);
      if(cell_state == 1)
	robot_pos.x -= 1;
      else return cell_state;
    }
  if(MOVE_RIGHT && robot_pos.x + 1 < right_border)
    {
      int cell_state = is_free(robot_pos.x+1,robot_pos.y);
      if(cell_state == 1)
	robot_pos.x += 1;
      else return cell_state;
    }

  return 0;
}
