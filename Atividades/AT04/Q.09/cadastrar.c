#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

Pessoa cadastrarCliente(){

//PEGA AS INFORMAÇÕES DO CLIENTE
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


//VALIDA OS DADOS DO CLIENTE
  int nome; 
  char sexo;
  int cpf;
  int data;
  
  printf("\n");

  //VALIDAR NOME
  nome = validarNome(cliente);
  if(nome != 0)  
    printf("\tNome: %s", cliente.nome);
  else
    printf("\tNome: invalido!\n");

//VALIDAR SEXO 
  sexo = validarSexo(cliente);    
  if(sexo != 'n')  
    printf("\tSexo: %c\n", cliente.sexo);
  else
    printf("\tSexo: invalido!\n");

//VALIDAR CPF
  cpf = validarCPF(cliente);
  if(cpf != 0)
   printf("\tCPF: %s", cliente.cpf);
  else 
   printf("\tCPF: invalido!\n"); 

//VALIDAR DATA
  data = validarNascimento(cliente);
  if(data != 0)
    printf("\tData Nascimento: %d/%d/%d\n", cliente.datanascimento.dia, cliente.datanascimento.mes,                                                                                        cliente.datanascimento.ano);      
  else  
    printf("\tData Nascimento: invalida!\n");


  if(nome != 0 && sexo != 'n' && cpf != 0 && data != 0)
    printf("\nCadastro realizado com sucesso!\n");
  else  
    printf("\nNao foi possivel concluir seu cadastro!\n"); 

  return cliente;
}