#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_Lista_De_Posicoes.h"

typedef struct{
    char *Palavra;
    TLista_De_Posicoes *posicoes;
}TPalavra;

/*Criação e preenchimento da cadeia de caracteres*/
void FPosicao_Vazia(TPalavra* pPalavra);
void Preenche_Cadeia_De_Caracteres(TPalavra* pPalavra, char *ppalavra, int tamanho); /* SET */

/*.....*/
char* Retorna_Cadeia_De_Caracteres(TPalavra* pPalavra); /* GET */
void Imprime_Cadeia_De_Caracteres(TPalavra* pPalavra);
void Imprime_Palavra(TPalavra* pPalavra, TLista_De_Posicoes *posicoes);