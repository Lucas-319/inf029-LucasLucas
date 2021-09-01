#include <stdio.h>


int funcao_sub(int v1, int v2, int v3){

  int sub;

  sub = v1 - v2 - v3;

  return sub;
}

int main(){

  int valor1, valor2, valor3;
  int subtracao;

  puts("Por gentileza, informe |3| valores: ");
  scanf("%d %d %d", &valor1, &valor2, &valor3);

  subtracao = funcao_sub(valor1, valor2, valor3);

  printf("O resultado da subtracao eh: %d.", subtracao);
  
}