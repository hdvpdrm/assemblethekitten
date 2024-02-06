#include"raylib.h"

int main(int argc, char** argv)
{
  InitWindow(640,480,"WORLDOFFUCKINGSORROW");
  SetTargetFPS(10);
  
  while(!WindowShouldClose())
    {


      BeginDrawing();
      ClearBackground(RAYWHITE);

      EndDrawing();
    }

  EndDrawing();
  return 0;
}
