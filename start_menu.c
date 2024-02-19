#include"start_menu.h"


void process_help_menu(int* outer_state)
{
  if(IsKeyPressed(KEY_Z))
    *outer_state = -2;
}
void process_start_menu(int* outer_state)
{
  if(IsKeyPressed(KEY_SPACE) ||
     IsKeyPressed(KEY_ENTER))
    {
      if(switch_state == 1)
	*outer_state = 1;
      else
	*outer_state = 0;
    }

  if(IsKeyPressed(KEY_UP)   ||
     IsKeyPressed(KEY_DOWN) ||
     IsKeyPressed(KEY_W)    ||
     IsKeyPressed(KEY_S))
    {
      switch_state = switch_state == 0? 1: 0;
    }
}
void draw_start_menu(void)
{
  DrawText("ASSEMBLETHEKITTEN",120,100,32,RAYWHITE);
  DrawLine(118,130,496,130,RAYWHITE);

  if(switch_state == 0)
    {
      DrawText("Play",275,250,24,MAGENTA);
      DrawText("See help",245,300,24,RAYWHITE);
    }
  else
    {
      DrawText("Play",270,250,24,RAYWHITE);
      DrawText("See help",250,300,24,MAGENTA);
    }
}
void draw_help_menu(void)
{
  DrawText(":help reference:",10,10,28, RAYWHITE);

  DrawText("Use",45,100,24,RAYWHITE);
  DrawText("arrows",99,100,24,MAGENTA);
  DrawText("or",195,100,24,RAYWHITE);
  DrawText("W,A,S,D",230,100,24,MAGENTA);
  DrawText("to move around the map.",330,100,24,RAYWHITE);
  DrawText("Your",45,130,24,RAYWHITE);
  DrawText("goal",110,130,24,MAGENTA);
  DrawText("is to find",170,130,24,RAYWHITE);
  DrawText("3",290,130,24,MAGENTA);
  DrawText("elements of kitten.",320,130,24,RAYWHITE);
  DrawText("These are: head, tail, body.",45,160,24,RAYWHITE);
  DrawText("But you",45,210,24,RAYWHITE);
  DrawText("don't have",150,210,24,MAGENTA);
  DrawText("much time!",290,210,24,RAYWHITE);
  DrawText("Each time you make wrong decision, the moment",45,260,24,RAYWHITE);
  DrawText("when map becomes smaller comes closer, so",45,290,24,RAYWHITE);
  DrawText("chance to fail the quest rises!",45,320,24,RAYWHITE);
  DrawText("press",190, 380,20,RAYWHITE);
  DrawText("Z",270,380,20,MAGENTA);
  DrawText("to get back",300,380,20,RAYWHITE);
  
  DrawText("good luck,",190,430,24,RAYWHITE);
  DrawText(getUserName(),320,430,24,MAGENTA);
}

const char *getUserName()
{
 char* p=getenv("USER");
 if(p == NULL)
  return "yet another robot";

 return p;
}
