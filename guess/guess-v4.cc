#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>


//  x
//  ^   z
//  |  / 
//  | /
//   /
//  -------> y

struct Punto
{
  int x,y,z;
};


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


// Vista usando iostream
struct guessVista
{
  Punto leer()
  {
    Punto pt;
    std::cin >> pt.x >> pt.y >> pt.z;
    return pt;
  }
  
  void reporte(const Punto& res, int intentos) const
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
  
  void gano() { std::cout << "BOOOM!!\n"; }

  void perdio() { std::cout << "Alien invasion!!\n"; } 
};


// Controlador
struct guessControlador
{
  guessModelo data;
  guessVista  view;
  int iguales;

  void jugar()
  {
    iguales = 0;
    Punto res;
    Punto pt = view.leer();
    // X
    res.x = check_dimesion(data.punto().x, pt.x, iguales);
    // Y
    res.y = check_dimesion(data.punto().y, pt.y, iguales);
    // Z
    res.z = check_dimesion(data.punto().z, pt.z, iguales);

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

private:
  int check_dimesion(int e, int t, int& iguales)
  {
    if (e < t) return 1;
    if (e > t) return -1;
    ++iguales;
    return 0;
  }

};


int main(int argc, char *argv[])
{
  guessControlador ctrl;

  do {
    ctrl.jugar();
  } while (ctrl.evaluar());
  ctrl.terminar();

  return 0;
}
