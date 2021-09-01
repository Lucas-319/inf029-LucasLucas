#include <stdio.h>

int funcao_soma(int num1, int num2){
  
  int soma;

  soma = num1 + num2;

  return soma;
}

int main(){

  int valor1, valor2;
  int soma;

  puts("Por gentileza, informe |2| valores:");
  scanf("%d %d", &valor1, &valor2);

  soma = funcao_soma(valor1, valor2);

  printf("O resultado da soma eh: %d.", soma); 
}