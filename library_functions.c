#include"library_functions.h"

int livroExiste(book head, int id) {
    book atual = head;
    while (atual != NULL) {
        if (atual->id == id) {
            return 1; // ID já existe
        }
        atual = atual->next;
    }
    return 0; // ID não existe
}

void adicionar_livro(book *head){
    //alocação de memoria para o novo livro
    book new_book = (book)malloc(sizeof(struct biblioteca));

    //verificação da alocação se foi bem sucedida
    if (new_book == NULL){
        printf("FALHA: Memoria insuficiente para adicionar o livro!\n");
        return;
    }

    //inserção dos dados do livro
    printf("Introduza o ID do livro: ");
    if (scanf("%d",&new_book->id) != 1){
        printf("ERRO: ID invalido!\n");
        free(new_book);
        return;
    }
    
    // Verificar se o ID já existe (função auxiliar)
    if (livroExiste(*head, new_book->id)) {
        printf("Erro: ID do livro ja existe!\n");
        free(new_book);
        return;
    }

    // Limpar buffer de entrada para evitar problemas com fgets
    while(getchar() != '\n');

    printf("Digite o titulo do livro: ");
    fgets(new_book->titulo, 100, stdin);
    new_book->titulo[strcspn(new_book->titulo, "\n")] = '\0';

    // Verificar se o título é válido
    if (strlen(new_book->titulo) == 0) {
        printf("Erro: O titulo do livro nao pode ser vazio!\n");
        free(new_book);
        return;
    }

    printf("Digite o nome do autor do livro: ");
    fgets(new_book->autor, 100, stdin);
    new_book->autor[strcspn(new_book->autor, "\n")] = '\0';

    // Verificar se o autor é válido
    if (strlen(new_book->autor) == 0) {
        printf("Erro: O nome do autor nao pode ser vazio!\n");
        free(new_book);
        return;
    }

    printf("Digite o ano de publicação: ");
    if (scanf("%d", &new_book->ano_publicacao) != 1) {
        printf("Erro: Ano de publicacao invalido!\n");
        free(new_book);
        return;
    }
    

    printf("Digite a edicao do livro: ");
    if (scanf("%d", &new_book->edicao) != 1) {
        printf("Erro: Edição de publicação inválido!\n");
        free(new_book);
        return;
    }

    //inicializar o livro como disponivel
    new_book->disponivel = 1;

    //inserir o novo livro no inicio da lista
    new_book->next = *head;
    *head = new_book;

    printf("SUCESSO: O livro %s foi adionado a biblioteca.\n", new_book->titulo);
}

void listar_livros(book *head){
    if (*head == NULL){
        printf("ERRO: a biblioteca esta vazia.\n");
        return;
    }

    printf("------------ LISTA DE LIVROS ----------\n");
    printf("\t ID \t|\t Titulo \t|\t Autor \t|\t Ano \t|\t Edicao \t\n");

    book atual = *head;

    while (atual != NULL){
        printf("  %d  |  %s  |  %s  |  %d  |  %d  \n",atual->id,atual->titulo,atual->autor,atual->ano_publicacao,atual->edicao);

        atual = atual->next;
    }
    
    printf("----------------------------------------\n");
}

void procura_por_nome(book head, char *book_name) {
    book var_aux = head;
    
    while (var_aux != NULL){
        if (strcmp(var_aux->titulo, book_name) == 0){
        printf("Livro encontrado:\n");
        printf("ID: %d\n", var_aux->id);
        printf("Titulo: %s\n", var_aux->titulo);
        printf("Autor: %s\n", var_aux->autor);
        printf("Ano: %d\n", var_aux->ano_publicacao);
        printf("Edicao: %d\n", var_aux->edicao);
        printf("Disponivel: %s\n", (var_aux->disponivel == 1) ? "Sim" : "Não");
        return;
        }
        var_aux = var_aux->next;
    }
    printf("Livro nao encontrado.\n");
}

void procura_por_id(book head, int book_id){
    book var_aux = head;;
    while(var_aux != NULL){
        if (var_aux->id == book_id){
            printf("Livro encontrado:\n");
            printf("ID: %d\n", var_aux->id);
            printf("Titulo: %s\n", var_aux->titulo);
            printf("Autor: %s\n", var_aux->autor);
            printf("Ano: %d\n", var_aux->ano_publicacao);
            printf("Edicao: %d\n", var_aux->edicao);
            printf("Disponivel: %s\n", (var_aux->disponivel == 1) ? "Sim" : "Não");
            return;
        }
        var_aux = var_aux->next;
    }
    printf("Livro nao encontrado.\n");
}

void remover_livro(book *head, int id){
    //verificação se a lista esta vazia
    if (*head == NULL){
        printf("ERRO: A biblioteca esta vazia. Nenhum livro para remover.\n");
        return;
    }

    book atual = *head;
    book anterior = NULL;

    //percorre a lista para achar o livro com o ID correspondente
    while (atual != NULL){
        if (atual->id == id){
            //se o livro a ser removido for o primeiro da lista
            if (anterior == NULL){
                *head = atual->next;
            }
            else{
                //liga o no anterior ao proximo e remove o no atual
                anterior->next = atual->next;
            }

            printf("SUCESSO: O livro de ID: %d foi removido da biblioteca.\n", id);
            free(atual); //libera a memoria do livro removido
            return;
        }
        
        anterior = atual;
        atual = atual->next;
    }
    printf("ERRO: Livro de ID: %d nao foi encontrado  ou ja foi removida da biblioteca.\n",id);
}

void salvar_lista_de_livro(book head){
    //abertura do arquivo "Biblioteca.txt" em modo de escrita
    FILE *file = fopen("Biblioteca.txt", "w");

    //verificação se o arquivo foi aberto corretamente
    if (file == NULL){
        printf("EERO: arquivo nao foi aberta corretamente para salvar os livro.\n");
        return;
    }
    
    //cabeçalho do arquivo
    fprintf(file, "ID\tAutor\t\t\tTítulo\t\t\tAno\tEdição\tDisponível\n");
    fprintf(file, "---------------------------------------------------------------\n");

    //percorre a lista de livros para salvar as informações no arquivo
    book atual = head;
    while (atual != NULL){
        fprintf(file, "\t%d\t%s\t\t%s\t\t%d\t%d\t%s\t\n",atual->id,atual->autor,atual->titulo,atual->ano_publicacao,atual->edicao,atual->disponivel ? "Sim" : "Não");

        atual = atual->next;
    }
    
    //fechar o arquivo apos salvar as informações
    fclose(file);

    printf("SUCESSO: lista de livros salva no arquivo 'Biblioteca.txt'.\n");
}

void carregar_lista_de_livros(book *head) {
    FILE *file = fopen("Biblioteca.txt", "r");
    if (file == NULL) {
        printf("ERRO: Nao foi possível abrir o arquivo!\n");
        return;
    }

    // Variáveis temporárias para armazenar os dados do livro
    int id, ano_publicacao, edicao, disponivel;
    char autor[100], titulo[100];

    // Ler cada linha do arquivo e adicionar à lista
    // Ignora o cabeçalho
    fscanf(file, "%*[^\n]\n"); // Ignora a primeira linha (cabeçalho)

    while (fscanf(file, "%d\t%[^\t]\t%[^\t]\t%d\t%d\t%d\n", &id, autor, titulo, &ano_publicacao, &edicao, &disponivel) == 6) {
        // Aqui você irá criar um novo nó para a lista e preencher com os dados lidos do arquivo
        book new_book = (book)malloc(sizeof(struct biblioteca));
        
        if (new_book == NULL) {
            printf("FALHA: Memoria insuficiente para carregar o livro!\n");
            fclose(file);
            return;
        }

        // Atribuindo os dados lidos ao novo livro
        new_book->id = id;
        strcpy(new_book->autor, autor);
        strcpy(new_book->titulo, titulo);
        new_book->ano_publicacao = ano_publicacao;
        new_book->edicao = edicao;
        new_book->disponivel = disponivel; // Considerando que 1 é Sim e 0 é Não
        new_book->next = *head; // Inserindo o novo livro no início da lista
        *head = new_book; // Atualizando o head para apontar para o novo livro

        // A leitura continua até que não haja mais livros no arquivo
    }

    // Fecha o arquivo após carregar as informações
    fclose(file);
    printf("SUCESSO: lista de livros carregada do arquivo 'Biblioteca.txt'.\n");
}
