#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *Palavra;
}TPalavra;

/*Criação e preenchimento da cadeia de caracteres*/
void Criar_Palavra_Vazia(TPalavra* pPalavra, int n);
void Preenche_Cadeia_De_Caracteres(TPalavra* pPalavra, FILE *file); /* SET */

/*....*/
void Retorna_Cadeia_De_Caracteres(TPalavra* pPalavra, FILE *file, char *palavra); /* GET */
void Imprime_Cadeia_De_Caracteres(TPalavra* pPalavra);
void Imprime_Palavra(TPalavra* pPalavra);