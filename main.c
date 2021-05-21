#include <stdio.h>
#include <stdlib.h>

#include "ListaDinEncadDesc.h"

int main() {
    
    Lista* li = cria_lista();
    int opcao;
    int mat, pos;
    int i = 1;

    // Declarando a struct para armazenar e inserir elementos do tipo aluno
    struct Aluno dados_aluno;

    while (i == 1) {

        // system("clear");
        show_menu_principal();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                    show_menu_cadastro(&dados_aluno);
                    if (insere_lista_final(li, dados_aluno) == 1)
                        printf("Cadastro feito com sucesso! Pressione ENTER para continuar.\n");

                    getchar();
                    break;
            case 2:
                    show_menu_cadastro(&dados_aluno);
                    insere_lista_inicio(li, dados_aluno);
                    break;
            case 3:
                    if (remove_lista_final(li) == 1)
                        printf("Removido com sucesso! Pressione ENTER para continuar.\n");

                    getchar();
                    break;
            case 4:
                    if (remove_lista_inicio(li) == 1)
                        printf("Removido com sucesso! Pressione ENTER para continuar.\n");

                    getchar();
                    break;
            case 5:
                    pos = show_menu_posicao();
                    consulta_lista_pos(li, pos, &dados_aluno);
                    break;
            case 6:
                    mat = show_menu_matricula();
                    consulta_lista_mat(li, mat, &dados_aluno);
                    break;
            case 7:
                    show_mensagem_default();
                    break;
            case 8:
                    if (imprime_lista(li, &dados_aluno) == 2) {
                        printf("Lista vazia! Pressione ENTER para continuar.\n");
                    }
                    getchar();
                    break;
            case 9:
                    printf("Tamanho da lista: %d\n", tamanho_lista(li));
                    printf("Pressione ENTER para continuar.\n");
                    getchar();
                    break;
            case 10:
                    show_mensagem_saida();
                    i--;
                    break;
            default:
                    show_mensagem_default();
                    i--;
                    break;
        }
        getchar();
    }

    libera_lista(li);

    return 0;
}