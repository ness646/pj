#include <cmath>
#include <iostream>

#include "grille.hpp"
#include <unistd.h>

using namespace std;


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


bool attaqueRenard(grille &g, Animal &a){
 EnsCoord voisins;
  coord c;
  Animal animalCase, nouveauNe;
  if(especeAnimal(a) == Renard){
    voisins = trouverVoisins( creerCoord(getX(a.c), getY(a.c)));

      //on teste toutes les cases autour au hasard
      while(cardEC(voisins)!=0){
        c = randomEC(voisins);
        animalCase = g.tab[getX(c)][getY(c)];
        if(especeAnimal(animalCase) == Lapin){
          if(seReproduitAnimal(a,voisins.nbElts)){
            nouveauNe = creerAnimal(Renard, coordAnimal(a));
            setAnimal(g, nouveauNe);
          }
          mangeRenard(a);
          changeCoordAnimal(a, c);
          setAnimal(g, a);
          return true;
        }
      supprimeEC(voisins,c);
      }
  }
  return false;

}


void deplaceAnimal(grille g, grille &ng, Animal &a){
  coord res;
  coord c = coordAnimal(a);
  EnsCoord ec =voisinespece(ng, c,Vide);
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

void deplacetousleslapins_(grille g, grille &ng){
  EnsCoord ec=CreerEC();
  ec=toutEspece(g, Lapin);
  coord c, c1;
  Animal a;
  while(cardEC(ec)>0){
    c= randomEC(ec);
    a=getAnimal(g,c);
    EnsCoord ec1 =voisinespece(ng, c,Vide);
    c1=randomEC(ec1);
    changeCoordAnimal(a, c1);
    setAnimal(ng, a);
    supprimeEC(ec, c);
    //afficheGrille(ng);
  }
}

void deplacetouslesrenard(grille g,grille &ng){
  EnsCoord ensRenard = toutEspece(g, Renard);
  EnsCoord voisins, casesVides;
  Animal nouveauNe;
  coord destination;

    int compteur;
    for(int i = 0; i<cardEC(ensRenard); i++){
    Animal renard = g.tab[getX(ensRenard.tab[i])][getY(ensRenard.tab[i])];

    if(not mortAnimal(renard)){
      //S'il n'est pas mort on prends ses voisins et une destination au hasard parmi celles ci
      voisins = trouverVoisins(creerCoord(getX(ensRenard.tab[i]), getY(ensRenard.tab[i])));
      casesVides = voisinvide(ng, creerCoord(getX(ensRenard.tab[i]), getY(ensRenard.tab[i])));

      if(seReproduitAnimal(renard, voisins.nbElts)){
        nouveauNe = creerAnimal(Renard, coordAnimal(renard));
        setAnimal(ng, nouveauNe);
      }
      //Dans le cas ou il y a un lapin dans la case
      if(not attaqueRenard(ng, renard) and cardEC(casesVides)>0 ){
        destination = randomEC(casesVides);
        faimRenard(renard);
        changeCoordAnimal(renard, destination);
        setAnimal(ng, renard);
      }
    }
  }

}



int main(){
 srand(time(NULL)); //Pour que la fonction aleatoire ne soit pas tt le temps la meme 
//Pourdsgferghjktrdnljbqn3151561
 grille gNew, gOld;

 initialiseGrille(gOld);

 afficheGrille(gOld);

 int lapins, renards;
 compteEspeces(gOld, lapins, renards);
 grilleVide(gNew);
 verifieGrille(gNew);
 /*
 //deplacetousleslapins(gOld,gNew);
 deplacetouslesrenard(gOld,gNew);
 verifieGrille(gOld);
 afficheGrille(gNew);
	*/
while ( (lapins != 0) && (renards != 0) ){
    usleep(1000000);
    grilleVide(gNew);
 	  deplacetousleslapins(gOld,gNew);
 	  deplacetouslesrenard(gOld,gNew);
    copieGrille(gNew, gOld);
    verifieGrille(gOld);
 	  afficheGrille(gNew);
 }

 EnsCoord test = trouverVoisins({0,10});

 afficheEC(test);

 return 0;

}

