// Metaprogramming

#include <iostream>

template <int N>
struct fibo
{
  enum { value = fibo<N-1>::value + fibo<N-2>::value };
};

template <>
struct fibo<0>
{
  enum { value = 1 };
};

template <>
struct fibo<1>
{
  enum { value = 1 };
};

int main()
{
  std::cout << "fibo(40): " << fibo<40>::value << std::endl;
  return 0;
}
