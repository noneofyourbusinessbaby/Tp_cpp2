CPPFLAGS = -g -Wall -ansi -pedantic -std=c++11
# version initiale sans variable
# règle explicite pour la reliure
EXE = prog
OBJ =  main.o lecturelog.o noeud.o sousnoeud.o Graph.o
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
# règle explicite pour la compilation de Graph
Graph.o : Graph.h Graph.cpp # dépendance
	$(GCC) -c Graph.cpp $(CPPFLAGS)
# règle explicite pour la compilation de sousnoeud
sousnoeud.o : sousnoeud.h sousnoeud.cpp # dépendance
	$(GCC) -c sousnoeud.cpp $(CPPFLAGS)

val:
	valgrind --leak-check=yes $(EXE)

clean:
	rm *.o
	rm $(EXE)

test:
	cd tests; ./mktest.sh

val:
	valgrind --leak-check=yes ./$(EXE) ./depart.log
