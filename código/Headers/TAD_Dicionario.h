#include "TAD_Lista_De_Palavras.h"
#define Tamanho_Palavra 50 //Na língua portuguesa as maiores palavras não ultrapassam 50 letras

//ponteiro para celulaDicionario
typedef struct CelulaDicionario* ApontadorDicionario;

typedef struct CelulaDicionario{
    
    //Estrutura que guarda uma lista com a letra correspondente além do endereço da proxima estrutura

    char letra_lista;
    TLista_De_Palavras ListaDePalavras;
    struct CelulaDicionario* pProx;

}TCelulaDicionario;

typedef struct{

    //Lista encadeada das listas de palavras(Dicionario)

    ApontadorDicionario pPrimeiro;
    ApontadorDicionario pUltimo;
}TDicionario;


//operacoes do dicionario
void Inicializa_Dicionario(TDicionario* pDicionario);                                //Inicializa o dicionario juntamente
void Constroi_Dicionario(TDicionario* pDicionario, FILE* arquivo);                   //Recebe um arquivo como parametro e constrói o Dicionario com suas palavras
TLista_De_Palavras* Cria_e_Insere_Nova_Lista(TDicionario* pDicionario, char letra);  //Cria uma nova lista, insere no dicionario e retorna seu endereço
ApontadorDicionario Verifica_Lista(TDicionario* pDicionario, char letra);            //Verifica se ja existe uma lista com uma determiana letra, se existir retorna o endereço
int Dicionario_eh_vazio(TDicionario* pDicionario);                                   //Verifica se o dicionario é vazio
void Imprime_Dicionario(TDicionario Dicionario);                                     //Imprime todas as lista do dicionario em ordem alfabética
void Insere_Palavra_Dicionario(TDicionario* pDicionario, char* palavra, int linha);  //Recebe uma palavra e insere no dicionario na respectiva lista
void Imprime_Lista_Determinada_Letra(TDicionario* pDicionario, char letra);          //Imprime uma lista de palavras de uma determinada letra

