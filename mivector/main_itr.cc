// Ejemplo de move semantics

#include <iostream>
#include <algorithm>
#include <numeric>
#include "mivector.hpp"

template <typename T>
miVector<T> crear(int n)
{
  miVector<T> v(n);
  size_t i = 0;
  for(auto& x : v)
    x = i++;
  return v;
}

int main(int argc, char *argv[])
{
  size_t n = 1000;
  if (argc>1)
    n = atoi(argv[1]);

  miVector<int> z = {2,5,3,77,8,1,3};

  for(auto x : z)
    std::cout << x << " ";
  std::cout << std::endl;

  std::for_each(z.begin(), z.end(), [](int x){std::cout << x << " ";});
  std::cout << std::endl;

  miVector<int> w;
  w = crear<int>(n);
  
  size_t res = 0;
  for (size_t i=0; i<n; ++i)
    res+=w[i];
  std::cout << "Res: " << res << std::endl;

  res = std::accumulate(w.begin(),w.end(),0);
  std::cout << "Res: " << res << std::endl;

  if (n<20)
    for(auto x : w)
      std::cout << x << " ";

  std::cout << std::endl;
  return 0;
}
