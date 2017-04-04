#include <iostream>
#include <ctype.h>
#include "grid.h"


//Constructor for grid class
grid::grid(){
  //Sets all states to empty
  for(int index = 0; index < GRID_SIZE; index++){
    board[index] = 'E';
  }

  turn = 0;

  //Allows for easy indexing of checker for current turn
  turn_char[0] = 'B';
  turn_char[1] = 'W';
}

//Copy constructor for grid class
grid::grid(const grid &g){
  //Allows for easy indexing of checkers for current turn
	turn_char[0] = 'B';
	turn_char[1] = 'W';
	turn = g.turn;
  //Sets all states to other object
	for(int index = 0; index < GRID_SIZE; index++){
		board[index] = g.board[index];
	}
}

//Changes string form to index form
int grid::boardIndex(string loc){
  //Gets row from letter
  char letter = toupper(loc[0]) - 65;
  //Gets column from number
  char number = loc[1] - 49;
  return (8 * letter) + number;
}



//Gets state using string form
char grid::getState(string loc){
  int index = boardIndex(loc);
  return board[index];
}

//Gets state using index
char grid::getState(int index){
  return board[index];
}

//Gets current turn
int grid::getTurn(){
  return turn;
}

//Sets state using string form
void grid::setState(string loc){
  int index = boardIndex(loc);
  board[index] = turn_char[turn];
}

//Sets state using index
void grid::setState(int index){
  board[index] = turn_char[turn];
}

//Sets turn
void grid::setTurn(char t){
  turn = t;
}

//Checks bound. Returns an 8-bit number with lsb meaning up and goes clockwise.
//Ergo, right is 0000 0100 and left is 0100 0000. 1111 1111 would mean it is
//bound in all directions. A very good move.
unsigned char grid::checkBound(int index){
	unsigned char retVal = 0;
	retVal = (checkUp(index)) ? retVal | 0b00000001 : retVal;	
	retVal = (checkNE(index)) ? retVal | 0b00000010 : retVal;	
	retVal = (checkRight(index)) ? retVal | 0b00000100 : retVal;	
	retVal = (checkSE(index)) ? retVal | 0b00001000 : retVal;	
	retVal = (checkDown(index)) ? retVal | 0b00010000 : retVal;	
	retVal = (checkSW(index)) ? retVal | 0b00100000 : retVal;	
	retVal = (checkLeft(index)) ? retVal | 0b01000000 : retVal;	
	retVal = (checkNW(index)) ? retVal | 0b10000000 : retVal;	
	return retVal;
}

//Checks for bounding on right
bool grid::checkRight(int index){
	index+= 1; //Checkers to right are one index over
	int sindex = index;
  //Checks if on board, if not empty, and if not new row
	while(index < 64 && board[index] != 'E' && index % 8 != 0){
		//If checker is same color and not adjacent to start, it is bound
    if(board[index] == turn_char[turn]){
			return (sindex != index) ? true : false;
		}
		index++;
	}
	return false;
}

//Checks for bounding on left
bool grid::checkLeft(int index){
	index -= 1; //Checkers to left are one index behind
	int sindex = index;
  //Checks if on board, not empty, and not new row
	while(index >= 0  && board[index] != 'E' && index % 8 != 7){
		//Is bound if not adjacent and same color
    if(board[index] == turn_char[turn]){
			return (sindex != index) ?  true : false;
		}
		index--;
	}
	return false;
}

//Checks for bounding up
bool grid::checkUp(int index){
	index -= 8; //Checkers above are 8 back
	int sindex = index;
  //Checks if on board and not empty
	while(index >= 0  && board[index] != 'E'){
    //Is bound if not adjacent and same color
		if(board[index]  == turn_char[turn]){
			return (sindex != index) ? true : false;
		}
		index -= 8;
	}
	return false;
}

//Checks for bounding down
bool grid::checkDown(int index){
	index += 8; //Below checkers are 8 forward
	int sindex = index;
  //On board and not empty
	while(index < 64  && board[index] != 'E'){
    //Not adjacent, same color -> return true
		if(board[index]  == turn_char[turn]){
			return (sindex != index ) ? true : false;
		}
		index += 8;
	}
	return false;
}

//Checks for north east bounding
bool grid::checkNE(int index){
	index -= 7; //Northeast is back 7
	int sindex = index;
  //Not empty, on board, not new row
	while(index >= 0  && board[index] != 'E' && index % 8 != 0){
		//Not adjacent, same color -> returns true
    if(board[index]  == turn_char[turn]){
			return (sindex != index) ? true: false;
		}
		index -= 7;
	}
	return false;
}

//Checks for north west bounding
bool grid::checkNW(int index){
	index -= 9; //Northwest is back 9
	int sindex = index;
  //Not empty, on board, not new row
	while(index >= 0 && board[index] != 'E' && index % 8 != 7){
		//Not adjacent, same color -> true
    if(board[index]  == turn_char[turn]){
			return (sindex != index) ? true: false;
		}
		index -= 9;
	}
	return false;
}

//Bounded south east
bool grid::checkSE(int index){
	index += 9; //South east is back 9
	int sindex = index;
  //On board, not empty, not new row
	while(index < 64 && board[index] != 'E' && index % 8 != 0){
    //Not adjacent, same color -> true
		if(board[index]  == turn_char[turn]){
			return (sindex != index) ? true: false;
		}
		index += 9;
	}
	return false;
}

//Bounded south west
bool grid::checkSW(int index){
	index += 7; //South west back 9
	int sindex = index;
  //Not empty, on board, not new row
	while(index < 64 && board[index] != 'E' && index % 8 != 7){
    //Not adjacent, same color -> true
		if(board[index]  == turn_char[turn]){
			return (sindex != index) ? true: false;
		}
		index += 7;
	}	
  return false;
}

//Checks if goal state. Goal state is when no moves are boundable during turn.
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

//Places checker on board
void grid::placeChecker(int index){
  //Places initial checker
  board[index] = turn_char[turn];
  //Checks bounding of character
  unsigned char val = checkBound(index);
  //If North
  if((val & 0b00000001) != 0){
    int sindex = index;
    sindex -= 8;
    //Place until at same color
    while(sindex >= 0 && board[sindex] != turn_char[turn]){
      board[sindex] = turn_char[turn];
      sindex -= 8;
    }
  }
  //If NE
  if((val & 0b00000010) != 0){
    int sindex = index;
    sindex -= 7;
    //Place until end of bound
    while(sindex >= 0 && sindex % 8 != 0 && board[sindex] != turn_char[turn]){
      board[sindex] = turn_char[turn];
      sindex -= 7;
    }
}
  //If Right
  if((val & 0b00000100) != 0){
    int sindex = index;
    sindex += 1;
    //Place until end of bound
    while(sindex < 64 && sindex % 8 != 0 && board[sindex] != turn_char[turn]){
      board[sindex] = turn_char[turn];
      sindex += 1;
    }
  }
//If SE
  if((val & 8) != 0){
    int sindex = index;
    sindex += 9;
    //Place until end of bound
    while(sindex < 64 && sindex % 8 != 0 && board[sindex] != turn_char[turn]){
      board[sindex] = turn_char[turn];
      sindex += 9;
    }
  }
//If down
  if((val & 16) != 0){
    int sindex = index;
    sindex += 8;
    //Place until end of bound
    while(sindex < 64 && board[sindex] != turn_char[turn]){
      board[sindex] = turn_char[turn];
      sindex += 8;
    }
  }
//If SW
  if((val & 0b00100000) != 0){
    int sindex = index;
    sindex += 7;
    //Place until end of bound
    while(sindex < 64 && sindex % 8 != 7 && board[sindex] != turn_char[turn]){
      board[sindex] = turn_char[turn];
      sindex += 7;
    }
  }
  //If left
  if((val & 0b01000000) != 0){
    int sindex = index;
    sindex -= 1;
    //Place until end of bound
    while(sindex >= 0 && sindex % 8 != 7 && board[sindex] != turn_char[turn]){
      board[sindex] = turn_char[turn];
      sindex -= 1;
    }
  }
//If NW
  if((val & 0b10000000) != 0){
    int sindex = index;
    sindex -= 9;
    //Place until end of bound
    while(sindex >= 0 && sindex % 8 != 7 && board[sindex] != turn_char[turn]){
      board[sindex] = turn_char[turn];
      sindex -= 9;
    }
  }
}





