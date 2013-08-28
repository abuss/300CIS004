// Ejemplo de move semantics

#include <iostream>
#include <algorithm>
#include "mivector_gen.hpp"

int main(int argc, char *argv[])
{
  size_t n = 1000;
  if (argc>1)
    n = atoi(argv[1]);

  miVector<int> w(n);
  
  size_t res = 0;
  for (size_t i=0; i<n; ++i)
    res+=w[i];
  std::cout << "Res: " << res << std::endl;

  if (n<20)
    for(size_t i=0; i<n; ++i)
      std::cout << w[i] << " ";
  std::cout << std::endl;

  res = std::accumulate(w.begin(),w.end(),0);
  std::cout << "Res: " << res << std::endl;

  if (n<20)
    for(auto x : w)
      std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}
