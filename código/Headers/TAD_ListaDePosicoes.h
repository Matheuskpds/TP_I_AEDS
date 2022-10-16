#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Posicao* Apontador_posicao;

/*Estrutura que armazena as posições que a palavra aparece no texto além de um esdereço
para uma estrutura do mesmo tipo para implementação de uma lista encadeada */

typedef struct Posicao { 
    
    int posicao;             //Posicoes são as linhas em que as palavras aparecem
    struct Posicao* pProx;

}CPosicao;

typedef struct { //Lista encadeada das posições que as palavras aparecem no texto
    
    Apontador_posicao pPrimeiro;
    Apontador_posicao pUltimo;
    
}TLista_De_Posicoes;

void FLPosicoes_Vazia(TLista_De_Posicoes* pLista);              //Inicializa a Lista de posições sem nenhum conteúdo
void Insere_Posicao(TLista_De_Posicoes* pLista, int posicao);   //Insere uma nova posição em uma lista ja inicializada
void Imprimir_Posicao(TLista_De_Posicoes* pLista);              //Imprime a lista de posições
int Verifica_Posicao(TLista_De_Posicoes* pLista, int posicao);  /*Percorre a lista para verificar se ja existe uma determinada posição antes
                                                                de inserir para os casos em que a palavra aparece duas vezes na mesma linha*/

              
