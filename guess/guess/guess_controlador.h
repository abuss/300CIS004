#pragma once

#include "guess_modelo.h"
#include "guess_vista_iostream.h"
#include "punto.h"

namespace details {

  int check_dimesion(int e, int t, int& iguales);

} // details namespace

// Controlador
template <typename Vista>
struct guessControlador
{
  void jugar()
  {
    iguales = 0;
    Punto res;
    Punto pt = view.leer();
    // X
    res.x = details::check_dimesion(data.punto().x, pt.x, iguales);
    // Y
    res.y = details::check_dimesion(data.punto().y, pt.y, iguales);
    // Z
    res.z = details::check_dimesion(data.punto().z, pt.z, iguales);
    
    data.incrementar_intentos();
    view.reporte(res,data.intentos());
  }

  bool evaluar() const
  {
    return data.intentos()<10 && iguales!=3;
  }
  
  void terminar()
  {
    if (iguales==3)
      view.gano();
    else
      view.perdio();
  }

protected:
  guessModelo data;
  Vista       view;
  int iguales;
};
