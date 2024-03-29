#include"map.h"
#include<stdio.h>

void init_map()
{
  for(int y = 0;y<6;++y)
    for(int x = 0;x<6;++x)
      {
	map[y][x] = 0;
      }

  left_border = 0;
  right_border = 6;
}
int compute_free_space()
{
  int S = 0;
  for(int y = 0;y<6;++y)
    for(int x = 0;x<6;++x)      
      if(map[y][x] > -1)++S;
      
  return S;
}
int compute_free_cells(Vector** cells, int* cells_number,Vector* robot_pos)
{  
  //create initial array for cells
  *cells_number = 1;
  *cells = malloc(sizeof(Vector));
  if(*cells == NULL)
    {
      return -1;
    }
  (*cells)[0].x = -1; //-1 indicates that this element isn't filled with actual value
  
  for(int y = 0;y<6;++y)
    for(int x = 0;x<6;++x)
      {
	//if it's under 0, then it's blocked,otherwise it's object
	if(map[y][x] == 0 && x != robot_pos->x && y != robot_pos->y)
	  {
	    //if first element isn't used, then fill it
	    if( (*cells)[0].x == -1)
	      {
		(*cells)[0].x = x;
		(*cells)[0].y = y;
	      }
	    //increase size of array and fill it with new value
	    else
	      {
		*cells = realloc(*cells,sizeof(Vector)* ((*cells_number) + 1));
		if(*cells == NULL)
		  {
		    return -1;
		  }
		*cells_number = *cells_number+1;

		int index = (*cells_number) - 1;
		(*cells)[index].x = x;
		(*cells)[index].y = y;
	      }	    
	  }
      }
  
  return 0;
}
int generate_random_objects(int amount,Vector* robot_pos)
{
  Vector* free_cells = NULL;
  int free_cells_size = 0;
  if(compute_free_cells(&free_cells,&free_cells_size,robot_pos) == 0)
    {
      srand(time(NULL));
      int* random_cells_ids = generate_random_sequence(0,free_cells_size-1,amount);   //LoadRandomSequence(amount, 0, free_cells_size-1);
      
      if(random_cells_ids == NULL) return -1;

      int kitten_id = GetRandomValue(0,amount-1);
      for(int i = 0;i<amount;++i)
	{
	  int index = random_cells_ids[i];
	  if(index < 0) index*=-1;
	  int x = free_cells[index].x;
	  int y = free_cells[index].y;
	 
	  int rnd_ch_pos = GetRandomValue(0,CHARS_LEN-1);
	  map[y][x] = (int)_CHARS[rnd_ch_pos];
	  
	  if(kitten_id == i)
	    {
	      kitten_pos.x = x;
	      kitten_pos.y = y;
	    }
	}
      
      free(free_cells);
      free(random_cells_ids);
      //UnloadRandomSequence(random_cells_ids);
      return 0;
    }
  free(free_cells);
  return -1;
}
void draw_objects()
{
  for(int y = 0; y<CELL_MAX;++y)
    for(int x = 0;x<CELL_MAX;++x)
      {
	int x_pos = COMP_X_POS(x)+3;
	int y_pos = COMP_Y_POS(y)-1;
       
	if(map[y][x] > 0)
	  {
	    char buffer[2] = "0\0";
	    buffer[0] = (char)map[y][x];
	    DrawText(buffer,x_pos,y_pos,40,MAGENTA);
	  }
      }

}
short is_free(int x, int y)
{
  //check boundaries
  if(x < 0  || y < 0) return 0;
  if(x == 6  || y == 6) return 0;

  if(map[y][x] == 0) return 1;
  else if(map[y][x] == -1) return 0;
  else if(map[y][x] > 0) return map[y][x];
  return 0;
}
short is_free_to_move(int x,int y)
{
  if(x-1 < 0) return 1;
  if(x+1>= 6) return -1;

  if(map[y][x-1] == -1) return 1;
  else return -1;
  
}
void make_cell_dead(int x, int y)
{
  map[y][x] = 0;
}
void draw_map()
{
  for(int y = 0; y<CELL_MAX;++y)
    for(int x = 0;x<CELL_MAX;++x)
      {
	int x_pos = COMP_X_POS(x);
	int y_pos = COMP_Y_POS(y);

	if(map[y][x] != -1)
	  DrawRectangle(x_pos,y_pos,CELL_SIZE,CELL_SIZE,RAYWHITE);
	else
	  DrawRectangle(x_pos,y_pos,CELL_SIZE,CELL_SIZE,BLACK);
      }

  draw_objects();
}
void cut_map()
{
  for(int y = 0;y<CELL_MAX;++y)
    {
      map[y][left_border] = -1;
      map[y][right_border-1] = -1;
    }
  ++left_border;
  --right_border;
}
short is_kitten(int x, int y)
{
  return (x == kitten_pos.x && y == kitten_pos.y)? 1: 0;
}
short is_dead_cell(int x, int y)
{
  return map[y][x] == -1?1:0;
}
