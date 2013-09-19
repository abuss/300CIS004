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

int main(int argc, char *argv[])
{
  Punto pe = {rand()%10, rand()%10, rand()%10};
  int intentos = 0;
  int iguales;
  Punto pt;
  do {
    iguales = 0;
    pt = read();

    // X
    iguales += check_dimesion(pe.x, pt.x,
                              "Mas abajo. ", "Mas arriba. ");

    // Y
    iguales += check_dimesion(pe.y, pt.y,
                              "Mas a la izquierda. ", "Mas a la derecha. ");

    // Z
    iguales += check_dimesion(pe.z, pt.z,
                              "Mas cerca. ", "Mas lejos. ");
    ++intentos;
    std::cout << std::endl;
  } while (intentos<10 && iguales!=3);
  if (iguales==3)
    std::cout << "BOOOM!!\n";
  else
    std::cout << "Alien invasion!!\n";

  return 0;
}
