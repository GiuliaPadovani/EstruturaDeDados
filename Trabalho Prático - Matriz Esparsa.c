//Trabalho Prático - Matrizes Esparsas feito por Giulia Padovani - Estrutura de Dados

#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo
{
	float dado;
	int linha, coluna;
	struct Bloco *prox;
} MatrizEsparsa;

void inicializaLista(MatrizEsparsa **N);
void leElemento(MatrizEsparsa **Nodo);
void insereLista(MatrizEsparsa ***N, float dado, int i, int j);
void imprimeMatriz(MatrizEsparsa *N, int nLinhas, int nColunas);
int menu();
int informaColunas();
int informaLinhas();
void imprimeDiagonal(MatrizEsparsa *N, int nLinhas, int nColunas);
void removeLista(MatrizEsparsa *N);
void imprimeDados(MatrizEsparsa *N);
int buscaElemento(MatrizEsparsa *N);
int verifica(int i, int j, int m, int n, int x, int *Rl, int *Rc);
void somar(MatrizEsparsa *NA, MatrizEsparsa *NB, MatrizEsparsa **R, int nLinhas, int nColunas);
void subtrair(MatrizEsparsa *NA, MatrizEsparsa *NB, MatrizEsparsa **R, int nLinhas, int nColunas);

void inicializaLista(MatrizEsparsa **N)//inicializa a lista, coloca todos as variáveis como null
{
	*N = NULL;
}

MatrizEsparsa * criaNodo() //aloca memória para o nodo
{
	MatrizEsparsa *p; //ponteiro externo
	p = (MatrizEsparsa *) malloc(sizeof(MatrizEsparsa));
	if(!p){
		printf("Problema de alocação");
		exit(0);
	}
	return p;
}

int menu()
{
	int op;
	printf("\n------------------MENU------------------");
	printf("\n1. Inserir elementos na matriz.");
	printf("\n2. Imprimir dados.");
	printf("\n3. Imprimir matriz.");
	printf("\n4. Imprimir diagonal principal.");
	printf("\n5. Buscar elemento.");
	printf("\n6. Liberar lista.");
	printf("\n7. Somar as matrizes.");
	printf("\n8. Subtrair as matrizes.");
	printf("\n9. Gerar matriz transposta.");
	printf("\n10. Limpar a tela.");
	printf("\n11. Sair.");
	printf("\n----------------------------------------");
	printf("\n->");
	scanf("%i", &op);
	return op;
}

void leElemento(MatrizEsparsa **N) //lê os elementos e a posição na matriz, insere o que for != 0
{
	int l, c;
	char sair;
	float valor;
	do{
		printf("\nIserir um elemento na matriz.\n");
		printf("Linha:");
		scanf("%i", &l);
		printf("Coluna:");
		scanf("%i", &c);
		printf("Valor:");
		scanf("%f", &valor);
		if (valor != 0) {
			MatrizEsparsa *novo;
			novo = criaNodo();
			novo->dado = valor;
			novo->linha=l;
			novo->coluna=c;
			novo->prox = *N;
			*N = novo;
		}
		printf("Sair? (*)");
		scanf("%*c%c", &sair);
	}while(sair!='*');
}


void removeLista(MatrizEsparsa *N)//Remove todos os nós da Lista
{
    MatrizEsparsa *aux;
    if(N==NULL)
    	printf("List is empty!");
    else{
	    while (N != NULL)
	    {
	        aux = N;
	        N = N->prox;
	        free(aux);
	    }
	    N = NULL;
	    printf("\nEspaco liberado!\n");
	    getch();
	}
}


void imprimeDados(MatrizEsparsa *N)
{
	MatrizEsparsa *aux;
	if(N == NULL)
		printf("\n List is empty!");
	else {
		for(aux = N; aux != NULL; aux = aux->prox){

			printf("%f(%i,%i)->", aux->dado, aux->linha, aux->coluna);
		}
	}
}

void imprimeMatriz(MatrizEsparsa *N, int nLinhas, int nColunas)
{
	MatrizEsparsa *aux;
	int i, j;
	float found;
	if(N == NULL)
		printf("\n List is empty!");
	else {
		for (i = 1; i < nLinhas+1; i++){
			for ( j = 1; j < nColunas+1; j++){
				if(j==1)
					printf("|");
				for(aux = N; aux != NULL; aux = aux->prox){
					if (aux->linha==i && aux->coluna==j){
						found=aux->dado;
						break;
					}
					else
						found=0;
				}
				printf(" %f ", found);
				if (j==nColunas)
					printf("|\n");
			}
		}
	}
}

void imprimeDiagonal(MatrizEsparsa *N, int nLinhas, int nColunas)
{
	MatrizEsparsa *aux;
	int i, j;
	float found;
	if(N == NULL)
		printf("\n List is empty!");
	else {
		for (i = 1; i < nLinhas+1; i++){
			for ( j = 1; j < nColunas+1; j++){
				if(j==1)
					printf("|");
				if(i==j){
					for(aux = N; aux != NULL; aux = aux->prox){
						if (aux->linha==i && aux->coluna==j)
							found=aux->dado;
						else
							found=0;
					}
					printf(" %f ", found);
				}else
					printf("         ");
				if (j==nColunas)
					printf("|\n");
			}
		}
	}
}

int informaLinhas()
{
	int linha;
	printf("Dimensao da matriz:\n");
	printf("Informe o numero de linhas:");
	scanf("%i", &linha);
	return linha;
}

int informaColunas()
{
	int coluna;
	printf("Informe o numero de colunas:");
	scanf("%i", &coluna);
	return coluna;
}

int buscaElemento(MatrizEsparsa *N){
	MatrizEsparsa *aux;
	int  found=0, Lindice, Cindice;
	float elemento;
	printf("Digite o elemento que deseja procurar:");
	scanf("%f", &elemento);
	aux = N;
	do{
		if (aux->dado==elemento){
			found=1;
			Lindice=N->linha;
			Cindice=N->coluna;
		}
		aux = aux->prox;
	}while(found!=1 || aux != NULL);
	if (found==1){
		printf("\nO elemento %f foi encontrado na posicao %i,%i.", elemento, Lindice, Cindice);
		return elemento;
	}
	else{
		printf("Elemento not found.");
		return 0;
	}
}

int verifica(int i, int j, int m, int n, int x, int *Rl, int *Rc)
{
	if(x==7 || x==8){
		if (i==j && m==n)
			return 1;
		else
			return 0;
	}else{
		if(j==m){
			Rl=i;
			Rc=n;
			return 1;
		}
		else
			return 0;
	}

}

void somar(MatrizEsparsa *NA, MatrizEsparsa *NB, MatrizEsparsa **R, int nLinhas, int nColunas)
{
	int i, j;
	float elementoA, elementoB, r;
	MatrizEsparsa *auxA, *auxB;
	MatrizEsparsa *novo;
	for (i = 1; i < nLinhas+1; i++){
		for ( j = 1; j < nColunas+1; j++){
			for(auxA = NA; auxA != NULL; auxA = auxA->prox){
				if (auxA->linha==i && auxA->coluna==j){
					elementoA=auxA->dado;
					break;
				}
				else
					elementoA=0;

			}
			for(auxB = NB; auxB != NULL; auxB = auxB->prox){
				if (auxB->linha==i && auxB->coluna==j){
					elementoB=auxB->dado;
					break;
				}
				else
					elementoB=0;
			}
			r=elementoA+elementoB;
			if (r != 0) {
				novo = criaNodo();
				novo->dado = r;
				novo->linha=i;
				novo->coluna=j;
				novo->prox = *R;
				*R = novo;
			}
		}
	}
	printf("\nA + B = R.\n");
}

void subtrair(MatrizEsparsa *NA, MatrizEsparsa *NB, MatrizEsparsa **R, int nLinhas, int nColunas)
{
	int i, j;
	float elementoA, elementoB, r;
	MatrizEsparsa *auxA, *auxB;
	MatrizEsparsa *novo;
	for (i = 1; i < nLinhas+1; i++){
		for ( j = 1; j < nColunas+1; j++){
			for(auxA = NA; auxA != NULL; auxA = auxA->prox){
				if (auxA->linha==i && auxA->coluna==j){
					elementoA=auxA->dado;
					break;
				}
				else
					elementoA=0;
			}
			for(auxB = NB; auxB != NULL; auxB = auxB->prox){
				if (auxB->linha==i && auxB->coluna==j){
					elementoB=auxB->dado;
					break;
				}
				else
					elementoB=0;
			}
			r=elementoA-elementoB;
			if (r != 0) {
				novo = criaNodo();
				novo->dado = r;
				novo->linha=i;
				novo->coluna=j;
				novo->prox = *R;
				*R = novo;
			}
		}
	}
}

int escolherMatriz(int x)
{
	int qual;
	if(x==1){
		printf("Matriz (1)A ou (2)B?");
		scanf("%i", &qual);
	}else{
		printf("Matriz (1)A ou (2)B ou (3)R?");
		scanf("%i", &qual);
	}

	return qual;

}

void matrizTransposta(MatrizEsparsa *N, MatrizEsparsa **NT)
{
	MatrizEsparsa *aux, *novo;
	for(aux = N; aux != NULL; aux = aux->prox){
		novo = criaNodo();
		novo->dado = aux->dado;
		novo->linha=aux->coluna;
		novo->coluna=aux->linha;
		novo->prox = *NT;
		*NT = novo;
	}
}



int main()
{
	MatrizEsparsa *matrizA, *matrizB, *resultado, *T;
	int option, valor, ret,linhasA, colunasA, linhasB, colunasB, linhasR, colunasR;
	inicializaLista(&matrizA);
	inicializaLista(&matrizB);
	inicializaLista(&resultado);
	inicializaLista(&T);
	do{
		option=menu();
		switch(option) {
			case 1:
				ret=escolherMatriz(option);
				if(ret==1){
					linhasA=informaLinhas();
					colunasA=informaColunas();
					leElemento(&matrizA);
				}
				else{
					linhasB=informaLinhas();
					colunasB=informaColunas();
					leElemento(&matrizB);
				}
			break;
			case 2:
				ret=escolherMatriz(option);
				if(ret==1)
					imprimeDados(matrizA);
				else if(ret==2)
					imprimeDados(matrizB);
				else
					imprimeDados(resultado);
			break;
			case 3:
				ret=escolherMatriz(option);
				if(ret==1)
					imprimeMatriz(matrizA, linhasA, colunasA);
				else if(ret==2)
					imprimeMatriz(matrizB, linhasB, colunasB);
				else
					imprimeMatriz(resultado, linhasA, colunasA);
			break;
			case 4:
				ret=escolherMatriz(option);
				if(ret==1)
					imprimeDiagonal(matrizA, linhasA, colunasA);
				else if(ret==2)
					imprimeDiagonal(matrizB, linhasB, colunasB);
				else
					imprimeDiagonal(resultado, linhasA, colunasA);
			break;
			case 5:
				ret=escolherMatriz(option);
				if(ret==1)
					buscaElemento(matrizA);
				else if(ret==2)
					buscaElemento(matrizB);
				else
					buscaElemento(resultado);
			break;
			case 6:
				ret=escolherMatriz(option);
				if(ret==1)
					removeLista(matrizA);
				else if(ret==2)
					removeLista(matrizB);
				else
					removeLista(resultado);
			break;
			case 7:
				if (verifica(linhasA, linhasB, colunasA, colunasB, option, &linhasR, &colunasR)==1){
					somar(matrizA, matrizB, &resultado, linhasA, colunasA);
					imprimeMatriz(resultado,linhasA, colunasA);
				}else
					printf("Nao pode somar: ixj != mxn.");
			break;
			case 8:
				if (verifica(linhasA, linhasB, colunasA, colunasB,option, &linhasR, &colunasR)==1){
					subtrair(matrizA, matrizB, &resultado, linhasA, colunasA);
					imprimeMatriz(resultado,linhasA, colunasA);
				}else
					printf("Nao pode subtrair: ixj != mxn.");

			break;
			case 9:
				ret=escolherMatriz(option);
				if(ret==1){
					matrizTransposta(matrizA, &T);
					imprimeMatriz(T, colunasA, linhasA);
				}
				else if(ret==2){
					matrizTransposta(matrizB, &T);
					imprimeMatriz(T, colunasB, linhasB);
				}
				else{
					matrizTransposta(resultado, &T);
					imprimeMatriz(T, colunasR, linhasR);
				}
			break;
			case 10:
				system("cls");
			break;
			case 11:
				printf("\n\n\n------Saindo do programa!------");
			break;
			default:
				printf("\nOpcao Invalida!!!");
		}
	}while(option != 11);
	return 0;
}
