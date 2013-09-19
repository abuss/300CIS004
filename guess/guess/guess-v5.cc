#include "guess_vista_iostream.h"
#include "guest_controlador_iostream.h"

int main(int argc, char *argv[])
{
  guessControladorIOStream ctrl;

  do {
    ctrl.jugar();
  } while (ctrl.evaluar());
  ctrl.terminar();

  return 0;
}
