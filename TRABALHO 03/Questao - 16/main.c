#include <stdio.h>
#include <stdlib.h>

long double fatorialDuplo(int n);

int main(void){
  int num;
  long double retorno;
  
  printf("Informe um valor: ");
  scanf("%d",&num);
  
  if(num % 2 != 0){
      retorno = fatorialDuplo(num);
      
      printf("Fatorial duplo de %d = %.0Lf", num, retorno);
  }
  else
    printf("Impossivel prosseguir, digite um numero impar!\n");
           
}

long double fatorialDuplo(int n){
  long double vfat;
  
  if ( n <= 1 )    
    return (1);
  else{    
    vfat = n * fatorialDuplo(n - 2);
    return (vfat);
  } 
}