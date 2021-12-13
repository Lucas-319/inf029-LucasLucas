#include <stdio.h>
#include <stdlib.h>

long double fatorial(int n);

int main(void){
  int num;
  long double retorno;
  
  printf("Informe um valor: ");
  scanf("%d",&num);
    
  retorno = fatorial(num);
  
  printf("Fatorial de %d = %.0Lf", num, retorno);      
}

long double fatorial(int n){
  long double vfat;
  
  if ( n <= 1 )    
    return (1);
  else{    
    vfat = n * fatorial(n - 1);
    return (vfat);
  } 
}