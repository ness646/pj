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


EnsCoord toutEspece(grille g, Espece e) {
  EnsCoord ec=CreerEC();
  coord c;
  for(int i=0;i<TAILLE_GRILLE;i++){
     for(int j=0;j<TAILLE_GRILLE;j++){
          c=creerCoord(j,i);
      if (especeAnimal(getAnimal(g,c))==e) {
        ajouteEC(ec,c);
      }
    }
  }
  return ec;
}


//void deplaceanimal(



void deplacetousleslapins(grille g, grille &ng){
  EnsCoord ec=CreerEC();
  ec=toutEspece(g, Lapin);
  coord c;
  Animal a;
  while(cardEC(ec)!=0){
    c= randomEC(ec);
    a=getAnimal(g,c);
    deplaceAnimal(g, ng, a);
    int nbVide = cardEC(voisinvide(g,c));
    if(seReproduitAnimal(a,nbVide)){
      setAnimal(ng, creerAnimal(Lapin,c));
    }
    supprimeEC(ec, c);
  }
}

    

   



void deplaceAnimal(grille g, grille &ng, Animal &a){
  coord res;
  coord c = coordAnimal(a);
  EnsCoord ec =voisinespece(g, c,Vide);
  if(not mortAnimal(a)){
    if (cardEC(ec) != 0){
      if( especeAnimal(a) == Renard ){
        if(not attaqueRenard(g,a)){
          res = randomEC(ec);
          changeCoordAnimal(a, res);
          faimRenard(a);
        }
      } else {
        res = randomEC(ec);
        changeCoordAnimal(a,res);
      }
    }
    setAnimal(ng, a);
  }
  
}




bool attaqueRenard(grille g, Animal &a){
  if( especeAnimal(a) == Renard ){
    EnsCoord ec = (g, coordAnimal(a));
    if(cardEC(ec) == 0 ){
      return false;
    } else {
      coord c = randomEC(ec);
      changeCoordAnimal(a, c);
      mangeRenard(a);
      return true;
    }
  } else {
    cout << "N est pas un renard ! Ne peut pas attaquer !" << endl;
        return false;
  }
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
