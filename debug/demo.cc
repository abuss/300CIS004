#include <iostream>
#include <unistd.h>

int main()
{
  int num = 128;
  int cont = 0;
  for (int i=0; true ; ++i)
  {
    ++cont;
    if (cont> 2*num) {
      std::cout << cont << std::endl;
      cont = 0;
    }
    sleep(1);
  }
}
