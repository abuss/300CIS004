# Makefile

# Set the compiler 
# CXX = g++-4.7 -std=c++11 -O3
CXX = clang++ -std=c++11 -O3

OBJS = guess_controlador.o guess_vista_iostream.o
OBJSCGI = guess_controlador_cgi.o guess_vista_html.o ${OBJS}

all: ${OBJS} guess-v5

cgi: ${OBJSCGI} guess.cgi

guess-v5: guess-v5.cc
	${CXX} ${CFLAGS} -o guess-v5 $< ${OBJS} ${LIB}

guess.cgi: guess-cgi.cc ${OBJSCGI}
	${CXX} ${CFLAGS} -o guess.cgi $< ${OBJSCGI} ${LIB} -lboost_regex

clean:
	rm -f *.o guess-v5 guess.cgi


