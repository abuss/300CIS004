#include <iostream>

struct Base
{
  int val;

  Base() : val(0) { }

  int foo(int x)
  {
    val = x;
    return x+1; 
  }
};


struct DerivedB
  : public Base
{
  int bar(int y) const { return y-1; }
};


struct DerivedC
  : public Base
{
  int baz(int w) const { return w; }
};


struct DerivedD
  : virtual public DerivedB, 
    virtual public DerivedC
{
  void print1(int z)
  {
    std::cout << "foo: " << DerivedB::foo(z) << std::endl;
    std::cout << "DerivedB::val: " << DerivedB::val << std::endl;
    std::cout << "DerivedC::val: " << DerivedC::val << std::endl;
  }
};


int main(int argc, char const *argv[])
{
  DerivedD d;
  d.print1(5);
}
