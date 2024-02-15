#include"death_screen.h"

void draw_death_screen()
{
  DrawText("Robot is",160,100,40,RAYWHITE);
  DrawText("broken!",340,100,40,MAROON);
  DrawText("Kitten",160,200,40,MAGENTA);
  DrawText("is dead...",320,200,40,RAYWHITE);

  if(choice == 0)
    {
      DrawText("Start again",255,320,24,MAGENTA);
      DrawText("Don't start again",215,360,24,RAYWHITE);
    }
  else
    {
      DrawText("Start again",250,320,24,RAYWHITE);
      DrawText("Don't start again",220,360,24,MAGENTA);
    }
}
void process_death_screen(int* change)
{
  if(IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S) ||
     IsKeyPressed(KEY_UP)   || IsKeyPressed(KEY_W))
    {
      choice = choice == 1?0:1;
    }

  if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER))
    {
      if(choice == 0)*change = -2;
      else exit(0);
    }
}
