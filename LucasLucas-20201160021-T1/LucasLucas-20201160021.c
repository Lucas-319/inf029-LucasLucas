#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LucasLucas-20201160021.h"

//FUNÇÃO RESPONSÁVEL POR QUEBRAR UMA STRING DATA//
Data quebraData(char *data){

  char sDia[3];
	char sMes[3];
	char sAno[5];

  Data aux;  
  aux.valido = 1;
	int i;

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else 
		aux.valido = 0;
	
	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else
		aux.valido = 0;
	
	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
  int k;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else
		aux.valido = 0;
	
  int iDia;
  int iMes;
  int iAno;
  
  //transforma as strings em inteiros//
  iDia = atoi(sDia);
  iMes = atoi(sMes);
  iAno = atoi(sAno);

  aux.sDia = iDia;
  aux.sMes = iMes;
  aux.sAno = iAno;
   
  return aux;
}

//FUNÇÃO QUE VERIFICA SE O ANO É BISSEXTO/
int bissexto(int ano){
  if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
    return 1;
  else 
    return 0;  
}

//FUNÇÃO QUE VALIDA UMA DATA//
int validarData(Data dq){
  
  if(dq.valido == 0){
   return 0;
  }

  //NAO FIZ VALIDAÇÃO DE ANO PQ O ANO PODE TER 2 OU 4 CARACTERES//

   //VALIDA MES//
    if(dq.sMes >= 1 && dq.sMes <= 12){

        //MESES COM 31 DIAS//
        if(dq.sMes == 1 || dq.sMes == 3 || dq.sMes == 5 || dq.sMes == 7 ||
            dq.sMes == 8 || dq.sMes == 10 || dq.sMes == 12){

              //VERIFICA SE O MÊS TEM ATÉ 31 DIAS
              if(dq.sDia > 31)
                return 0;
                
            }

        //MESES COM 30 DIAS//
        if(dq.sMes == 4 || dq.sMes == 6 || dq.sMes == 9 || dq.sMes == 11){
              
              //VERIFICA SE O MÊS TEM ATÉ 30 DIAS
              if(dq.sDia > 30)
                return 0;
              
        }
        //FEVEREIRO//
        if(dq.sMes == 2){

            //VERIFICA SE O ANO É BISSEXTO// 
            if(bissexto(dq.sAno)){
              
              if(dq.sDia > 29)
                return 0;

            }
            else{

              if(dq.sDia > 28)
                return 0;

            } 
        
        }

    }
    else 
      return 0; 

  return 1;
}

//FUNÇÃO QUE VERIFICA SE DATAINICIAL < DATAFINAL//
int ehmaior(int iDia, int iMes, int iAno, int fDia, int fMes, int fAno){

    if (iAno > fAno)
        return 4;
    else if(iAno == fAno){
        if (iMes > fMes)
            return 4;
        else if (iMes == fMes){
            if (iDia > fDia)
                return 4;
        } 
    } 

  //VALOR ALEATÓRIO SÓ PRA TER UM RETORNO FORA DOS IF//  
  return 10;
}

/*COMEÇO DAS QUESTÕES DO TRABALHO 01

*************************************/

//QUESTÃO 1//
int q1(char *data){

   Data retorno;
   int r;

   retorno = quebraData(data); 

  if(retorno.valido == 0)
    return 0;
  

   r = validarData(retorno);

   return r; 
}

//QUESTÃO 2//
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){

  Data inicio;
  Data fim;
  int i, f;
  int maior;

  //QUEBRA A DATA INICIAL E FINAL//
  inicio = quebraData(datainicial);
  fim = quebraData(datafinal);

  //SE NÃO FOI POSSIVEL QUEBRAR A DATA, RETORNA 2//
  if(inicio.valido == 0)  
   return 2;
  //SE NÃO FOI POSSIVEL QUEBRAR A DATA, RETORNA 3//
  if(fim.valido == 0)
   return 3; 

  // 'i' e 'f' recebem se a data é valida ou não//
  i = validarData(inicio);
  f = validarData(fim); 
  
  //SE A DATA FOR INVALIDA, RETORNA 2//
  if(i == 0) 
    return 2;
  //SE A DATA FOR INVALIDA, RETORNA 3//
  if(f == 0)
    return 3;  

  //CRIANDO VARIAVEIS INTEIRAS PARA FACILITAR O ENTENDIMENTO//
  int iDia, iMes, iAno;
  int fDia, fMes, fAno;

  //VARIAVEIS DA DATA INICIAL//
  iDia = inicio.sDia;
  iMes = inicio.sMes;
  iAno = inicio.sAno;

  //VARIVEIS DA DATA FINAL//
  fDia = fim.sDia;
  fMes = fim.sMes;
  fAno = fim.sAno;

  //FUNÇÃO QUE VERIFICA SE A DATA INICIAL É MAIOR QUE A FINAL//
  //ELA RETORNA 4 SE INICIAL > FINAL --- E 10 SE ESTIVER CORRETA//
  maior = ehmaior(iDia, iMes, iAno, fDia, fMes, fAno);
  if(maior == 4)
    return 4;

 
  //VARIAVEIS AUXILIARES//
  int  nDias;
  int  nMeses;
  int  nAnos;

  //CALCULO//
  nDias = fDia - iDia;
  nMeses = fMes - iMes;
  nAnos = fAno - iAno;
    
  /*mantenha o código abaixo, para salvar os dados  
  nos parâmetros da funcao
  */
  *qtdDias = nDias;
  *qtdAnos = nAnos;
  *qtdMeses = nMeses;

   return 1;     
}

//QUESTÃO 3//
int q3(char *texto, char c, int isCaseSensitive){

  int ocorrencias = 0;
   
    for(int i = 0; i < (strlen(texto)); i++){
        if(isCaseSensitive == 1){

            if(c == texto[i])             
             ocorrencias++;
            
        }
        else if(isCaseSensitive == 0){
          int aux = 0;

            //Se o caracter for maiusculo, transforma em minusculo       
            if(c >= 'A' && c <= 'Z')
             c = c + 32; // 32 é a distância entre 'a' e 'A', ou seja, 97 - 65 = 32

            //Se o caracter for maiusculo, transforma em minusculo
            while(texto[aux] != '\0'){
               if(texto[aux]>= 'A' && texto[aux] <= 'Z')
                  texto[aux] = texto[aux] + 32; // 'b' e 'B', ou seja, 98 - 66 = 32
              aux++;
            } 
        
            if(c == texto[i])             
             ocorrencias++;
            
        }

    }

  return ocorrencias;
}

//QUESTÃO 4//
int q4(char *strTexto, char *strBusca, int posicoes[30]){

  int ocorrencias = 0;
  int aux, ok = 0;
  int cont = 0;
  int cont2 = 1;

  //Busca a strBusca DENTRO DE strTexto//
  int vet_aux[strlen(strTexto)];
  for(int i = 0; i <= strlen(strTexto) - strlen(strBusca); i++){

    if(strTexto[i] == strBusca[0]){
      
      for(int k = 0; k < strlen(strBusca); k++)
        vet_aux[k] = 0;

      aux = i;
      for(int j = 0; j < strlen(strBusca); j++){
        if(strBusca[j] == strTexto[aux] ){
          vet_aux[j] = 1;
          aux++;
        }
      }

      ok = 1;
      for(int m = 0; m < strlen(strBusca); m++){
        if(vet_aux[m] == 0)
         ok = -1;
      }

      
      if(ok == 1){
        ocorrencias++;
        posicoes[cont] = i;
        posicoes[cont2]= aux;
        cont = cont + 2;
        cont2 = cont2 + 2;

      }
    
    }
  
  }


  return ocorrencias;
}

//QUESTÃO 5//
int q5(int num){
  
  int inverso = 0, lembrar;
  
  do{
    lembrar = num % 10;
    inverso = inverso * 10 + lembrar;
    num /= 10;
  }while(num > 0);
  
  return inverso;  
}

//QUESTÃO 6//
int q6(int numerobase, int numerobusca){
 
  int ocorrencias = 0;
  int aux, ok = 0;

  int base[20];
  int busca[20];

  int TamBASE = 0; 
  int TamBUSCA = 0;

  /* Transformando em string fica mais fácil
  sprintf(base, "%d", numerobase);
  sprintf(busca, "%d", numerobusca);
  */

  //SEPARA numerobase NO VETOR BASE (ELE FICA INVERTIDO!)//
  do{
    base[TamBASE] = numerobase % 10;
    numerobase /= 10;
    TamBASE++;
  }while(numerobase > 0);

  //SEPARA numerobusca NO VETOR BUSCA (ELE FICA INVERTIDO!)//
  do{
    busca[TamBUSCA] = numerobusca % 10;
    numerobusca /= 10;
    TamBUSCA++;
  }while(numerobusca > 0);
  
  //BUSCA o numerobusca DENTRO DO numerobase//
  int vet_aux[TamBASE];
  for(int i = 0; i <= TamBASE - TamBUSCA; i++){

    if(base[i] == busca[0]){
      
      for(int k = 0; k < TamBUSCA; k++)
        vet_aux[k] = 0;

      aux = i;
      for(int j = 0; j < TamBUSCA; j++){
        if(busca[j] == base[aux] ){
          vet_aux[j] = 1;
          aux++;
        }
      }

      ok = 1;
      for(int m = 0; m < TamBUSCA; m++){
        if(vet_aux[m] == 0)
         ok = -1;
      }

      
      if(ok == 1){
        ocorrencias++;       
      }
    
    }
  
  }
 
  return ocorrencias;
}



