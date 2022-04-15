#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

TRGDIR=/tmp/rysowanie_3D

__start__: ./rysowanie_3D
	./rysowanie_3D

./rysowanie_3D: obj obj/main.o obj/lacze_do_gnuplota.o obj/Lamana.o obj/PowierzchniaGeom.o obj/PowierzchniaGeomScn.o\
                        obj/Scena.o obj/Dron.o obj/PowierzchniaWody.o obj/PowierzchniaDna.o
	g++ -Wall -pedantic -std=c++11 -o ./rysowanie_3D obj/main.o\
                        obj/lacze_do_gnuplota.o obj/Lamana.o obj/PowierzchniaGeom.o obj/PowierzchniaGeomScn.o\
                        obj/Scena.o obj/Dron.o obj/PowierzchniaWody.o obj/PowierzchniaDna.o


obj:
	mkdir -p obj

obj/main.o: src/main.cpp inc/lacze_do_gnuplota.hh inc/SWektor.hh inc/Lamana.hh inc/Wektor3D.hh\
        inc/PowierzchniaGeom.hh inc/PowierzchniaGeomScn.hh inc/Scena.hh inc/Dron.hh\
        inc/PowierzchniaDna.hh  inc/PowierzchniaWody.hh
        
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/Lamana.o: src/Lamana.cpp inc/Lamana.hh 
	g++ -c ${CXXFLAGS} -o obj/Lamana.o src/Lamana.cpp

obj/PowierzchniaGeom.o: src/PowierzchniaGeom.cpp inc/PowierzchniaGeom.hh 
	g++ -c ${CXXFLAGS} -o obj/PowierzchniaGeom.o src/PowierzchniaGeom.cpp

obj/PowierzchniaGeomScn.o: src/PowierzchniaGeomScn.cpp inc/PowierzchniaGeomScn.hh 
	g++ -c ${CXXFLAGS} -o obj/PowierzchniaGeomScn.o src/PowierzchniaGeomScn.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh 
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/Dron.o: src/Dron.cpp inc/Dron.hh 
	g++ -c ${CXXFLAGS} -o obj/Dron.o src/Dron.cpp

obj/PowierzchniaDna.o: src/PowierzchniaDna.cpp inc/PowierzchniaDna.hh 
	g++ -c ${CXXFLAGS} -o obj/PowierzchniaDna.o src/PowierzchniaDna.cpp

obj/PowierzchniaWody.o: src/PowierzchniaWody.cpp inc/PowierzchniaWody.hh 
	g++ -c ${CXXFLAGS} -o obj/PowierzchniaWody.o src/PowierzchniaWody.cpp



clean:
	rm -f obj/*.o ./rysowanie_3D
