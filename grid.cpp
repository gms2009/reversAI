#include <iostream>
#include <ctype.h>
#include "grid.h"

grid::grid(){
  for(int index = 0; index < GRID_SIZE; index++){
    board[index] = 'E';
  }

  turn = 0;
  turn_char[0] = 'B';
  turn_char[1] = 'W';
}

int grid::boardIndex(string loc){
  char letter = toupper(loc[0]) - 65;
  char number = loc[1] - 48;
  return (8 * letter) + number;
}

char grid::getState(string loc){
  int index = boardIndex(loc);
  return board[index];
}

void grid::setState(string loc){
  int index = boardIndex(loc);
  board[index] = turn_char[turn];
}

void grid::setTurn(char t){
  turn = t;
}
