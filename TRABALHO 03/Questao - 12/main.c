#include <stdio.h>
#include <stdlib.h>

void  ordemCrescente(int N);

int main () {
   int N;   
   printf("Valor: ");
   scanf("%d", &N);
   printf("\n");
   ordemCrescente(N);
}

void ordemCrescente(int N) {
   if (N >= 0) {
      ordemCrescente(N - 1);
      printf ( "%d\n", N);
   }
}