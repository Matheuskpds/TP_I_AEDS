#include"TAD_Palavra.h"

typedef struct Celula* Apontador;
typedef struct Celula{

//Celula para guardar cara palavra e o endereço da proxima celula

    TPalavra Palavra;
    struct Celula* pProx;

}CPalavra;

typedef struct {

//Lista encadeada das estruturas TPalavra contendo uma cadeia de caracteres e uma lista encadeada de posicoes

    Apontador pPrimeiro_Lista;
    Apontador pUltimo_Lista;

}TLista_De_Palavras;

void Criar_Nova_Lista_De_Palavra(TLista_De_Palavras *pLista);                  //Inicializa a uma lista vazia
void Insere_Nova_Palavra(TLista_De_Palavras *pLista, char *palavra, int linha);//Insere uma nova palavra juntamente com a linha em que ela aparece
void Remove_Palavra(TLista_De_Palavras *pLista, char *palavra);                //Remove uma determinada palavra da lista
void Remove_Palavra_Final(TLista_De_Palavras *pLista);                         //Remove uma palavra do final da lista
Apontador Verifica_Palavra(TLista_De_Palavras* pLista, char *palavra);         //Verifica se uma palavra ja existe na lista e caso exista retorna seu endereço
int Retorna_Numero_De_Palavras(TLista_De_Palavras *pLista);                    //Retorna o numero de TPalavras dentro da lista
void Imprime_Lista_De_Palavras(TLista_De_Palavras *pLista);                    //Imprime a lista com cada palavra e as posições que aparece


