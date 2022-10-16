#include"Headers/TAD_Dicionario.h"
#define Tamanho_Arquivo 256 //Tamanho máximo de caracteres aceitos na nomeação de um arquivo

void opcoes(){
    //Subprograma para printar as opções do menu
    printf("-=-=-=-=-=-=-=-=-=-=-=-= MENU -=-=-=-=-=-=-=-=-=-=-=\n");

    printf("[1] Contruir Dicionario\n");
    printf("[2] Imprimir Dicionario\n");
    printf("[3] Imprimir lista de palavras de determinada letra\n");
    printf("[4] Encerrar programa\n");

    printf("-=-=--=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

void menu(){

    TDicionario pDicionario;
    FILE* arquivo = NULL;

    int resp = 0;
    char enter;
    int loop=1;
    char deletar_palavra[Tamanho_Palavra] = {0};
	char letra;
    Inicializa_Dicionario(&pDicionario);

    char nomeArquivo[Tamanho_Arquivo]={0};
    //Subprograma Menu, que recebe o nome do arquivo que sera lido e realiza as ações de acordo com as opções escolhidas pelo usuario
    while(loop){
		system("cls");
        opcoes();
        fflush(stdin);
        scanf("%d", &resp);
        switch(resp){
            case 1:
                printf("Insira o nome do arquivo de entrada: \n");
				fflush(stdin);
                //Recebe o nome do arquivo a ser lido
                scanf("%[^\n]", nomeArquivo);
                //Realiza a leitura do arquivo
                arquivo=fopen(nomeArquivo,"rt");
                //Constroi o dicionario com as palavras presentes no texto do arquivo
                Constroi_Dicionario(&pDicionario, arquivo);
                break;
            case 2:
                //Imprime listas das palavras com posicoes
                Imprime_Dicionario(pDicionario);
                break;
            case 3:
				printf("Deseja visualizar a lista correspondente a qual letra?\n");
				fflush(stdin);
				scanf("%c", &letra);
				Imprime_Lista_Determinada_Letra(&pDicionario, letra);
				break;
            case 4:
                //Encerra o programa
                printf("Programa Encerrado.\n");
                loop = 0;
                break;
        }
        if(resp!=4){
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
