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

const int TAILLE_GRILLE=20;
const int MAXENSCOORD=TAILLE_GRILLE*TAILLE_GRILLE; 

/* Créer une structure coord */
struct coord {
    int ligne;
    int colonne;
  }; 
 
/* Créer une structure ensemble de coordonnées*/ 
 struct EnsCoord{
      coord tab[MAXENSCOORD] ;
      int nbElts;
        
 } ;
 
/* Créer une coordonnée (x,y)    */ 
 coord creerCoord(int ligne,int colonne);
 
 
 /* Afficher une coordonnée 

       @param c une coordonée  

       @return la cordonnée (ligne,colonne) */
void afficheCoord (coord c);
 /*recupere une coordonnée en X*/
int getX(coord c);
 /*recupere une coordonnée en y*/
int getY(coord c);
   
/* Affiche si les deux coordonnées sont égales 

       @param c1 une coordonnée 

       @param c2 une coordonnée 

       @return vrai si c1 = c2  
    
*/
bool egalCoord(coord c1,coord c2);
 
 /* Afficher l'ensemble de coordonnées  

  @param ec un ensemble de coordonnées */ 
void afficheEC(EnsCoord ec);
 
 /* Afficher un ensemble de coordonnées ne contenant aucun élément */ 
EnsCoord CreerEC();
  
/* Ajouter une coordonnée à un ensemble de coordonnées 

       @param ec un ensemble de coordonnées  

       @param c une coordonnée 
*/
void ajouteEC(EnsCoord &ec, coord c);
  

/* Afficher le nombre d’éléments d’un ensemble de coordonnées 

       @param ec un ensemble de coordonnées 
       
*/
 
int cardEC (EnsCoord ec);
 
/* Afficher l’ensemble des coordonnées des voisines d'une coordonnée c 

       @param c une coordonnée 
    
*/
EnsCoord trouverVoisins( coord c);
 /*  Supprimer un élément d’un ensemble de coordonnées 

        @param ec un ensemble de coordonnées 
*/
 
void supprimeEC(EnsCoord &ec,coord c);
/* Afficher une coordonnée au hasard dans un ensemble de coordonnées 

       @param ec un ensemble de coordonnées 
*/ 
coord randomEC(EnsCoord ec);

#endif
