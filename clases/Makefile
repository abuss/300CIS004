
# CC = clang++
CC = g++-4.8

main :	persona.o main.cc
	${CC}  -o main main.cc persona.o -std=c++11

persona.o : persona.cc persona.h
	${CC} -std=c++11 -c persona.cc

main-op : persona.cc main.cc
	${CC} -O3 -std=c++11 -c persona.cc
	${CC} -O3 -o main-op main.cc persona.o -std=c++11


clean :
	rm persona.o main main-op
