run: compile
	./listas.o

compile:
	clang++ -o listas.o main.cpp

clear:
	rm listas.o
