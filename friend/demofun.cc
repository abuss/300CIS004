#include <iostream>

class A
{
  int m_valor;
  int m_dato;
  friend int get_valor(const A&);
  
  int dato() const
  {
    return m_dato;
  }

public:
  A(int x)
    : m_valor(x), m_dato(2*x)
  { };
};

int get_valor(const A& o)
{
  std::cout << "Valor: " << o.m_valor << " Dato: " << o.dato() << std::endl;
  return o.m_valor;
}

int get_dato(const A& o)
{
  std::cout << " Dato: " << o.dato() << "Valor: " << o.m_valor << std::endl;
  return o.dato();
}

int main(int argc, char *argv[])
{
  A a(5);
  //  std::cout << "a.dato(): " << a.dato() << std::endl; 
  get_valor(a);
  get_dato(a);
  return 0;
}
