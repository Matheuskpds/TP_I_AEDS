#include"../Headers/TAD_ListaDePalavras.h"

void Criar_Nova_Lista_De_Palavra(TLista_De_Palavras *pLista){
	
    pLista->pPrimeiro_Lista = (Apontador)malloc(sizeof(CPalavra));
    pLista->pUltimo_Lista = pLista->pPrimeiro_Lista;
    pLista->pPrimeiro_Lista->pProx = NULL;

}

Apontador Verifica_Palavra(TLista_De_Palavras* pLista, char *palavra){
	
	Apontador pAux;
	pAux = pLista->pPrimeiro_Lista->pProx;
	while(pAux != NULL){
		
		if (strcmp(palavra, pAux->Palavra.Palavra) == 0){
			
			return pAux;
			
		}
		
		pAux = pAux->pProx;
		
	}

	return 0;
	
}

void Insere_Nova_Palavra(TLista_De_Palavras *pLista, char *palavra, int linha){

	CPalavra* PExiste;
	PExiste = Verifica_Palavra(pLista, palavra);
	
	if (PExiste != 0){
		if(Verifica_Posicao(&pLista->pUltimo_Lista->Palavra.posicoes, linha) == 0)
			Insere_Posicao(&PExiste->Palavra.posicoes, linha);
		return;
		
	}
	else{
		
		int tamanho;
		TPalavra Palavra;
		tamanho = strlen(palavra);
		pLista->pUltimo_Lista->pProx = (Apontador) malloc(sizeof(CPalavra));
		pLista->pUltimo_Lista = pLista->pUltimo_Lista->pProx;
		pLista->pUltimo_Lista->pProx = NULL;
		Cria_Palavra_Vazia(&Palavra, tamanho);
		Insere_Posicao(&Palavra.posicoes, linha);
		Preenche_Cadeia_De_Caracteres(&Palavra, palavra);
		pLista->pUltimo_Lista->Palavra = Palavra;

		
	}

}

void Remove_Palavra_Final(TLista_De_Palavras *pLista){
	
	CPalavra* pNovo_Ultimo;
	pNovo_Ultimo = pLista->pPrimeiro_Lista->pProx;
	
	while(pNovo_Ultimo->pProx->pProx != NULL){
		pNovo_Ultimo = pNovo_Ultimo->pProx;
	}
	
	free(pNovo_Ultimo->pProx);
	pNovo_Ultimo->pProx = NULL;
	pLista->pUltimo_Lista = pNovo_Ultimo;

}

void Remove_Palavra(TLista_De_Palavras *pLista, char *palavra){
	
	Apontador pRemovedor;
	Apontador pAux;
	pAux = pLista->pPrimeiro_Lista;
	
	while((strcmp(palavra, pAux->pProx->Palavra.Palavra) != 0) && pAux != NULL){
		
		pAux = pAux->pProx;
		
	}
	
	if(strcmp(palavra, pAux->pProx->Palavra.Palavra) == 0){
		
		pRemovedor = pAux->pProx;
		pAux->pProx = pAux->pProx->pProx;
		free(pRemovedor);
		
	}
	
}

int Retorna_Numero_De_Palavras(TLista_De_Palavras *pLista){
	
	if (pLista->pPrimeiro_Lista->pProx == NULL){
		
		return 0;
		
	}
	
	int contador;
	contador = 1;
	CPalavra *pAux;
	pAux = pLista->pPrimeiro_Lista->pProx;
	
	while(pAux != NULL){
		
		contador++;
		pAux = pAux->pProx;
		
	}
	
	return contador;
	
}

void Imprime_Lista_De_Palavras(TLista_De_Palavras *pLista){
	
	Apontador pAux;
	pAux = pLista->pPrimeiro_Lista->pProx;
	
	while(pAux != NULL){
		
		Imprime_Palavra(&pAux->Palavra);
		pAux = pAux->pProx;

	}
	
}
