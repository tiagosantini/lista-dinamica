#include <stdio.h>
#include <stdlib.h>

#include "../headers/ListaDinEncadDesc.h"

int main() {
    
    Lista* li = cria_lista();
    int opcao;
    int mat, pos;
    int i = 1;

    // Declarando a struct para armazenar e inserir elementos do tipo aluno
    struct Aluno dados_aluno;

    while (i == 1) 
    {
        show_menu_principal();
        scanf("%d", &opcao);
        switch (opcao) {
                case 1:
                        if (show_menu_cadastro(li, &dados_aluno) == 1)
                        {
                                if (insere_lista_final(li, dados_aluno) == 1)
                                        mensagem_cadastro_sucesso();
                        }
                        else
                                mensagem_erro_inesperado();
                        break;
                case 2:
                        show_menu_cadastro(li, &dados_aluno);
                        if (insere_lista_inicio(li, dados_aluno) == 1)
                                mensagem_cadastro_sucesso();
                        else
                                mensagem_erro_inesperado();
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

                        if (consulta_lista_pos(li, pos, &dados_aluno) == 1)
                                mensagem_posicao_encontrada();
                        else
                                mensagem_posicao_nao_encontrada();
                        break;
                case 6:
                        mat = show_menu_matricula();
                        
                        if (consulta_lista_mat(li, mat, &dados_aluno) == 1)
                                mensagem_matricula_encontrada();
                        else
                                mensagem_matricula_nao_encontrada();
                        break;
                case 7:
                        if (imprime_lista(li, &dados_aluno) == 2) {
                                printf("Lista vazia! Pressione ENTER para continuar.\n");
                        }
                        getchar();
                        break;
                case 8:
                        printf("Tamanho da lista: %d\n", tamanho_lista(li));
                        printf("Pressione ENTER para continuar.\n");
                        getchar();
                        break;
                case 9:
                        mensagem_saida();
                        i--;
                        break;
                default:
                        mensagem_default();
                        i--;
                        break;
        }
        getchar();
    }

    libera_lista(li);

    return 0;
}