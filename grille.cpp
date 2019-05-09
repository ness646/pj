#include <cmath>
#include <iostream>
using namespace std;

#include "grille.hpp"



void grilleVide(grille &g) { //OK
    for(int i=0; i<TAILLE_GRILLE; i++) {
        for(int j=0; j<TAILLE_GRILLE; j++){
            g.tab[i][j].espece = Vide;
        }
    }
}


void copieGrille(grille g1, grille &g2) { 
    g2 = g1;
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

void afficheGrille(grille g){ // OK
    int lapin, renard, vide;
     lapin=0;
     renard=0;
     vide=0;
    for(int x=0; x < TAILLE_GRILLE; x++){
        for(int y=0; y < TAILLE_GRILLE; y++){
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
    for(int i=0; i<TAILLE_GRILLE; i++) {
        for(int j=0; j<TAILLE_GRILLE; j++) {
            float h= hasard();
            if(h <= ProbRenard) {
                e = Renard;
            } else if(h<= ProbRenard + ProbLapin) {
                e = Lapin;
            } else {
                e = Vide;
            }
            coord c = creerCoord(i,j);
            Animal a = creerAnimal(e,c);
            setAnimal(g,a);
        }
    }
}

EnsCoord voisinespece(grille g,coord c, Espece e){
     EnsCoord ec;
     ec=trouverVoisins(c);
     for(int i=0;i<cardEC(ec);i++){
        if(especeAnimal(getAnimal(g,c))!=e) {
                supprimeEC(ec,c);
                
          }
       }
      return  ec;
    
    }
     
EnsCoord voisinvide(grille g,coord c){
     EnsCoord ec;
     ec=trouverVoisins(c);
    for(int i=0;i<cardEC(ec);i++){
        if(especeAnimal(getAnimal(g,c))!=Vide) {
                supprimeEC(ec,c);
                
          }
       }
      return  ec;
    
    }
void compteEspeces(grille g, int &lapin, int &renard){
 lapin = 0;
 renard = 0;
 for(int i = 0; i < TAILLE_GRILLE; i++){

 	 for (int j = 0; j < TAILLE_GRILLE; j++){

 	 	 if(especeAnimal(g.tab[i][j]) == Renard){

 	 	 	 renard ++;

 	 	 }

 	 	 if(especeAnimal(g.tab[i][j]) == Lapin){

 	 	 	 lapin ++;

 	 	 }

 	 }

 }

}
