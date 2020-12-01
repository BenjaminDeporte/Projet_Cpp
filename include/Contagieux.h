#ifndef CONTAGIEUX_H
#define CONTAGIEUX_H

#include <Population.h>


class Contagieux : public Population
{
    public:
        Contagieux();
        Contagieux(int nombre, int duree_contagiosite);    // constructeur avec param�tres :
                                                        // nombre = taille de la population contagieuse
                                                        // duree_contagiosite = nb jours pendant lesquels les individus sont contagieux
        virtual ~Contagieux();

        void affichage();   // polymorphisme sur la m�those affichage de Population

        int evolution();    // evolution de la population contagieuse
                            // renvoie le nombre de personnes 'recovered' ou 'dead' � l'issue de l'infection

        void add_new_inf(int nouveaux); // m�thode pour ajouter de nouveaux infect�s


    protected:

    private:
        // h�rite de nombre par class Population
        int duree_contagiosite;   // dur�e de la contagiosit�, souvent 14 jours
        int *cont;   // pointeur sur un tableau d'entiers.
                    // chaque valeur est le nombre d'individus contagieux depuis x jours
};

#endif // CONTAGIEUX_H
