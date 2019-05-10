#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <cmath>
#include <iostream>
using namespace std;

#include "ensCoord.hpp"

const int FoodInit=5;
const int MaxFood=10;
const int FoodLapin=5;
const int FoodReprod=8; // CHANGEZ LES VALEURS 
const int ProbbirthRenard=0.05; 
const int minFreebirthlapin=4; 
const float ProbRenard=0.07; 
const float ProbLapin=0.30; 

enum Espece {Vide,Lapin,Renard};
struct Animal{
   Espece espece;
   int food;
   coord c;
};


float hasard();

 /*  Crée un animal connaissant son espèce, et ses scoordonnées sur la grille  

        @param e l'espece de l'animal,  

        @param c ses coordonées 

        @return un Animal a 
     

    */    
Animal creerAnimal(Espece e, coord c);

/*  Afficher les coordonées d'un animal 

        @param a un animal 

        @return les coordonnées a.c  
  
*/

coord coordAnimal( Animal a);

/* Afficher l'espece 

        @param a un animal 

        @return l'espece entre Vide Lapin ou Renard 
*/
Espece especeAnimal( Animal a);
 
/* Afficher le niveau de nourriture 

        @param a un animal 

        @return le niveau de nourriture a.food 

*/
int nourritureRenard(Animal a);

/* Afficher si la case ne contient aucun animal 

       @param a un animal 

       @return vrai si aucun animal n'es présent donc si la case est egal à Vide 
 
*/
bool estVide (Animal a);
 
    /* Déplacer un animal 

       @param a un animal  

       @param c ses coordonnées 

       @return les nouvelles coordonnées a.c 
    
*/ 
void changeCoordAnimal(Animal &a, coord c);

/*Augmente le niveau de nourriture du renard quand il mange un lapin

@param[in/out] l animal

*/
void mangeRenard(Animal &a);

/*Diminue le niveau de nourriture du renard de 1

@param[in/out] l animal

*/
void faimRenard(Animal &a);

  /* Afficher si l'animal est mort 

       @param a un animal 

       @return vrai si l'animal meurt 

*/
bool mortAnimal(Animal a);
  
    /* Afficher si l'animal se reproduit 

       @param a un animal  

       @param nbVoisinsVides tous les voisins vide de cet animal 

       @return vrai si l'animal meurt 

*/
bool seReproduitAnimal(Animal a, int nbVoisinsVides);

#endif
