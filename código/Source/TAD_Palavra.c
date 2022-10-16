#include"../Headers/TAD_Palavra.h"


void Cria_Palavra_Vazia(TPalavra* pPalavra, int tamanho){
	
	//Aloca espaço para a cadeia de caracteres de acordo com o seu tamanho
	//e inicializa a lista de posicoes

	pPalavra->Palavra = (char*)malloc(sizeof(char) * tamanho);
	FLPosicoes_Vazia(&pPalavra->posicoes);

}

void Preenche_Cadeia_De_Caracteres(TPalavra* pPalavra, char *ppalavra){

	//Preenche o campo Palavra da estrutura TPalavra com o conteudo da string

	strcpy(pPalavra->Palavra, ppalavra);

}

char* Retorna_Cadeia_De_Caracteres(TPalavra* pPalavra){
	
	//Retorna o conteúdo do campo Palavra

	return pPalavra->Palavra;
	
}

void Imprime_Cadeia_De_Caracteres(TPalavra* pPalavra){

	printf("---------------------\n");
	//Entra na estrutura e imprime o conteudo do campo Palavra
    printf("Palavra: %s\n", pPalavra->Palavra);

}

void Imprime_Palavra(TPalavra* pPalavra){

	//Imprime a estrutura TPalavra chamando os subprogramas para imprimir cada campo

	Imprime_Cadeia_De_Caracteres(pPalavra);
	Imprimir_Posicao(&pPalavra->posicoes);

}
