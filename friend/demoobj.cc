#include <iostream>

class A
{
  int m_valor;
  int m_dato;
  
  int dato() const
  {
    return m_dato;
  }

  // friend class B;

public:
  A(int x)
    : m_valor(x), m_dato(2*x)
  { };
};


class B
{
  int m_res;
public:
  B(const A& a)
    : m_res(a.m_valor+a.dato())
  {}

  int get_valor_gw(const A& a) const
  {
    return a.m_valor;
  }
};


int main(int argc, char *argv[])
{
  A a(5);
  B b(a);
  std::cout << "a.valor: " << b.get_valor_gw(a) << std::endl;
  return 0;
}
