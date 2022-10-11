#include"TAD_Palavra.h"

/*Recebe a palavra e armazena na cadeia de caracteres*/
void Cria_Palavra_Vazia(TPalavra* pPalavra, int tamanho){
	pPalavra->Palavra = (char*)malloc(sizeof(char)*tamanho);
	pPalavra->posicoes = (TLista_De_Posicoes*)malloc(sizeof(TLista_De_Posicoes));
	FLPosicoes_Vazia(pPalavra->posicoes);
}

void Preenche_Cadeia_De_Caracteres(TPalavra* pPalavra, char *ppalavra){

	strcpy(pPalavra->Palavra, ppalavra);

}

char* Retorna_Cadeia_De_Caracteres(TPalavra* pPalavra){
	
	return pPalavra->Palavra;
	
}

void Imprime_Cadeia_De_Caracteres(TPalavra* pPalavra){
	printf("%s\n", pPalavra->Palavra);
}

void Imprime_Palavra(TPalavra* pPalavra){
	printf("Palavra: %s", Retorna_Cadeia_De_Caracteres(pPalavra));
	Imprimir_Posicao(pPalavra->posicoes);
}
