#include"../Headers/TAD_Palavra.h"


void Cria_Palavra_Vazia(TPalavra* pPalavra, int tamanho){
	
	pPalavra->Palavra = (char*)malloc(sizeof(char) * tamanho);
	FLPosicoes_Vazia(&pPalavra->posicoes);

}

void Preenche_Cadeia_De_Caracteres(TPalavra* pPalavra, char *ppalavra){

	strcpy(pPalavra->Palavra, ppalavra);

}

char* Retorna_Cadeia_De_Caracteres(TPalavra* pPalavra){
	
	return pPalavra->Palavra;
	
}

void Imprime_Cadeia_De_Caracteres(TPalavra* pPalavra){
	printf("---------------------\n");
    printf("Palavra: %s\n", pPalavra->Palavra);
}

void Imprime_Palavra(TPalavra* pPalavra){
	Imprime_Cadeia_De_Caracteres(pPalavra);
	Imprimir_Posicao(&pPalavra->posicoes);

}
