#include <stdio.h>

int main()
{
	int opcao;
	

	printf("Ola, por gentileza seleciona uma opção:\n");
	puts("[1] para somar       [2] para subtrair");
	puts("[3] para multiplicar [4] para dividir");
	puts("\n            [0] para sair");
    
    int valor_1, valor_2;
    
    do{
    printf("\nOpcao: ");
	scanf("%d", &opcao);
    
	if(opcao == 1){
     printf("\t==SOMAR=="); 
     puts("\nInforme os valores a serem somados:");
     scanf("%d %d", &valor_1, &valor_2);
     int soma = valor_1 + valor_2;
     printf("Resultado da soma = %d.", soma);
	}
	
	if(opcao == 2){
	 printf("\t==SUBTRAIR==");
	 puts("\nInforme os valores a serem subtraidos:");
     scanf("%d %d", &valor_1, &valor_2);
     int subtracao = valor_1 - valor_2;
     printf("Resultado da subtracao = %d.", subtracao);
	}
			
	if(opcao == 3){
	printf("\t==MULTIPLICAR=="); 
	puts("\nInforme os valores a serem multiplicados:");
	scanf("%d %d", &valor_1, &valor_2);
	int multiplicacao = valor_1 * valor_2;
	printf("Resultado da multiplicacao = %d.", multiplicacao);
	}
	
	if(opcao == 4){
	 printf("\t==DIVIDIR=="); 
	 puts("\nInforme os valores a serem divididos:");
     scanf("%d %d", &valor_1, &valor_2);
     int divisao = valor_1 / valor_2;
     printf("Resultado da divisao = %d.", divisao);
	}
	
    }
	while(opcao != 0);
	
}