CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic


__start__: ./test_wektora
	./test_wektora



obj:
	mkdir -p obj

./test_wektora: obj obj/main.o obj/Wektor.o
	g++ -o ./test_wektora obj/main.o obj/Wektor.o

obj/main.o: src/main.cpp inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor.o src/Wektor.cpp
