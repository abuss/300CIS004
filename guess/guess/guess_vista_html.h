#ifndef GUESS_VISTA_HTML_HPP
#define GUESS_VISTA_HTML_HPP

#include <iostream>
#include "guess_vista_iostream.h"
#include "punto.h"

// Vista usando iostream
struct guessVistaHTML
  : public guessVista
{
  void forma_captura();

  Punto leer();
  
  // void reporte(const Punto& res, int intentos) const;

  void gano() { std::cout << "<b>BOOOM!!</b>"; }

  void perdio() { std::cout << "<b>Alien invasion!!<b>"; } 
};

#endif /* GUESS_VISTA_HTML_HPP */
