#include <iostream>
#include <vector>

class punto
{
  int x,y;
public:
  punto(int xx, int yy)
    : x(xx), y(yy)
  { }

  void print() const
  {
    std::cout << "Punto["<< x << "," << y <<"] ";
  }
};


class figura
{
  std::vector<punto> puntos;
public:
  figura(std::initializer_list<punto> const& ps)
    : puntos{ps}
  { }

  void print() const
  {
    for(auto& p : puntos)
      p.print();
  }
};


int main(int argc, char *argv[])
{
  figura fig {{1,2},{0,1},{5,4}};
  fig.print();
  return 0;
}
