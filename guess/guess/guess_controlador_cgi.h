#ifndef GUESS_CONTROLADOR_CGI_HPP
#define GUESS_CONTROLADOR_CGI_HPP

#include "guess_controlador.h"
#include "guess_vista_html.h"

// Controlador
struct guessControladorCGI
  : public guessControlador<guessVistaHTML>
{
  void jugar();

  void terminar();
};

#endif /* GUESS_CONTROLADOR_CGI_HPP */
