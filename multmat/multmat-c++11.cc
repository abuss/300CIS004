#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>


template<typename T>
struct Matrix
{
  typedef std::vector<T> row_type;

  std::vector<row_type> mat;
  size_t rows, cols;

  Matrix()
    : rows{0}, cols{0}
  { }

  Matrix(size_t n_rows, size_t n_cols)
    : mat{n_rows}, rows{n_rows}, cols{n_cols}
  {
    for (auto& row: mat)
      row.resize(cols);
  }
  
  T& operator()(size_t i, size_t j)
  {
    return mat[i][j];
  }

  T const& operator()(size_t i, size_t j) const
  {
    return mat[i][j];
  }

  void fill(T val)
  {
    for(auto row: mat)
      for (auto& elem : row)
        elem = val;
  }   

  void print() const
  {
    for(auto row: mat) {
      for (auto elem : row)
        std::cout << elem << " ";
      std::cout << std::endl;
    }
  }
  
  Matrix& operator+=(Matrix const& b)
  {
    assert(rows==b.rows && cols==b.cols);
    for (int i=0;i<rows;++i) 
      for (int j=0; j<cols; ++j) {
        (*this)(i,j) += b(i,j);
      }
    return (*this);
  }

  Matrix operator*(Matrix const& Mb) const
  {
    assert(cols==Mb.rows);
    Matrix res{rows,Mb.cols};
    res.fill(0);
    for (int i=0;i<rows;++i) 
      for (int j=0; j<Mb.rows; ++j) {
        T tmp = res(i,j);
        for (int k=0; k<cols; ++k)
          tmp += mat[i][k]*Mb(k,j);
        res(i,j) = tmp;
      }
    return res;
  }

};
  


int main(int argc, char** argv) 
{
  if (argc<2) {
    std::cout << "Usage: exe #rows" << std::endl;
    exit(1);
  }
  
  int n = atoi(argv[1]);
  typedef Matrix<int> matrix_t;

  matrix_t m1 = matrix_t(n,n);
  matrix_t m2 = matrix_t(n,n);
  matrix_t res;

  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j) {
      m1(i,j) = i+j+1;
      m2(j,i) = i+j+1;
    }

  res = m1 * m2;
  if (n<20) {
    m1.print();
    std::cout << "---------------\n";
    m2.print();
    std::cout << "---------------\n";
    res.print();
    std::cout << "===============\n";
  }

  res += m1;
  if (n<20) {
    m1.print();
    std::cout << "---------------\n";
    res.print();
  }
}
  
