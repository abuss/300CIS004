#include <iostream>

class Objeto
{
  static size_t num_instances;

public:
  Objeto() 
  { ++num_instances; }

  size_t get_num_instances()
  {
    return num_instances;
  }

  // ~Objeto()
  // { --num_instances; }
};


size_t Objeto::num_instances = 0;

int main(int argc, char *argv[])
{
  Objeto o1;
  std::cout << "num instances: " << o1.get_num_instances() << std::endl;
  
  {
    Objeto o2;
    std::cout << "num instances: " << o2.get_num_instances() << std::endl;
  }

  Objeto o2;
  std::cout << "num instances: " << o2.get_num_instances() << std::endl;
  
  return 0;
}
