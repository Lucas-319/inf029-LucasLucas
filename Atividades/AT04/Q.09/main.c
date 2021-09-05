#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

int main() {

  Pessoa cadastro1;
  
  cadastro1 = cadastrarCliente();
  imprimir(cadastro1);
 
  return 0;                      
}