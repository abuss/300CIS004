// C++11

#include <iostream>

constexpr int fibo(int n)
{
  return (n==0 || n==1) ? 1 : fibo(n-1)+fibo(n-2);
}

int main()
{
  const int res = fibo(40);
  std::cout << "fibo(40): " << res << std::endl;
  return 0;
}
