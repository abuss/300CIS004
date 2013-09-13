CXX = clang++
# CXX = g++-4.8 

all: main main_move main_gen main_itr

main: main.cc mivector.hpp
	${CXX} -o main main.cc -Wall -std=c++11 -O3

main_move: main.cc mivector.hpp
	${CXX} -o main_move main.cc -Wall -std=c++11 -O3 -D_WITH_MOVE

main_gen: main_gen.cc mivector_gen.hpp
	${CXX} -o main_gen main_gen.cc -Wall -std=c++11 -O3

main_itr: main_itr.cc mivector.hpp
	${CXX} -o main_itr main_itr.cc -Wall -std=c++11 -O3

clean:
	rm -f main main_move main_gen main_itr *~

