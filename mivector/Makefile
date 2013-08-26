CXX = clang++
# CXX = g++-4.8 

main: main.cc mivector.hpp
	${CXX} -o main main.cc -Wall -std=c++11 -O3

main_move: main.cc mivector.hpp
	${CXX} -o main_move main.cc -Wall -std=c++11 -O3 -D_WITH_MOVE

clean:
	rm -f main main_move *~

