#include <stdio.h>
#include <stdlib.h>

int  fibonacci(int N);

int main() {
   int N;
   int retorno;  
   printf("Informe um valor: ");
   scanf("%d", &N);
   printf("\n");
   retorno = fibonacci(N);
   printf("N-esimo Termo: %d", retorno);
}

int fibonacci(int N) {
  
  if(N == 1 || N == 2)
   return 1;
  else 
  return fibonacci(N - 1)+ fibonacci(N - 2);;            
}