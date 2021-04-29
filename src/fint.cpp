#include "fint.h"

using namespace std;

fint::fint(int_t n) {
    int_t base = 0;
    mult_t exponent = 1;

    while (n % 2 == 0) {
        if (base == 0) {
            base = 2;
        } else {
            exponent += 1;
        }
        n /= 2;
    }
    if (base != 0) {
        factors.push_back(make_pair(base, exponent));
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        base = 0;
        exponent = 1;
        while (n % i == 0) {
            if (base == 0) {
                base = i;
            } else {
                exponent += 1;
            }
            n /= i;
        }
        if (base == i) {
            factors.push_back(make_pair(base, exponent));
        }
    }

    if (n > 2) {
        base = n;
        exponent = 1;
        factors.push_back(make_pair(base, exponent));
    } 
}

fint::fint(const initializer_list<int_t>& lf,const initializer_list<mult_t>& lm) {
    int_t base;
    mult_t exponent;

    for (int i = 0; i < lf.size(); i++) {
        base = lf.begin()[i];
        exponent = lm.begin()[i];
        factors.push_back(make_pair(base, exponent));
    }
}

int_t fint::to_int() const {
    int_t base, result;
    mult_t exponent;

    result = 1;
    for (int i = 0; i < factors.size(); i++) {
        base = factors[i].first;
        exponent = factors[i].second;
        result = result * pow(base, exponent);
    }
    return result;
}

/* bool fint::divides(const fint& a) const {
    for (int i = 0; i < this->factors.size(); i++) {
        if (this->factors[i].first != a.factors[i].first || this->factors[i].second < a.factors[i].second) {
            return 0;
        }
    }
    return 1;   
} */

bool fint::is_prime() const {
    return (this->factors.size() <= 1 && this->factors[0].second == 1);
}

bool operator==(const fint& a, const fint& b) {
    if (a.factors.size() != b.factors.size()) {
        return 0;
    }
    for (int i = 0; i < a.factors.size(); i++) {
        if (a.factors[i].first != b.factors[i].first || a.factors[i].second != b.factors[i].second) {
            return 0;
        }
    }
    return 1;   
}

bool operator!=(const fint& a, const fint& b) {
    return !operator==(a, b);
}

ostream& operator<<(std::ostream& os, const fint& a) {
    os << "{";
    for (int i = 0; i < a.factors.size(); i++) {
        if (i != a.factors.size() - 1) {
            os << a.factors[i].first << ", ";
        } else {
            os << a.factors[i].first;
        }
    }
    os << "}" << endl;

    os << "{";
    for (int i = 0; i < a.factors.size(); i++) {
        if (i != a.factors.size() - 1) {
            os << a.factors[i].second << ", ";
        } else {
            os << a.factors[i].second;
        }
    }
    os << "}" << endl;

    return os;
}


/* 

bool fint::divides(const fint& a) const {
    return a.to_int() % this->to_int() == 0;   
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
 
*/