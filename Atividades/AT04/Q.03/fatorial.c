#include <stdio.h>
#include <stdlib.h>

int fatorial(int x){
  
  int fat; 

  fat = 1;

   if(x < 13){
      for(int i=x; i>1; i--)
        fat = fat*i;
        return fat;        
   }else
     return 0;
}
int main(){
    int n, fat;
    
    printf("Por gentileza, informe o valor de n: ");
    scanf("%d", &n);

    fat = fatorial(n);

  if(fat != 0)
    printf("O fatorial de %d eh: %d.", n, fat);
  else
    printf("Nao eh possivel calcular o fatorial de %d!", n);      
}