#include <stdio.h>
#include <stdlib.h>

int  somatorio(int N);

int main () {
   int N;
   int retorno;  
   printf("Valor: ");
   scanf("%d", &N);
   printf("\n");
   retorno = somatorio(N);
   printf("Soma: %d", retorno);
}

int somatorio(int N) {
  int soma = 0;
   if (N > 0) {
      soma = N + somatorio(N - 1);      
   }
   return soma;
}