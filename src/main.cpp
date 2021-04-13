#include <iostream>
#include <vector>
#include "fint.h"

using namespace std;

int main() {
    fint f({2,5,11}, {1,2,2});

    cout << f.get_valeur(2) << endl;
    cout << f.get_puissance(0) << endl;

    cout << f.list_size() << endl;
}
