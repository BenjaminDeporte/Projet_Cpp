#ifndef POPULATION_H
#define POPULATION_H


class Population
{
    private:

    protected:
        int nombre; // nombre d'individus dans la population

    public:
        Population();   // constructeur par défaut
        Population(int taille);  // constructeur France
        virtual ~Population();

        virtual void affichage();  // affichage d'infos sur l'objet instancié

        int get_nombre();   // renvoie la taille de la population
        void set_nombre(int taille);  // définit la taille de la population
};

#endif // POPULATION_H
