#include <iostream>
#include "guess_vista_iostream.h"


// Vista usando iostream
Punto guessVista::leer()
{
  Punto pt;
  std::cin >> pt.x >> pt.y >> pt.z;
  return pt;
}
  
void guessVista::reporte(const Punto& res, int intentos) const
{
  std::cout << "[Numero de intentos: "<<intentos<<"] ";
  if (res.x>0) 
    std::cout << "Mas abajo. ";
  else 
    if (res.x<0) std::cout << "Mas arriba. ";
  
  if (res.y>0) 
    std::cout << "Mas a la izquierda. ";
  else 
    if (res.y<0) std::cout << "Mas a la derecha. ";
  
  if (res.z>0) 
    std::cout << "Mas cerca. ";
  else 
    if (res.z<0) std::cout << "Mas lejos. ";
  std::cout << std::endl;
}
