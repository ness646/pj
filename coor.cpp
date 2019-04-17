#include <cmath>
#include <iostream>
using namespace std;
/** Infrastructure minimale de test **/
#define ASSERT(test)                                                           \
    if (!(test))                                                               \
    cout << "Test failed in file " << __FILE__ << " line " << __LINE__         \
         << ": " #test << endl









struct coord {
    int ligne;
    int colonne;
  };
  
  
  
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
 
 const int MAXENSCOORD=15; 
 
 
 struct EnsCoord{
      coord tab[MAXENSCOORD] ;
      int nbElts;
        
 } ;
 
 
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
 void surprimeEC(EnsCoord &ec,coord c){
     ec.tab[ec.nbElts]=c;
     ec.nbElts=ec.nbElts-1;
     }
     
 
 
 
 
 
 int main(){
coord c1 = nouvcoord(2,1);
afficheCoord(c1);
cout << endl;
return 0;
           
}           
           
           
           
           
         
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           

      
    
