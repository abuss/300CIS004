#pragma once

#include "guess_controlador.h"
#include "guess_vista_iostream.h"

// Controlador
struct guessControladorIOStream
  : public guessControlador<guessVista>
{ };
