#include <stdio.h>

void inverter(int num);

int main(void) {
  int num;
  int retorno;

  printf("Informe um numero: ");
  scanf("%d", &num);

  printf("\n");
  printf("Numero invertido: ");
  inverter(num);      
}

void inverter(int num){

  int lembrar, inverso = 0, retorno;
  int aux;

  if(num < 0){
    num = num * (-1);
    if(num > 0){         
        lembrar = num % 10;
        inverso = inverso * 10 + lembrar;
        inverso = inverso * (-1);
        printf("%d", inverso);
        inverter(num / 10);     
    }
  }  
  else if(num > 0){         
    lembrar = num % 10;
    inverso = inverso * 10 + lembrar;
    printf("%d", inverso);
    inverter(num / 10);     
  }
                  
}