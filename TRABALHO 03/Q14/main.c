#include <stdio.h>
#include <stdlib.h>

void  ordemCrescentePar(int N);

int main () {
   int N;   
   printf("Valor: ");
   scanf("%d", &N);
   if(N % 2 == 0){
   printf("\n");
   ordemCrescentePar(N);
   }
   else
     printf("Impossivel prosseguir, digite um numero par!\n");
}

void ordemCrescentePar(int N) {
   if (N >= 0) {
      ordemCrescentePar(N - 2);
      printf ( "%d\n", N);
   }
}