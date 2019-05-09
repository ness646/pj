#include "ensCoord.hpp"

  
 coord creerCoord(int ligne,int colonne){
      coord c;
      c.ligne=ligne;
      c.colonne=colonne;
      return c;
 }
 
void afficheCoord (coord c){
    cout<<"("<<getX(c)<<", "<<getY(c)<<")";
 }
 
 int getX(coord c){
   return c.ligne;
 }
 
int getY(coord c){
 return c.colonne;
 }
 
bool egalCoord(coord c1,coord c2){
     return c1.ligne==c2.ligne and c1.colonne==c2.colonne;
   } 
 
void afficheEC(EnsCoord ec){
  for(int i=0; i<ec.nbElts ; i++){
    afficheCoord(ec.tab[i]);
  }
  cout<<endl;
}
 
 /* Afficher un ensemble de coordonnées ne contenant aucun élément */ 
EnsCoord CreerEC() {
  EnsCoord ec;
  ec.nbElts=0;
  return ec;
}
   
 /* Ajouter une coordonnée à un ensemble de coordonnées */

void ajouteEC(EnsCoord &ec, coord c){
  ec.tab[ec.nbElts]=c;
  ec.nbElts++;
}
 
 /* Afficher le nombre d’éléments d’un ensemble de coordonnées */
int cardEC (EnsCoord ec) {
  return ec.nbElts;
    
}
 
 /* Afficher l’ensemble des coordonnées des voisines d'une coordonnée c */
EnsCoord trouverVoisins(coord c){
  /*
  EnsCoord CoordAutour;
  CoordAutour.nbElts=0;
  for(int colonne=c.colonne-1; colonne<=c.colonne+1; colonne++){
    for(int ligne=c.ligne-1; ligne<=c.ligne+1; ligne++){
        if( not(ligne==c.ligne and colonne==c.ligne) and (ligne>=0 and ligne<TAILLE_GRILLE and colonne>=0 and colonne<TAILLE_GRILLE) ){
            CoordAutour.tab[CoordAutour.nbElts]={ligne, colonne};
            CoordAutour.nbElts++;
        }
    }
  }
  return CoordAutour;*/

    int minx, maxx;
    EnsCoord res = CreerEC();
    int xc = getX(c);
    int yc = getY(c);
    if(xc == 0) {
        minx = 0;
    } else {
        minx = xc - 1;
        ajouteEC(res, creerCoord(minx, yc));
    }
    if(xc == TAILLE_GRILLE - 1) {
        maxx = TAILLE_GRILLE - 1;
    } else {
        maxx = xc + 1;
        ajouteEC(res, creerCoord(maxx, yc));
    }
    if(yc != 0) {
        for(int i = minx; i<= maxx; i++) {
            ajouteEC(res, creerCoord(i, yc - 1));
        }
    }
    if(yc != TAILLE_GRILLE - 1) {
        for(int i = minx; i<= maxx; i++) {
            ajouteEC(res, creerCoord(i, yc + 1));
        }
    }
    return res;
}
          
 
 //** c'est faux
 /* On cherche la coordonnée dans le tableau
 * Une fois trouvée on l'enregistre l'indexe 
 * Puis on copie les elements dans l'indexe n+1 dans n
 * on soustraie le nombre d'elements dans le tableau
 * attention a ne pas déborder dans le tableau....
 */ 
void supprimeEC(EnsCoord &ec, coord c) {
  int index=0;
  if (ec.nbElts>0){
    for(int i=0;i<ec.nbElts;i++){
    
      if(egalCoord(ec.tab[i],c)){
        index=i;
      } 
    }

    for(int i=index;i<ec.nbElts-1;i++){
      ec.tab[i]=ec.tab[i+1];
      }   
        
    ec.nbElts--;
  }
  else{
    cout<<ec.nbElts<<endl;
    //ec.nbElts--;
  }


}

/* Afficher une coordonnée au hasard dans un ensemble de coordonnées */
coord randomEC(EnsCoord ec){
  if(ec.nbElts==0)
    return ec.tab[0];
  int alea = rand()%ec.nbElts;// renvoie un element [0,ex.nbElts-1]
  return ec.tab[alea]; 
}
