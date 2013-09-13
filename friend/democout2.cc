#include <iostream>
#include <vector>

class punto
{
  int x,y;
public:
  punto(int xx, int yy)
    : x(xx), y(yy)
  { }

  friend std::ostream& operator<<(std::ostream& o, const punto& p);
};

std::ostream& operator<<(std::ostream& o, const punto& p)
{
  o << "["<< p.x << "," << p.y <<"]";
  return o;
}


class figura
{
  std::vector<punto> puntos;
public:
  figura(std::initializer_list<punto> const& ps)
    : puntos{ps}
  { }


  friend std::ostream& operator<<(std::ostream& o, const figura& f);
};


std::ostream& operator<<(std::ostream& o, const figura& f)
{
  o << "Figura:\n";
  int i = 0;
  for(auto& p : f.puntos)
    o << "  punto"<< i++ <<": " << p << std::endl;
  return o;
}


int main(int argc, char *argv[])
{
  figura fig {{1,2},{0,1},{5,4}};
  std::cout << fig;
  return 0;
}
