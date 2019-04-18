#include <cmath>
#include <iostream>
using namespace std;
/** Infrastructure minimale de test **/
#define ASSERT(test)                                                           \
    if (!(test))                                                               \
    cout << "Test failed in file " << __FILE__ << " line " << __LINE__         \
         << ": " #test << endl

const int MAXENSCOORD=15; 


struct coord {
    int ligne;
    int colonne;
  }; 
 
 struct EnsCoord{
      coord tab[MAXENSCOORD] ;
      int nbElts;
        
 } ;
  
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
 
 
  void cardEC (EnsCoord ec,int &res) {
      res = 0;
     for(int i = 0; i<=ec.nbElts; i++) {
        if(getX(ec.tab[i]) != 0 and getY(ec.tab[i]) != 0) {
        res++;
        }
        
    
    }
    
  }
 
 
 EnsCoord trouverVoisins( Coord c){
          
 
 
 
 
 //** c'est faux
 /* Tu cherche la coordonnée dans le tableau
 * Une fois trouvée tu enregistres l'indexe 
 * Puis tu copies les elements dans l'indexe n+1 dans n
 * tu soustraies le nombre d'elements dans le tableau
 * attention a ne pas déborder dans le tableau....
 */ 
 void surprimeEC(EnsCoord &ec,coord c){ 
     ec.tab[ec.nbElts]=c;
     ec.nbElts=ec.nbElts-1;
     }
     
 
 
 
 
 
 int main(){
coord c1 = nouvcoord(2,1);
coord c2 = nouvcoord(1,2);
afficheCoord(c1);
cout << endl;
return 0;
           
} 
