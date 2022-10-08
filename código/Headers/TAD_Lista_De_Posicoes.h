#include<stdio.h>


typedef struct Posicao { //Célula para guardar as posições 
    
    int posicao;
    struct Posicao* pProx;

}CPosicao;

typedef struct { //Lista de posições 
    
    CPosicao *pPrimeiro;
    CPosicao *pUltimo;
    
}TLista_De_Posicoes;

void FLPosicoes_Vazia(TLista_De_Posicoes* pLista);
void Insere_Posicao(TLista_De_Posicoes* pLista, int posicao);
void Imprimir_Posicao(TLista_De_Posicoes* pLista);
