# options de compilation
CFLAGS = -g -std=c++0x -pedantic -Wfatal-errors -Wconversion -Wredundant-decls -Wshadow -Wall -Wextra
# liste des fichiers implémentant un sudoku
Su = grille.hpp grille.cpp nombre.hpp FPtab.hpp FPtab.tpp

all : main.exe test.exe

%.o : %.cpp %.hpp
	g++ $(CFLAGS) -c -o $@ $< 

test.exe : test.cpp $(Su)
	g++ $(CFLAGS) test.cpp -o test.exe

main.exe : main.cpp $(Su)
	g++ $(CFLAGS) main.cpp -o main.exe

clean :
	@rm *.o *.exe

.PHONY: all clean
