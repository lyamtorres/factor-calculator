#include <iostream>
#include <vector>
#include "fint.h"

using namespace std;

int main() {
    fint f({2,5,13,83}, {2,3,2,1});

    int nombre = f.assemble(f);

    cout << nombre << endl;
    
}
