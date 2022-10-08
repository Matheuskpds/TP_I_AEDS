#include"TAD_Posicao.h"

typedef struct {

	char *palavra;
	TLista_De_Posicoes* posicoes;
	
}TPalavra;

void FPalavra_Vazia(TPalavra* pPalavra);
void Preenche_Cadeia_De_Caracteres(TPalavra* pPalavra, char *ppalavra, int tamanho);
char* Retorna_Cadeia_De_Caracteres(TPalavra* pPalavra);
void Imprime_Cadeia_De_Caracteres(TPalavra* pPalavra);
void Imprime_Palavra(TPalavra* pPalavra);
