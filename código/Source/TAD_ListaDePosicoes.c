#include"../Headers/TAD_Lista_De_Posicoes.h"

void FLPosicoes_Vazia(TLista_De_Posicoes* pLista){

	//Aloca espaço para a primeira celula da lista(celula cabeça) e define os Apontadores primeiro e ultimo

	pLista->pPrimeiro = (Apontador_posicao) malloc(sizeof(CPosicao));  
	pLista->pUltimo = pLista->pPrimeiro;
	pLista->pPrimeiro->pProx = NULL;

}

void Insere_Posicao(TLista_De_Posicoes* pLista, int posicao){

	//Aloca espaço para para uma nova celula e preenche o campo posição com o valor recebido como paramatro

    pLista->pUltimo->pProx = (Apontador_posicao)malloc(sizeof(CPosicao));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->posicao = posicao;
    pLista->pUltimo->pProx = NULL;
    
}

void Imprimir_Posicao(TLista_De_Posicoes* pLista){

	//Apontador para celula utilizado para percorrer a lista de posições
	Apontador_posicao pAux;
	//Começa apontando para a primeira celula após a celula cabeça
    pAux = pLista->pPrimeiro->pProx;
    printf("Linhas: ");
	
    while(pAux != NULL) {
		
		//Imprime cada posição e avança para a proxima celula até chegar ao final da lista
        printf("[%d] ", pAux->posicao);
        pAux = pAux->pProx;

    }
    printf("\n--------------------\n");
    printf("\n");

}

int Verifica_Posicao(TLista_De_Posicoes* pLista, int posicao){
	
	//Apontador para celula para percorrer a lista
	Apontador_posicao pAux;
	//Começa apontando para a primeira celula após a celula cabeça
	pAux = pLista->pPrimeiro->pProx;
	while(pAux != NULL){
		
		//Percorre toda a lista comparando os valores 

		if (pAux->posicao == posicao){
			
			//retorna 1 caso a posição exista dentro da lista
			return 1;
			
		}
		
		pAux = pAux->pProx;
		
	}
	
	return 0;
	
}

