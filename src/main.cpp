#include <iostream>
#include "fint.h"

using namespace std;

int main() {
    //fint f({2, 5, 13, 83}, {2 ,3 ,2 ,1});

    fint f1(281);
    fint f2(279);

    cout << f1;
    cout << f2;

    cout << operator!=(f1, f2) << endl;

/*     cout << f1.is_prime() << endl;
    cout << f2.is_prime() << endl; */

    /* cout << f2.divides(f1) << endl; */

    /* fint f(7013500); */

/*     cout << f.to_int() << endl;

    cout << "{";
    for (int i = 0; i < f.vector_size(); i++) {
        if (i != f.vector_size() - 1) {
            cout << f.get_base(i) << ", ";
        } else {
            cout << f.get_base(i) << "}" << endl;
        }
    }

    cout << "{";
    for (int i = 0; i < f.vector_size(); i++) {
        if (i != f.vector_size() - 1) {
            cout << f.get_exponent(i) << ", ";
        } else {
            cout << f.get_exponent(i) << "}" << endl;
        }
    } */

/*     fint f(7834543);
    fint f2(10);

    cout << f;
 */

    //cout << f.to_int() << endl;

    //cout << f1.is_prime() << endl;
}
