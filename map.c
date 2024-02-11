#include"map.h"
#include<stdio.h>

void init_map()
{
  for(int y = 0;y<6;++y)
    for(int x = 0;x<6;++x)
      {
	map[y][x] = 0;
      }
}
int compute_free_space()
{
  int S = 0;
  for(int y = 0;y<6;++y)
    for(int x = 0;x<6;++x)      
	if(map[y][x])++S;
      
  return S;
}
