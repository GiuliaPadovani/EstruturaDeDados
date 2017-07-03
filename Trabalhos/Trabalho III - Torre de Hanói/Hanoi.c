//Trabalho desenvolvido por Giulia Padovani para disciplina Estrutura de Dados

#include <stdio.h>
#define TAM 3

typedef struct Pilha {
 int topo;
 int pilha[TAM];
 char nome;
}Stack;

void inicializa(Stack *a, Stack *b, Stack *c, Stack *d)
{
    a->topo=-1;
    b->topo=-1;
    c->topo=-1;
    d->topo=-1;


    int i;
    for (i=TAM; i>0; i--){
        push(i, a);
        b->pilha[i]=0;
        c->pilha[i]=0;
        d->pilha[i]=0;
    }

    a->nome='A';
    b->nome='B';
    c->nome='C';
    d->nome='D';
}

void push(int valor, Stack *P)
{
    P->topo++;
    if(P->topo < TAM)
        P->pilha[P->topo] = valor;
    else
        printf("A pilha está cheia!!!!");
}

int pop(Stack *P)
{
    if(P->topo < 0){
        printf("A pilha está vazia!!!!");
        return 9999;
    }
    return P->pilha[P->topo--];
}

void move_torre(int n, Stack *origem, Stack *intermed1, Stack *intermed2, Stack *dest, Stack *A, Stack *B, Stack *C, Stack *D)
{
    int e, i;
    if ( n == 1 ){
        e=pop(origem);
        push(e, dest);
        exibe_torre(A, B, C, D);
        getch();
    }
    else if ( n == 2 )
    {
        e=pop(origem);
        push(e, intermed1);
        exibe_torre(A, B, C, D);
        getch();
        e=pop(origem);
        push(e,dest);
        exibe_torre(A, B, C, D);
        getch();
        e=pop(intermed1);
        push(e, dest);
        exibe_torre(A, B, C, D);
        getch();
    }
    else
    {
        move_torre(n - 2, origem, intermed2, dest, intermed1, A , B ,C, D);
        e=pop(origem);
        push(e,intermed2);
        exibe_torre(A, B, C, D);
        getch();
        e=pop(origem);
        push(e, dest);
        exibe_torre(A, B, C, D);
        getch();
        e=pop(intermed2);
        push(e, dest);
        exibe_torre(A, B, C, D);
        getch();
        move_torre(n - 2, intermed1, origem, intermed2, dest, A, B , C ,D);
    }
}

void exibe_torre(Stack *a, Stack *b, Stack *c, Stack *d)
{
     int i;
     printf("\n\n");
     printf("      %c          %c          %c          %c        \n", a->nome, b->nome, c->nome, d->nome);
     for (i=TAM-1; i>=0; i--){
        if(a ->pilha[i]!=0 && a->topo>=i)
            printf("    | %d  |     " , a->pilha[i]);
        else
            printf("    |    |     ");
        if(b->pilha[i]!=0 && b->topo>=i)
            printf("| %d  |     " , b->pilha[i]);
        else
            printf("|    |     ");
        if(c->pilha[i]!=0 && c->topo>=i)
            printf("| %d  |     " , c->pilha[i]);
        else
            printf("|    |     ");
        if(d->pilha[i]!=0 && d->topo>=i)
            printf("| %d  |     " , d->pilha[i]);
        else
            printf("|    |     ");
        printf("\n");
     }
     printf("\n");
}

void menu()
{
    system("cls");
    printf("\n _______________________");
    printf("\n|                       |");
    printf("\n|                       |");
    printf("\n|    Torre de Hanoi     |");
    printf("\n|  ___________________  |");
    printf("\n|                       |");
    printf("\n|    Giulia Padovani    |");
    printf("\n|        ______         |");
    printf("\n|                       |");
    printf("\n|   *Pressione Enter*   |");
    printf("\n|                       |");
    printf("\n|_______________________|\n");
}

void titulo()
{
    system("cls");
    printf("\n ____________________________________________");
    printf("\n|                                            |");
    printf("\n|               Torre de Hanoi               |");
    printf("\n|____________________________________________|\n");
}

void main ()
{
    Stack A, B, C, D;
    char op;

    menu();
    getch();
    titulo();
    inicializa(&A, &B, &C, &D);
    printf("\n ____________________________________________");
    printf("\n|                                            |");
    printf("\n              Posicao inicial:                ");
    exibe_torre(&A, &B, &C, &D);
    printf("\n|-> Mover discos?(m)");
    printf("\n|-> About me (a)");
    printf("\n|-> Sair (x)");
    scanf("%c", &op);

    if (op=='x'){
        printf("\n|-> Saindo do sistema...\n\n");
        return;
    }
    else if (op=='m'){
        system("cls");
        move_torre(TAM, &A, &C, &B, &D, &A, &B, &C, &D);
        titulo();
        printf("\n ____________________________________________");
        printf("\n|                                            |");
        printf("\n               Resultado final:                ");
        exibe_torre(&A, &B, &C, &D);
        printf("\n|____________________________________________|\n");

    }else if (op=='a')
        about();
    else{
        printf("\nOpcao invalida. Pressione enter para voltar.");
        getch();
        main();
    }
}

void about()
{
    titulo();
    printf("\nEste e um trabalho feito para disciplina Estrutura de Dados.");
    printf("\nNele, utiliza-se 4 pilhas estaticas de 8 lugares para simular as torres");
    printf("\ne uma funcao recursiva para fazer os movimentos.");
    printf("\n\n|->Voltar (enter)");
    getch();
    main();
}
