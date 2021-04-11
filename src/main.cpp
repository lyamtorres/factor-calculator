#include <iostream>
#include <vector>
#include "fint.h"

using namespace std;

int main() {
    vector<int> data = {1, 2, 3};
    data.push_back(12);
    cout << data[3] << endl;
}