#include <iostream>

template <typename Derived>
struct operacionA
{
  int foo(int X) 
  { 
    std::cout << "x: " << x << std::endl;
  }

  void add(int w)
  {
    static_cast<Derived>(this)->y += w;
  }
};


struct claseB
  : public operacionA<claseB>
{
  int y;
  claseB(int w) : y(w) { }
};

int main(int argc, char *argv[])
{
  claseB b;
  b.add(4);
  return 0;
}
