#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

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
