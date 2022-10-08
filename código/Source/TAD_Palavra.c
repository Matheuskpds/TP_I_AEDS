#include "TAD_Palavra.h"

/*Cria cadeia de caracteresde tamanho único para cada palavra*/
void Criar_Palavra_Vazia(TPalavra* pPalavra, int n){
    pPalavra->Palavra = (char *)malloc(n*sizeof(char));
}

void Preenche_Cadeia_De_Caracteres(TPalavra* pPalavra, FILE *file){
    
    /*Contador de caracteres de cada palavra*/
    int cont = 0;
    char c;
    c = fgetc(file); 
    while(c != '\n'){
        cont++;
        c = fgetc(file);
    }
    TPalavra* aux_palavra; 
    Criar_Palavra_Vazia(aux_palavra, cont);
}