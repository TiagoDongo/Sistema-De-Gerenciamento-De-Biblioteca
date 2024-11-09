#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"user_functions.h"

void listar_usuarios(user *head){
    if (*head == NULL){
        printf("ERRO: a biblioteca esta vazia.\n");
        return;
    }

    printf("\n------------ LISTA DE USUARIOS DA BIBLIOTECA ----------\n");
    printf("\t  Nome  \t|\t   Telefone  \t|\t  Livros Emprestados  \t|\t  Livros Devolvidos \t\n");

    user atual = *head;

    while (atual != NULL){
        printf("  %s  |  %d  |  %d  |  %d  \n",atual->nome,atual->telefone,atual->livros_emprestados,atual->livros_devolvidos);

        atual = atual->next;
    }
    
    printf("----------------------------------------\n");
}