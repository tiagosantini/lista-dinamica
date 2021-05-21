// Protótipos das Funções

// Implementação da struct Aluno
struct Aluno
{
    int matricula;
    char nome[30];
    double n1, n2, n3;
};

// Typedef Lista da struct Descritor
typedef struct Descritor Lista;

// Funções de CRUD

void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);

Lista* cria_lista();
int insere_lista_inicio(Lista* li, struct Aluno al);
int insere_lista_final(Lista* li, struct Aluno al);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int consulta_lista_pos(Lista* li, int pos, struct Aluno *al);
int consulta_lista_mat(Lista* li, int mat, struct Aluno *al);
int imprime_lista(Lista* li, struct Aluno *al);

// Funções de exibição de menus e mensagens

int show_menu_posicao();
int show_menu_matricula();
void show_menu_principal();
void show_menu_cadastro(Lista* li, struct Aluno *al);
void exibe_consulta(struct Aluno *al);
void mensagem_cadastro_sucesso();
void mensagem_erro_inesperado();
void mensagem_matricula_encontrada();
void mensagem_matricula_nao_encontrada();
void mensagem_posicao_encontrada();
void mensagem_posicao_nao_encontrada();
void mensagem_saida();
void mensagem_default();