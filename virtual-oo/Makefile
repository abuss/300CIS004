# Makefile

#CC = g++-4.7 -std=c++11 -O3
CC = clang++ -std=c++11

%: %.cc
	${CC} ${CFLAGS} -o $@ $< ${LIB}

clean:
	rm -f demo1 demo2 demo3a demo3b test

