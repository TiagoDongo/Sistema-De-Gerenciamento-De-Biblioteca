#include"user_functions.h"

void cadastro_usuario(user *head){
    //alocação de memoria para um novo utilizador
    user novo_usuario = (user)malloc(sizeof(struct usuario));

    //verificação da alocação se foi bem sucedida ou não
    if (novo_usuario == NULL){
        printf("ERRO: ao alocar memoria!\n");
        return;
    }
    
    //inserção do dados do usuario
    printf("Digite o nome a ser registrado: ");
    fgets(novo_usuario->nome, 100, stdin);
    novo_usuario->nome[strcspn(novo_usuario->nome, "\n")] = '\0';

    if (strlen(novo_usuario->nome) == 0){
        printf("ERRO: Nome não pode ser vazio!\n");
        free(novo_usuario); // Libera a memória alocada
        return;
    }

    printf("Digite o telefone: ");
    scanf("%d", &novo_usuario->telefone);
    getchar();

    //inicialização das outras variaveis com valores padrão
    novo_usuario->livros_emprestados = 0;
    novo_usuario->livros_devolvidos = 0;
    strcpy(novo_usuario->data_emprestimo, "");
    strcpy(novo_usuario->data_devolucao, "");
    novo_usuario->multa = 0.0;
    novo_usuario->next = NULL;

    // Inserção no início da lista encadeada
    if (*head == NULL) {
        // Se a lista está vazia, então é o primeiro e ele aponta para ele mesmo
        *head = novo_usuario;
        novo_usuario->next = *head;  // formação da lista circular aqui
    } 
    else {
        // Se a lista não está vazia, insere no início e ajusta o ponteiro do último nó
        novo_usuario->next = *head;
        *head = novo_usuario;

        // Percorre até o último nó da lista e ajusta o ponteiro next para formar o ciclo
        user atual = *head;
        while (atual->next != *head) {  // Percorre até o nó que aponta para o head
            atual = atual->next;
        }
        // O último nó agora aponta para o novo head, formando uma lista circular
        atual->next = *head;
    }

    printf("Usuário %s registrado com sucesso!\n", novo_usuario->nome);
}

void listar_usuarios(user *head){
    if (*head == NULL){
        printf("ERRO: a biblioteca esta vazia.\n");
        return;
    }

    printf("\n------------ LISTA DE USUARIOS DA BIBLIOTECA ----------\n");
    printf("\t  Nome  \t|\t   Telefone  \t|\t  Livros Emprestados  \t|\t  Livros Devolvidos \t\n");

    user atual = *head;

    do
    {
        printf("  %s  |  %d  |  %d  |  %d  \n",atual->nome,atual->telefone,atual->livros_emprestados,atual->livros_devolvidos);

        atual = atual->next;
    } while (atual != *head);
    
    
    printf("----------------------------------------\n");
}