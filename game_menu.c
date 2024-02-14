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
        
	DrawRectangle(x_pos,y_pos,CELL_SIZE,CELL_SIZE,RAYWHITE);
      }

  draw_objects();
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

  if(choose == 1)
    {
      draw_option();
    }
}
void draw_option()
{
  DrawText("You see some object",300,40,20,RAYWHITE);

  if(option_to_choose == 0)
    {
      DrawRectangle(295,70,75,20,RAYWHITE);
    }
  else
    {
      DrawRectangle(415,70,105,20,RAYWHITE);
    }
  DrawText("Kitten!",300,70,20,MAGENTA);
  DrawText("No kitten.",420,70,20,MAGENTA);
}
void draw_stat()
{
  DrawText(" assembled:",15,240,20,RAYWHITE);
  char buffer[4] = "0/7\0";
  buffer[0] = '0' + compute_kitten();
  DrawText(buffer,135,240,20,RAYWHITE);
  
  DrawText("free space:",10,280,20,RAYWHITE);

  int free_space_amount = compute_free_space();
  char fsa_buffer[8]; 
  sprintf(fsa_buffer,"%d",free_space_amount);
  strcat(fsa_buffer,"/36\0");

  DrawText(fsa_buffer,130,280,20,RAYWHITE);
  
  DrawText("map cut in:",20,320,20,RAYWHITE);
  char map_cut_buffer[2] = "0\0";
  map_cut_buffer[0] = '0' + turns_till_map_cut;
  DrawText(map_cut_buffer,130,320,20,RAYWHITE);
}


void init_game()
{
  SetRandomSeed(time(NULL));
  init_map();
  generate_random_objects(turns_till_map_cut+1);
  init_robot();
}
void process_option_choosing()
{
  if(MOVE_LEFT || MOVE_RIGHT)
    {
      option_to_choose = option_to_choose == 0?1:0;
    }
  if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER))
    {
      choose = 0;
    }
}
void process_game()
{
  //if choose is 0, then robot can move, otherwise robot should deicide what is object(kitten or not)
  if(choose == 0)
    {
      int result = move_robot();
      if(result != 0)
	{
	  choose = 1;
	}
    }
  else
    {
      process_option_choosing();
    }
}
