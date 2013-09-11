class Base
{
  virtual int foo(int x) {};
};

class Derived
  : public Base
{
  int foo(int);
  //int foo(int x) { return x+1; }
};

int Derived::foo(int x)
{ return x+1; }

int main(int argc, char const *argv[])
{
  Base a;
  Derived b;
}
