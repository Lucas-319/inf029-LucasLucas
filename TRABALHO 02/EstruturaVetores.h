#define TAM 11

enum { TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11, NOVO_TAMANHO_INVALIDO, NUMERO_INEXISTENTE,
       ESTRUTURA_AUXILIAR_VAZIA, TAMANHO_INVALIDO, SEM_ESPACO_DE_MEMORIA, POSICAO_INVALIDA,
       JA_TEM_ESTRUTURA_AUXILIAR, SEM_ESTRUTURA_AUXILIAR, SEM_ESPACO, SUCESSO };
       
typedef struct{
  int qtd;
  int qtdmax;
  int *valor;  
}Num;

Num vetorPrincipal[TAM];  

//Funcões//

//Funcão que inicia a estrutura principal//
void inicializar();
//Função que da um free nos espaço de memória alocados//
void finalizar();
//Funcão que cria as estruturas auxiliares//
int criarEstruturaAuxiliar(int posicao, int tamanho);
//Funcão que altera o tamanho da estrutura auxiliar//
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
//Funcão que insere os valores na estrutura auxiliar//
int inserirNumeroEmEstrutura(int posicao, int valor);
//Funcão que imprime apenas 1 estrutura//
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
//Funcão que ordena os elementos de 1 estrutura//
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
//Funcão que imprime todas as estrututas; 
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
//Funcão que ordena os elementos de todas as estrututas;
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
//Funcão que remove um elemento selecionado da estrutura//
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor);
//Funcão que remove o ultimo elemento de uma estrutura;
int excluirNumeroDoFinaldaEstrutura(int posicao);
//Funcão que pega a qtd de elementos da estrututura; 
int getQuantidadeElementosEstruturaAuxiliar(int posicao);















