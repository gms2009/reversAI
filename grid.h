//Name: Tobias Hughes
//Purpose: An abstract representation of the reversi game board. Is an 8x8 grid
//that can be one of three states, E, W, B which represent 'empty', 
//'white', and 'black'
//Date: 3/22/17

#ifndef GRID_H
#define GRID_H

#include <string>
using namespace std;

#define GRID_SIZE 64

class grid{
  private:
      char board[GRID_SIZE];
      char turn;
      char turn_char[2];
      int boardIndex(string);
  public:
      grid();
      char getState(string);
      void setState(string);
      void setTurn(char);


};

#endif
