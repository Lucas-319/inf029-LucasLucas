#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

   int dia, mes, ano; 

}DataNas;


typedef struct{

 char nome[100];
 char sexo;
 char cpf[25];
 DataNas datanascimento;

}Pessoa; 

Pessoa cadastrarCliente(){

  Pessoa cliente;

  printf("Informe seu nome: ");
  fgets(cliente.nome, 100, stdin);
  
  printf("Digite |M| ou |F| ou |O| para o sexo: ");
  scanf("%c", &cliente.sexo);

    fflush(stdin);
    //getchar();
    
  printf("Digite seu CPF: ");
  fgets(cliente.cpf, 12, stdin);

  printf("Informe sua data de nascimento (dd/mm/aaaa): ");
  scanf("%d %d %d", &cliente.datanascimento.dia, &cliente.datanascimento.mes, &cliente.datanascimento.ano);

  return cliente;
}

void imprimir(Pessoa p){
  
  printf("\tNome: %s", p.nome);
  printf("\tSexo: %c\n", p.sexo);
  printf("\tCPF: %s\n", p.cpf);
  printf("\tData Nascimento: %d/%d/%d", p.datanascimento.dia, p.datanascimento.mes, p.datanascimento.ano);

}

int main() {

  Pessoa cadastro1;
  
  cadastro1 = cadastrarCliente();
  imprimir(cadastro1);
 
  return 0;                      
}