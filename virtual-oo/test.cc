#include <iostream>

struct Base
{
   int foo() { std::cout << "Base.foo\n"; }

  virtual ~Base() { std::cout << "Base destructor\n"; }
};

struct Derived : public Base
{
  int * dato;
  Derived() : dato(new int()) {}

  int foo() { std::cout << "Derived::foor\n"; }
  
  virtual ~Derived() 
  {
    std::cout << "Derived destructor\n"; 
    delete dato;
  }
};

int main(int argc, char *argv[])
{
  Base a;
  Base* b = new Derived();
  a.foo();
  b->foo();
  delete b;
  return 0;
}
