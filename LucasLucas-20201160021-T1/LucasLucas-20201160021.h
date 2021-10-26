typedef struct{
  int sDia;
	int sMes;
	int sAno;
  int valido;
}Data;

//FUNÇÕES PARA 1ª E 2ª QUESTÃO//
int bissexto(int ano);
int validarData(Data dq);
Data quebraData(char *data);

//1ª QUESTÃO//
int q1(char *data);
void teste_q1();

//2ª QUESTÃO//
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos);
void testQ2();
int ehmaior(int iDia, int iMes, int iAno, int fDia, int fMes, int fAno);

//3ª QUESTÃO//
int q3(char *texto, char c, int isCaseSensitive);
void testQ3();

//4ª QUESTÃO//
int q4(char *strTexto, char *strBusca, int posicoes[30]);
void testQ4();

//5ª QUESTÃO//
int q5(int num);
void testQ5();

//6ª QUESTÃO//
int q6(int numerobase, int numerobusca);
void testQ6();

