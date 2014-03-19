// Runtime

#include <iostream>

int fibo(int n)
{
  if (n==0 || n==1)
    return 1;
  return fibo(n-1)+fibo(n-2);
}

int main()
{
  std::cout << "fibo(40): " << fibo(40) << std::endl;
  return 0;
}
