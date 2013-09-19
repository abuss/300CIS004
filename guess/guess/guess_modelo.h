#ifndef GUESS_MODELO_HPP
#define GUESS_MODELO_HPP

#include <stdlib.h>
#include "punto.h"

// Modelo
struct guessModelo
{
  Punto m_punto;
  int   m_intentos;

  guessModelo() 
    : m_punto{rand()%10, rand()%10, rand()%10},
      m_intentos(0)
  { }

  const Punto& punto() const { return m_punto; }

  void incrementar_intentos() { ++m_intentos; }

  int intentos() const { return m_intentos; }
};

#endif /* GUESS_MODELO_HPP */
