#include <iostream>
#include "grid.h"

using namespace std;

int
main(){
    grid g;
    g.setState("A3");
    char state = g.getState("A3");
    cout << state << endl;
    return 0;
}
