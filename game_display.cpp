#include <iostream>
#include "grid.h"

using namespace std;

void drawBoard(grid states)
{
  //Row names
  char line = 'A';
  //column names.  
  cout << "       1         2         3         4         5         6         7         8\n";   
  
  //for loop governs which row you're working on.
  for(int i = 0; i < 8; i++)
    {
      //for loop governs which line of the row you're working on.
      for(int j = 0; j < 5; j++)
	{
    //prints left border.
	  if(j != 2)
	    cout << "  X";
    //prints out the character for the row names.
	  else if(j == 2 && line < 'I')
	    {
	      cout << line << " X";
	      line++;
	    }
    //works with what columns to print in.
	  for(int k = 0; k < 8; k++)
	    {
        //print a line.
	      if(j == 0 && k == 0)
		cout << "XXXXXXXXX";
	      else if(j == 0 && k > 0)
		cout << "XXXXXXXXX";
        //prints white
	      else if((j == 1 || j == 4) && states.getState(8 * i + k) == 'W')
		cout << "   XXX   ";
	      else if((j == 2 || j == 3) && states.getState(8 * i + k) == 'W')
		cout << "  XXXXX  ";
	      //print black
        else if((j == 1 || j == 4) && states.getState(8 * i + k) == 'B')
		cout << "   X X   ";
	      else if((j == 2 || j == 3) && states.getState(8 * i + k) == 'B')
		cout << "  X   X  ";
	      else
		cout << "         ";

	      cout << "X";
	    }
	  cout << endl;
	}
    }
  
  for(int i = 0; i < 1; i++)
    cout << "  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";   
}

