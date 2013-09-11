#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

#include "persona.h"

persona::persona(const persona& p)
  : m_nombre(p.m_nombre), m_edad(p.m_edad),
    m_direccion(p.m_direccion), m_email(p.m_email)
{
  std::cout << "Constructor de copia\n";
}


persona::persona(persona&& p)
  : m_nombre(p.m_nombre), m_edad(p.m_edad),
    m_direccion(p.m_direccion), m_email(p.m_email)
{
  std::cout << "Constructor de movimiento\n";
}


persona::persona(const std::string& nombre, short edad,
                 const std::string& direccion, const std::string& email)
  : m_nombre(nombre), m_edad(edad), m_direccion(direccion)
{
  assert(chequeo_email(email));
  m_email = email;
  std::cout << "Constructor de inicializacion\n";
}


persona& persona::operator=(const persona& p)
{
  m_nombre = p.m_nombre;
  m_edad = p.m_edad;
  m_direccion = p.m_direccion;
  m_email = p.m_email;
  std::cout << "Asignacion\n";
  return *this;
}


persona& persona::operator=(persona&& p)
{
  m_nombre = p.m_nombre;
  m_edad = p.m_edad;
  m_direccion = p.m_direccion;
  m_email = p.m_email;
  std::cout << "Asignacion de movimiento\n";
  return *this;
}


void persona::imprimir() const
{
  std::cout << "Nombre: " << m_nombre
            << " Edad: " << m_edad
            << " Direccion: " << m_direccion
            << " Email: " << m_email
            << std::endl;
}

bool persona::chequeo_email(const std::string& email) const
{
  auto it = find(email.begin(), email.end(),'@');
  return email.end()!=it;
}
