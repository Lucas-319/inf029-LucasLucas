#include <stdio.h>
#include <stdlib.h>

int multiplicacao(int n1, int n2);

int main(){

  int n1, n2;
  int retorno;

  printf("Digite o valor de n1: ");
  scanf("%d", &n1);
  printf("\n");

  printf("Digite o valor de n2: ");
  scanf("%d", &n2);
  printf("\n");

  retorno = multiplicacao(n1, n2);
  printf("Multiplicacao de %d x %d = %d\n", n1, n2, retorno);   

}

int multiplicacao(int n1, int n2){
  if(n2 > 0)
    return n1 + multiplicacao(n1, n2 - 1);

  return 0;  
}