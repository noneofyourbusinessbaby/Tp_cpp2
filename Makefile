CPPFLAGS = -g -Wall -ansi -pedantic -std=c++11
# version initiale sans variable
# règle explicite pour la reliure
EXE = prog
OBJ =  main.o LectureLog.o Noeud.o SousNoeud.o Graph.o
GCC = g++

$(EXE) : $(OBJ) # dépendance
	$(GCC) -o $(EXE) $(OBJ)
# règle explicite pour la compilation de main.cpp
main.o : main.cpp # dépendance
	$(GCC) -c main.cpp $(CPPFLAGS)
# règle explicite pour la compilation de LectureLog.cpp
LectureLog.o : LectureLog.h LectureLog.cpp # dépendance
	$(GCC) -c LectureLog.cpp $(CPPFLAGS)
# règle explicite pour la compilation de Noeud
Noeud.o : Noeud.h Noeud.cpp # dépendance
	$(GCC) -c Noeud.cpp $(CPPFLAGS)
# règle explicite pour la compilation de Graph
Graph.o : Graph.h Graph.cpp # dépendance
	$(GCC) -c Graph.cpp $(CPPFLAGS)
# règle explicite pour la compilation de SousNoeud
SousNoeud.o : SousNoeud.h SousNoeud.cpp # dépendance
	$(GCC) -c SousNoeud.cpp $(CPPFLAGS)

val:
	valgrind --leak-check=yes $(EXE)

clean:
	rm *.o
	rm $(EXE)

test:
	cd tests; ./mktest.sh

val:
	valgrind --leak-check=yes ./$(EXE) ./depart.log
