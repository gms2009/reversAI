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
      bool checkRight(int);
      bool checkLeft(int);
      bool checkUp(int);
      bool checkDown(int);
      bool checkNE(int);
      bool checkNW(int);
      bool checkSE(int);
      bool checkSW(int);
  public:
      grid();
      grid(const grid&);
      char getState(string);
      void setState(string);
      void setTurn(char);
      int boardIndex(string);
      unsigned char checkBound(int);
      bool goalState();
};
#endif
