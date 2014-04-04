#include <iostream>
#include <vector>

struct Base
{
  virtual void print()
  { std::cout << "Soy BASE\n"; }
};


struct DerivedA : public Base
{
  virtual void print()
  { std::cout << "Soy DerivedA\n"; }
};


struct DerivedB : public Base
{
  virtual void print()
  { std::cout << "Soy DerivedB\n"; }
};


int main(int argc, char *argv[])
{
  std::vector<Base*> v;
  v.push_back(new DerivedA());
  v.push_back(new DerivedB());
  v.push_back(new DerivedA());

  for(auto x : v)
    x->print();

  return 0;
}
