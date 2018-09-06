GPP = g++ -O3 -Wall -std=c++11

PRG = Aprog

$(PRG): main.o dec_2_hex.o
	$(GPP) -o $(PRG) main.o dec_2_hex.o

main.o: main.h main.cc dec_2_hex.h
	$(GPP) -o main.o -c main.cc

dec_2_hex.o: dec_2_hex.h dec_2_hex.cc
	$(GPP) -o dec_2_hex.o -c dec_2_hex.cc

clean:
	rm $(PRG)
	rm main.o
	rm dec_2_hex.o
