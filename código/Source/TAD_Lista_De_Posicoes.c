#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "TAD_Lista_De_Posicoes.h"

void FLPosicoes_Vazia(TLista_De_Posicoes* pLista){

    pLista->pPrimeiro = (CPosicao*)malloc(sizeof(CPosicao));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;

}

void Insere_Posicao(TLista_De_Posicoes* pLista, int posicao){

    pLista->pUltimo->pProx = (CPosicao*)malloc(sizeof(CPosicao));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->posicao = posicao;
    pLista->pUltimo->pProx = NULL;
    
}

void Imprimir_Posicao(TLista_De_Posicoes* pLista){

	CPosicao* pAux;
    pAux = pLista->pPrimeiro->pProx;
    printf("Linhas: ");
    while(pAux != NULL) {
    
        printf("%d ", pAux->posicao);
        pAux = pAux->pProx;
    
    }

}
