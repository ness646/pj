



#include <cmath>
#include <iostream>
using namespace std;



const int FoodInit=5;
const int MaxFood=10;
const int FoodLapin=5;






enum Espece {Vide,Lapin,Renard}
struct Animal{
   Espece espece;
   int food;
   coord c;
};



float hasard(){
    return float(rand()) / float(RAND_MAX);
}


Animal creerAnimal(Espece e, coord c){
     Animal a;
     a.espece= e;
     a.c=c;
     if(e==Renard){
        a.food=FoodInit;
     }else{
        a.food=-1;
     }
        return a;
 }
   
          
         
        
       





coord coordAnimal( Animal a){
 return a.c;
}

Espece especeAnimal( Animal a){
 return a.espece;
}

int nourritureRenard(Animal a){
      return a.food;
}

bool estVide (Animal a){
     return especeAnimal(a)==Vide;
 }
 
 void changeCoordAnimal(Animal &a, coord c){
     a.c = c;
}

void mangeRenard(Animal &a){
    
     a.food += FoodLapin;
 }



void faimRenard(Animal &a){
      a.food--;
  }



bool mortAnimal(Animal a){
  if(especeAnimal(a)==Renard){
      return nourritureRenard(a)<=0;
  }else if(especeAnimal(a)==Lapin){
         return false;
  } else{ 
      cout<<"pas d'animal"<<endl;
        return false;
      }
  }
  
  
  
bool seReproduitAnimal(Animal a, int nbVoisinsVides){
     if(especeAnimal(a)==Renard){
       return nourritureRenard(a)>=FoodReprod) and (hasard()<ProbbirthRenard);
     }else if(especeAnimal(a)==lapin) {
        return (nbvoisinvides>=minFreebirthlapin) and (hasard()<PropbirthLapin)
        } else { 
            cout<<"pas d'animal ici"<<endl;
            return false;
       }
   }
 
