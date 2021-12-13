#include <stdio.h>
#include <stdlib.h>

void  ordemDecrescente(int N);

int main () {
   int N;   
   printf("Valor: ");
   scanf("%d", &N);
   printf("\n");
   ordemDecrescente(N);
}

void ordemDecrescente(int N) {
   if (N >= 0) {
      printf ( "%d\n", N);
      ordemDecrescente(N - 1);      
   }
}