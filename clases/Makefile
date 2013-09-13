
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

demo-static : demo-static.cc
	${CC} -o demo-static demo-static.cc

clean :
	rm persona.o main main-op static demo-static
