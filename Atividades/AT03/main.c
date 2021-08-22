#include <stdio.h>
#include "area.h"

int main(){
	
	int base, altura;
	int area;

	printf("Por gentileza, informe a base do retangulo: ");
	 scanf("%d", &base);

	printf("Agora informe a altura do retangulo: ");
	 scanf("%d", &altura);  
	
	area = area_retangulo(base, altura);
	 
	printf("A area do retangulo eh: %d metros quadrados.", area); 
}