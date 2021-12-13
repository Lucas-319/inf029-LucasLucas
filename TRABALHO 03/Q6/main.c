#include <stdio.h>
#include <stdlib.h>

int potencia(int K, int N);

int main(){

  int n, k;
  int retorno;

  printf("Digite o valor de K: ");
  scanf("%d", &k);
  printf("\n");

  printf("Digite o valor de N: ");
  scanf("%d", &n);
  printf("\n");
  
  retorno = potencia(k, n);
  printf("Resultado de %d elevado a %d: %d\n", k, n, retorno);
  
}

int potencia(int K, int N){
  if(N == 0)
    return 1;
  else
    return K * potencia(K, N - 1);
}