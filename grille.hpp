#ifndef GRILLE_HPP
#define GRILLE_HPP


#include <cmath>
#include <iostream>
using namespace std;

#include "animal.hpp"



struct grille{
    Animal tab[TAILLE_GRILLE][TAILLE_GRILLE];
};


void grilleVide(grille &g) ;
void copieGrille(grille g1, grille &g2) ;

Animal getAnimal(grille g, coord c) ;
void setAnimal(grille &g, Animal a);
void verifieGrille(grille g) ;
void afficheGrille(grille g);
void initialiseGrille(grille &g);
EnsCoord voisinespece(grille g,coord c, Espece e);
EnsCoord voisinvide(grille g,coord c);
void compteEspeces(grille g, int &lapin, int &renard);
#endif
