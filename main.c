#include"start_menu.h"
#include<stdio.h>


typedef enum GameState {Start, Game, Death, Victory} GameState;

void draw(GameState* state);
int main(int argc, char** argv)
{
  InitWindow(640,480,"WORLDOFFUCKINGSORROW");
  ClearWindowState(FLAG_WINDOW_RESIZABLE);
  SetTargetFPS(10);


  GameState state = Start;
  
  while(!WindowShouldClose())
    {
      BeginDrawing();
      ClearBackground(BLACK);
      draw(&state);
      EndDrawing();
    }

  EndDrawing();
  return 0;
}
void draw(GameState* state)
{
  switch(*state)
  {
     case Start:
       draw_start_menu();
     break;
  }
}
