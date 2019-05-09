#include <cmath>
#include <iostream>
using namespace std;

#include "grille.hpp"



void grilleVide(grille &g) { //OK
    for(int y=0; y<TAILLE_GRILLE; y++) {
        for(int x=0; x<TAILLE_GRILLE; x++){
            g.tab[x][y] = creerAnimal(Vide, creerCoord(x,y));
        }
    }
}


void copieGrille(grille g1, grille &g2) { 
    //g2 = g1;
    for(int y=0; y<TAILLE_GRILLE; y++){
      for(int x=0; x<TAILLE_GRILLE; x++){
        g2.tab[x][y] = g1.tab[x][y];
      }
  } 
}


Animal getAnimal(grille g, coord c) {
    return g.tab[getX(c)][getY(c)];
}


void setAnimal(grille &g, Animal a) { 
    g.tab[getX(a.c)][getY(a.c)] = a;
}

void verifieGrille(grille g) { //OK
    coord cg;
    Animal animal;
    coord ca;
    for (int y=0; y<TAILLE_GRILLE; y++){
        for(int x=0; x<TAILLE_GRILLE; x++){
            cg=creerCoord(x,y);
            animal=g.tab[x][y];
            ca=coordAnimal(animal);
            if(not(egalCoord(ca, cg))){
                cout<<"Erreur dans la verification de la grille"<<endl;
                exit(1);
            }
        }
    }


}

void afficheGrille_ness(grille g){ // OK
    int lapin, renard, vide;
     lapin=0;
     renard=0;
     vide=0;
    for(int y=0; y<TAILLE_GRILLE; y++) {
        for(int x=0; x<TAILLE_GRILLE; x++){
            if(g.tab[x][y].espece==Lapin){
                cout << "L ";
                lapin++;
            }
            else if(g.tab[x][y].espece==Renard){
                cout << "R ";
                renard++;
            }
            else{
                cout << "0 ";
                vide++;
            }
        }
        cout<<endl;
    }
    cout<<"Lapin:"<< lapin <<" Renard :"<< renard << " Vide: "<< vide <<endl; 


}

void initialiseGrille(grille &g) { //OK
    Espece e;
    for(int y=0; y<TAILLE_GRILLE; y++) {
        for(int x=0; x<TAILLE_GRILLE; x++){
            float h= hasard();
            if(h <= ProbRenard) {
                e = Renard;
            } else if(h<= ProbRenard + ProbLapin) {
                e = Lapin;
            } else {
                e = Vide;
            }
            coord c = creerCoord(x,y);
            Animal a = creerAnimal(e,c);
            setAnimal(g,a);
        }
    }
}

EnsCoord voisinespece(grille g,coord c, Espece e){
   /* EnsCoord ec;
     ec=trouverVoisins(c);
     for(int i=0;i<cardEC(ec);i++){
        if(especeAnimal(getAnimal(g,c))!=e) {
                supprimeEC(ec,c);
                
          }
       }
      return  ec;*/
    EnsCoord EC1;
    EnsCoord EC2;
    EC1= trouverVoisins(c);
    EC2=CreerEC();
    Animal a;
    for(int i=0; i<EC1.nbElts; i++){
        a=g.tab[getX(EC1.tab[i])][getY(EC1.tab[i])];
                     if(a.espece==Vide){
                         ajouteEC(EC2,EC1.tab[i]);
                     }
    }
    return EC2;

    }
     
EnsCoord voisinvide(grille g,coord c){
    EnsCoord ec;
    ec=trouverVoisins(c);
    for(int i=0;i<cardEC(ec);i++){
        coord c1= ec.tab[i];
        if(especeAnimal(getAnimal(g,c1))!=Vide) {
                supprimeEC(ec,c1);
          }
       }
             return  ec;
/*EnsCoord voisins = trouverVoisins(c);
  EnsCoord res = CreerEC();
  for(int i = 0; i<voisins.nbElts ; i++){
    //on prends l'animal dans la  grille à ces coordonnées et on teste s'il est vide
    Animal a = g.tab[getX(voisins.tab[i])][getY(voisins.tab[i])];
    if(a.espece == Vide){
      ajouteEC(res,voisins.tab[i]);
    }
  }
  return res;*/

}

void compteEspeces(grille g, int &lapin, int &renard){
 lapin = 0;
 renard = 0;
 for(int i = 0; i < TAILLE_GRILLE; i++){
 	 for (int j = 0; j < TAILLE_GRILLE; j++){
 	 	 if(especeAnimal(g.tab[j][i]) == Renard){
 	 	 	 renard ++;
 	 	 }
 	 	 if(especeAnimal(g.tab[j][i]) == Lapin){
 	 	 	 lapin ++;
 	 	 }
 	 }
 }
}
void afficheGrille(grille g){
  int vide,LapinM, RenardF;
  RenardF=0;
  LapinM=0;
  vide=0;
  for (int y=0; y<TAILLE_GRILLE; y++){
      cout<<" ";
    for(int x=0; x<TAILLE_GRILLE; x++){
      if(g.tab[x][y].espece==Lapin){
LapinM++;
        cout << "\033[34m\u25A0 ";

      }
      else if(g.tab[x][y].espece==Renard){
          RenardF++;        
        cout << "\033[31m\u25A0 ";
      }
      else {
        vide++;
        //cout << 0<<" ";
        cout << "\033[97m\u25A0 ";
      }
    }
    cout<<endl;
  }

  cout<<"\033[1;97mLapin\033[0m :"<<LapinM<<" Renard :"<< RenardF<< " Vide: "<<vide <<endl; 


}