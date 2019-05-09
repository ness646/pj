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

struct coord {
    int ligne;
    int colonne;
  }; 
 
 struct EnsCoord{
      coord tab[MAXENSCOORD] ;
      int nbElts;
        
 } ;
  
 coord creerCoord(int ligne,int colonne);
 
 
 
void afficheCoord (coord c);
 
int getX(coord c);
 
int getY(coord c);
 
bool egalCoord(coord c1,coord c2);
 
void afficheEC(EnsCoord ec);
 
EnsCoord CreerEC();
 
void ajouteEC(EnsCoord &ec, coord c);
 
int cardEC (EnsCoord ec);
 
EnsCoord trouverVoisins( coord c);

void supprimeEC(EnsCoord &ec,coord c);

coord randomEC(EnsCoord ec);

#endif
