#include <iostream>
#include <string>


class punto2D
{
protected:
  int x;
  int y;
  std::string nom;
public:
  punto2D(std::string n="punto", int xx=0,int yy=0)
    : x(xx), y(yy), nom(n)
  {
    std::cout << "Crear "<< nom <<" x: " << x << " y: " << y << std::endl;
  }

  punto2D(const punto2D& p)
    : nom(p.nom), x(p.x), y(p.y)
  {
    std::cout << "Copia "<< nom <<" x: " << x << " y: " << y << std::endl; 
  }

  punto2D& operator=(const punto2D& p)
  {
    nom = p.nom;
    x = p.x;
    y = p.y;
    std::cout << "Asignar "<< nom <<" x: " << x << " y: " << y << std::endl; 
    return *this;
  }

  int suma() {
    return x+y;
  }

  ~punto2D() {
    std::cout << "Destruir " << nom << std::endl;
  }
};



class punto3D
  : public punto2D
{
  int z;
public:
  punto3D(std::string n="punto", int xx=0,int yy=0, int zz=0)
    : punto2D(n,xx,yy), z(zz)
  {
    std::cout << "Crear "<< nom <<" x: " << x << " y: " << y << " z: " << z << std::endl;
  }

  punto3D(const punto2D& p, int zz=0)
    : punto2D(p), z(zz)
  {
    std::cout << "Crear "<< nom <<" x: " << x << " y: " << y << " z: " << z << std::endl;
  }

  int suma() {
    return punto2D::suma()+z;
  }

};




int main(int argc, char *argv[])
{
  punto2D* p4 = new punto2D{"p4",5,6};
  punto2D p1("p1");
  punto2D p2("p2",4);
  punto2D p3{"p3",4,5};

  punto2D p5 = punto2D("p5",7,9);
  punto2D p6(p2);
  p2 = *p4;

  // std::cout << "p4.x: " << p4->x << std::endl;

  delete p4;

  punto3D q1("q1",4,5,6);
  std::cout << q1.suma() << std::endl;

  punto3D q2(p3,9);
  std::cout << q2.suma() << std::endl;
  
  return 0;
}
