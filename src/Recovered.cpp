#include "Recovered.h"
#include <iostream>
using namespace std;

Recovered::Recovered()
{
    this->nombre = 0;
}

Recovered::Recovered(int nombre=0)
{
    this->nombre = nombre;
}

Recovered::~Recovered()
{
    //dtor
}

void Recovered::affichage()
{
    cout << "(aff classe Reco) Population Recovered : " << this->nombre << endl;
}

void Recovered::add_new_rec(int nouveaux)
{
    this->nombre += nouveaux;
}
