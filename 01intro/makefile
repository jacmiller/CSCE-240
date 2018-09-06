GPP = g++ -O3 -Wall -std=c++11

PRG = Aprog
OBJ = intro.o
SRC = intro.cc

$(PRG): $(OBJ)
	$(GPP) -o $(PRG) $(OBJ)

$(OBJ): $(SRC)
	$(GPP) -o $(OBJ) -c $(SRC)

clean:
	rm $(PRG) 
	rm $(OBJ)

