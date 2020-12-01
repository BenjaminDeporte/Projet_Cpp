#include "Population.h"
#include <iostream>
using namespace std;

// classe Parent Population

Population::Population()
{
    this->nombre = 100;   // constructeur par défaut : village 100 personnes
}

Population::Population(int taille = 65000000)
{
    this->nombre = taille;
}

Population::~Population()
{
    //dtor
}

void Population::affichage()
{
    cout << "(aff classe Pop) Taille population = " << this->nombre << endl;
}

int Population::get_nombre()   // renvoie la taille de la population
{
    return(this->nombre);
}

void Population::set_nombre(int taille)  // définit la taille de la population
{
    this->nombre = taille;
}
