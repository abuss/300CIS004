#include <iostream>

struct Base
{
  int foo(int x) const { return x+1; }
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
  : public DerivedB,
    public DerivedC
{
  // Error: Ambiguous invocation 
  // void print1(int z) const
  // {
  //   std::cout << "foo: " << foo(z) << std::endl;
  // }
  
  // Ok
  void print2(int z) const
  {
    std::cout << "foo: " << DerivedB::foo(z) << std::endl;
  }
};

int main(int argc, char const *argv[])
{
  DerivedD d;
  //  d.print1(5); // Error
  d.print2(5); // Ok
}
