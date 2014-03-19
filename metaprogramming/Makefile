# Makefile

CC = g++ -std=c++11 -O3
# CC = clang++ -std=c++11

%: %.cc
	${CC} ${CFLAGS} -o $@ $< ${LIB}

clean:
	rm -f fact fibonacci-ct fibonacci-rt fibonacci-c++11

