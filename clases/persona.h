// Demo de clase
#include <iostream>
#include <string>

#pragma once

class persona
{
  std::string m_nombre;
  short       m_edad = 0;
  std::string m_direccion;
  std::string m_email;

  
public:

  // Constructor por defecto
  persona()
    : m_nombre(""), m_direccion(""), m_email("")
  {
    std::cout << "Default constructor\n";
  }

  // Constructor de copia
  persona(const persona& p);

  // Constructor de movimiento
  persona(persona&& p);


  // Constructor principal
  persona(const std::string& nombre, short edad,
          std::string const& direccion, std::string const& email);

  persona(const std::string& nombre, std::string const& email)
    : persona(nombre,0,"",email)
  { }

  ~persona()
  {
    std::cout << "Destructor\n";
  }
  
  // Operador de asignacion
  persona& operator=(const persona& p);

  // // Asignacion con movimiento (move semantics)
  // persona& operator=(persona&& p);


  // Imprime en pantalla la informacion de la persona
  void imprimir() const;

  
private:
  // Verifica que el email enviado este bien formado
  bool chequeo_email(const std::string& email) const;

};
