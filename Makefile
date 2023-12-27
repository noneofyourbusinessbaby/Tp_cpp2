CPPFLAGS = -g -Wall -ansi -pedantic -std=c++11
# version initiale sans variable
# règle explicite pour la reliure
EXE = prog
OBJ =  main.o lecturelog.o noeud.o sousnoeud.o graph.o
GCC = g++

$(EXE) : $(OBJ) # dépendance
	$(GCC) -o $(EXE) $(OBJ)
# règle explicite pour la compilation de main.cpp
main.o : main.cpp # dépendance
	$(GCC) -c main.cpp $(CPPFLAGS)
# règle explicite pour la compilation de lecturelog.cpp
lecturelog.o : lecturelog.h lecturelog.cpp # dépendance
	$(GCC) -c lecturelog.cpp $(CPPFLAGS)
# règle explicite pour la compilation de noeud
noeud.o : noeud.h noeud.cpp # dépendance
	$(GCC) -c noeud.cpp $(CPPFLAGS)
# règle explicite pour la compilation de graph
graph.o : graph.h graph.cpp # dépendance
	$(GCC) -c graph.cpp $(CPPFLAGS)
# règle explicite pour la compilation de sousnoeud
sousnoeud.o : sousnoeud.h sousnoeud.cpp # dépendance
	$(GCC) -c sousnoeud.cpp $(CPPFLAGS)
clean:
	rm -f $(EXE) $(OBJ)
test:
	cd tests; ./mktest.sh

