#include "punto.h"
#include "guess_controlador_cgi.h"

// Controlador
void guessControladorCGI::jugar()
{
  this->iguales = 0;
  Punto res;
  view.forma_captura();

  Punto pt = view.leer();
  std::cout << "<p>";
  // // X
  res.x = details::check_dimesion(data.punto().x, pt.x, this->iguales);
  // Y
  res.y = details::check_dimesion(data.punto().y, pt.y, this->iguales);
  // Z
  res.z = details::check_dimesion(data.punto().z, pt.z, this->iguales);
  
  data.incrementar_intentos();
  view.reporte(res,data.intentos());
  terminar();
}

void guessControladorCGI::terminar()
{
  if (this->iguales==3)
    view.gano();
  else
    if (this->data.intentos()>10)
      view.perdio();
}
