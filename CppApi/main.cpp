#include <iostream>
#include "Cube.h"
#include "CubeConstants.h"

using namespace std;

int main() {
    Cube c(169, 2, 3, 4, 5, 6);
    Cube c1(169, 2, 3, 4, 5, 6);
    if(c == c1){
        cout << "JEP" << endl;
    }
    unsigned test = 169;
    c.setSequence(1, 7, test);
    cout << test << endl;
    cout << c.getSequence(1, test) << endl;

    for (int i = 0; i < 18; ++i) {
        c.rotate(i);
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
