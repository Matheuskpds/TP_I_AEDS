#include"TAD_Palavra.h"


void FPalavra_Vazia(TPalavra* pPalavra){
	
	pPalavra->posicoes = (TLista_De_Posicoes*)malloc(sizeof(TLista_De_Posicoes));
	FLPosicoes_Vazia(pPalavra->posicoes);
	pPalavra->palavra = NULL;
	
}

void Preenche_Cadeia_De_Caracteres(TPalavra* pPalavra, char *ppalavra, int tamanho){

	pPalavra->palavra =  (char*)malloc(sizeof(char)*tamanho);
	strcpy(pPalavra->palavra, ppalavra);

}

char* Retorna_Cadeia_De_Caracteres(TPalavra* pPalavra){
	
	return pPalavra->palavra;
	
}
