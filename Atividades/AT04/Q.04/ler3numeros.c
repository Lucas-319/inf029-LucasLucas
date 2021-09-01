#include <stdio.h>

void ler3numeros(int vetor[]){

  int i;
  
  for(i = 0; i < 3; i++){
    printf("Informe o elemento |0%d|: ", i+1);
     scanf("%d", &vetor[i]);
  }
}


int main() {
  
  int vetor[3];
  int v;
  

  ler3numeros(vetor);

  
  for(v = 0; v < 3; v++)
   printf("\nNumero |0%d|: %d",v+1 , vetor[v]);


}