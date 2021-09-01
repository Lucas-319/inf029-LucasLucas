#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

   char palavra01[100],palavra02[100],palavra03[100]; 

}Palavra;

Palavra ler3Palavras(){

  Palavra palavra;

  printf("Informe a primeira palavra: ");
  scanf(" %s", palavra.palavra01);
  
  printf("Informe a segunda palavra: ");
  scanf(" %s", palavra.palavra02);
  
  printf("Informe a terceira palavra: ");
  scanf(" %s", palavra.palavra03);
  
  return palavra;
}

void imprimir(Palavra x){
   
   printf("\n");
   printf("Palavra |01| -> %s\n",x.palavra01);
   printf("Palavra |02| -> %s\n",x.palavra02); 
   printf("Palavra |03| -> %s\n",x.palavra03); 
    
}
int main(){

  Palavra retorno;

  retorno = ler3Palavras();
  imprimir(retorno);
}