#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
  scanf(" %c", &cliente.sexo);

  fflush(stdin);   
  
  printf("Digite seu CPF: ");
  fgets( cliente.cpf, 25, stdin);

  printf("Informe sua data de nascimento (dd/mm/aaaa): ");
  scanf("%d %d %d", &cliente.datanascimento.dia, &cliente.datanascimento.mes, &cliente.datanascimento.ano);

  return cliente;
}

int validarNome(Pessoa teste){
    
  int aux;
  int i = 0;

   while(teste.nome[i] != '\0'){
      if(teste.nome[i] == '\n')
         teste.nome[i] = '\0';
    i++;
  }
  
  if(i > 21){
    aux = 0;
    return aux;
  }else{
    aux = 1;
    return aux;
  }    
}

char validarSexo(Pessoa teste02){    
  
  char aux = 'n';
      
  if(teste02.sexo == 'M' || teste02.sexo == 'F' || teste02.sexo == 'O' ||
     teste02.sexo == 'm' || teste02.sexo == 'f' || teste02.sexo == 'o'){
    aux = 's';
    return aux;
  }  
  
  return aux;        
}

char validarCPF(Pessoa teste03){

  int size;  
  int aux;
  int i = 0;

   while(teste03.cpf[i] != '\0'){
      if(teste03.cpf[i] == '\n')
         teste03.cpf[i] = '\0';
    i++;
  }
   
  if(i != 12){
    aux = 0;
    return aux;
  }else{
    aux = 1;
    return aux;
    } 
}

int validarNascimento(Pessoa teste04){
  
  int aux;

  if((teste04.datanascimento.ano >= 1900 && teste04.datanascimento.ano <= 2100) &&
      (teste04.datanascimento.mes >= 1 && teste04.datanascimento.mes <= 12) &&
        (teste04.datanascimento.dia >= 1 && teste04.datanascimento.dia <= 31))
          aux = 1;           
  else 
    aux = 0;

  return aux;
}



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
    printf("\tNome: Nome inserido ultrapassa o limite de caracteres!\n");

//VALIDAR SEXO 
  sexo = validarSexo(p);    
  if(sexo != 'n')  
    printf("\tSexo: %c\n", p.sexo);
  else
    printf("\tSexo: Sexo digitado eh invalido!\n");

//VALIDAR CPF
  cpf = validarCPF(p);
  if(cpf != 0)
   printf("\tCPF: %s", p.cpf);
  else 
   printf("\tCPF: CPF digitado eh invalido!\n"); 

//VALIDAR DATA
  data = validarNascimento(p);
  if(data != 0)
    printf("\tData Nascimento: %d/%d/%d\n", p.datanascimento.dia, p.datanascimento.mes, p.datanascimento.ano);
  else  
    printf("\tData Nascimento: Data de nascimento invalida!\n");


  if(nome != 0 && sexo != 'n' && cpf != 0 && data != 0)
    printf("\nCadastro realizado com sucesso!\n");
  else  
    printf("\nNao foi possivel concluir seu cadastro!\n");    
}

int main() {

  Pessoa cadastro1;
  
  cadastro1 = cadastrarCliente();
  imprimir(cadastro1);
 
  return 0;                      
}