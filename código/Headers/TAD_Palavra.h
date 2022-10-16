#include "TAD_Lista_De_Posicoes.h"


typedef struct{ 

/*Estrutura que guarda uma palavra e uma lista encadeada
com todas as posições em que ela aparece*/

    char *Palavra;
    TLista_De_Posicoes posicoes;

}TPalavra;

void Cria_Palavra_Vazia(TPalavra* pPalavra, int tamanho);               //Inicializa a lista de posicões e aloca espaço para a palavra
void Preenche_Cadeia_De_Caracteres(TPalavra* pPalavra, char *ppalavra); //Preenche a palavra dentro da estrutura TPalavra
char* Retorna_Cadeia_De_Caracteres(TPalavra* pPalavra);                 //Retorna a palavra que está dentro da estrutura TPalavra
void Imprime_Cadeia_De_Caracteres(TPalavra* pPalavra);                  //Imprime a palavra presente na estrutura
void Imprime_Palavra(TPalavra* pPalavra);                               //Imprime a estrutura TPalavra ou seja imprime uma palavra e a lista de posicoes

