#include <cmath>
#include <iostream>
/** Infrastructure minimale de test **/
#define ASSERT(test)                                                           \
    if (!(test))                                                               \
    cout << "Test failed in file " << __FILE__ << " line " << __LINE__         \
         << ": " #test << endl

#include "ensCoord.hpp"

using namespace std;

void testegalCoord() {
    ASSERT(egalCoord(creerCoord(4,4),creerCoord(4,4)== true))
    ASSERT(egalCoord(creerCoord(4,1),creerCoord(4,5)== false))
}

void testcardEC(){
    EnsCoord ec = CreerEC();
    ajouteEC(ec, creerCoord(4,4));
    
    ASSERT(cardEC(ec)==1);
}

int main(){

    testegalCoord();
    testcardEC();
    
    //tests ajouteEC
    cout << "Tests ajouteEC :" << endl;
    EnsCoord ec = CreerEC();
    ajouteEC(ec, creerCoord(4,4));
    afficheEC(ec);
    coord c = creerCoord(1,4);
    ajouteEC(ec, c);
    afficheEC(ec);
    cout << endl << "Tests supprimeEC :" << endl;
    supprimeEC(ec, c);
    afficheEC(ec);

    return 0;
 }
