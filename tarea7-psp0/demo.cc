#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
  // std::string filename{"demo.cc"};
  std::string filename{"psp0.cc"};
  std::string line;

  std::ifstream myfile;
  myfile.open(filename);
  if (myfile.is_open()) {
    while (!myfile.eof()) {
      std::getline(myfile,line);
      if (line[0]=='#')
        std::cout << line << std::endl;
      else {
        int pos = line.find(" ");
        int pos2 = line.find("(");
        if (pos>0 && pos2>pos) {
          auto name = line.substr(pos,pos2-pos);
          std::cout << "pos: " << pos
                    << " pos2: " << pos2
                    << " name: " << name
                    << std::endl;
        }
      }
    }
    myfile.close();
  }
  return 0;
}
