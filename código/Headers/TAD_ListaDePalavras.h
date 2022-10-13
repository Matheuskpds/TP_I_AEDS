#include"TAD_Palavra.h"

typedef struct Celula* Apontador;
typedef struct Celula{

    TPalavra Palavra;
    struct Celula* pProx;

}CPalavra;

typedef struct {

    Apontador pPrimeiro_Lista;
    Apontador pUltimo_Lista;

}TLista_De_Palavras;

void Criar_Nova_Lista_De_Palavra(TLista_De_Palavras *pLista);
void Insere_Nova_Palavra(TLista_De_Palavras *pLista, char *palavra, int linha);
void Remove_Palavra(TLista_De_Palavras *pLista, char *palavra);
void Remove_Palavra_Final(TLista_De_Palavras *pLista);
Apontador Verifica_Palavra(TLista_De_Palavras* pLista, char *palavra);
int Retorna_Numero_De_Palavras(TLista_De_Palavras *pLista);
void Imprime_Lista_De_Palavras(TLista_De_Palavras *pLista);
