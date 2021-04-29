#ifndef FINT_H
#define FINT_H

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <stdexcept>

// choix d'un type entier non signé
typedef unsigned long int int_t;
typedef unsigned short int mult_t;

// valeur maximum du type entier choisi
static const int_t MAX_INT_T = std::numeric_limits<int_t>::max();

// ------------------------------------------------------------------
// Définition partielle de la classe fint à compléter SANS MODIFIER
// les signatures des opérations fournies ci-après, ce qui permettra
// au professeur de compiler un programme utilisateur de son choix
// qui respecte cette spécification.
// ------------------------------------------------------------------
class fint {
public:
   // constructeur à partir d'un entier n >= 1
   fint(int_t n);

   // constructeur à partir d'une liste de facteurs premiers lf
   // et d'une liste de multiplicité lm telles que lm et lf ont la
   // même taille et lm[i]>0 est la multiplicité de lf[i] pour tout i
   // exemple d'appel de ce constructeur :
   // fint f({2,5,11}, {1,2,2});
   fint(const std::initializer_list<int_t>& lf,
        const std::initializer_list<mult_t>& lm);

   // destructeur
   // ~fint();

   // retourne la valeur décimale de this, throws std::overflow_error
   int_t to_int() const;

   // teste si this divise a
   bool divides(const fint& a) const;

   // teste si this est premier
   bool is_prime() const;

   // teste si a est égal à b
   friend bool operator==(const fint& a, const fint& b);

   // teste si a est different de b
   friend bool operator!=(const fint& a, const fint& b);
   
   // retourne le plus petit commun multiple de a et b
   friend fint lcm(const fint& a, const fint& b);

   // retourne le plus grand diviseur commun de a et b
   friend fint gcd(const fint& a, const fint& b);

   // retourne a * b
   friend fint operator*(const fint& a, const fint& b);

   // retourne a / b si b divise a, throws std::domain_error sinon
   friend fint operator/(const fint& a, const fint& b);

   // retourne a % b
   friend fint operator%(const fint& a, const fint& b);

   // retourne a puissance n
   friend fint pow(const fint& a, unsigned int n);

   // écriture de a sur un flot de sortie
   friend std::ostream& operator<<(std::ostream& os, const fint& a);

   bool is_prime_integer(int n) const;

   int_t get_base(int index) const;

   mult_t get_exponent(int index) const;

   int vector_size();

private:
/*    struct Factor {
      int_t base;
      mult_t exponent;
   }; */

   //std::vector<Factor> factors;
   std::vector<std::pair<int_t, mult_t>> factors;
};

#endif
