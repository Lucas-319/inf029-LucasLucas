#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

Pessoa cadastrarCliente(){

  Pessoa cliente;
    
  printf("Informe seu nome: ");
  fgets(cliente.nome, 100, stdin);
    
  printf("Digite |M| ou |F| ou |O| para o sexo: ");
  scanf(" %c", &cliente.sexo);

  fflush(stdin);   
  
  printf("Digite seu CPF: ");
  fgets(cliente.cpf, 25, stdin);

  printf("Informe sua data de nascimento (dd/mm/aaaa): ");
  scanf("%d %d %d", &cliente.datanascimento.dia, &cliente.datanascimento.mes, &cliente.datanascimento.ano);

  return cliente;
}