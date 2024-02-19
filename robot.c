#include"robot.h"

void init_robot()
{
  vector_init(&robot_pos);

  Vector* free_cells = NULL;
  int free_cells_amount = 0;
  if(compute_free_cells(&free_cells,&free_cells_amount,&robot_pos) == 0)
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


int move_robot(Vector* target_pos)
{
  if(MOVE_DOWN && robot_pos.y + 1 < 6)
    {
      target_pos->x = robot_pos.x;
      target_pos->y = robot_pos.y+1;
      
      int cell_state = is_free(robot_pos.x,robot_pos.y+1); 
      if(cell_state == 1)
	robot_pos.y += 1;
      else return cell_state;
    }
  
  if(MOVE_UP && robot_pos.y - 1 > -1)
    {
      target_pos->x = robot_pos.x;
      target_pos->y = robot_pos.y-1;
      
      int cell_state = is_free(robot_pos.x,robot_pos.y-1);
      if(cell_state == 1)
	robot_pos.y -= 1;
      else return cell_state;
    }
  
  if(MOVE_LEFT && robot_pos.x -1 > left_border-1)
    {
      target_pos->x = robot_pos.x-1;
      target_pos->y = robot_pos.y;
      
      int cell_state = is_free(robot_pos.x-1,robot_pos.y);
      if(cell_state == 1)
	robot_pos.x -= 1;
      else return cell_state;
    }
  if(MOVE_RIGHT && robot_pos.x + 1 < right_border)
    {
      target_pos->x = robot_pos.x+1;
      target_pos->y = robot_pos.y;
      
      int cell_state = is_free(robot_pos.x+1,robot_pos.y);
      if(cell_state == 1)
	robot_pos.x += 1;
      else return cell_state;

    }

  return 0;
}
Vector* get_robot_pos()
{
  return &robot_pos;
}

void move_from_dead_cell()
{
  if(is_free_to_move(robot_pos.x-1,robot_pos.y) == 1)
    {
      robot_pos.x-=1;
    }
  else if(is_free_to_move(robot_pos.y+1,robot_pos.y) == 1)
    {
      robot_pos.x+=1;
    }
}
