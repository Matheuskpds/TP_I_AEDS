#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/TAD_Dicionario.h"
#include "../Headers/TAD_ListaDePalavras.h"

void Inicializa_Dicionario(TDicionario* pDicionario){
    pDicionario->pPrimeiro = (ApontadorDicionario)malloc(sizeof(TCelulaDicionario));
    pDicionario->pUltimo = pDicionario->pPrimeiro;
    pDicionario->pPrimeiro->pProx = NULL;
    pDicionario->pPrimeiro->letra_lista = 0;
}

void Constroi_Dicionario(TDicionario* pDicionario){

    //pegar o nome do arquivo
    char nomeArquivo[100]={0};
    int linha=1, numLetras=0;
    //printf("Insira o nome do arquivo de entrada:");
    //scanf("%s", nomeArquivo);
    //pegar o arquivo
    FILE* arquivo=NULL;
    arquivo=fopen("gabriel.txt","rt");
    if(arquivo==NULL){
        printf("Arquivo inexistente! Por favor, verifique o nome do arquivo!");
    }else{
        //pegar palavra por palavra
        TLista_De_Palavras listaPalavras;
        Criar_Nova_Lista_De_Palavra(&listaPalavras);
        //não existe palavra maior que 50 caracteres
        char palavra[50], caractere;
        while (!feof(arquivo)){

            fscanf(arquivo,"%s%c",palavra,&caractere);
            numLetras=strlen(palavra);
            if(caractere=='\n'){
                linha++;
            }
            //mando a palavra e a linha  para a função insere da lista de palavras
            Insere_Palavra_Dicionario(pDicionario, palavra, linha);
        }

    }
    
    
}

TLista_De_Palavras* Cria_e_Insere_Nova_Lista(TDicionario *pDicionario, char letra){

    TLista_De_Palavras lista_de_palavras;
    Criar_Nova_Lista_De_Palavra(&lista_de_palavras);
    ApontadorDicionario pAux_Ordenador;
    TLista_De_Palavras* Lista_Palavra;
	if (Verifica_Lista(pDicionario, letra) != 0){

		printf("Ja existe uma lista com essa letra");
		return 0;

	}
	else{
        if(Dicionario_eh_vazio(pDicionario)){

            pDicionario->pPrimeiro->pProx = (ApontadorDicionario)malloc(sizeof(TCelulaDicionario));
            pDicionario->pUltimo = pDicionario->pPrimeiro->pProx;
            pDicionario->pUltimo->pProx = NULL;
            pDicionario->pUltimo->ListaDePalavras = lista_de_palavras;
            pDicionario->pUltimo->letra_lista = letra;
        }
        else{
            
            pDicionario->pUltimo->pProx = (ApontadorDicionario)malloc(sizeof(TCelulaDicionario));
            pDicionario->pUltimo = pDicionario->pUltimo->pProx;
            pDicionario->pUltimo->pProx = NULL;
            pDicionario->pUltimo->ListaDePalavras = lista_de_palavras;
            pDicionario->pUltimo->letra_lista = letra;
        }
        Lista_Palavra = &pDicionario->pUltimo->ListaDePalavras;
        return Lista_Palavra;

    }
}


ApontadorDicionario Verifica_Lista(TDicionario *pDicionario, char letra){

    ApontadorDicionario pAux;
	pAux = pDicionario->pPrimeiro->pProx;

	while(pAux != NULL){
		
		if (pAux->letra_lista == letra){
			
			return pAux;
			
		}
		
		pAux = pAux->pProx;
		
	}

	return 0;

}

int Dicionario_eh_vazio(TDicionario* pDicionario){

    if(pDicionario->pPrimeiro == pDicionario->pUltimo)
        return 1;
    return 0;
}

void Imprime_Dicionario(TDicionario Dicionario){

    ApontadorDicionario pAux;
    pAux = Dicionario.pPrimeiro->pProx;

    while(pAux != NULL){

        printf("|%c|\n", pAux->letra_lista);
        Imprime_Lista_De_Palavras(&pAux->ListaDePalavras);
        pAux = pAux->pProx;
    }

}

void Insere_Palavra_Dicionario(TDicionario* pDicionario, char* palavra, int linha){

    if(Verifica_Lista(pDicionario, palavra[0]) != 0){

        Insere_Nova_Palavra(&Verifica_Lista(pDicionario, palavra[0])->ListaDePalavras, palavra, linha);

    }
    else{

        Insere_Nova_Palavra(Cria_e_Insere_Nova_Lista(pDicionario, palavra[0]), palavra, linha);
        
    }

}
