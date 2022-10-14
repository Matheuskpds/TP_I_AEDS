#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Posicao* Apontador_posicao;
typedef struct Posicao { //Célula para guardar as posições 
    
    int posicao;
    struct Posicao* pProx;

}CPosicao;

typedef struct { //Lista de posições 
    
    Apontador_posicao pPrimeiro;
    Apontador_posicao pUltimo;
    
}TLista_De_Posicoes;

void FLPosicoes_Vazia(TLista_De_Posicoes* pLista);
void Insere_Posicao(TLista_De_Posicoes* pLista, int posicao);
void Imprimir_Posicao(TLista_De_Posicoes* pLista);
int Verifica_Posicao(TLista_De_Posicoes* pLista, int posicao);
