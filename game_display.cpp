#include <iostream>

using namespace std;

void drawBoard(int states[64])
{
  char line = 'A';
  cout << "       1         2         3         4         5         6         7         8\n";   
  for(int i = 0; i < 8; i++)
    {
      for(int j = 0; j < 5; j++)
	{
	  if(j != 2)
	    cout << "  X";
	  else if(j == 2 && line < 'I')
	    {
	      cout << line << " X";
	      line++;
	    }
	  for(int k = 0; k < 8; k++)
	    {
	      if(j == 0 && k == 0)
		cout << "XXXXXXXXX";
	      else if(j == 0 && k > 0)
		cout << "XXXXXXXXX";
	      else if((j == 1 || j == 4) && states[(8 * i + k)] == 1)
		cout << "   XXX   ";
	      else if((j == 2 || j == 3) && states[(8 * i + k)] == 1)
		cout << "  XXXXX  ";
	      else if((j == 1 || j == 4) && states[(8 * i + k)] == 2)
		cout << "   X X   ";
	      else if((j == 2 || j == 3) && states[(8 * i + k)] == 2)
		cout << "  X   X  ";
	      else
		cout << "         ";

	      cout << "X";
	    }
	  cout << endl;
	}
    }
  
  for(int i = 0; i < 5; i++)
    cout << "  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";   
}

int main()
{
  int state[64];
  for(int i = 0; i < 64; i++)
    state[i] = 0;
  state[27] = 1;
  state[28] = 2;
  state[35] = 2;
  state[36] = 1;
  state[0] = 1;
  drawBoard(state);
}
