//Names: Tobias Hughes --- Jonathan Holcomb --- Nelson Debate
//Date: 4/3/17
//Game: Othello/Reversie
//Methods used: Positional table, minimax, alpha-beta pruning
#include <iostream>
#include "grid.h"

using namespace std;

void drawBoard(grid); //Draws game board on terminal
int getMove(grid); //Gets move for ai

int main(){
    //Sets up initial game grid
    grid g;
    g.setState("E4");
    g.setState("D5");
    g.setTurn(1);
    g.setState("E5");
    g.setState("D4");
    g.setTurn(0);
    drawBoard(g);
    //Loops until goal state is reached
    while(true){
      //Input
      if(g.goalState()){
        //Changes turn and other player attempts
        g.setTurn((g.getTurn() == 0) ? 1 : 0);
        if(g.goalState()){
          break;
          break;
          break;
        }
      }
      //Holds next move
      string move;
      int move_n = 0;
      //Player Move
      if(g.getTurn() == 0){
        cin >> move;
        //Forces correct move
        while(g.checkBound(g.boardIndex(move)) == 0){
          cout << "ILLEGAL MOVE. TRY AGAIN" << endl;
          cin >> move;

        }
        //Converts it to an index
        move_n = g.boardIndex(move);
      }
      //AI Move
      else {
        move_n = getMove(g);    
      }
    //Places checker on board
    g.placeChecker(move_n);
    //Changes turn
    g.setTurn((g.getTurn() == 0) ? 1 : 0);
    //Draws on board
    drawBoard(g);
    }
    //Finds winner
    int bval = 0;
    int wval = 0;
    for (int i = 0; i < 64; i++){
     if(g.getState(i) == 'B'){
      bval += 1;
     }
     if(g.getState(i) == 'W'){
      wval += 1;
     }
    }
     if (bval > wval){
      cout << "BLACK WINS" << endl;
     }
     else if(bval < wval){
      cout << "WHITE WINS" << endl;
     }
     else{
      cout << "YOU TIED!" << endl;
     }
    return 0;
}
