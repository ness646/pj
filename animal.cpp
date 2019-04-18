




Animal creerAnimal(Espece c, Coord c){
 Animal a;



Coord coordAnimal( Animal a){
 return a.coord;
}

Espece especeAnimal( Animal a){
 return a.espece;
}

int nourritureRenard(Animal a){
      return a.FoodInit;
}

bool estVide (Animal a){
     return especeAnimal(a)==0;
 }
 
 void changeCoordAnimal(Animal &a, Coord c){
 a.coord = c;
}

void mangeRenard(Animal &a){




void faimRenard(Animal &a){




bool mortAnimal(Animal a){
  if(espece animal(a)=renard){
      return nourritureRenard(a)<=0;
  }else if(espece animal(a)=Lapin){
         return false;
  } else{ 
      cout<<"pas d'animal"<<endl;
      }
  }
  
  
  
  bool seReproduitAnimal(Animal a, int nbVoisinsVides){
