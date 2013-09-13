#include <iostream>

class Constantes
{
public:
  // Constantes() = delete;
  const static int default_radio = 10;
  
  constexpr static double PI = 3.141592;
  
  static double area_circulo(double radio = default_radio)
  {
    return PI*radio*radio;
  }
};


int main(int argc, char *argv[])
{
  double p = Constantes::PI;

  double area = Constantes::area_circulo(40);

  std::cout << "Pi: " << p << std::endl;
  std::cout << "Area de circulo radio 40: " << area << std::endl;
  std::cout << "Area de circulo radio " << Constantes::default_radio <<" : "
            << Constantes::area_circulo() << std::endl;

  Constantes c;

  std::cout << "Pi: " << c.PI << std::endl;
  std::cout << "Area de circulo radio 40: " << c.area_circulo(40) << std::endl;
  std::cout << "Area de circulo radio " << c.default_radio <<" : "
            << c.area_circulo() << std::endl;

  return 0;
}
