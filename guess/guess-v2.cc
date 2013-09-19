#include <iostream>
#include <stdlib.h>
#include <string>

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
Punto read()
{
  Punto pt;
  std::cin >> pt.x >> pt.y >> pt.z;
  return pt;
}


int check_dimesion(int e, int t, std::string major, std::string menor)
{
  if (e < t) {
    std::cout << major;
    return 0;
  }
  if (e > t) {
    std::cout << menor;
    return 0;
  }
  return 1;
}

struct guestModelo
{
  Punto m_punto;
  int   m_intentos;

  guestModelo() 
    : m_punto{rand()%10, rand()%10, rand()%10},
      m_intentos(0)
  { }

  const Punto& punto() const { return m_punto; }

  void incrementar_intentos() { ++m_intentos; }

  int intentos() const { return m_intentos; }
};


int main(int argc, char *argv[])
{
  guestModelo data;
  int iguales;
  Punto pt;
  do {
    iguales = 0;
    pt = read();

    // X
    iguales += check_dimesion(data.punto().x, pt.x,
                              "Mas abajo. ", "Mas arriba. ");

    // Y
    iguales += check_dimesion(data.punto().y, pt.y,
                              "Mas a la izquierda. ", "Mas a la derecha. ");

    // Z
    iguales += check_dimesion(data.punto().z, pt.z,
                              "Mas cerca. ", "Mas lejos. ");
    data.incrementar_intentos();
    std::cout << std::endl;
  } while (data.intentos()<10 && iguales!=3);
  if (iguales==3)
    std::cout << "BOOOM!!\n";
  else
    std::cout << "Alien invasion!!\n";

  return 0;
}
