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
  int j = 0;
  int i;
  int suporte = 0;

  
    while(teste.nome[j] != '\0'){
          if((teste.nome[j] >= 'a' && teste.nome[j] <= 'z') ||
             (teste.nome[j] >= 'A' && teste.nome[j] <= 'Z') ||
             (teste.nome[j] == ' ') || (teste.nome[j] == '\n'))
          {                          
              suporte = 1; 
                                         
          }
          else{
            
            suporte = 0;
            break;         
          }    
      j++;
    }

    if(suporte == 1){
      
      i = 0;  
        while(teste.nome[i] != '\0')         
          i++;      
    }
    else
     return 0;   

    if(i > 21){
     
     return 0; 
    }
      
    else{
      
      return 1;        
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

int validarCPF(Pessoa teste03){
   
  int aux;
  int i = 0;

  
  while(teste03.cpf[i] != '\0'){
    if(!(teste03.cpf[i] >= '0' && teste03.cpf[i] <= '9')) {
        break;
    }
    i++;
  }  
   
  if(i != 11){
    aux = 0;
  }else{
    aux = 1;
    }
  return aux;
}


int validarNascimento(Pessoa teste04){
  
  int aux;

  //VALIDA O ANO
  if(teste04.datanascimento.ano >= 1900 && teste04.datanascimento.ano <= 2100)
  {
        //VALIDA O MES
        if(teste04.datanascimento.mes >= 1 && teste04.datanascimento.mes <= 12)
        {
            //MESES COM 31 DIAS
            if(teste04.datanascimento.mes == 1 || teste04.datanascimento.mes == 3 || teste04.datanascimento.mes == 5 || teste04.datanascimento.mes == 7 || teste04.datanascimento.mes == 8 || teste04.datanascimento.mes == 10 ||   teste04.datanascimento.mes == 12)
            {
                 
                  if(teste04.datanascimento.dia <= 31)
                    aux = 1;
                  else 
                    aux = 0;

            
            }//MESES COM 30 DIAS
            else if(teste04.datanascimento.mes == 4 || teste04.datanascimento.mes == 6 || teste04.datanascimento.mes == 9 || teste04.datanascimento.mes == 11)                     
            {
                                   
                  if(teste04.datanascimento.dia <= 30)
                    aux = 1;
                  else 
                    aux = 0; 

            
            }//MES DE FEVEREIRO
            else if(teste04.datanascimento.mes == 2)
            {      
                  if((teste04.datanascimento.ano % 4 == 0 && teste04.datanascimento.ano % 100 != 0) ||  teste04.datanascimento.ano % 400 == 0)                                                        
                  {
                    if(teste04.datanascimento.dia <= 29)
                      aux = 1;
                    else 
                      aux = 0;

                  }
                  else
                  {
                    
                    if(teste04.datanascimento.dia <= 28)
                      aux = 1;
                    else 
                      aux = 0;

                  }         

            }
                  
        }
        else
          aux = 0;
      
  }
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

//CONFERE SE O CADASTRO FUI CONCLUIDO COM SUCESSO
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