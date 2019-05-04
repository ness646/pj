#include <cmath>
#include <iostream>

#include "grille.hpp"

using namespace std;

int main(){
	cout<<hasard()<<endl;
	grille g;
	grilleVide(g);
	afficheGrille(g);
	initialiseGrille(g);
	afficheGrille(g);
  return 0;
}