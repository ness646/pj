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

    /* Initialiser une grille vide 

       @param g une grille 

       @return chaque ligne i et colonne j en l'initialisant en case Vide 
     
*/
void copieGrille(grille g1, grille &g2) ;

    /* Copier une grille g1 dans une autre grille 2 

       @param g1 une grille  

       @param g2 deux grilles 

       @return l'égalité g1=g2 en mettant ce qu'il y a dans g1 dans g2  
    
*/

Animal getAnimal(grille g, coord c) ;

    /* Accéder à un animal pour le modifier dans la grille situé aux coordonnées indiquées 

       @param g une grille  

       @param c des coordonnées dans la grille 

       @return une copie de l'animal 
    
*/
    
void setAnimal(grille &g, Animal a);

    /* Ranger un animal dans la grille après l'avoir modifié, on connait ses coordonnées donc on n'utilise pas le parametre coord 

       @param g la grille 

       @param a un animal 

       @return une case de la grille avec l'animal rangé dedans 
       
*/
    
void verifieGrille(grille g) ;

    /* Vérifier si hchaque animal est bien à sa place dans la grille 

       @param g la grille 

       @return si les coordonnés de chaque animal corresponent à celles vérifiées 


*/
    
   
void afficheGrille(grille g);

    /* Afficher la grille 

       @param g la grille 

       @return la grille 
    
    
*/
void initialiseGrille(grille &g);

    /* Initialiser toute la grille 

       @param g la grille 

       @return une nouvelle grille initialisé avec les trois especes Vide Renard et Lapin  
    
    
*/

EnsCoord voisinespece(grille g,coord c, Espece e);
EnsCoord voisinvide(grille g,coord c);
void compteEspeces(grille g, int &lapin, int &renard);
#endif
