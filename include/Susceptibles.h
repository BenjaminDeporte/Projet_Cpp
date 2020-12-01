#ifndef SUSCEPTIBLES_H
#define SUSCEPTIBLES_H

#include <Population.h>


class Susceptibles : public Population
{
    public:
        Susceptibles();
        Susceptibles(int nombre);  // constructeur avec nombre
        virtual ~Susceptibles();

        void affichage();  // affichage d'infos sur l'objet instanci�
                            // polymorphisme sur affichage() de la classe parent

        // int get_nombre();   HERITE // renvoie la taille de la population
        // void set_nombre(int taille);  HERITE // d�finit la taille de la population

        void evolution(int p);    // m�thode d'�volution de la population, variation p individus

    protected:

    private:
        // h�rite de l'attribut nombre
};

#endif // SUSCEPTIBLES_H
