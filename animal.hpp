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
const float ProbRenard=0.20; 
const float ProbLapin=0.07; 

enum Espece {Vide,Lapin,Renard};
struct Animal{
   Espece espece;
   int food;
   coord c;
};


float hasard();
Animal creerAnimal(Espece e, coord c);

    /*  Crée un animal connaissant son espèce, et ses scoordonnées sur la grille  

        @param e l'espece de l'animal,  

        @param c ses coordonées 

        @return un Animal a 
     

    */    


coord coordAnimal( Animal a);

    /*  Afficher les coordonées d'un animal 

        @param a un animal 

        @return les coordonnées a.c  
  
*/


Espece especeAnimal( Animal a);

     /* Afficher l'espece 

        @param a un animal 

        @return l'espece entre Vide Lapin ou Renard 


*/

int nourritureRenard(Animal a);

     /* Afficher le niveau de nourriture 

        @param a un animal 

        @return le niveau de nourriture a.food 

*/


bool estVide (Animal a);

    /* Afficher si la case ne contient aucun animal 

       @param a un animal 

       @return vrai si aucun animal n'es présent donc si la case est egal à Vide 
 
*/
    
void changeCoordAnimal(Animal &a, coord c);

    /* Déplacer un animal 

       @param a un animal  

       @param c ses coordonnées 

       @return les nouvelles coordonnées a.c 
    
*/ 

void mangeRenard(Animal &a);

    /* Augmente le niveau de nourriture du Renard quand il mange un Lapin 

       @param a un animal 

       @return la nourriture du Renard a.food quand il a mangé un Lapin FoodLapin  

*/

void faimRenard(Animal &a);

    /* Diminue d'une unité le niveau de nourriture du renard 

       @param a un animal 

       @return la valeur a.food - 1 en diminuant la valeur de la nourriture 

*/

bool mortAnimal(Animal a);

    /* Afficher si l'animal est mort 

       @param a un animal 

       @return vrai si l'animal meurt 

*/


bool seReproduitAnimal(Animal a, int nbVoisinsVides);

    /* Afficher si l'animal se reproduit 

       @param a un animal  

       @param nbVoisinsVides tous les voisins vide de cet animal 

       @return vrai si l'animal meurt 

*/
#endif
