#include <math.h>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>

template <typename T>
double mean(T const& data)
{
  double sum = 0;
  for(auto e : data)
    sum += e;
  return sum/data.size();
}

template <typename T>
double std_dev(T const& data)
{
  double data_mean = mean(data);
  double sum = 0;
  size_t n = data.size();
  for(auto e : data) {
    sum += pow(e - data_mean, 2);
  }
  return sqrt(sum/(n-1));
}

template <typename T>
T load_data(std::string filename)
{
  T data;
  typename T::value_type d;
  std::ifstream myfile;
  myfile.open(filename);
  if (myfile.is_open()) {
    myfile >> d;
    while (!myfile.eof()) {
        data.push_back(d);
        myfile >> d;
    }
    myfile.close();
  }
  else
    std::cout << "Archivo " << filename << " no existe!\n";
  return data;
}

class Demo
{
public:
  Demo();
  virtual ~Demo();
};


template <typename T>
void print_values(T const& data)
{
  for(auto e : data)
    std::cout << e << std::endl; 
}

int main(int argc, char *argv[])
{
  typedef std::list<double> lista_t;
  
  lista_t l{160,591,114,229,230,270,128,1657,624,1503};

  std::cout << "mean: " << mean(l) << std::endl;
  std::cout << "std dev: " << std_dev(l) << std::endl;

  auto l2 = load_data<lista_t>("column1.txt");
  std::cout << "mean: " << mean(l2) << std::endl;
  std::cout << "std dev: " << std_dev(l2) << std::endl;
  print_values(l2);

  auto l3 = load_data<std::vector<double>>("column1.txt");
  std::cout << "mean: " << mean(l3) << std::endl;
  std::cout << "std dev: " << std_dev(l3) << std::endl;
  print_values(l3);

  return 0;
}
