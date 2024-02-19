#ifndef RANDOM_H
#define RANDOM_H
#include<stdlib.h>
#include<time.h>


static int* generate_random_sequence(int a, int b, int size)
{
  //this function is supposed to generate positive values
  if(a < -1 ||
     b < -1)
    return NULL;

  int* arr = (int*)malloc(size*sizeof(int));
  if(arr == NULL) return NULL;
  
  int current_element = 0;
  int i = 0;
  while(i< size)
    {
      int rand_number = a + rand() / (RAND_MAX / (b - a + 1) + 1);
      if(current_element == 0)
	{
	  arr[0] = rand_number;
	  ++i;
	  ++current_element;
	}
      else
	{
	  for(int n = 0;n<current_element;++n)
	    {
	      if(arr[n] == rand_number)
		{
		  --i;
		  --current_element;
		  break;
		}
	      else
		{
		  arr[current_element] = rand_number;
		  ++i;
		  ++current_element;
		  break;
		}
	    } 
	}
    }
  
  return arr;
}
#endif
