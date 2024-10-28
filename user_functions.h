#ifndef LIBRARY_FUNCTIONS_H_INCLUDED
#define LIBRARY_FUNCTIONS_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"library_functions.h"

typedef struct usuario{
    char nome[100];
    int book_id;
    char data_emprestimo[11];
    char data_devolucao[11];
    float multa;
    struct usuario *next;
} *user;


void calcular_multa(user *head, char *nome_usuario, int book_id);
//estas funções precisam de ser revistas pq ainda estão na fase de prototipo
//void emprestimo_de_livro(user *head, book *book_list, int book_id, char *nome_usuario);
//void devolucao_de_livro(user *head, book *book_list, int book_id, char *nome_usuario);
void cadastro_usuario(user *head);
void listar_usuarios(user head);

#endif