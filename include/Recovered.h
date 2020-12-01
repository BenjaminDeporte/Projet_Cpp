#ifndef RECOVERED_H
#define RECOVERED_H

#include <Population.h>


class Recovered : public Population
{
    public:
        Recovered();
        Recovered(int nombre);
        virtual ~Recovered();

        void affichage();   // polymorphisme sur la méthose affichage de Population

        void add_new_rec(int nouveaux);  // ajoute de nouveaux 'recovered'

    protected:

    private:
};

#endif // RECOVERED_H
