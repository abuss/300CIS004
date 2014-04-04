#include <iostream>
#define VERDE "\033[;32m"
#define ROJO "\033[;31m"
#define NORMAL "\033[0m"

class Base
{
public:
  Base()
  {
    std::cout << VERDE << "[Base] Constructor por defecto\n" << NORMAL;
  }
  
  // ~Base() 
  // {
  //   std::cout << ROJO << "[Base] Destructor\n" << NORMAL;
  // }

  virtual ~Base() 
  {
    std::cout << ROJO << "[Base] Destructor\n" << NORMAL;
  }
};


class DerA 
  : public Base 
{
public:
  DerA() 
  {
    std::cout << VERDE <<" [DerA] Constructor por defecto\n" << NORMAL;
  }

  ~DerA()
  {
    std::cout << ROJO << " [DerA] Destructor\n" << NORMAL;
  }
};


int main(int argc, char *argv[])
{
  {
    DerA a;
  }
  std::cout << "--------------------\n";
  {
    Base* b = new DerA();
    delete b;
  }
  // std::cout << "--------------------\n";
  // {
  //   DerA* c = new DerA();
  //   Base* d = c;
  //   delete d;
  // }
  // std::cout << "--------------------\n";
  //   DerA e;
  // {
  //   DerA f = e;
  // }
  return 0;
}
