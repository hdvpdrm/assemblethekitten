#include"victory_screen.h"

void null_victory_screen()
{
  show_buttons = 0;
  kitten_x = 405;
  counter = 0;
  turn_counter = 0;
  choose_o = 0;
}
void draw_animation()
{
  DrawText("#",200,100,40,RAYWHITE);
  DrawText("c",kitten_x,108,30,MAGENTA);
  DrawLine(180,135,435,135,RAYWHITE);
}
void draw_victory_screen()
{
   draw_animation();
   if(show_buttons == 1)
     {
       DrawText("You assembled the",160,200,25,RAYWHITE);
       DrawText("kitten",400,200,25,MAGENTA);
       DrawText("!",475,200,25,RAYWHITE);

       if(choose_o == 0)
	 {
	   DrawText("Find yet another kitten",170,300,25,MAGENTA);
	   DrawText("No kittens left to find",175,340,25,RAYWHITE);
	 }
       else
	 {
	   DrawText("Find yet another kitten",170,300,25,RAYWHITE);
	   DrawText("No kittens left to find",175,340,25,MAGENTA);
	 }
     }
}
void process_kitten()
{
  if(counter == 5)
  {
    counter = 0;
    kitten_x -=35;
    ++turn_counter;
  }
  if(turn_counter == 5)
  {
    show_buttons = 1;
    counter = 0;
  }
  
  ++counter;
}
void process_victory_screen(int* state)
{
  if(show_buttons == 0)
    {
      process_kitten();
    }
  if(show_buttons == 1)
    {

  if(IsKeyPressed(KEY_UP)   ||
     IsKeyPressed(KEY_DOWN) ||
     IsKeyPressed(KEY_W)    ||
     IsKeyPressed(KEY_S))
     {
       choose_o = choose_o == 0? 1: 0;
     }
    }

  if(IsKeyPressed(KEY_SPACE) ||
     IsKeyPressed(KEY_ENTER))
    {
      if(choose_o == 1)exit(0);
      else
	{
	  null_victory_screen();
	  *state = -2;
	}
    }
}
