#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../estruturas.h"
#include "lista_participantes.h"
#include "../eventos/eventos.h"

//Procedimento para inicializar lista de participantes, feito por Clarissa Morita
ListaParticipantes* inicializarLista(){
    ListaParticipantes* lista = (ListaParticipantes*) malloc(sizeof(ListaParticipantes));
    NodeParticipante* inicio = (NodeParticipante*) malloc(sizeof(NodeParticipante));

    lista->head = inicio;
    lista->head->proximo = NULL;
    lista->quantidade = 0;

    return lista;
}

//Função para buscar e imprimir lista de participantes, feita por Giovanna D
void imprimirLista(Evento* evento){
    // Evento* evento = buscarEvento(listaEventos, codigoEvento);
    ListaParticipantes* listaEvento = evento->inscritos;

    if(evento->inscritos->head->proximo == NULL){
        printf("\nLista de inscritos vazia!\n");
        printf("\n----------------------------------\n");
        return;
    }

    NodeParticipante* participante = listaEvento->head->proximo;

    int i = 1;
    printf("\nEVENTO : %s, NUM DE PARTICIPANTES: %d\n\n\tLISTA DE PARTICIPANTES:", evento->nome, listaEvento->quantidade);
    while(participante != NULL){
        printf("\n%d. Nome: %s, RA: %s", i, participante->dadosParticipante.nome, participante->dadosParticipante.ra);
        participante = participante->proximo;
        i++;
    }
    if(participante == NULL){
        printf("\n------------Fim-da-lista--------------\n");
    }
}

//--------------FUNÇÃO QUE BUSCA PARTICIPANTE POR RA, FEITO POR ISABELLA VICENTE --------------------
NodeParticipante* buscarParticipante(ListaParticipantes* lista, const char* raProcurado){
    //bool para retornar true se deu certo a remoção e false se não
    //parâmetros serão a lista onde procuro e o que procuro, declarando-os
    NodeParticipante* atual=lista->head->proximo;
    //declaro atual do tipo NodeParticipante dizendo para ele começar em uma valor real do começo da lista

    while(atual != NULL && strcmp(atual->dadosParticipante.ra, raProcurado) != 0){
    //atual vai andar e passar o dado para anterior até achar o que quer
        atual=atual->proximo;
        //atual anda para o proximo elemento, e ler o dado
    }
    if(atual==NULL){
        return NULL;
    }
    return atual;
}


void apagarListaParticipantes(ListaParticipantes* lista) {
    if (lista == NULL) return;   //verifica se a lista esta vazia, se sim então retorna fazendo nada

    NodeParticipante* atual = lista->head;  //caso nao, cria um ponteiro para começar pelo primeiro nó(head)
    NodeParticipante* proximo; // Cria outro ponteiro para armazenar temporariamente o próximo nó antes de liberar o atual

    while (atual != NULL) {   //loop para percorrer todos os elementos
        proximo = atual->proximo; //Armazena o próximo nó antes de liberar o atual.
        free(atual); //libera a memória para o nó atual
        atual = proximo;// vai para o próximo nó
    }

    lista->head = NULL; // quando terminar o loop(liberou a memoria de todos os nós), a lista é sinalizade como vazia
    lista->quantidade = 0;  //lista sem nenhum elemento, atualiza o campo quantidade
}
