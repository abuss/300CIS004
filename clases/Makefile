
CC = clang++ -std=c++11
#CC = g++-4.8 -std=c++11

main :	persona.o main.cc
	${CC}  -o main main.cc persona.o -std=c++11

persona.o : persona.cc persona.h
	${CC} -c persona.cc

main-op : persona.cc main.cc
	${CC} -O3 -c persona.cc
	${CC} -O3 -o main-op main.cc persona.o

static : static.cc
	${CC} -o static static.cc

herencia: herencia.cc
	${CC} -o herencia herencia.cc

herencia2: herencia2.cc
	${CC} -o herencia2 herencia2.cc

demo-static : demo-static.cc
	${CC} -o demo-static demo-static.cc

herencia3: herencia3.cc
	${CC} -o herencia3 herencia3.cc

clean :
	rm persona.o main main-op static demo-static
