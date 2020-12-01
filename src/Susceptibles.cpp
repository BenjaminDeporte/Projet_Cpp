#include "Susceptibles.h"
#include <iostream>
using namespace std;

Susceptibles::Susceptibles()
{
    this->nombre = 100;
}

Susceptibles::Susceptibles(int nombre = 65000000)
{
    this->nombre = nombre;
}

Susceptibles::~Susceptibles()
{
    //dtor
}


void Susceptibles::affichage()
{
    cout << "(aff classe Susc) Population saine = " << this->nombre << endl;
}

void Susceptibles::evolution(int p)
{
     // méthode d'évolution de la population,
     // la population saine diminue de p, voire tombe à 0.

     if (this->nombre > p)
     {
        this->nombre -= p;
     }
     else
     {
        this->nombre = 0;
     }
}
