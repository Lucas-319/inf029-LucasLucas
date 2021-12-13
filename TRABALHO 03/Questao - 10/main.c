#include <stdio.h>

int buscar(int N, int K);
int qtd = 0; //Tive que colocar como global, pq dentro da função tava dando erro//

int main(void) {
  int K, N;
  int retorno;
  
  printf("Informe o valor K: ");
  scanf("%d", &K);

  printf("Informe o valor N: ");
  scanf("%d", &N);

  printf("\n"); 

  retorno = buscar(N, K); 
  printf("Quantidade: %d", retorno);         
}

int buscar(int N, int K){

  int lembrar;  
        
  if(N > 0){         
    lembrar = N % 10;

    if(lembrar == K)      
      qtd++; 

    buscar((N / 10), K);                      
  }

  return qtd;                 
}