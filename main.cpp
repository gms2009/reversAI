#include <iostream>
#include "grid.h"

using namespace std;

int
main(){
    grid g;
    g.setState("C1");
    g.setTurn(1);
    g.setState("B1");
    g.setTurn(0);
    cout << +g.checkBound(g.boardIndex("A1")) << endl;
    //cout << state << endl;
    return 0;
}
