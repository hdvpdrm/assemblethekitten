#include"start_menu.h"
#include<stdio.h>
int main(int argc, char** argv)
{
  InitWindow(640,480,"WORLDOFFUCKINGSORROW");
  ClearWindowState(FLAG_WINDOW_RESIZABLE);
  SetTargetFPS(10);
  
  while(!WindowShouldClose())
    {


      BeginDrawing();
      ClearBackground(BLACK);
      draw_start_menu();
      EndDrawing();
    }

  EndDrawing();
  return 0;
}
