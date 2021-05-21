#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDesc.h"

// Implementação das estruturas de dados
struct Elemento
{
    struct Aluno dados;
    struct Elemento *p_prox;
};

typedef struct Elemento Elem;

struct Descritor
{
    struct Elemento *p_inicio;
    struct Elemento *p_final;
    int qtd;
};

// Funções
int lista_vazia(Lista* li)
{
    if (li == NULL)
        return 1;

    if (li->p_inicio == NULL)
        return 1;

    return 0;
}

int tamanho_lista(Lista* li)
{
    if (li == NULL)
        return 0;

    return li->qtd;
}

Lista* cria_lista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
    {
        li->p_inicio = NULL;
        li->p_final = NULL;
        li->qtd = 0;
    }
    return li;
}

int insere_lista_inicio(Lista* li, struct Aluno al)
{
    if (li == NULL)
        return 0;

    Elem* no;

    no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)
        return 0;
    
    no->dados = al;
    no->p_prox = li->p_inicio;

    // // Não deve ser possível inserir uma matrícula já existente
    // if (li->p_inicio->dados.matricula == no->dados.matricula)
    //     return 0;

    if (li->p_inicio == NULL)
        li->p_final = no;

    li->p_inicio = no;
    li->qtd++;

    return 1; 
}

int insere_lista_final(Lista* li, struct Aluno al)
{
    if (li == NULL)
        return 0;
    
    Elem* no;

    no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)
        return 0;

    no->dados = al;
    no->p_prox = NULL;

    if (li->p_inicio == NULL)
        li->p_inicio = no;
    else
        li->p_final->p_prox = no;
    
    li->p_final = no;
    li->qtd++;

    return 1;
}

int remove_lista_inicio(Lista* li)
{
    if (li == NULL)
        return 0;

    if (li->p_inicio == NULL)
        return 0;
    
    Elem *no = li->p_inicio;
    
    li->p_inicio = no->p_prox;

    free(no);

    if (li->p_inicio == NULL)
        li->p_final = NULL;
    
    li->qtd--;

    return 1;
}

int remove_lista_final(Lista* li)
{
    if (li == NULL)
        return 0;
    
    if (li->p_inicio == NULL)
        return 0;
    
    Elem *ant, *no = li->p_inicio;

    while (no->p_prox != NULL)
    {
        ant = no;

        no = no->p_prox;
    }

    if (no == li->p_inicio)
    {
        li->p_inicio = NULL;

        li->p_final = NULL;
    }
    else
    {
        ant->p_prox = no->p_prox;

        li->p_final = ant;
    }

    free (no);

    li->qtd--;

    return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct Aluno *al)
{
    if (li == NULL || li->p_inicio == NULL || pos <= 0)
        return 0;

    Elem *no = li->p_inicio;

    int i = 1;

    while (no != NULL && i < pos)
    {
        no = no->p_prox;
        i++;
    }

    if (no == NULL)
        return 0;
    else
    {
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, struct Aluno *al)
{
    if (li == NULL || li->p_inicio == NULL)
        return 0;
    
    Elem *no = li->p_inicio;

    while (no != NULL && no->dados.matricula != mat)
        no = no->p_prox;
    
    if (no->dados.matricula != mat)
        return 0;
    
    else
    {
        *al = no->dados;
        return 1;
    }
}

int imprime_lista(Lista* li, struct Aluno *al)
{
    Elem* no = li->p_inicio;

    do
    {
        exibe_consulta(no);
        no = no->p_prox;
    } while (no != NULL);

    return 1;
}

void libera_lista(Lista* li)
{
    if (li != NULL)
    {
        Elem* no;
        
        while ((li->p_inicio) != NULL)
        {
            no = li->p_inicio;
            li->p_inicio = li->p_inicio->p_prox;
            free(no);
        }
        free(li);
    }
}
