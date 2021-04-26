#include <iostream>
#include <cmath>
#include "fint.h"

using namespace std;

fint::fint(int_t n)
{

}

fint::fint(const initializer_list<int_t>& lf,const initializer_list<mult_t>& lm)
{
    factor fact;
    for (int i = 0; i < lf.size(); i++) 
    {
        fact.value = lf.begin()[i];
        fact.exponent = lm.begin()[i];
        array.push_back(fact); // 
    }
}

int fint::assemble(fint f) {
    int v, e, fact;

    fact = 1;
    for (int i = 0; i < f.array.size(); i++) 
    {
        v = f.array[i].value;
        e = f.array[i].exponent;
        fact = fact * pow(v, e);
    }
    return fact;
}

int_t fint::get_value(int index)
{
    return array[index].value;
}

mult_t fint::get_exponent(int index)
{
    return array[index].exponent;
}

int fint::list_size() 
{
    return array.size();
}
