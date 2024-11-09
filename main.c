#include "library_functions.h"
#include "user_functions.h"

int main() {
    book head = NULL; // Inicializa a lista de livros
    int choice, id;
    char book_name[100];

    do {
        printf("\n--------------- MENU ---------------\n");
        printf("1. Adicionar Livro\n");
        printf("2. Remover Livro\n");
        printf("3. Procurar Livro por ID\n");
        printf("4. Procurar Livro por Nome\n");
        printf("5. Listar Livros\n");
        printf("6. Salvar Lista de Livros\n");
        printf("7. Carregar Lista de Livros\n");
        printf("8. Registrar novo utilizador\n");
        printf("9. Listar usuarios\n");
        printf("10. Emprestar livro\n");
        printf("11. Devolver livro\n");
        printf("12. Calcular multa\n");
        printf("0. Sair\n");
        printf("---------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adicionar_livro(&head);
                break;
            case 2:
                printf("Digite o ID do livro a ser removido: ");
                scanf("%d", &id);
                remover_livro(&head, id);
                break;
            case 3:
                printf("Digite o ID do livro a ser procurado: ");
                scanf("%d", &id);
                procura_por_id(head, id);
                break;
            case 4:
                printf("Digite o nome do livro a ser procurado: ");
                // Limpar buffer antes de ler string
                while (getchar() != '\n');
                fgets(book_name, 100, stdin);
                book_name[strcspn(book_name, "\n")] = '\0'; // Remove nova linha
                procura_por_nome(head, book_name);
                break;
            case 5:
                listar_livros(&head);
                break;
            case 6:
                salvar_lista_de_livro(head);
                break;
            case 7:
                carregar_lista_de_livros(&head);
                break;
            case 8:
                printf("Opcao nao esta disponivel ainda.\n");
                break;
            case 9:
                printf("Opcao nao esta disponivel ainda.\n");
                break;
            case 10:
                printf("Opcao nao esta disponivel ainda.\n");
                break;
            case 11:
                printf("Opcao nao esta disponivel ainda.\n");
                break;
            case 12:
                printf("Opcao nao esta disponivel ainda.\n");
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (choice != 0);

    // Liberar memória alocada antes de sair
    book atual = head;
    while (atual != NULL) {
        book temp = atual;
        atual = atual->next;
        free(temp);
    }

    return 0;
}
