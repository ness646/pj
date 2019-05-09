#include "ensCoord.hpp"

  
 coord creerCoord(int ligne,int colonne){
      coord c;
      c.ligne=ligne;
      c.colonne=colonne;
      return c;
 }
 
void afficheCoord (coord c){
     cout<<c.ligne<<";"<<c.colonne<<endl;
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
  for(int i=0;i<ec.nbElts;i++) {
   afficheCoord(ec.tab[i]);
  }
}
 
 
EnsCoord CreerEC() {
  EnsCoord ec;
  ec.nbElts=0;
  return ec;
}
   
 
void ajouteEC(EnsCoord &ec, coord c){
  ec.tab[ec.nbElts]=c;
   ec.nbElts++;
}
 
 
int cardEC (EnsCoord ec) {
  return ec.nbElts;
    
}
 
 
EnsCoord trouverVoisins(coord c){
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
  return CoordAutour;
}
          
 
 //** c'est faux
 /* Tu cherche la coordonnée dans le tableau
 * Une fois trouvée tu enregistres l'indexe 
 * Puis tu copies les elements dans l'indexe n+1 dans n
 * tu soustraies le nombre d'elements dans le tableau
 * attention a ne pas déborder dans le tableau....
 */ 
void supprimeEC(EnsCoord &ec, coord c) {
    for(int i=0; i<cardEC(ec); i++) {
        if(egalCoord(ec.tab[i], c)) {
            for(int j=i; j<cardEC(ec); j++) {
                ec.tab[j] = ec.tab[j+1];
            }
            ec.nbElts--;
            return; // on sort de la fonction plus besoin de boucler jusqu a la fin
        }
    }
}
coord randomEC(EnsCoord ec){
  if(ec.nbElts==0)
    return ec.tab[0];
  int alea = rand()%ec.nbElts;// renvoie un element [0,ex.nbElts-1]
  return ec.tab[alea]; 
}
