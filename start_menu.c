#include"start_menu.h"


void process_start_menu(int* outer_state)
{
  if(IsKeyPressed(KEY_Q))
    {
      *outer_state = 0;
    }
  if(IsKeyPressed(KEY_Z))
    {
      *outer_state = 1;
    }
}
void draw_start_menu(void)
{
  DrawText("WORLDOFFUCKINGSORROW",100,100,32,RAYWHITE);
  DrawLine(98,130,538,130,RAYWHITE);

  DrawText("Press",190,250,24,RAYWHITE);
  DrawText("Q",285,250,24,MAGENTA);
  DrawText("to start",320,250,24,RAYWHITE);

  DrawText("Press",190,300,24,RAYWHITE);
  DrawText("Z",285,300,24,MAGENTA);
  DrawText("for help",320,300,24,RAYWHITE);
}
