#include"game_menu.h"
#include<stdio.h>


int compute_kitten()
{
  int S = 0;
  for(int i = 0;i<3;++i) S+=elements[i];
  return S;
}

void draw_design_stuff()
{
  DrawLine(OFFSET+50,0,OFFSET+50,480,RAYWHITE);
  DrawLine(0,80,OFFSET+50,80,RAYWHITE);
  DrawText("A",50,10,40,RAYWHITE);
  DrawText(".",80,10,40,RAYWHITE);
  DrawText("T",85,10,40,RAYWHITE);
  DrawText(".",110,10,40,RAYWHITE);
  DrawText("K",125,10,40,MAGENTA);
  DrawText("ASSEMBLETHE",10,50,16,RAYWHITE);
  DrawText("KITTEN",129,50,16,MAGENTA);
}
void draw_game()
{
  draw_map();
  draw_design_stuff();
  draw_stat();
  draw_robot();

  if(choose == 1)
    {
      draw_option();
    }
}
void draw_option()
{
  DrawText(nki_to_show,420-(MeasureText(nki_to_show,20)/2),40,20,RAYWHITE);

  if(option_to_choose == 0)
    {
      DrawRectangle(295,70,75,20,RAYWHITE);
    }
  else
    {
      DrawRectangle(415,70,105,20,RAYWHITE);
    }
  DrawText("Kitten!",300,70,20,MAGENTA);
  DrawText("No kitten.",420,70,20,MAGENTA);
}
void draw_stat()
{
  DrawText(" assembled:",15,240,20,RAYWHITE);
  char buffer[4] = "0/3\0";
  buffer[0] = '0' + compute_kitten();
  DrawText(buffer,135,240,20,RAYWHITE);
  
  DrawText("free space:",10,280,20,RAYWHITE);

  int free_space_amount = compute_free_space();
  char fsa_buffer[8]; 
  sprintf(fsa_buffer,"%d",free_space_amount);
  strcat(fsa_buffer,"/36\0");

  DrawText(fsa_buffer,130,280,20,RAYWHITE);
  
  DrawText("map cut in:",20,320,20,RAYWHITE);
  char map_cut_buffer[2] = "0\0";
  map_cut_buffer[0] = '0' + turns_till_map_cut;
  DrawText(map_cut_buffer,130,320,20,RAYWHITE);
}


void init_game()
{
  init_map();
  generate_random_objects(turns_till_map_cut+1,get_robot_pos());
  init_robot();
  vector_init(&next_pos);
}

char* get_random_nki()
{
  int id = GetRandomValue(0,453);
  return nki[id];
}
void load_nki()
{
  nki = read_nki_file();
  if(nki == NULL)
    {
      printf("hm... something went wrong... no nki...\n");
      exit(-1);
    }
}
void free_nki()
{
  for(int i = 0;i<453;++i)
    {
      free(nki[i]);
    }
  free(nki);
}

void null_state()
{
  prev_ttmp_state = 2;
  turns_till_map_cut = 2;
  for(int i = 0;i<3;++i)elements[i] = 0;
  left_border = 0;
  right_border = 6;
  init_map();
  generate_random_objects(turns_till_map_cut+1,get_robot_pos());
  init_robot();
  vector_init(&next_pos);
}
int process_option_choosing()
{
  if(MOVE_LEFT || MOVE_RIGHT)
    {
      option_to_choose = option_to_choose == 0?1:0;
    }
  if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER))
    {
      choose = 0;
      return 1;
    }

  return 0;
}
void process_object_interaction()
{
  bool found_kitten = is_kitten(next_pos.x,next_pos.y) == 1 && option_to_choose == 0;
  bool no_kitten = is_kitten(next_pos.x,next_pos.y) == 0 && option_to_choose == 0;
  bool kitten_mistake = is_kitten(next_pos.x,next_pos.y) == 1 && option_to_choose == 1;
  if(found_kitten)
    {
      int id = compute_kitten();
      if(id == 3)--id;
      elements[id] = 1;

      generate_random_objects(turns_till_map_cut+1,get_robot_pos());
    }
 else if(no_kitten)
    {
      --turns_till_map_cut;
    }
 else if(kitten_mistake)
    {
       turns_till_map_cut = 0;
    }
}
void process_game(int* state)
{
  if(compute_free_space() == 0)
    {
      *state = 3; //death
    }
  if(compute_kitten() == 3)
    {
      null_state();
      *state = 4; //victory
    }
  
  //if choose is 0, then robot can move, otherwise robot should deicide what is object(kitten or not)
  if(choose == 0)
    {
      int result = move_robot(&next_pos);
      if(result != 0)
	{
	  nki_to_show = get_random_nki();
	  choose = 1;
	}
    }
  else
    {
      if(process_option_choosing() == 1)
	{
	  make_cell_dead(next_pos.x,next_pos.y);
	  process_object_interaction();
	}

      if(turns_till_map_cut == 0)
	    {
	      cut_map();
	      if(compute_free_space() == 0)
		{
		  *state = 3;
		  null_state();
		  return;
		}

	      if(is_dead_cell(get_robot_pos()->x,get_robot_pos()->y) == 1)
		{
		  move_from_dead_cell();
		}
		
	      ++prev_ttmp_state;
	      turns_till_map_cut = prev_ttmp_state;
	      generate_random_objects(turns_till_map_cut+1,get_robot_pos());
	    }
    }
}
