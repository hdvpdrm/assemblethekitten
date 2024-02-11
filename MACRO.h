#ifndef MACRO_H
#define MACRO_H

#define CELL_MAX 6
#define CELL_SIZE 32
#define OFFSET 150

#define __COMP_POS(val) OFFSET + (val*CELL_SIZE) + (val*10) //10 is distance between cells
#define COMP_X_POS(val) __COMP_POS(val) + 150 //just magic number
#define COMP_Y_POS(val) __COMP_POS(val)

#endif
