#include"game_menu.h"
#include<stdio.h>


static int compute_kitten()
{
  int S = 0;
  for(int i = 0;i<4;++i) S+=elements[i];
  return S;
}
void draw_map()
{
  for(int y = 0; y<CELL_MAX;++y)
    for(int x = 0;x<CELL_MAX;++x)
      {
	int x_pos = COMP_X_POS(x);
	int y_pos = COMP_Y_POS(y);
        
	DrawRectangle(x_pos,y_pos,CELL_SIZE,CELL_SIZE,BLUE);
      }
}
void draw_design_stuff()
{
  DrawLine(OFFSET+50,0,OFFSET+50,480,RAYWHITE);
  DrawLine(0,80,OFFSET+50,80,RAYWHITE);
  DrawText("A",50,10,40,RAYWHITE);
  DrawText(".",80,10,40,RAYWHITE);
  DrawText("T",85,10,40,RAYWHITE);
  DrawText(".",110,10,40,RAYWHITE);
  DrawText("K",125,10,40,MAGENTA);
  DrawText("ASSEMBLETHE",10,50,16,RAYWHITE);
  DrawText("KITTEN",129,50,16,MAGENTA);
}
void draw_game()
{
  draw_map();
  draw_design_stuff();
  draw_stat();
  draw_robot();
}
void draw_stat()
{
  DrawText(" assembled:",15,240,20,RAYWHITE);
  char buffer[3] = "0/7";
  buffer[0] = '0' + compute_kitten();
  DrawText(buffer,135,240,20,RAYWHITE);
  
  DrawText("free space:",10,280,20,RAYWHITE);
  DrawText("map cut in:",20,320,20,RAYWHITE);
}


void init_game()
{
  SetRandomSeed(time(NULL));
  init_map();
  init_robot();
}
void process_game()
{
  move_robot();
}
