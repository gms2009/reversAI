//Ai uses 3 layer, so max-min-max
#include <iostream>
#include <vector>
#include "grid.h"

int minfunc(grid, int, int);
int maxfunc(grid, int, int);

//Gets value based on position. Scoring method for grid spaces
int getVal(int index){
  int values[64] = {99, -8, 8, 6, 6, 8, -8, 99,
                    -8, -24, -4, -3, -3, -4, -24, -8,
                    8, -4, 7, 4, 4, 7, -4, 8,
                    6, -3, 4, 0, 0, 4 -3, 6,
                    6, -3, 4, 0, 0, 4, -3, 6,
                    8, -4, 7, 4, 4, 7, -4, 8,
                    -8, -24, -4, -3, -3, -4, -24, -8,
                    99, -8, 8, 6, 6, 8, -8, 99};
  return values[index];
}

//Gets max and returns index
int getMove(grid g){
    //Max value
    int max = -100;
    //Index for max value
    int max_index = 10000;
    //Finds empty and boundable space to check
    for(int i = 0; i < 64; i++){
      if(g.checkBound(i) != 0 && g.getState(i) == 'E'){
         //Finds min on next layer
         int val = minfunc(g, i, max);
         //Checks if max
         if (val > max){
            max = val;
            max_index = i;
         }
      }
    }
    return max_index;
}

//Minimizes in minmax
int minfunc(grid g, int place, int beta){
  //Adds checked space to grid
  g.setState(place);
  //Sets turn for bounding function
  g.setTurn((g.getTurn() == 0) ? 1 : 0);
  int min = 100;
  //Checks for empty and boundable
  for(int i = 0; i < 64; i++){
    if(g.checkBound(i) != 0 && g.getState(i) == 'E'){
      //Finds max for next layer
      int val = maxfunc(g, i, min);
      //Checks if min
      if(val < min){
        min = val;
      }
      //Leaves if out of alpha-beta bounds
      if(min < beta){
        return min;
      }
    }
  }
  return min;
}

//Maximizes for minmax
int maxfunc(grid g, int place, int alpha){
  //Sets checked state
  g.setState(place);
  //Sets turn for bounding
  g.setTurn((g.getTurn() == 0) ? 1 : 0);
  int max = -100;
  //Checks for empty and boundable
  for(int i = 0; i < 64; i++){
    if(g.checkBound(i) != 0 && g.getState(i) == 'E'){
      //Finds max
      if(getVal(i) > max){
        max = getVal(i);
      }
      //LEaves if out of alpha-beta bounds
      if(max > alpha){
        return max;
      }
    }
  }
  return max;
}
