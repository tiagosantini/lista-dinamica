#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDesc.h"

// Apresenta o menu interativo principal.
void show_menu_principal() {
    printf("-----------------------------------------\n");
    printf("Lista Dinâmica Encadeada com Nó Descritor\n");
    printf("-----------------------------------------\n");
    printf("Escolha a função à ser executada:\n");
    printf("-----------------------------------------\n");
    printf("1 - Inserir elemento no Final\n");
    printf("2 - Inserir elemento no Início\n");
    printf("3 - Remover elemento do Final\n");
    printf("4 - Remover elemento do Início\n");
    printf("5 - Consultar elemento pela posição\n");
    printf("6 - Consultar elemento pela matrícula\n");
    printf("7 - Exibir lista\n");
    printf("8 - Exibir tamanho da lista\n");
    printf("9 - Sair\n");
    printf("-------------------------------------\n");
    printf("Opção: ");
}

// Apresenta o menu interativo de cadastro.
void show_menu_cadastro(Lista* li, struct Aluno *al) 
{
    printf("\nDigite a Matrícula: ");
    scanf("%d", &al->matricula);
    getchar(); // (Tiago): Captura o '\n' solto no input stream
    printf("Digite o nome: ");
    scanf("%[^\n]*", al->nome);

    printf("Digite a Nota 1: ");
    scanf("%lf", &al->n1);
    printf("Digite a Nota 2: ");
    scanf("%lf", &al->n2);
    printf("Digite a Nota 3: ");
    scanf("%lf", &al->n3);

    getchar();
    
    if ((al->n1 < 1 || al->n1 > 10)  || (al->n2 < 1 || al->n2 > 10) || (al->n3 < 1 || al->n3 > 10))
    {
        printf("-------------------------------------\n");
        printf("Uma nota não pode ser menor que 0 ou maior que 10!\n");
        printf("Pressione ENTER para tentar novamente...\n");
        getchar();
        system("clear");
        return show_menu_cadastro(li, &al);
    }
    else if (consulta_lista_mat(li, al->matricula, al) == 1)
    {
        printf("-------------------------------------\n");
        printf("Uma matrícula não pode ser repetida!\n");
        printf("Pressione ENTER para tentar novamente...\n");
        getchar();
        system("clear");
        return show_menu_cadastro(li, &al);
    }

}

void exibe_consulta(struct Aluno *al)
{
    printf("Matrícula: %d\n", al->matricula);
    printf("Nome: %s\n", al->nome);
    printf("Notas: %.2f %.2f %.2f\n",
        al->n1,
        al->n2,
        al->n3);
    printf("Média das notas: %.2f\n", ((al->n1 + al->n2 + al->n3) / 3));
    printf("---------------------------------------\n");
}

int show_menu_posicao() {
    int pos;

    printf("\nDigite a posição que deseja consultar: ");
    scanf("%d", &pos);

    return pos;
}

int show_menu_matricula() {
    int mat;
    
    printf("\nDigite a matricula que deseja consultar: ");
    scanf("%d", &mat);

    return mat;
}

void mensagem_cadastro_sucesso() {
    printf("Cadastro feito com sucesso! Pressione ENTER para continuar...\n");
    getchar();
}

void mensagem_erro_inesperado()
{
    printf("Ocorreu um erro inesperado! Pressione ENTER para continuar...\n");
    getchar();
}

void mensagem_matricula_encontrada()
{
    printf("Essa matrícula existe! Pressione ENTER para continuar...\n");
    getchar();
}

void mensagem_matricula_nao_encontrada()
{
    printf("Essa matrícula não existe! Pressione ENTER para continuar...\n");
    getchar();
}

void mensagem_posicao_encontrada()
{
    printf("Essa posição existe! Pressione ENTER para continuar...\n");
    getchar();
}

void mensagem_posicao_nao_encontrada()
{
    printf("Essa posição não existe! Pressione ENTER para continuar...\n");
    getchar();
}
// Apresenta a mensagem de saída.
void mensagem_saida() {
    printf("\nAté logo!!!\n");
}

// Apresenta a mensagem de saída padrão para input inválido.
void mensagem_default() {
    printf("\nOpção inválida! Parando execução...\n");
}

void mensagem_enter() {
    printf("Pressione ENTER para continuar.\n");
}