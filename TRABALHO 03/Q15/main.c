#include <stdio.h>
#include <stdlib.h>

void  ordemDecrescentePar(int N);

int main () {
   int N;   
   printf("Valor: ");
   scanf("%d", &N);
   if(N % 2 == 0){
   printf("\n");
   ordemDecrescentePar(N);
   }
   else
     printf("Impossivel prosseguir, digite um numero par!\n");
}

void ordemDecrescentePar(int N) {
   if (N >= 0) {
      printf ( "%d\n", N);
      ordemDecrescentePar(N - 2);      
   }
}