#include "fint.h"

using namespace std;

fint::fint(int_t n)
{

}

fint::fint(const initializer_list<int_t>& lf,const initializer_list<mult_t>& lm)
{
    Factor fact;
    for (int i = 0; i < lf.size(); i++) 
    {
        fact.base = lf.begin()[i];
        fact.exponent = lm.begin()[i];
        factors.push_back(fact); // 
    }
}

int fint::assemble(fint f) {
    int v, e, fact;

    fact = 1;
    for (int i = 0; i < f.factors.size(); i++) 
    {
        v = f.factors[i].base;
        e = f.factors[i].exponent;
        fact = fact * pow(v, e);
    }
    return fact;
}

int_t fint::get_base(int index)
{
    return factors[index].base;
}

mult_t fint::get_exponent(int index)
{
    return factors[index].exponent;
}

int fint::vector_size() 
{
    return factors.size();
}
