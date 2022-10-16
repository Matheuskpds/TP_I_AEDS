#include "../Headers/TAD_Dicionario.h"


void Inicializa_Dicionario(TDicionario* pDicionario){

    //Aloca espaço para a primeira celula da lista(celula cabeça) e define os Apontadores primeiro e ultimo
    //além de definir um valor nulo para a letra

    pDicionario->pPrimeiro = (ApontadorDicionario)malloc(sizeof(TCelulaDicionario));
    pDicionario->pUltimo = pDicionario->pPrimeiro;
    pDicionario->pPrimeiro->pProx = NULL;
    pDicionario->pPrimeiro->letra_lista = 0;
}

void Constroi_Dicionario(TDicionario* pDicionario, FILE* arquivo){

    //Realiza a leitura do arquivo e separa cara palavra
    int linha=1;

    if(arquivo==NULL){
        printf("Arquivo inexistente! Por favor, verifique o nome do arquivo!");
    }else{
        //Variaveis para colher as palavras os espaços e as quebras de linha
        char palavra[Tamanho_Palavra], caractere;
        while (!feof(arquivo)){
            //Lê o arquivo até o final separando palavra por palavra
            //A variavel palavra recebe as palavras
            //A variavel caractere recebe os espaços e as quebras de linha
            fscanf(arquivo,"%s%c",palavra,&caractere);

            if(caractere=='\n'){
                //Quando é detectada uma quebra de linha o contador de linha é incrementado em 1
                linha++;
            }
            //Insere no dicionario a palavra juntamente com a linha
            Insere_Palavra_Dicionario(pDicionario, palavra, linha);
        }

    }
    
    
}

TLista_De_Palavras* Cria_e_Insere_Nova_Lista(TDicionario *pDicionario, char letra){

    //Lista de palavras que sera preenchida e depois copiada para o dicionario
    TLista_De_Palavras lista_de_palavras;
    Criar_Nova_Lista_De_Palavra(&lista_de_palavras);
    //Apontadores para auxiliar na logica de inserção
    //Apontador para auxiliar na inserção das listas na ordem alfabética
    ApontadorDicionario pAux_Ordenador;
    //Apontador para guardar um endereço necessario durante a ordenação
    ApontadorDicionario Guarda_Endereco;
    //Apontador para guardar o endereço que sera retornado ao final da função
    TLista_De_Palavras* Lista_Palavra;
	if (Verifica_Lista(pDicionario, letra) != 0){
        
        //Verifica se existe uma lista com a letra solicitada
		printf("Ja existe uma lista com essa letra\n");
		return 0;

	}
	else{
        if(Dicionario_eh_vazio(pDicionario)){

            //Caso o dicionario esteja vazio, cria uma celula na primeira posição após a celula cabeça

            pDicionario->pPrimeiro->pProx = (ApontadorDicionario)malloc(sizeof(TCelulaDicionario));
            pDicionario->pUltimo = pDicionario->pPrimeiro->pProx;
            pDicionario->pUltimo->pProx = NULL;
            //Preenche os campos da celula dicionario
            pDicionario->pUltimo->ListaDePalavras = lista_de_palavras;
            pDicionario->pUltimo->letra_lista = letra;
            //Define o endereço que sera retornado ao final do subprograma
            Lista_Palavra = &pDicionario->pUltimo->ListaDePalavras;
        }
        else if (letra < pDicionario->pPrimeiro->pProx->letra_lista){
            
            //Caso a letra seja anterior a letra da lista da primeira posição, é realizada uma inserção no inicio
            pAux_Ordenador = pDicionario->pPrimeiro->pProx;
            pDicionario->pPrimeiro->pProx = (ApontadorDicionario)malloc(sizeof(TCelulaDicionario));
            pDicionario->pPrimeiro->pProx->pProx = pAux_Ordenador;
            //Preenche os campos da celula dicionario
            pDicionario->pPrimeiro->pProx->ListaDePalavras = lista_de_palavras;
            pDicionario->pPrimeiro->pProx->letra_lista = letra;
            //Define o endereço que sera retornado ao final do subprograma
            Lista_Palavra = &pDicionario->pPrimeiro->pProx->ListaDePalavras;
        }
        else{
            //Caso a letra seja posterior a letra da lista da primeira posição
            //Percorre a lista até que seja encontrada a posição adaquada
            pAux_Ordenador = pDicionario->pPrimeiro;
            while(pAux_Ordenador->pProx && letra > pAux_Ordenador->pProx->letra_lista){
                pAux_Ordenador = pAux_Ordenador->pProx;
            }
            //Realiza a inserção de uma nova celula no meio do dicionario ou ao final
            //Guarda o endereço da celula seguinte a do ponteiro ordenador
            Guarda_Endereco = pAux_Ordenador->pProx;
            //Aloca o espaço para uma nova celula após o ordenador
            pAux_Ordenador->pProx = (ApontadorDicionario)malloc(sizeof(TCelulaDicionario));
            //Faz essa celula apontar para a antiga celula no seu campo proximo
            pAux_Ordenador->pProx->pProx = Guarda_Endereco;
            //Preenche os campos do dicionario
            pAux_Ordenador->pProx->ListaDePalavras = lista_de_palavras;
            pAux_Ordenador->pProx->letra_lista = letra;
            //Define o endereço que sera retornado ao final do subprograma
            Lista_Palavra = &pAux_Ordenador->pProx->ListaDePalavras;
        }
        //Retorna o endereço da lista criada
        return Lista_Palavra;
    }
}


ApontadorDicionario Verifica_Lista(TDicionario *pDicionario, char letra){

    ApontadorDicionario pAux;
	pAux = pDicionario->pPrimeiro->pProx;

	while(pAux != NULL){
		//Percorre o dicionario até encontrar uma lista com a determinada letra ou até chegar ao final
		if (pAux->letra_lista == letra){
			//Se for encontrada uma lista com a letra é retornado o endereço dessa lista
			return pAux;
			
		}
		
		pAux = pAux->pProx;
		
	}
    //Se não for encontrado o a lista com a letra é retornado 0
	return 0;

}

int Dicionario_eh_vazio(TDicionario* pDicionario){
    //Verifica se o dicionario é vazio, se for retorna 1 se não retorna 0
    if(pDicionario->pPrimeiro == pDicionario->pUltimo)
        return 1;
    return 0;
}

void Imprime_Dicionario(TDicionario Dicionario){

    ApontadorDicionario pAux;
    pAux = Dicionario.pPrimeiro->pProx;
    //Percorre todo o dicionario e imprime cada lista com suas respectivas palavras
    while(pAux != NULL){
        printf("======================\n\n");
        printf("Letra: |%c|\n", pAux->letra_lista);
        //Função do TAD Lista de palavras para imprimir cada lista
        Imprime_Lista_De_Palavras(&pAux->ListaDePalavras);
        printf("======================\n\n");
        pAux = pAux->pProx;
    }

}

void Insere_Palavra_Dicionario(TDicionario* pDicionario, char* palavra, int linha){
    //Insere as palavras no dicionario
    if(Verifica_Lista(pDicionario, palavra[0]) != 0){
        //Caso a lista com a primeira letra da palavra ja exista, insere a palavra nesta lista junto com a linha
        Insere_Nova_Palavra(&Verifica_Lista(pDicionario, palavra[0])->ListaDePalavras, palavra, linha);

    }
    else{
        //Caso a lista não exista, é criada uma lista com a primeira letra da palavra
        Insere_Nova_Palavra(Cria_e_Insere_Nova_Lista(pDicionario, palavra[0]), palavra, linha);
        //A palavra é inserida nesta lista criada
    }

}

void Imprime_Lista_Determinada_Letra(TDicionario* pDicionario, char letra){
    //Imprime a lista de palavras com determinada letra
    ApontadorDicionario pAux_Celula;
    pAux_Celula = pDicionario->pPrimeiro->pProx;
    //Percorre o dicionario até encontrar a lista com a determinada letra
    while(pAux_Celula != NULL){
        if(pAux_Celula->letra_lista == letra){
            //Caso a lista seja encontrada ela é imprimida
            Imprime_Lista_De_Palavras(&pAux_Celula->ListaDePalavras);
            return;
        }
        pAux_Celula = pAux_Celula->pProx;
    }
    //Caso a lista não seja encontrada é printada a seguinte mensagem
    printf("Nao existe uma lista de palavras iniciadas com a letra [%c]\n", letra);
    

}
