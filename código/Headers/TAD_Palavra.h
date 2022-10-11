#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_ListaDePosicoes.h"


typedef struct{
    char *Palavra;
    TLista_De_Posicoes* posicoes;
}TPalavra;

/*Criação e preenchimento da cadeia de caracteres*/
void Cria_Palavra_Vazia(TPalavra* pPalavra, int tamanho);
void Preenche_Cadeia_De_Caracteres(TPalavra* pPalavra, char *ppalavra); /* SET */

/*.....*/
char* Retorna_Cadeia_De_Caracteres(TPalavra* pPalavra); /* GET */
void Imprime_Cadeia_De_Caracteres(TPalavra* pPalavra);
void Imprime_Palavra(TPalavra* pPalavra);
