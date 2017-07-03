//Trabalho extra Árvore Binária de Busca

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define TAM 30

typedef struct NodoArvore {
	int info;
	struct NodoArvore *dir, *esq;
}ArvBin;

ArvBin * cria_nodo()
{
	ArvBin *p;
	p = (ArvBin *) malloc(sizeof(ArvBin));
	if(!p){
		printf("Problema de alocação");
		exit(0);
	}
	return p;
}

ArvBin *insere_arvore(ArvBin *pai, ArvBin *filho, int dado)
{
	if(filho == NULL){
		filho = cria_nodo();
		filho->dir = NULL;
		filho->esq = NULL;
		filho->info = dado;
		if(pai == NULL) // inserção do primeiro nodo
			return filho;
		if(dado < pai->info) //verifica se insere no direita ou esquerda da sub-árvore
			pai->esq = filho;
		else
			pai->dir = filho;
		return filho;
	}
	if(dado < filho->info)
		insere_arvore(filho, filho->esq, dado);
	else
		insere_arvore(filho, filho->dir, dado);
	return filho;
}

void imprime_inordem(ArvBin *arv)
{
	if(!arv)
		return;
	imprime_inordem(arv->esq);
	printf("%d -> ", arv->info);
	imprime_inordem(arv->dir);
}

void imprime_posordem (ArvBin *arv)
{
	if (!arv)
		return;
	imprime_posordem (arv->esq);
	imprime_posordem (arv->dir);
	printf("%d -> ", arv->info);
}

void imprime_preordem (ArvBin *arv)
{
	if (!arv)
		return;
	printf("%d -> ", arv->info);
	imprime_preordem(arv->esq);
	imprime_preordem(arv->dir);
}

void gera_txt()
{
    int n;
    char elemento[4], linha[120]="";

	srand((unsigned)time(NULL));

	int i;
	for(i=0; i<TAM; i++){
		n= 100 + rand()%899;
		itoa(n, elemento, 10);
		strcat(elemento, ";");
		strcat(linha, elemento);
	}

	FILE * arq;

	if((arq = fopen("arquivo.txt", "w"))== NULL){
	    printf("O arquivo não pode ser aberto!");
	    exit(0);
	}

	fprintf(arq, "%s", linha);
	fclose(arq);
}

void percorre_txt(int vet[])
{
	FILE * arq;
	char linha[120], *token, delim[]=";";
	int n, soma=0;

	if((arq = fopen("arquivo.txt", "r"))== NULL)
	    return 0;

	fgets(&linha, 120, arq);
	token = strtok(linha, delim);

	int i;
	for(i=0; i<=TAM; i++){
		n=atoi(token);
		vet[i]=n;
		token = strtok(NULL, delim);
	}
}

int calcula_media(int vet[])
{
	int i, soma=0;
	for (i=0; i<TAM; i++){
		soma=soma+vet[i];
	}
	return (soma/TAM);
}

int identifica_no(int vet[])
{
	int media=calcula_media(vet), dif, dif2, aux;
	int i;
	for (i=0; i<TAM; i++){
		dif=abs(media-vet[i]);
		dif2=abs(media-vet[i+1]);
		if(dif>dif2){
			aux=vet[i];
			vet[i]=vet[i+1];
			vet[i+1]=aux;
		}
	}
	return vet[0];
}

ArvBin* busca (ArvBin *r, int n) {
    if (r == NULL || r->info == n)
       return r;
    if (r->info > n)
       return busca (r->esq, n);
    else
       return busca (r->dir, n);
}

void menu()
{
	system("cls");
	printf("\n ____________________________");
	printf("\n|                            |");
	printf("\n|            Menu            |");
	printf("\n|    ____________________    |");
	printf("\n|                            |");
	printf("\n| 1. Gerar arquivo de texto. |");
	printf("\n| 2. Montar arvore binaria.  |");
	printf("\n| 3. Ver arvore./            |");
	printf("\n| 4. Excluir elemento./      |");
	printf("\n| 5. Buscar elemento.        |");
	printf("\n| 6. Imprimir In-Ordem.      |");
	printf("\n| 7. Imprimir Pre-Ordem.     |");
	printf("\n| 8. Imprimir Pos-Ordem.     |");
	printf("\n| 9. Sair.                   |");
	printf("\n|____________________________|\n");
	printf("\n");
}

int altura(ArvBin *arv) {

	int u, v;
	if (arv == NULL)
		return -1;
	u = altura(arv->esq);
	v = altura(arv->dir);
	if (u > v)
		return u+1;
	else
		return v+1;
}

void imprime_folhas_inordem(ArvBin *arv)
{
	if(!arv)
		return;
	imprime_folhas_inordem(arv->esq);
	if(arv->esq == NULL && arv->dir == NULL)
		printf("%d -> ", arv->info);
	imprime_folhas_inordem(arv->dir);
}

/*int exclui(ArvBin *A, int n)
{
	ArvBin *nodo;
	if(!A)
		return -1;
	else {
		nodo=busca(A, n);
		if(nodo==NULL)
			return 0;
		else if(n==A->info)
			if(A->dir==NULL && A->esq==NULL)
				remove_raiz_sf(A);
			else {
				A=remove_raiz(A);
			}
	}
}

void remove_raiz_sf(ArvBin *R)
{
	free(R);
	R=NULL;
}

ArvBin remove_raiz (ArvBin *r) {
    ArvBin *p, *q;
    if (r->esq == NULL) {
       q = r->dir;
       free (r);
       return q;
    }
    p = r; q = r->esq;
    while (q->dir != NULL) {
       p = q; q = q->dir;
    }
    // q é nó anterior a r na ordem e-r-d
    // p é pai de q
    if (p != r) {
       p->dir = q->esq;
       q->esq = r->esq;
    }
    q->dir = r->dir;
    free (r);
    return q;
}*/

void main()
{
	ArvBin *p = NULL, *nodo;//ponteiro externo para o nó raiz
	int arr[TAM], no, op, h, n;

	do {
		menu();
		scanf("%i", &op);
		switch (op) {
			case 1:
				gera_txt();
				percorre_txt(&arr);
				printf("\nArquivo gerado!");
				getch();
			break;
			case 2:
				no=identifica_no(&arr);
				p=insere_arvore(p, p, no);
				printf("%i\n", p->info);
				arr[0]=NULL;
			    int i;
				for (i=1; i<TAM; i++){
					p=insere_arvore(p, p, arr[i]);
				}
				no=p->info;
				h=altura(p);
				printf("\nArvore criada!");
				printf("\nAltura: %d;", h);
				printf("\nRaiz: %d;", no);
				printf("\nFolhas:");
				imprime_folhas_inordem(p);
				printf("\n");
				getch();
			break;
			case 3:
				//não implementado
			break;
			case 4:
				printf("\nDigite o valor que deseja excluir: ");
				scanf("%d", &n);
				exclui(p, n);
			break;
			case 5:
				printf("\nDigite um valor para buscar: ");
				scanf("%d", &n);
				nodo=busca(p, n);
				printf("alguma coisa");
				getch();
				if(nodo==NULL)
					printf("\nValor nao existe!");
				else {
					printf("\nValor %d encontrado no nodo ", nodo->info);
					if(nodo->dir==NULL && nodo->esq==NULL)
						printf("folha.\n");
					else if (nodo->info == p->info)
						printf("raiz.\n");
					else
						printf("pai.\n");
				}
				getch();
			break;
			case 6:
				imprime_inordem(p);
				getch();
			break;
			case 7:
				imprime_preordem(p);
				getch();
			break;
			case 8:
				imprime_posordem(p);
				getch();
			break;
			case 9:
				break;
			default:
				printf("\nOpcao inválida. Enter para voltar.");
				getch();
				main();
			break;
		}
	}while(op!=9);
}
