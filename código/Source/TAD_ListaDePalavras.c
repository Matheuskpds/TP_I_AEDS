#include"../Headers/TAD_Lista_De_Palavras.h"

void Criar_Nova_Lista_De_Palavra(TLista_De_Palavras *pLista){
	
	//Aloca espaço para a primeira celula da lista(celula cabeça) e define os Apontadores primeiro e ultimo

    pLista->pPrimeiro_Lista = (Apontador)malloc(sizeof(CPalavra));
    pLista->pUltimo_Lista = pLista->pPrimeiro_Lista;
    pLista->pPrimeiro_Lista->pProx = NULL;

}

Apontador Verifica_Palavra(TLista_De_Palavras* pLista, char *palavra){
	
	//Apontador auxiliar para percorrer a lista
	Apontador pAux;
	pAux = pLista->pPrimeiro_Lista->pProx;
	while(pAux != NULL){
		
		//Compara todas as palavras da lista e se for encontrada uma palavra igual retorna seu endereço
		if (strcmp(palavra, pAux->Palavra.Palavra) == 0){
			
			return pAux;
			
		}
		
		pAux = pAux->pProx;
		
	}
	//Se não for encontrada uma palavra igual retorna 
	return 0;
	
}

void Insere_Nova_Palavra(TLista_De_Palavras *pLista, char *palavra, int linha){

	//Ponteiro auxiliar para receber o endereço retornado pela função "Verifica" caso a palavra exista

	CPalavra* PExiste;
	PExiste = Verifica_Palavra(pLista, palavra);
	
	if (PExiste != 0){
		if(Verifica_Posicao(&pLista->pUltimo_Lista->Palavra.posicoes, linha) == 0)
		//Se a palavra ja existe na lista, verifica se ja foi listada a posição em que ela aparece, se não houver, insere
			Insere_Posicao(&PExiste->Palavra.posicoes, linha);
		return;
		
	}
	else{
		//Caso a palavra não exista na lista é criada uma nova celula em que a palavra é inseria juntamente com sua posição
		int tamanho;
		TPalavra Palavra;
		tamanho = strlen(palavra);
		pLista->pUltimo_Lista->pProx = (Apontador) malloc(sizeof(CPalavra));
		pLista->pUltimo_Lista = pLista->pUltimo_Lista->pProx;
		pLista->pUltimo_Lista->pProx = NULL;
		//Inicializa uma TPalavra e preenche com a palavra e linha desejadas
		Cria_Palavra_Vazia(&Palavra, tamanho);
		Insere_Posicao(&Palavra.posicoes, linha);
		Preenche_Cadeia_De_Caracteres(&Palavra, palavra);
		//Copia o conteudo da TPalavra criada para a TPalavra dentro da lista
		pLista->pUltimo_Lista->Palavra = Palavra;

		
	}

}

void Remove_Palavra_Final(TLista_De_Palavras *pLista){
	
	//Apontador para auxiliar na remoção de uma celula
	CPalavra* pNovo_Ultimo;
	pNovo_Ultimo = pLista->pPrimeiro_Lista->pProx;
	
	while(pNovo_Ultimo->pProx->pProx != NULL){
		//Percorre a lista até chegar ao final
		pNovo_Ultimo = pNovo_Ultimo->pProx;
	}
	//Desaloca o espaço da ultima celula e define o endereço como nulo
	free(pNovo_Ultimo->pProx);
	pNovo_Ultimo->pProx = NULL;
	pLista->pUltimo_Lista = pNovo_Ultimo;

}

void Remove_Palavra(TLista_De_Palavras *pLista, char *palavra){
	
	//Apontadores para auxiliar na remoção da celula
	//Apontador que guarda a o endereço da celula que sera removida
	Apontador pRemovedor;
	//Apontador auxiliar para percorrer na celula
	Apontador pAux;
	pAux = pLista->pPrimeiro_Lista;
	
	while((strcmp(palavra, pAux->pProx->Palavra.Palavra) != 0) && pAux != NULL){
		
		//Compara todos as palavras da lista até chegar na palavra igual ou no final da lista

		pAux = pAux->pProx;
		
	}
	
	if(strcmp(palavra, pAux->pProx->Palavra.Palavra) == 0){
		
		//Se for encontrada uma palavra igual guarda o seu endereço
		pRemovedor = pAux->pProx;
		//Faz a celula anterior a que vai ser reemovida apontar para a celula seguinte
		pAux->pProx = pAux->pProx->pProx;
		//Desaloca o espaço reservado do endereço guardado
		free(pRemovedor);
		
	}
	else{
		printf("Essa palavra não existe na lista\n");
	}
	
}

int Retorna_Numero_De_Palavras(TLista_De_Palavras *pLista){
	
	if (pLista->pPrimeiro_Lista->pProx == NULL){
		//Se a lista for vazia retorna 0
		return 0;
		
	}
	
	int contador;
	contador = 1;
	CPalavra *pAux;
	pAux = pLista->pPrimeiro_Lista->pProx;
	
	while(pAux != NULL){
		//Percorre a lista e conta cada celula existente
		contador++;
		pAux = pAux->pProx;
		
	}
	//Retorna o numero total de celulas na lista
	return contador;
	
}

void Imprime_Lista_De_Palavras(TLista_De_Palavras *pLista){
	
	Apontador pAux;
	pAux = pLista->pPrimeiro_Lista->pProx;
	
	while(pAux != NULL){
		//Percorre a lista e imprime seus elementos, as cadeias de caracteres e as suas respectivas posições no texto
		Imprime_Palavra(&pAux->Palavra);
		pAux = pAux->pProx;

	}
	
}
