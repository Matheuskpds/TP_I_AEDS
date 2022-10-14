#include "TAD_ListaDePalavras.h"


//ponteiro para celulaDicionario
typedef struct CelulaDicionario* ApontadorDicionario;
//celula da lista
typedef struct CelulaDicionario{
    TLista_De_Palavras listaDePalavras;
    struct CelulaDicionario* pProx;
}TCelulaDicionario;
//lista de listas - dicionario
typedef struct{
    ApontadorDicionario pPrimeiro;
    ApontadorDicionario pUltimo;
}TDicionario;


//operacoes do dicionario
void Inicializa_Dicionario(TDicionario* pDicionario);
void Constroi_Dicionario(TDicionario* pDicionario);

