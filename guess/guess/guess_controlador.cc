// #include "punto.h"
// #include "guess_controlador.h"

// // Controlador
// template <typename T>
// void guessControlador<T>::jugar()
// {
//   iguales = 0;
//   Punto res;
//   Punto pt = view.leer();
//   // X
//   res.x = details::check_dimesion(data.punto().x, pt.x, iguales);
//   // Y
//   res.y = details::check_dimesion(data.punto().y, pt.y, iguales);
//   // Z
//   res.z = details::check_dimesion(data.punto().z, pt.z, iguales);
  
//   data.incrementar_intentos();
//   view.reporte(res,data.intentos());
// }

// template <typename T>
// bool guessControlador<T>::evaluar() const
// {
//   return data.intentos()<10 && iguales!=3;
// }

// template <typename T>
// void guessControlador<T>::terminar()
// {
//   if (iguales==3)
//     view.gano();
//   else
//     view.perdio();
// }

namespace details {

int check_dimesion(int e, int t, int& iguales)
{
  if (e < t) return 1;
  if (e > t) return -1;
  ++iguales;
  return 0;
}

} // details namespace
