#include "TAD_Posicao.h"


typedef struct{
    char *Palavra;
    TLista_De_Posicoes posicoes;
}TPalavra;

void Cria_Palavra_Vazia(TPalavra* pPalavra, int tamanho);
void Preenche_Cadeia_De_Caracteres(TPalavra* pPalavra, char *ppalavra);
char* Retorna_Cadeia_De_Caracteres(TPalavra* pPalavra);
void Imprime_Cadeia_De_Caracteres(TPalavra* pPalavra);
void Imprime_Palavra(TPalavra* pPalavra);
