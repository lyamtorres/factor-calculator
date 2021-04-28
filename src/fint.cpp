#include "fint.h"

using namespace std;

fint::fint(int_t n) {
    Factor fact;
    
    fact.base = 0;
    fact.exponent = 1;

    while (n % 2 == 0) {
        if (fact.base == 0) {
            fact.base = 2;
        } else {
            fact.exponent += 1;
        }
        n /= 2;
    }
    if (fact.base != 0) {
        factors.push_back(fact);
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        fact.base = 0;
        fact.exponent = 1;
        while (n % i == 0) {
            if (fact.base == 0) {
                fact.base = i;
            } else {
                fact.exponent += 1;
            }
            n /= i;
        }
        if (fact.base == i) {
            factors.push_back(fact);
        }
    }

    if (n > 2) {
        fact.base = n;
        fact.exponent = 1;
        factors.push_back(fact);
    } 
}

fint::fint(const initializer_list<int_t>& lf,const initializer_list<mult_t>& lm) {
    Factor factor;

    for (int i = 0; i < lf.size(); i++) {
        factor.base = lf.begin()[i];
        factor.exponent = lm.begin()[i];
        factors.push_back(factor);
    }
}

int_t fint::to_int() const {
    int_t b, e, result;

    result = 1;
    for (int i = 0; i < factors.size(); i++) {
        b = factors[i].base;
        e = factors[i].exponent;
        result = result * pow(b, e);
    }
    return result;
}

bool fint::divides(const fint& a) const {
    return a.to_int() % this->to_int() == 0;    
}

bool fint::is_prime() const {
    return is_prime_integer(this->to_int());
}

bool operator==(const fint& a, const fint& b) {
    return a.to_int() == b.to_int();
}

bool operator!=(const fint& a, const fint& b) {
    return a.to_int() != b.to_int();
}

fint operator*(const fint& a, const fint& b) {
    fint f(a.to_int() * b.to_int());
    return f;
}

fint operator/(const fint& a, const fint& b) {
    try {
        if (b.divides(a) == false) {
            throw domain_error("b doit diviser a.");
        }
        fint f(a.to_int() / b.to_int());
        return f;
    } catch (domain_error error) {
        cout << "Erreur : " << error.what() << endl;
    }
    exit(1);
}


bool fint::is_prime_integer(int n) const {
    static int i = 2;

    if(n == 0 || n == 1) {
        return false;
    }
    if(n == i) {
        return true;
    }
    if(n % i == 0) {
        return false;
    }
    i += 1;

    return is_prime_integer(n);
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
