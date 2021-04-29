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
    int_t b, result;
    mult_t e;

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

fint lcm(const fint& a, const fint& b) {
    fint f1 = gcd(a, b);
    fint f2((a.to_int() / f1.to_int()) * b.to_int());
    return f2;
}

fint gcd(const fint& a, const fint& b) {
    int_t n1, n2, result;

    n1 = a.to_int();
    n2 = b.to_int();
    result = n2;
    while (n1 % n2 > 0) {
        result = n1 % n2;
        n1 = n2;
        n2 = result;
    }
    fint f(result);
    return f;
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

fint operator%(const fint& a, const fint& b) {
    if (b.divides(a) == true) {
        exit(1);
    }
    fint f(a.to_int() % b.to_int());
    return f;
}

fint pow(const fint& a, unsigned int n) {
    int_t x, result;
    
    x = a.to_int();
    result = 1;
    while (n != 0) {
        result *= x;
        n -= 1;
    }
    fint f(result);
    return f;
}

ostream& operator<<(std::ostream& os, const fint& a) {
    os << a.to_int() << endl;
    return os;
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

int_t fint::get_base(int index) const
{
    return factors[index].base;
}

mult_t fint::get_exponent(int index) const
{
    return factors[index].exponent;
}

int fint::vector_size() 
{
    return factors.size();
}
