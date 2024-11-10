#ifndef LIBRARY_FUNCTIONS_H_INCLUDED
#define LIBRARY_FUNCTIONS_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Biblioteca.h"

//estrutura de dados do tipo lista para guardar as informação sobre os livros
/*
typedef struct biblioteca{
    int id;
    char titulo[100];
    char autor[100];
    int ano_publicacao;
    int edicao;
    int disponivel;  //1 para disponivel e 0 para não disponivel
    struct biblioteca *next;
} *book;
*/

//função para adicionar um livro a lista
void adicionar_livro(book *head); //pronto

//função para remover um livro da lista
void remover_livro(book *head, int id); //pronto

//procura um livro na lista pelo titulo do livro
void procura_por_nome(book head, char *book_name); //pronto

//procura um livro na lista pelo ID do livro
void procura_por_id(book head, int book_id); //pronto

//lista todos os livros junto coos seus dados
void listar_livros(book *head); //pronto

//salva a lista de livros em um arquivo txt
void salvar_lista_de_livro(book head);

//carrega o arquivo txt que contem a lista de livros
void carregar_lista_de_livros(book *head);

// Função auxiliar para verificar se o ID do livro já existe
int livroExiste(book head, int id); //pronto

#endif
