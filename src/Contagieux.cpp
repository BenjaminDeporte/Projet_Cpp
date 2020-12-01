#include "Contagieux.h"
#include <iostream>
using namespace std;

Contagieux::Contagieux()
{
    this->nombre = 0; // le village
    this->duree_contagiosite = 14; // un porteur de covid est contagieux 14 jours par d�faut

    cont = new int[duree_contagiosite];  // la population totale est divis�e en <duree_contagiosite> compartiments
    for (int i=1; i<duree_contagiosite; i++)   // initialisation de la population contagieuse : tout le monde � j=0
    {
        cont[i] = 0;
    }
    cont[0] = this->nombre;
}

Contagieux::Contagieux(int nombre = 65000000, int duree_contagiosite=14)
{
    this->nombre = nombre;
    this->duree_contagiosite = duree_contagiosite;

    cont = new int[duree_contagiosite];  // la population totale est divis�e en <duree_contagiosite> compartiments
    for (int i=1; i<duree_contagiosite; i++)   // initialisation de la population contagieuse : tout le monde � j=0
    {
        cont[i] = 0;
    }
    cont[0] = this->nombre;
}

Contagieux::~Contagieux()
{
    delete[] cont;
}

void Contagieux::affichage()
{
    cout << "(aff classe Cont) Population Contagieuse : " << this->nombre << endl;

    // lignes ci-dessous pour debug �ventuel
    //for(int i=0; i<duree_contagiosite; i++)
    //{
    //    cout << "nombre contagieux j=" << i+1 <<" = "<< cont[i] << endl;
    //}
}


int Contagieux::evolution()
{
    // evolution de la population de t � t+1
    int sortis = cont[duree_contagiosite-1];  // les ontagieux depuis le plus longtemps sortent de la cat�gorie

    for (int i=duree_contagiosite-2; i>=0; i--)  // d�calage dans le temps des nombres de contagieux depuis x jours
    {
        cont[i+1] = cont[i];
    }
    cont[0] = 0;  // il faudra remettre en entr�e le nouveau nombre d'infect�s
    this->nombre -= sortis;
    return sortis;  // sortis de la contagion : soit remis, soit DCD.
}

void Contagieux::add_new_inf(int nouveaux)
{
    cont[0] += nouveaux;
    this->nombre += nouveaux;
}

