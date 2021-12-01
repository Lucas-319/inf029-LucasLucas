#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

int criarEstruturaAuxiliar(int posicao, int tamanho){
        
  if(posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;

  if(vetorPrincipal[posicao].qtdmax != 0)
   return JA_TEM_ESTRUTURA_AUXILIAR;   
          
  if(tamanho < 1)
    return TAMANHO_INVALIDO;

  vetorPrincipal[posicao].qtdmax = tamanho;  
  vetorPrincipal[posicao].valor= malloc(tamanho*sizeof(int));
  
  return SUCESSO;           
}

int inserirNumeroEmEstrutura(int posicao, int valor){
        
  if(posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;

  if(vetorPrincipal[posicao].qtdmax == 0)
    return SEM_ESTRUTURA_AUXILIAR;    
  
  if(vetorPrincipal[posicao].qtd == vetorPrincipal[posicao].qtdmax)
    return SEM_ESPACO;   
    
  vetorPrincipal[posicao].valor[vetorPrincipal[posicao].qtd]= valor;   
  vetorPrincipal[posicao].qtd = vetorPrincipal[posicao].qtd + 1;
  
  return SUCESSO;
}

int excluirNumeroDoFinaldaEstrutura(int posicao){

  if(posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;

  if(vetorPrincipal[posicao].qtdmax == 0)
    return SEM_ESTRUTURA_AUXILIAR;

  if(vetorPrincipal[posicao].qtd == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;
        
  vetorPrincipal[posicao].qtd--;

  return SUCESSO;
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){ 
 
  int num_aux = -1;
  
  if(posicao < 1 || posicao > 10)
     return POSICAO_INVALIDA;

  if(vetorPrincipal[posicao].qtdmax == 0)
    return SEM_ESTRUTURA_AUXILIAR;

  if(vetorPrincipal[posicao].qtd == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;  

  
  for(int i = 0; i < vetorPrincipal[posicao].qtd; i++){
      if(vetorPrincipal[posicao].valor[i] == valor){
        num_aux = i;
        for(int j = num_aux; j < vetorPrincipal[posicao].qtd - 1; j++){
            vetorPrincipal[posicao].valor[j] = vetorPrincipal[posicao].valor[j + 1];
        }
      vetorPrincipal[posicao].qtd = vetorPrincipal[posicao].qtd - 1;
      break;
      }   
  }

  if(num_aux == -1)
    return NUMERO_INEXISTENTE;
  else 
    return SUCESSO; 
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
     
  if(posicao < 1 || posicao > 10)
     return POSICAO_INVALIDA;

  if(vetorPrincipal[posicao].qtdmax == 0)
     return SEM_ESTRUTURA_AUXILIAR;   
     
  for(int i = 0; i< vetorPrincipal[posicao].qtd; i++){
    vetorAux[i] = vetorPrincipal[posicao].valor[i];
  }
  
  return SUCESSO;
}


int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
     
  //Criando vetor auxiliar;
  int vetor[vetorPrincipal[posicao].qtd];

  int i, j, k;
  
  if(posicao < 1 || posicao > 10)
     return POSICAO_INVALIDA;  

  if(vetorPrincipal[posicao].qtdmax == 0)
     return SEM_ESTRUTURA_AUXILIAR;

  
  for(int l = 0; l< vetorPrincipal[posicao].qtd; l++){
    vetor[l] = vetorPrincipal[posicao].valor[l];
  }

    int guardar;

    for(i = 0; i < vetorPrincipal[posicao].qtd; i++){
      for(j = i+1; j < vetorPrincipal[posicao].qtd; j++){
          if(vetor[i] > vetor[j]){
            guardar = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = guardar;
          }
      }    
    }          
      for(k = 0; k < vetorPrincipal[posicao].qtd; k++){
        vetorAux[k] = vetor[k];
      } 

  return SUCESSO;         
}  

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){

  int aux  = 0;
  int indice = 0;
  int i, j, cont;

  for(i = 1; i < TAM; i++){
    if(vetorPrincipal[i].valor == NULL || vetorPrincipal[i].qtd == 0)
       aux++;
  }     
     
  if(aux == 10)
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
   
  for(cont = 1; cont < TAM; cont++){    
      for(j = 0; j < vetorPrincipal[cont].qtd; j++){       
        vetorAux[indice] = vetorPrincipal[cont].valor[j];        
        indice++;            
      }      
  }    
       
  return SUCESSO;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
 
   //Criando vetor auxiliar;
  int vetor_2[50];

  int i, j, k, o;
  int p, l;
  int cont;
  int guardar;  
  int aux = 0;
  int indice = 0;
  
  for(o = 1; o < TAM; o++){
    if(vetorPrincipal[o].valor == NULL || vetorPrincipal[o].qtd == 0)
       aux++;
  }     
     
  if(aux == 10)
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;


  for(cont = 1; cont < TAM; cont++){    
      for(j = 0; j < vetorPrincipal[cont].qtd; j++){       
        vetor_2[indice] = vetorPrincipal[cont].valor[j];        
        indice++;            
      }      
  }     
  
  for(i = 0; i < indice; i++){
      for(j = i + 1;j < indice; j++){ 
          if(vetor_2[i] > vetor_2[j]){  
            guardar = vetor_2[i];
            vetor_2[i] = vetor_2[j];
            vetor_2[j] = guardar;
          }  
      }
  }      
     
  for(k = 0; k < indice; k++){
    vetorAux[k] = vetor_2[k];
  }
    
  return SUCESSO;
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
    
  int removidos = 0;
    
  if(novoTamanho < 0)
   removidos = novoTamanho; 

  novoTamanho = vetorPrincipal[posicao].qtdmax + novoTamanho;  

  if(posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;
    
  if(vetorPrincipal[posicao].valor == NULL)
    return SEM_ESTRUTURA_AUXILIAR;
                                                                  
  if(novoTamanho < 1)
    return NOVO_TAMANHO_INVALIDO;   

  vetorPrincipal[posicao].valor = realloc(vetorPrincipal[posicao].valor, novoTamanho);       
  vetorPrincipal[posicao].qtdmax = novoTamanho;
  vetorPrincipal[posicao].qtd += removidos; 
               
  return SUCESSO; 
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao){
   
  int retorno; 

  if(posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;

  if(vetorPrincipal[posicao].valor == NULL)
    return SEM_ESTRUTURA_AUXILIAR;    
    
  if(vetorPrincipal[posicao].qtd == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;

  retorno = vetorPrincipal[posicao].qtd;
  return retorno; 
}

void inicializar(){
  for(int i = 1; i < TAM; i++){
    vetorPrincipal[i].valor = NULL;
    vetorPrincipal[i].qtd = 0;
    vetorPrincipal[i].qtdmax = 0;
  }
}

void finalizar(){
  for(int i = 1; i < TAM; i++){    
    free(vetorPrincipal[i].valor);
  }
}





 