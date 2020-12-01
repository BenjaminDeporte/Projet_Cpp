#include <iostream>
using namespace std;

#include "Population.h"
#include "Susceptibles.h"
#include "Contagieux.h"
#include "Recovered.h"


int main()
{
    const int POPULATION_TOTALE = 65000000; // population de départ
    const int SEED = 100; // population contagieuse au départ
    const float R0 = 0.1; // nombre moyen de personnes infectées par contagieux par jour
    const int DUREE_CONTAGIOSITE = 14; // pour test

    Susceptibles s(POPULATION_TOTALE - SEED);
    Contagieux c(SEED, DUREE_CONTAGIOSITE);
    Recovered r(0);

    Susceptibles *p_s = &s;
    Contagieux *p_c = &c;
    Recovered *p_r = &r;

    int sortis;
    int nvx_cas = 1; // fake value pour démarrer la boucle while

    int jour = 0;

    float max_cas = 0.0; // maximum nouveaux cas journaliers

    float coeff = 1.0; // coefficient confinement : c=1 = pas de confinment, c=0 = confinement total, aucun contact

    while (nvx_cas > 0)
    {
        // affiche les donnéés
        cout << "Jour " << jour << endl;

        p_s->affichage();
        p_c->affichage();
        p_r->affichage();  // polymorphisme sur affichage() de Population

        // moteur du jour
        nvx_cas = int(p_c->get_nombre() * R0 * coeff * p_s->get_nombre()/POPULATION_TOTALE);  // nombre d'infectés du jour

        if (nvx_cas > p_s->get_nombre())  // le nombre de nouveaux cas est borné supérieurement par le nombre de personnes saines !
        {
            nvx_cas = p_s->get_nombre();
        }
        p_s->evolution(nvx_cas);
        cout << "nouveaux cas = " << nvx_cas << endl;
        if (nvx_cas > max_cas)  // mise à jour éventuelle du pic journalier
        {
            max_cas = nvx_cas;
        }

        sortis = p_c->evolution(); // evolution des contagieux : décalage de +1 des jours d'infection;
        p_c->add_new_inf(nvx_cas);  // ajoute les nouveaux contagieux
        p_r->add_new_rec(sortis); // on ajoute les personnes sorties de l'infection aux recovered

        jour++;
    }

    cout << "pic journalier = " << max_cas << " cas" << endl;  // affiche le pic journalier
    cout << "duree epidemie = " << jour << " jours" << endl; // nombre jours jusqu'à ce que nouveaux cas = 0
    cout << "population ayant ete infectee = " << (1-(float(p_s->get_nombre()) / float(POPULATION_TOTALE)))*100 << "%" << endl;  // affiche le %age correspondant à l'immunité collective
}
