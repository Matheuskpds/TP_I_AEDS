#include <stdio.h>
#include <stdlib.h>
#include "TAD_Lista_De_Palavras.h"

void menu(){
    
    printf("-=-=-=-=-=-=-=-=-=-=-=-= MENU -=-=-=-=-=-=-=-=-=-=-=\n");

    printf("[1] Inicializar com arquivo txt\n");
    printf("[2] Imprimir Palavras com Posicoes\n");
    printf("[3] Remover Ultima Palavra\n");
    printf("[4] Remover determinada palavra\n");
    printf("[5] Encerrar programa\n");

    printf("-=-=--=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}


void resp_usuario(){
    TLista_De_Palavras pListaDePalavras;
    int resp;
    int loop=1;
    char deletar_palavra[50] = {0};
    Criar_Nova_Lista_De_Palavra(&pListaDePalavras);
    while(loop){
        menu();
        scanf("%d", &resp);
        switch (resp)
        {
            case 1:
                printf("\n");
                Insere_Nova_Palavra(&pListaDePalavras, "matheus", 8);
                break;
            
            case 2:
                Imprime_Lista_De_Palavras(&pListaDePalavras);
                break;
            case 3:
                Remove_Palavra_Final(&pListaDePalavras);
            case 4:
                fgets(deletar_palavra, 50, stdin);
                Remove_Palavra(&pListaDePalavras, deletar_palavra);
            case 5:
                printf("Programa Encerrado. \n");
                loop = 0;
                break;
            
            default:
                break;
        }
        if(resp!=5){
          printf("\n\nAperte uma tecla para continuar: ");
          fflush(stdin);
          getchar();
    }
}


int main(){
   TPalavra pPalavra;
   TLista_De_Palavras pListaDePalavras;
   TLista_De_Posicoes pListaDePosicoes;
   resp_usuario();
}
