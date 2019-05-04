# Le compilateur à utiliser
CXX = g++
# Les options du compilateur
CXXFLAGS = -Wall -std=c++11 -g

# Les programmes principaux
# On donne le fichier cpp et la liste des fichiers .o qu'ils utilisent
projet: projet.cpp ensCoord.o  animal.o grille.o
testEnsCoord: testEnsCoord.cpp ensCoord.o

# Les différents composants
# on donne le fichier cpp ainsi que la liste des fichiers .hpp dont ils dépendent
ensCoord.o: ensCoord.cpp ensCoord.hpp 
animal.o: animal.cpp animal.hpp ensCoord.hpp 
grille.o: grille.cpp grille.hpp animal.hpp ensCoord.hpp 

# Pour faire le ménage
clean:
	rm -f projet ensCoord animal grille *.o
