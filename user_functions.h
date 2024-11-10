#ifndef LIBRARY_FUNCTIONS_H_INCLUDED
#define LIBRARY_FUNCTIONS_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Biblioteca.h"

//estrutura de dados do tipo lista para guardar as informação sobre os utilizadores da biblioteca
/*
typedef struct usuario{
    char nome[100];
    int telefone;
    int livros_emprestados;
    int livros_devolvidos;
    int book_id;
    char data_emprestimo[11];
    char data_devolucao[11];
    float multa;
    struct usuario *next;
} *user;
*/

//função que ira calcular a multa por cada dia de atraso depois da data de devolução do livro
void calcular_multa(user *head, char *nome_usuario, int book_id, char *data_devolucao);

//função responsavel por fazer o emprestimo de livros aos utilizadores
void emprestimo_de_livro(user *head, char *data_emprestimo, int book_id, char *nome_usuario,char *data_devolucao);

//função responsavel por fazer o registro de devoluções dos livros e que vai utilizar a função calcular_multa
void devolucao_de_livro(user *head, int book_id, char *nome_usuario,char *data_devolucao);

//função que vai fazer o registro do utilizador e caso ja tenha registro ira atualizar os dados
void cadastro_usuario(user *head);

//função que ira listar todos os utilizadores da biblioteca
void listar_usuarios(user *head);

#endif