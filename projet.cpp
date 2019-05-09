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
  cout<<" la taille de ec dans toutEspece: "<< cardEC(ec)<<endl;
  return ec;  
}


bool attaqueRenard(grille &g, Animal &a){
    EnsCoord L = voisinespece(g, a.c, Lapin);
    if(cardEC(L)>0){
        coord c = randomEC(L);
        changeCoordAnimal(a,c);
        mangeRenard(a);
        setAnimal(g,a);
        return true;
    }
    else{
              cout<<"mange"<<endl;

        return false;
    }

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
  cout<<" la taille de ec est: "<< cardEC(ec)<<endl;
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
  cout<<" la taille de ec est: "<< cardEC(ec)<<endl;
  int compteur=0;
  cout<<"cardEC "<<cardEC(ec)<<endl;
  while(cardEC(ec)>0){
    c= randomEC(ec);
    a=getAnimal(g,c);
    EnsCoord ec1 =voisinespece(ng, c,Vide);
    c1=randomEC(ec1);
    changeCoordAnimal(a, c1);
    setAnimal(ng, a);
    supprimeEC(ec, c);
    //afficheGrille(ng);
    compteur++;
    cout<<"compteur " <<compteur<< endl;
  }
}

void deplacetouslesrenard(grille g,grille &ng){
    EnsCoord E = toutEspece(g,Renard);
    EnsCoord V;
    Animal bebe;
    int compteur;
    for(int i = 0;i< cardEC(E);i++){
        Animal a = getAnimal(g, E.tab[i]);
        V = voisinvide(ng, a.c);
        faimRenard(a);
        if(not mortAnimal(a)){
            if(not attaqueRenard(ng, a)){
              cout<<"test"<<endl;
                if(seReproduitAnimal(a,V.nbElts)){
                    //exit(1);
                    coord c = randomEC(V);
                    bebe = creerAnimal(a.espece,c);
                    cout<<"bebe"<<endl;
                    setAnimal(ng,bebe);
                    supprimeEC(V,bebe.c);
                }
                if(V.nbElts > 0){
                    coord c = randomEC(V);
                    changeCoordAnimal(a,c);
                    setAnimal(ng,a);
                }
            }
            else{
                if(seReproduitAnimal(a,V.nbElts)){
                    coord c = randomEC(V);
                    bebe = creerAnimal(a.espece, c);
                    setAnimal(ng,bebe);
                }
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
    afficheGrille(gNew);
 	  deplacetousleslapins(gOld,gNew);
        afficheGrille(gNew);

 	  deplacetouslesrenard(gOld,gNew);
    copieGrille(gNew, gOld);
    verifieGrille(gOld);
 	  afficheGrille(gNew);
 }

 EnsCoord test = trouverVoisins({0,10});

 afficheEC(test);

 return 0;

}

