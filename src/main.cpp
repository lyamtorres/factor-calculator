#include <iostream>
#include "fint.h"

using namespace std;

int main() {
    //fint f({2,5,13,83}, {2,3,2,1});

    fint f1(50);
    fint f2(100);

    fint newF = lcm(f1, f2);
    cout << newF.to_int() << endl;


/*     cout << "f.base : ";
    for (int i = 0; i < f.vector_size(); i++) {
        cout << f.get_base(i) << " -> ";
    }
    cout << "fin" << endl;

    cout << "f.exponent : ";
    for (int i = 0; i < f.vector_size(); i++) {
        cout << f.get_exponent(i) << " -> ";
    }
    cout << "fin" << endl;
    cout << "" << endl;

    cout << f.assemble() << endl; */

    //cout << f1.is_prime() << endl;
}
