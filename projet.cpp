#include <cmath>
#include <iostream>

#include "grille.hpp"

using namespace std;



EnsCoord toutEspece(grille g, Espece e) {
  EnsCoord ec;
  coord c;
  for(int i=0;i<ec.nbElts;i++){
     for(int j=0;j<ec.nbElts;j++){
          c=creerCoord(j,i);
      if (especeAnimal(getAnimal(g,c))==e) {
        ajouteEC(ec,c);
      }
    }
  }
  return ec;
}





int main(){
	cout<<hasard()<<endl;
	grille g;
	grilleVide(g);
	afficheGrille(g);
	initialiseGrille(g);
	afficheGrille(g);
  return 0;
}
