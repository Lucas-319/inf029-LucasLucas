typedef struct{

   int dia, mes, ano; 

}DataNas;

typedef struct{

 char nome[100];
 char sexo;
 char cpf[25];
 DataNas datanascimento;

}Pessoa;

Pessoa cadastrarCliente();

int validarNome(Pessoa teste);

char validarSexo(Pessoa teste02);

char validarCPF(Pessoa teste03);

int validarNascimento(Pessoa teste04);

void imprimir(Pessoa p);
