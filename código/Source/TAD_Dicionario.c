#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/TAD_Dicionario.h"

void Inicializa_Dicionario(TDicionario* pDicionario){
    pDicionario->pPrimeiro = (ApontadorDicionario)malloc(sizeof(TCelulaDicionario));
    pDicionario->pUltimo = pDicionario->pPrimeiro;
    pDicionario->pPrimeiro->pProx = NULL;
    pDicionario->pPrimeiro->letra_lista = 0;
}

void Constroi_Dicionario(TDicionario* pDicionario, FILE* arquivo){

    //pegar o nome do arquivo
    int linha=1, numLetras=0;
    //printf("Insira o nome do arquivo de entrada:");
    //scanf("%s", nomeArquivo);
    //pegar o arquivo
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
    ApontadorDicionario Guarda_Endereco;
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
            Lista_Palavra = &pDicionario->pUltimo->ListaDePalavras;
        }
        else if (letra < pDicionario->pPrimeiro->pProx->letra_lista){

            pAux_Ordenador = pDicionario->pPrimeiro->pProx;
            pDicionario->pPrimeiro->pProx = (ApontadorDicionario)malloc(sizeof(TCelulaDicionario));
            pDicionario->pPrimeiro->pProx->pProx = pAux_Ordenador;
            pDicionario->pPrimeiro->pProx->ListaDePalavras = lista_de_palavras;
            pDicionario->pPrimeiro->pProx->letra_lista = letra;
            Lista_Palavra = &pDicionario->pPrimeiro->pProx->ListaDePalavras;

        }
        else{

            pAux_Ordenador = pDicionario->pPrimeiro;
            while(pAux_Ordenador->pProx && letra > pAux_Ordenador->pProx->letra_lista){
                pAux_Ordenador = pAux_Ordenador->pProx;
            }
            Guarda_Endereco = pAux_Ordenador->pProx;
            pAux_Ordenador->pProx = (ApontadorDicionario)malloc(sizeof(TCelulaDicionario));
            pAux_Ordenador->pProx->pProx = Guarda_Endereco;
            pAux_Ordenador->pProx->ListaDePalavras = lista_de_palavras;
            pAux_Ordenador->pProx->letra_lista = letra;
            Lista_Palavra = &pAux_Ordenador->pProx->ListaDePalavras;
        }
        
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
        printf("======================\n\n");
        printf("Letra: |%c|\n", pAux->letra_lista);
        Imprime_Lista_De_Palavras(&pAux->ListaDePalavras);
        printf("======================\n\n");
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

void Imprime_Lista_Determinada_Letra(TDicionario* pDicionario, char letra){

    ApontadorDicionario pAux_Celula;
    pAux_Celula = pDicionario->pPrimeiro->pProx;

    while(pAux_Celula != NULL){
        if(pAux_Celula->letra_lista == letra){
            Imprime_Lista_De_Palavras(&pAux_Celula->ListaDePalavras);
            return;
        }
        pAux_Celula = pAux_Celula->pProx;
    }
    printf("Nao existe uma lista de palavras iniciadas com a letra [%c]\n", letra);
    

}
