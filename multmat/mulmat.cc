#include <stdlib.h>
#include <iostream>
#include <assert.h>

template<typename T>
struct Matrix
{
  typedef T* row_type;

  row_type* mat;
  size_t rows, cols;
  
  Matrix()
    : mat(NULL), rows(0), cols(0)
  { }
  
  Matrix(int n_rows, int n_cols)
    : rows(n_rows), cols(n_cols)
  {
    mat = new row_type[rows];
    for (int i=0; i<rows; ++i)
      mat[i] = new T[cols];
  }
  
  void set(int i, int j, T val)
  {
    mat[i][j] = val;
  }
  
  T get(int i, int j) const
  {
    return mat[i][j];
  }

  void fill(T val)
  {
    for (int i=0; i<rows; ++i) 
      for (int j=0; j<cols; ++j) 
	mat[i][j] = val;
  }   

  void print() const
  {
    for (int i=0;i<rows;++i) {
      for (int j=0; j<cols; ++j) 
	std::cout << mat[i][j] << " ";
      std::cout << std::endl;
    }   
  }
  
  Matrix mult(Matrix const& Mb) const
  {
    assert(cols==Mb.rows);
    Matrix res(rows,Mb.cols);
    T tmp;
    res.fill(0);
    for (int i=0;i<rows;++i) 
      for (int j=0; j<Mb.rows; ++j) 
	for (int k=0; k<cols; ++k) {
	  tmp = res.get(i,j);
	  tmp += mat[i][k]*Mb.get(k,j);
	  res.set(i,j,tmp);
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
      m1.set(i,j,i+j+1);
      m2.set(j,i,i+j+1);
    }

  res = m1.mult(m2);
  if (n<20) {
    m1.print();
    std::cout << "---------------\n";
    m2.print();
    std::cout << "---------------\n";
    res.print();
  }
}
  
