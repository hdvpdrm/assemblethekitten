#include"start_menu.h"
#include"game_menu.h"
#include<stdio.h>

//all possible game states. Each state is associated with its own data and events
typedef enum GameState {Start, Help, Game, Death, Victory} GameState;

void draw(GameState* state);
void process(GameState* state);
int main(int argc, char** argv)
{
  InitWindow(640,480,"ASSEMBLETHEKITTEN");
  ClearWindowState(FLAG_WINDOW_RESIZABLE); //makes window unresizable(but it doesn't work on i3 DE)
  SetTargetFPS(10); //this is turn-based game, so it doesn't require too many FPS

  init_game();
  
  GameState state = Start;//initial state
  while(!WindowShouldClose())
    {
      //game cycle is simple: DoSomething.DrawSomething.Repeat.
      
      process(&state);

      BeginDrawing();
      ClearBackground(BLACK);
      draw(&state);
      EndDrawing();
    }

  EndDrawing();
  return 0;
}
void process(GameState* state)
{
  int change = -1;
  switch(*state)
    {
    case Start:
      process_start_menu(&change);
    break;
    case Help:
      process_help_menu(&change);
      break;
    case Game:
      process_game();
      break;
    }

  if(change == 0)
    {
      *state = Game;
    }
  else if(change == 1)
    {
      *state = Help;
    }
  else if(change == -2)
    {
      *state = Start;
    }
}
void draw(GameState* state)
{
  switch(*state)
  {
     case Start:
       draw_start_menu();
     break;
  case Help:
       draw_help_menu();
     break;
  case Game:
       draw_game();
     break;
  }
}
