#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "01-header.h"

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
