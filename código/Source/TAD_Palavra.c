#include"TAD_Palavra.h"
#include "TAD_Lista_De_Posicoes.h"


/*Cria uma posicao vazia para a linha*/
void FPosicao_Vazia(TPalavra* pPalavra){
	FLPosicoes_Vazia(pPalavra->posicoes);
	pPalavra->Palavra = NULL;	
}

/*Recebe a palavra e armazena na cadeia de caracteres*/
void Preenche_Cadeia_De_Caracteres(TPalavra* pPalavra, char *ppalavra, int tamanho){

	pPalavra->Palavra =  (char*)malloc(sizeof(char)*tamanho);
	strcpy(pPalavra->Palavra, ppalavra);

}

char* Retorna_Cadeia_De_Caracteres(TPalavra* pPalavra){
	
	return pPalavra->Palavra;
	
}

void Imprime_Cadeia_De_Caracteres(TPalavra* pPalavra){
	printf("%s\n", pPalavra->Palavra);
}

void Imprime_Palavra(TPalavra* pPalavra, TLista_De_Posicoes *posicoes){
	printf("Palavra: %s", pPalavra->Palavra);
	Imprimir_Posicao(posicoes);
}