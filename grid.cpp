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

grid::grid(const grid &g){
	turn_char[0] = 'B';
	turn_char[1] = 'W';
	turn = g.turn;
	for(int index = 0; index < GRID_SIZE; index++){
		board[index] = g.board[index];
	}
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

unsigned char grid::checkBound(int index){
	unsigned char retVal = 0;
	retVal = (checkUp(index)) ? retVal | 0b00000001 : retVal;	
	retVal = (checkNE(index)) ? retVal | 0b00000010 : retVal;	
	retVal = (checkRight(index)) ? retVal | 0b00000100 : retVal;	
	retVal = (checkSE(index)) ? retVal | 0b000010000 : retVal;	
	retVal = (checkDown(index)) ? retVal | 0b00010000 : retVal;	
	retVal = (checkSW(index)) ? retVal | 0b00100000 : retVal;	
	retVal = (checkLeft(index)) ? retVal | 0b01000000 : retVal;	
	retVal = (checkNW(index)) ? retVal | 0b10000000 : retVal;	
	return retVal;
}

bool grid::checkRight(int index){
	index+= 1;
	int sindex = index;
	while(index < 64 && board[index] != 'E' && index % 8 != 0){
		if(board[index] == turn_char[turn]){
			return (sindex != index) ? true : false;
		}
		index++;
	}
	return false;
}

bool grid::checkLeft(int index){
	index -= 1;
	int sindex = index;
	while(index >= 0  && board[index] != 'E' && index % 8 != 7){
		if(board[index] == turn_char[turn]){
			return (sindex != index) ?  true : false;
		}
		index--;
	}
	return false;
}

bool grid::checkUp(int index){
	index -= 8;
	int sindex = index;
	while(index >= 0  && board[index] != 'E'){
		if(board[index]  == turn_char[turn]){
			return (sindex != index) ? true : false;
		}
		index -= 8;
	}
	return false;
}

bool grid::checkDown(int index){
	index += 8;
	int sindex = index;
	while(index < 64  && board[index] != 'E'){
		if(board[index]  == turn_char[turn]){
			return (sindex != index ) ? true : false;
		}
		index += 8;
	}
	return false;
}

bool grid::checkNE(int index){
	index -= 7;
	int sindex = index;
	while(index >= 0  && board[index] != 'E' && index % 8 != 0){
		if(board[index]  == turn_char[turn]){
			return (sindex != index) ? true: false;
		}
		index -= 7;
	}
	return false;
}

bool grid::checkNW(int index){
	index -= 9;
	int sindex = index;
	while(index >= 0 && board[index] != 'E' && index % 8 != 7){
		if(board[index]  == turn_char[turn]){
			return (sindex != index) ? true: false;
		}
		index -= 9;
	}
	return false;
}

bool grid::checkSE(int index){
	index += 9;
	int sindex = index;
	while(index < 64 && board[index] != 'E' && index % 8 != 0){
		if(board[index]  == turn_char[turn]){
			return (sindex != index) ? true: false;
		}
		index += 9;
	}
	return false;
}

bool grid::checkSW(int index){
	index += 7;
	int sindex = index;
	while(index < 64 && board[index] != 'E' && index % 8 != 7){
		if(board[index]  == turn_char[turn]){
			return (sindex != index) ? true: false;
		}
		index += 7;
	}	
}

bool grid::goalState(){
	for(int i = 0; i < 64; i++){
		if(board[i] == 'E'){
			if(checkBound(i) != 0){
				return false;
			}
		}
	}
	return true;
}
