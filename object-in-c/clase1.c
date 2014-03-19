#include <stdio.h>
#include <stdlib.h>

typedef struct clase clase_t;

struct clase
{
  int valor;
  void (*fn)(clase_t*, int);
};

clase_t* init(int v)
{
  void add(clase_t* c, int v)
  {
    c->valor+=v;
  };

  clase_t* c1 = (clase_t*)malloc(sizeof(clase_t));
  c1->fn = &add;
  c1->valor = v;
  return c1; 
}


int main(int argc, char *argv[])
{
  clase_t* c1 = init(6);
  c1->fn(c1,3);
  printf("valor: %d\n",c1->valor);
  free(c1);
  return 0;
}
