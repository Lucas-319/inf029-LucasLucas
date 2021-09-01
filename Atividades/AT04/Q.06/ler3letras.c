#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

   char letra01, letra02, letra03; 

}Letra;

Letra ler3Letras(){

  Letra caracter;

  printf("Informe a primeira letra: ");
  scanf(" %c", &caracter.letra01);
  
  printf("Informe a segunda letra: ");
  scanf(" %c", &caracter.letra02);
  
  printf("Informe a terceiraa letra: ");
  scanf(" %c", &caracter.letra03);
  
  return caracter;
}

void imprimir(Letra x){
   
   printf("\n");
   printf("Letra |01| -> %c\n",x.letra01);
   printf("Letra |02| -> %c\n",x.letra02); 
   printf("Letra |03| -> %c\n",x.letra03); 
    
}
int main(){

  Letra retorno;

  retorno = ler3Letras();
  imprimir(retorno);
}