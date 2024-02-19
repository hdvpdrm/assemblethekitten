#include"start_menu.h"
#include"game_menu.h"
#include"death_screen.h"
#include"victory_screen.h"
#include<stdio.h>

//all possible game states. Each state is associated with its own data and events
typedef enum GameState {Start, Help, Game, Death, Victory} GameState;

void draw(GameState* state);
void process(GameState* state);
int main(int argc, char** argv)
{
  load_nki();
  
  InitWindow(640,480,"ASSEMBLETHEKITTEN");
  ClearWindowState(FLAG_WINDOW_RESIZABLE); //makes window unresizable(but it doesn't work on i3 DE)
  SetTargetFPS(10); //this is turn-based game, so it doesn't require too many FPS
  
  init_game();
  srand(time(NULL));
  //SetRandomSeed(time(NULL));
  
  GameState state =Start;//initial state
  while(!WindowShouldClose())
    {
      //game cycle is simple: DoSomething.DrawSomething.Repeat.
      
      process(&state);

      BeginDrawing();
      ClearBackground(BLACK);
      draw(&state);
      EndDrawing();
    }

  free_nki();
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
      process_game(&change);
      break;
    case Death:
      process_death_screen(&change);
      break;
    case Victory:
      process_victory_screen(&change);
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
  else if(change == 3)
    {
      *state = Death;
    }
  else if(change == 4)
    {
      *state = Victory;
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
  case Death:
       draw_death_screen();
    break;
  case Victory:
    draw_victory_screen();
    break;
  }
}
