GPP = g++ -O3 -Wall -std=c++11

intro: intro.cc
	$(GPP) -o intro intro.cc

dyna: dyna.cc
	$(GPP) -o dyna dyna.cc

multi: multi.cc
	$(GPP) -o multi multi.cc

undefined: undefined.cc
	$(GPP) -o undefined undefined.cc

clean:
	rm intro &
	rm dyna &
	rm multi &
	rm dmulti &
	rm undefined &
	clear && clear
