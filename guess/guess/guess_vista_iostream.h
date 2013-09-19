#ifndef GUESS_VISTA_IOSTREAM_HPP
#define GUESS_VISTA_IOSTREAM_HPP

#include <iostream>
#include "punto.h"

// Vista usando iostream
struct guessVista
{
  Punto leer();
  
  void reporte(const Punto& res, int intentos) const;

  void gano() { std::cout << "BOOOM!!\n"; }

  void perdio() { std::cout << "Alien invasion!!\n"; } 
};

#endif /* GUESS_VISTA_IOSTREAM_HPP */
