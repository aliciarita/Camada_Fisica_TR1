#COMPILER
CPP=g++

# Nome do projeto
SIM=simulador

#FLAGS G++
FLAGS= -c -Wall -pedantic

all: $(SIM)

$(SIM): simulador.o camadaFisica.o
	$(CPP) -o $@ $^

simulador.o: simulador.cpp camadaFisica.hpp
	$(CPP) -o $@ $< $(FLAGS)

camadaFisica.o: camadaFisica.cpp camadaFisica.hpp
	$(CPP) -o $@ $< $(FLAGS)

run: 
	./$(SIM)

clean:
	rm -rf *.o $(SIM)	