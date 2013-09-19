#include <iostream>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
  Punto pe = {rand()%10, rand()%10, rand()%10};
  int intentos = 0;
  int iguales;
  Punto pt;
  do {
    iguales = 0;
    std::cin >> pt.x >> pt.y >> pt.z;

    // X
    if (pe.x < pt.x)
      std::cout << "Mas abajo. ";
    else
      if (pe.x > pt.x)
        std::cout << "Mas arriba. ";
      else
        ++iguales;
    // Y
    if (pe.y < pt.y)
      std::cout << "Mas a la izquierda. ";
    else
      if (pe.y > pt.y)
        std::cout << "Mas a la derecha. ";
      else
        ++iguales;

    // Z
    if (pe.z < pt.z)
      std::cout << "Mas cerca. ";
    else
      if (pe.z > pt.z)
        std::cout << "Mas lejos. ";
      else
        ++iguales;

    ++intentos;
    std::cout << std::endl;
  } while (intentos<10 && iguales!=3);
  if (iguales==3)
    std::cout << "BOOOM!!\n";
  else
    std::cout << "Alien invasion!!\n";

  return 0;
}
