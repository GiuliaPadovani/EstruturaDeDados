//Fila. Feito por Giulia Padovani para a disciplina de Estrutura de Dados.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct fila
{
	char nome[15], origem[15], destino[15];
	int id;
	struct fila *prox;
} Nodo;

void inicializa_fila(Nodo **N);
Nodo * cria_nodo();
void insere_fila(Nodo **N);
int remove_fila(Nodo **N);
void insere_fila(Nodo **N);
int mostra_menu();
void imprime_primeiro(Nodo *N);
void aviao_decolando();
void aviao();

void inicializa_fila(Nodo **N)//inicializa a lista
{
	*N = NULL;
}

Nodo * cria_nodo() //aloca memória para o nodo
{
	Nodo *p;
	p = (Nodo *) malloc(sizeof(Nodo));
	if(!p) {
		printf("Problema de alocação");
		exit(0);
	}
	return p;
}

int mostra_menu()
{
	int op;
	printf("\n");
	aviao();
	printf("\n*-----------------MENU-----------------*");
	printf("\n| 1. Lista de espera decolagem.        |");
	printf("\n| 2. Lista de espera pouso.            |");
	printf("\n| 3. Autorizar decolagem.              |");
	printf("\n| 4. Autorizar pouso.                  |");
	printf("\n| 5. Entrar na lista de decolagem.     |");
	printf("\n| 6. Entrar na lista de pouso.         |");
	printf("\n| 7. Sair.                             |");
	printf("\n*--------------------------------------*");
	printf("\n->");
	scanf("%i", &op);
	return op;
}

void insere_fila(Nodo **N)
{
	Nodo *novo, * aux;
	char nome[15], or[15], dest[15];
	int id;
	novo = cria_nodo();

	printf("Nome do voo:");
	scanf("%s", nome);
	printf("Origem:");
	scanf("%s", or);
	printf("Destino:");
	scanf("%s", dest);
	printf("Numero do voo:");
	scanf("%d", &id);
	strcpy(novo->nome, nome);
	strcpy(novo->origem, or);
	strcpy(novo->destino, dest);
	novo->id=id;
	novo->prox = NULL;

	if(*N == NULL){
		*N = novo;
	}
	else {
		aux = *N;
		while(aux->prox != NULL)
			aux = aux->prox;
		aux->prox = novo;
	}



}

int remove_fila(Nodo **N)
{
	Nodo *aux;
	if(*N == NULL) //verifica se a lista está vazia
		printf("\nList is empty!");
	else{
		aux = (*N)->prox;
		free(*N);
		*N = aux;
	}

	return 1;
}

void imprime_fila(Nodo *N)
{
	Nodo *aux;
	if(N == NULL)
		printf("\n List is empty!");
	else{
		int i=0;
		avioes_em_fila();
		for(aux = N; aux != NULL; aux = aux->prox){
			i++;
			printf("%s, %d -> ", aux->nome, aux->id);
		}
		printf("\nTOTAL: %d", i);
	}
}

void aviao_decolando() {

	printf("\n                   |~~\\_____/~~\\__  |");
    printf("\n_________________  \\______====== )-+");
    printf("\n                         ~~~|/~~  |");    
    printf("\n                            ()");  
   	getch();
    system("cls");  
    
    printf("\n                        |~~\\_____/~~\\__  |");
    printf("\n______________________  \\______====== )-+");
    printf("\n                              ~~~|/~~  |");    
    printf("\n                                 ()"); 
    getch();
    system("cls");
	
	printf("\n                                |~~\\_____/~~\\__  |");
	printf("\n______________________________  \\______====== )-+");
	printf("\n                                      ~~~|/~~  |");    
	printf("\n                                         ()");  
	getch();
	system("cls");

	printf("\n                                    |~~\\_____/~~\\__  |");
	printf("\n___________________________________  \\______====== )-+");
	printf("\n                                           ~~~|/~~  |");    
	printf("\n                                              ()");  
	getch();
	system("cls");  
	
	printf("\n                                          |~~\\_____/~~\\__  |");
	printf("\n________________________________________  \\______====== )-+");
	printf("\n                                                ~~~|/~~  |");    
	printf("\n                                                   ()");
	getch();
	system("cls");
	
	printf("\n                                               |~~\\_____/~~\\__  |");
    printf("\n_____________________________________________  \\______====== )-+");
    printf("\n                                                     ~~~|/~~  |");    
    printf("\n                                                        ()");  
    getch();
	system("cls");
	
	printf("\n                                                        |~~\\_____/~~\\__  |");
    printf("\n______________________________________________________  \\______====== )-+");
    printf("\n                                                              ~~~|/~~  |");    
    printf("\n                                                                 ()");  
    getch();
	system("cls");
	
	printf("\n                                                               |~~\\_____/~~\\__  |");
    printf("\n_____________________________________________________________  \\______====== )-+");
    printf("\n                                                                     ~~~|/~~  |");    
    printf("\n                                                                        ()");  
    getch();
	system("cls");

}

void aviao()
{
	printf("\n               \\         /");
	printf("\n                \\       /");
	printf("\n                 \\  _  /");
	printf("\n                  \\/_\\/");
	printf("\n()---------------(|_*_|)---------------()");   
	printf("\n");                                                        
}

void avioes_em_fila(){
	printf("____       _                ____       _                ____       _    ");
	printf("\n| __\\_\\_o____/_|          | __\\_\\_o____/_|          | __\\_\\_o____/_| ");
	printf("\n<[___\\_\\_-----<  _ _ _ _  <[___\\_\\_-----<  _ _ _ _  <[___\\_\\_-----<  ");
	printf("\n|  o'                       |  o'                       |  o'");
	printf("\n\n");
}


void imprime_primeiro(Nodo *N)
{
	Nodo *aux;
	if(N == NULL)
		printf("\n List is empty!");
	else{
		int i=1;
		for(aux = N; i==1; aux = aux->prox){
			printf("\nNome: %s", aux->nome);
			printf("\nOrigem: %s", aux->origem);
			printf("\nDestino: %s", aux->destino);
			printf("\nNumero: %d", aux->id);
			printf("\n\n");
			i++;
		}
		printf("\n Autorizar aviao?");
		getch();
		system("cls");
	}	
}

void main()
{
	Nodo *decolagem, *pouso;
	char aut;

	inicializa_fila(&decolagem);
	inicializa_fila(&pouso);
	int op;
	do{
		op=mostra_menu();

		switch(op) {
			case 1:
				imprime_fila(decolagem);
			break;
			case 2:
				imprime_fila(pouso);
			break;
			case 3:
				imprime_primeiro(decolagem);
				remove_fila(&decolagem);
				aviao_decolando();
			break;
			case 4:
				imprime_primeiro(pouso);
				remove_fila(&pouso);
				aviao_decolando();
			break;
			case 5:
				insere_fila(&decolagem);
			break;
			case 6:
				insere_fila(&pouso);
			break;
			case 7:
				printf("\n\n\n*------Saindo do programa!------*");
			break;
			default:
				printf("\n Opcao invalida!!!");
		}
	}while(op!=7);

}


//_____________________________________________________________________________________________________________________________________________________

//Pilha. Feito por Giulia Padovani.

#include <stdio.h>

#define COL 30
#define ROW 30

enum position {livre=0, parede, visitada, beco} pos;

typedef struct nodoPilha {
	int elemento;
	struct nodoPilha *prox;
}NODO;

NODO criaNodo();
void push(int dado);
int pop();
void criaMapa();
void mostraMapa();

NODO *pilha=NULL; //ponteiro externo
int mapa[ROW][COL];

NODO criaNodo()
{
	NODO p;//ponteiro
	p = (Nodo *) malloc(sizeof(Nodo));
	p = (NODO) malloc(sizeof(struct nodoPilha));
	if(!p){
		printf(“Problemas na Alocação!!!”);
		exit(0);
	}
	return p;
}

void push(int dado) 
{
	NODO nodo;
	nodo= criaNodo();
	nodo->elemento = dado;
	nodo->prox = pilha;
	pilha = nodo;
}

int pop()
{
	NODO nodo;
	int elem;
	if(!pilha){
		printf(“A pilha está vazia!!!”);
		return -1;
	}
	nodo = pilha;
	elem = nodo->elemento;
	pilha = nodo->prox;
	free(nodo);
	return elem;
}

void criaMapa()
{
	int i, j;
	for  (i = 0; i < ROW; ++i){
		for (j = 0; i < COL; ++i){
			if (i==0 || i==30 || j=1 || j=30){
				mapa[i][j]=parede;
				printf("%i", mapa[i][j]);
			}
		}
	}
}

void main()
{
	criaMapa();
	
}






