#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

void imprimir(Pessoa p){

  int nome;
  char sexo;
  int cpf;
  int data;
  
  printf("\n");

//VALIDAR NOME
  nome = validarNome(p);
  if(nome != 0)  
    printf("\tNome: %s", p.nome);
  else
    printf("\tNome: invalido!\n");

//VALIDAR SEXO 
  sexo = validarSexo(p);    
  if(sexo != 'n')  
    printf("\tSexo: %c\n", p.sexo);
  else
    printf("\tSexo: invalido!\n");

//VALIDAR CPF
  cpf = validarCPF(p);
  if(cpf != 0)
   printf("\tCPF: %s", p.cpf);
  else 
   printf("\tCPF: invalido!\n"); 

//VALIDAR DATA
  data = validarNascimento(p);
  if(data != 0)
    printf("\tData Nascimento: %d/%d/%d\n", p.datanascimento.dia, p.datanascimento.mes, p.datanascimento.ano);
  else  
    printf("\tData Nascimento: invalida!\n");


  if(nome != 0 && sexo != 'n' && cpf != 0 && data != 0)
    printf("\nCadastro realizado com sucesso!\n");
  else  
    printf("\nNao foi possivel concluir seu cadastro!\n");    
}