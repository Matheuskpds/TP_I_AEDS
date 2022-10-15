#include <stdio.h>
#include <stdlib.h>
#include "TAD_Dicionario.h"

void opcoes(){
    printf("-=-=-=-=-=-=-=-=-=-=-=-= MENU -=-=-=-=-=-=-=-=-=-=-=\n");

    printf("[1] Contruir Dicionario\n");
    printf("[2] Imprimir Dicionario\n");
    printf("[3] Imprimir Dicionario em Ordem Alfabética\n");
    printf("[4] Remover Ultima Palavra\n");
    printf("[5] Remover determinada palavra\n");
    printf("[6] Encerrar programa\n");

    printf("-=-=--=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}


void menu(){
    TLista_De_Palavras pListaDePalavras;
    TDicionario pDicionario;
    FILE* arquivo = NULL;

    int resp = 0;
    char enter;
    int loop=1;
    char deletar_palavra[50] = {0};
    Inicializa_Dicionario(&pDicionario);
    
    char nomeArquivo[100]={0};
    
    while(loop){
        opcoes();
        fflush(stdin);
        scanf("%d", &resp);
        switch(resp){
            case 1:
                printf("Insira o nome do arquivo de entrada: \n");
                scanf("%[^\n]", nomeArquivo);
                arquivo=fopen(nomeArquivo,"rt");
                Constroi_Dicionario(&pDicionario, arquivo);
                break;
            case 2:
                //Imprimir palavras com posicoes
                Imprime_Dicionario(pDicionario);
                break;
            case 3:
                //Aguardando a função ser criada
            case 4:
                Remove_Palavra_Final(&pListaDePalavras);
                break;
            case 5:
                fgets(deletar_palavra, 50, stdin);
                Remove_Palavra(&pListaDePalavras, deletar_palavra);
                break;
            case 6:
                printf("Programa Encerrado.\n");
                loop = 0;
                break;
        }
        if(resp!=6){
            fflush(stdin);
            printf("Aperte enter para continuar.//");
            getchar();
            printf("\n");
        }
    }
      
}

int main(){
    menu();
}
