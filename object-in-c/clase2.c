#include <stdio.h>
#include <stdlib.h>

typedef struct clase clase_t;

struct clase
{
  int valor;
  void (*add)(int);
};

clase_t* create(int v)
{
  clase_t* c1 = (clase_t*)malloc(sizeof(clase_t));

  void add(int v)
  {
    c1->valor+=v;
  };

  c1->add = &add;
  c1->valor = v;
  return c1; 
}


int main(int argc, char *argv[])
{
  clase_t* c1 = create(6);
  c1->add(3);
  printf("valor: %d\n",c1->valor);
  free(c1);
  return 0;
}
