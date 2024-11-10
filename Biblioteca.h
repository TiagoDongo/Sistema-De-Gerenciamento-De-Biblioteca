// biblioteca.h
#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

// Declaração da estrutura do tipo lista para os livros
typedef struct biblioteca {
    int id;
    char titulo[100];
    char autor[100];
    int ano_publicacao;
    int edicao;
    int disponivel;  // 1 para disponível, 0 para não disponível
    struct biblioteca *next;
} *book;

// Declaração da estrutura do tipo lista para os usuários
typedef struct usuario {
    char nome[100];
    int telefone;
    int livros_emprestados;
    int livros_devolvidos;
    int book_id;  // ID do livro emprestado
    char data_emprestimo[11];
    char data_devolucao[11];
    float multa;
    struct usuario *next;
} *user;

#endif
