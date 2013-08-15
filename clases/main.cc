#include <utility>
#include "persona.h"

// Funcion para captura de datos de una persona
persona pedir_datos()
{
  using namespace std;

  string nombre;
  short edad;
  string direccion;
  string email;
  
  cout << "====== Entradad de Datos ======\n";
  cout << "Nombre: ";
  getline(cin,nombre);
  cout << "Edad: ";
  cin >> edad;
  cin.ignore();
  cout << "Direccion: ";
  getline(cin,direccion);
  cout << "Email: ";
  cin >> email;
  return persona(nombre, edad, direccion, email);
}

int main(int argc, char *argv[])
{
  std::cout << "------------------------------\n";
  persona p;
  p.imprimir();
  // p.chequeo_email("ab.com"); // Error?

  std::cout << "------------------------------\n";
  persona q("Pedro Perez",20,"Cll 5 #4-33","a@b.com");
  q.imprimir();

  {
    std::cout << "------------------------------\n";
    persona q2("Carlos Fernandez","ff@demo.com");
    q2.imprimir();
  }

  std::cout << "------------------------------\n";
  persona r(q);
  r.imprimir();

  std::cout << "------------------------------\n";
  p = pedir_datos();
  p.imprimir();  

  std::cout << "------------------------------\n";
  // persona s(q); // Copia
  persona s(std::move(q));
  s.imprimir();  
  q.imprimir();  
  
  return 0;
}
