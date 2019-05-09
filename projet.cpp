#include <cmath>
#include <iostream>

#include "grille.hpp"

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





/*deplace un renard dans une case d'un lapin et retourne vrai sinon retourne faux*/
bool attaqueRenard(grille g, Animal &a){
  if( especeAnimal(a) == Renard ){
    EnsCoord ec=CreerEC();
    ec=toutEspece(g,Renard);
    if(cardEC(ec) == 0 ){
      return false;
    } else {
      coord c = randomEC(ec);
      changeCoordAnimal(a,c);
      mangeRenard(a);
      return true;
    }
  } else {
    cout << "N est pas un renard ! Ne peut pas attaquer !" << endl;
        return false;
  }
}







/*deplace un animal dans une case vide*/
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

   /* void deplacetousleslapins(grille g1,grille &g2){
    EnsCoord E= toutEspece(g1,Lapin);
    EnsCoord V;
    for(int i = 0;i< cardEC(E);i++){
        Animal a = getAnimal(g1, E.tab[i]);
        V= voisinvide(g2,coordAnimal(a));
        if(seReproduitAnimal(a,V.nbElts)){
            setAnimal(g2,a);
        }
        if(V.nbElts > 0){
            coord c = randomEC(V);
            changeCoordAnimal(a,c);
            setAnimal(g2,a);
        }else{
            cout<<"test"<<endl;
        }
    }
}
*/

void deplacetouslesrenard(grille g,grille &ng){
    EnsCoord e = toutEspece(g,Renard);
    EnsCoord v;
    for(int i = 0;i< cardEC(e);i++){
        Animal a = getAnimal(g, e.tab[i]);
        v = voisinvide(ng,coordAnimal(a));
        if(seReproduitAnimal(a,v.nbElts)){
            setAnimal(ng,a);
        }
        if(attaqueRenard(g,a)){
        setAnimal(ng,a);
        }
        else if(v.nbElts > 0){
            coord c = randomEC(v);
            changeCoordAnimal(a,c);
            setAnimal(ng,a);
        }
        faimRenard(a);
        if(mortAnimal(a)){
            creerAnimal(Vide,coordAnimal(a));
        }
    }
}



int main(){
	 srand(time(NULL)); //Pour que la fonction aleatoire ne soit pas tt le temps la meme

 grille g1, g2;

 initialiseGrille(g2);
 afficheGrille(g2);
 int lapins, renards;

 compteEspeces(g2, lapins, renards);
	
 while ( (lapins != 0) && (renards != 0) ){

    grilleVide(g1);
	copieGrille(g2,g1);
	
	
	
 	 deplacetousleslapins(g2,g1);

 	 deplacetouslesrenard(g2,g1);

     
 	 afficheGrille(g1);
     //afficheGrille(g2);
 }

 

 

 return 0;

}

