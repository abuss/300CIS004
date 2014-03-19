#include <iostream>

template <int N>
struct fact
{
	enum { value = N*fact<N-1>::value };
};

template <>
struct fact<1>
{
	enum { value = 1 };
};

int main(int argc, char const *argv[])
{
  std::cout << fact<12>::value << std::endl;
	return 0;
}