// Definicion de un vector parametrico

#pragma once

#include <algorithm>

template <typename T>
struct miVector
{
  // Default constructor
  miVector() { }

  // Main constructor
  miVector(int n)
    : m_data(new T[n]), m_size(n)
  { }

  // Copy constructor
  miVector(const miVector& other)
    : m_data(new T[other.m_size]), m_size(other.m_size)
  {
    std::cout << "copy constructor" << std::endl;
    std::copy(other.m_data, other.m_data+other.m_size,
              m_data);
  }

#ifdef _WITH_MOVE
  // Move constructor
  miVector(miVector&& other)
    : m_data(other.m_data), m_size(other.m_size)
  {
    std::cout << "move constructor\n";
    other.m_data = nullptr;
    other.m_size = 0;
  }
#endif

  // Assigment operator
  miVector& operator=(const miVector& other)
  {
    std::cout << "copy assigment" << std::endl;
    m_data = new T[other.m_size];
    m_size = other.m_size;
    std::copy(other.m_data, other.m_data+other.m_size,
              m_data);
    return *this;
  }

#ifdef _WITH_MOVE
  // Move assigment
  miVector& operator=(miVector&& other)
  {
    std::cout << "move assigment\n";
    m_data = other.m_data;
    m_size = other.m_size;
    other.m_data = nullptr;
    other.m_size = 0;
    return *this;
  }
#endif

  // Destructor
  ~miVector()
  {
    if (m_data)
      delete [] m_data;
  }

  T& operator[](int i)
  {
    return m_data[i];
  }

private:
  T*      m_data = nullptr;
  size_t  m_size = 0;
};
