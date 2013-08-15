#include <stdio.h>
#include <stdlib.h>

#define VALUE int

typedef VALUE*  row_type;
typedef VALUE** matrix_type;

struct matrix
{
  matrix_type mat;
  int rows, cols;
};

matrix_type create_matrix(int rows, int cols)
{
  matrix_type mat = malloc(sizeof(row_type)*rows);
  int i;
  for (i=0; i<rows; ++i)
    mat[i] = malloc(sizeof(VALUE)*cols);
  return mat;
}

void print(matrix_type mat, int rows, int cols)
{
  int i,j;
  for (i=0;i<rows;++i) {
    for (j=0;j<cols;++j) 
      printf("%d ",mat[i][j]);
    printf("\n");
  }
}


matrix_type multmat(matrix_type matA, int rowsA, int colsA, 
                    matrix_type matB, int rowsB, int colsB)
{
  matrix_type res = create_matrix(rowsA,colsB);
  int i,j,k;
  for (i=0; i<rowsA; ++i)
      for (k=0; k<colsA; ++k) 
    for (j=0; j<colsB; ++j)
        res[i][j] += matA[i][k]*matB[k][j]; 
  return res;
}


int main(int argc, char *argv[])
{
  if (argc<2) {
    printf("Usage: exe #rows\n");
    exit(1);
  }
  
  int n = atoi(argv[1]);
  matrix_type m1 = create_matrix(n,n);
  matrix_type m2 = create_matrix(n,n);
  matrix_type res;

  int i,j;
  for(i=0;i<n;++i)
    for(j=0;j<n;++j) {
      m1[i][j] = i+j+1;
      m2[i][j] = i+j+1;
    }
  
  res = multmat(m1,n,n, m2,n,n);
  if (n<20) {
    print(m1,n,n);
    printf("---------------\n");
    print(m2,n,n);
    printf("---------------\n");
    print(res,n,n);
  }
  
  printf("Done!\n");
  return 0;
}
