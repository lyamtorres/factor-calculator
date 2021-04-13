#include <iostream>
#include "fint.h"

using namespace std;

fint::fint(const std::initializer_list<int_t>& lf,const std::initializer_list<mult_t>& lm)
{
    Facteur fact;
    for (int i = 0; i < lf.size(); i++) 
    {
        fact.valeur = lf.begin()[i];
        fact.puissance = lm.begin()[i];
        liste.push_back(fact); // 
    }
}

int_t fint::get_valeur(int indice)
{
    return liste[indice].valeur;
}

mult_t fint::get_puissance(int indice)
{
    return liste[indice].puissance;
}

int fint::list_size() 
{
    return liste.size();
}
