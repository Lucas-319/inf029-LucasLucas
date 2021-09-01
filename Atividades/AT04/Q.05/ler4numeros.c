#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

   int num01, num02, num03, num04; 

}Numero;

Numero ler4Numeros(){

  Numero numero;

  printf("Informe o primeiro numero: ");
  scanf("%d", &numero.num01);
  printf("Informe o segundoo numero: ");
  scanf("%d", &numero.num02);
  printf("Informe o terceiro numero: ");
  scanf("%d", &numero.num03);
  printf("Informe o quarto numero: ");
  scanf("%d", &numero.num04);
  
  return numero;
}

void imprimir(Numero x){
   
   printf("\n");
   printf("Numero |01| -> %d\n",x.num01);
   printf("Numero |02| -> %d\n",x.num02); 
   printf("Numero |03| -> %d\n",x.num03); 
   printf("Numero |04| -> %d\n",x.num04); 
}
int main(){

  Numero retorno;

  retorno = ler4Numeros();
  imprimir(retorno);
}