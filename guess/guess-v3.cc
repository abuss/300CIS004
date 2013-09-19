#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

enum Coord { X, Y, Z };

struct Punto
{
  int x,y,z;
};

//  x
//  ^   z
//  |  / 
//  | /
//   /
//  -------> y


int check_dimesion(int e, int t, int& iguales)
{
  if (e < t) {
    return 1;
  }
  if (e > t) {
    return -1;
  }
  ++iguales;
  return 0;
}

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


struct guessVista
{
  Punto leer()
  {
    Punto pt;
    std::cin >> pt.x >> pt.y >> pt.z;
    return pt;
  }
  
  template <typename T>
  void reporte(const T& res, int intentos) const
  {
    std::cout << "[Numero de intentos: "<<intentos<<"] ";
    if (res[X]>0) 
      std::cout << "Mas abajo. ";
    else 
      if (res[X]<0) std::cout << "Mas arriba. ";

    if (res[Y]>0) 
      std::cout << "Mas a la izquierda. ";
    else 
      if (res[Y]<0) std::cout << "Mas a la derecha. ";

    if (res[Z]>0) 
      std::cout << "Mas cerca. ";
    else 
      if (res[Z]<0) std::cout << "Mas lejos. ";
    std::cout << std::endl;
  }
  
  void gano() { std::cout << "BOOOM!!\n"; }

  void perdio() { std::cout << "Alien invasion!!\n"; } 
};


int main(int argc, char *argv[])
{
  guessModelo data;
  guessVista  view;
  int iguales;
  std::vector<int> res(3);
  Punto pt;
  do {
    iguales = 0;
    pt = view.leer();
    res.clear();
    
    // X
    res[X] = check_dimesion(data.punto().x, pt.x, iguales);
    // Y
    res[Y] = check_dimesion(data.punto().y, pt.y, iguales);
    // Z
    res[Z] = check_dimesion(data.punto().z, pt.z, iguales);

    std::cout << res[X] << " ";
    std::cout << res[Y] << " ";
    std::cout << res[Z] << " ";

    data.incrementar_intentos();
    view.reporte(res,data.intentos());
  } while (data.intentos()<10 && iguales!=3);
  if (iguales==3)
    view.gano();
  else
    view.perdio();

  return 0;
}
