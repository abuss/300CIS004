// Definicion de un vector parametrico

#pragma once

#include <algorithm>

template <typename T>
struct miVector
{
  class miIterator
  {
    miVector&  m_data;
    size_t     m_index;
  public:
    typedef T value_type;

    miIterator(miVector& v, size_t i)
      : m_data(v), m_index(i)
    { }
    
    miIterator& operator++()
    {
      ++m_index;
      return *this;
    }

    value_type operator*()
    {
      return m_data[m_index];
    }

    bool operator!=(miIterator const& other) const
    {
      return (m_index!=other.m_index);
    }
  };

  typedef miIterator      iterator;
  typedef const iterator  const_iterator;
  typedef T               value_type;
  typedef T               reference;

  // Default constructor
  miVector() { }

  // Main constructor
  miVector(int n)
    : m_size(n)
  { }

  // Copy constructor
  miVector(const miVector& other)
    : m_size(other.m_size)
  {
    std::cout << "copy constructor" << std::endl;
  }

  // Assigment operator
  miVector& operator=(const miVector& other)
  {
    std::cout << "copy assigment" << std::endl;
    m_size = other.m_size;
    return *this;
  }

  T operator[](size_t i) const
  {
    return static_cast<T>(i);
  }

  size_t size() const
  {
    return m_size;
  }

  iterator begin()
  {
    return iterator(*this,0);
  }

  iterator end()
  {
    return iterator(*this,m_size);
  }

private:
  size_t  m_size = 0;
};
