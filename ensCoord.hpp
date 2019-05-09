#ifndef ENSCOORD_HPP
#define ENSCOORD_HPP

#include <cmath>
#include <iostream>
using namespace std;
/** Infrastructure minimale de test **/
#define ASSERT(test)                                                           \
    if (!(test))                                                               \
    cout << "Test failed in file " << __FILE__ << " line " << __LINE__         \
         << ": " #test << endl

const int MAXENSCOORD=15; 
const int TAILLE_GRILLE=20;


/* Créer une structure coord */
struct coord {

    int ligne; 

    int colonne; 
}; 

 
/* Créer une structure ensemble de coordonnées*/ 
struct EnsCoord{

      coord tab[MAXENSCOORD] ; 

      int nbElts; 


};


coord creerCoord(int ligne,int colonne);

    /* Créer une coordonnée (x,y)    */ 
 
 
void afficheCoord (coord c);

    /* Afficher une coordonnée 

       @param c une coordonée  

       @return la cordonnée (ligne,colonne) 
       
*/
    
int getX(coord c);

    /* Affiche la première coordonée de c 

       @param c les coordonnées 
    
*/

int getY(coord c);

    /* Affiche la deuxième coordonée de c 

       @param c les coordonnées 
    
*/
    
bool egalCoord(coord c1,coord c2);

    /* Affiche si les deux coordonnées sont égales 

       @param c1 une coordonnée 

       @param c2 une coordonnée 

       @return vrai si c1 = c2  
    
*/
 
void afficheEC(EnsCoord ec);

    /* Afficher l'ensemble de coordonnées  

       @param ec un ensemble de coordonnées */ 
 
 
EnsCoord CreerEC();

    /* Afficher un ensemble de coordonnées ne contenant aucun élément */ 
   
   
void ajouteEC(EnsCoord &ec, coord c);

    /* Ajouter une coordonnée à un ensemble de coordonnées 

       @param ec un ensemble de coordonnées  

       @param c une coordonnée 
*/
    
int cardEC (EnsCoord ec);

    /* Afficher le nombre d’éléments d’un ensemble de coordonnées 

       @param ec un ensemble de coordonnées 
       
*/
 
EnsCoord trouverVoisins( coord c);

    /* Afficher l’ensemble des coordonnées des voisines d'une coordonnée c 

       @param c une coordonnée 
    
*/
    
void randomEC (EnsCoord ec);

    /* Afficher une coordonnée au hasard dans un ensemble de coordonnées 

       @param ec un ensemble de coordonnées 
*/ 

void supprimeEC(EnsCoord &ec,coord c);

    /*  Supprimer un élément d’un ensemble de coordonnées 

        @param ec un ensemble de coordonnées 
*/

#endif
