#ifndef SUSCEPTIBLES_H
#define SUSCEPTIBLES_H

#include <Population.h>


class Susceptibles : public Population
{
    public:
        Susceptibles();
        Susceptibles(int nombre);  // constructeur avec nombre
        virtual ~Susceptibles();

        void affichage();  // affichage d'infos sur l'objet instancié
                            // polymorphisme sur affichage() de la classe parent

        // int get_nombre();   HERITE // renvoie la taille de la population
        // void set_nombre(int taille);  HERITE // définit la taille de la population

        void evolution(int p);    // méthode d'évolution de la population, variation p individus

    protected:

    private:
        // hérite de l'attribut nombre
};

#endif // SUSCEPTIBLES_H
