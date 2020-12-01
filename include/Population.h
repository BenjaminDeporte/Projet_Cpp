#ifndef POPULATION_H
#define POPULATION_H


class Population
{
    private:

    protected:
        int nombre; // nombre d'individus dans la population

    public:
        Population();   // constructeur par d�faut
        Population(int taille);  // constructeur France
        virtual ~Population();

        virtual void affichage();  // affichage d'infos sur l'objet instanci�

        int get_nombre();   // renvoie la taille de la population
        void set_nombre(int taille);  // d�finit la taille de la population
};

#endif // POPULATION_H
