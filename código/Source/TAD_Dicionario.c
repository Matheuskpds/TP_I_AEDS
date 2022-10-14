#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/TAD_Dicionario.h"
#include "../Headers/TAD_ListaDePalavras.h"

void Inicializa_Dicionario(TDicionario* pDicionario){
    pDicionario->pPrimeiro = (ApontadorDicionario)malloc(sizeof(TCelulaDicionario));
    pDicionario->pUltimo=pDicionario->pPrimeiro;
    pDicionario->pPrimeiro->pProx=NULL;
}

void Constroi_Dicionario(TDicionario* pDicionario){

    //manda pra celula a lista de palavras
    //pra mandar a lista pra celula, ele tem que receber de algum lugar
    //O TAD_ListaDePalavras faz a lista e eu pego dele essa lista
    //ou seja, pra mandar pra lá eu acesso o TAD_ListaDePalavras e pego cada lista
    //cada item(da struct) já alocado via lista encadeada
    //-------------------------------------------------------------------------------
    //pegar o nome do arquivo
    char nomeArquivo[100]={0};
    int linha=1, numLetras=0;
    //printf("Insira o nome do arquivo de entrada:");
    //scanf("%s", nomeArquivo);
    //pegar o arquivo
    FILE* arquivo=NULL;
    arquivo=fopen("arq.txt","rt");
    if(arquivo==NULL){
        printf("Arquivo inexistente! Por favor, verifique o nome do arquivo!");
    }else{
        //pegar palavra por palavra
        //não existe palavra maior que 50 caracteres
        char palavra[50], caractere;
        while (!feof(arquivo)){
        fscanf(arquivo,"%s%c",palavra,&caractere);
        numLetras=strlen(palavra);
        if(caractere=='\n'){
            linha++;
        }
        //mando a palavra e a linha  para a função insere da lista de palavras
        TLista_De_Palavras listaPalavras;
        Insere_Nova_Palavra(&listaPalavras, palavra, linha);
        }
        //apos inserida, pegar a lista feita pelo TAD_ListaDePalavras
        //com a lista de palavras em maos, percorrer a lista e pegar quais são as letras
        //iniciais de cada palavra, ou seja quantas listas devemos colocar no dicionario.
        //com isso, percorrer com a intencao de pegar as palavras, separar em uma lista e
        //mandar

    //char *pointerCaractere=NULL;
    //char caractere=' ';
    //pointerCaractere=(char*)malloc(sizeof(char));
    //int linha=1, numLetras=0;
    //int i=0;
        //pegar palavra por palavra
        /*
        while(!feof(arquivo)){
            caractere=fgetc(arquivo);
            if(caractere==' '){
                i=0;
                printf("%d", linha);
                //chamo a função insere da listaDePalavras
                free(pointerCaractere);
                pointerCaractere=(char*)malloc(sizeof(char));
                
            }
            else if(caractere=='\n'){
                linha++;
                i=0;
            }
            if(caractere!=' ' && caractere!='\n' && caractere!='\0'){
                numLetras++;
                printf("%c", caractere);
                
                pointerCaractere[i]=caractere;
                i++;
            }
            
        }

    }
    for(int j=0;j<i;j++){
        printf("%c", pointerCaractere[j]);
    }*/

    }
    
    
}
