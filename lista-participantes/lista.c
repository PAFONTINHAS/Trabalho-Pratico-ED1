#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "eventos.h"
#include "lista.h"
#include "participantes.h"
// #include "../Trabalho-Pratico-ED1/eventos/eventos.h"
// #include "../Trabalho-Pratico-ED1/lista-participantes/lista.h"
// #include "../Trabalho-Pratico-ED1/participantes/participantes.h"


//Procedimento para inicializar lista de participantes
void inicializarLista(ListaParticipantes* lista, int codigoEvento){
    Participante* inicio = (Participante*) malloc(sizeof(Participante));
    
    lista->head->codigoEvento = codigoEvento;
    lista->head = inicio;
    lista->head->proximo = NULL;
    lista->quantidade = 0;
}

void imprimirLista(ListaParticipantes* lista, int codigoEvento, GerenciadorEventos* listaEventos){
    Evento* evento = buscarEvento(listaEventos, codigoEvento);

    if(evento->inscritos->head == NULL){
        printf("Lista de inscritos vazia!");
        return;
    }

    NodeParticipante* participante = listaEvento->head->proximo;

    printf("\nEVENTO : %s, NUM DE PARTICIPANTES: %d\nLISTA DE PARTICIPANTES", evento->nome, listaEvento->quantidade);
    while(participante != NULL){
        printf("%s, RA: %d\n", participante->dadosParticipante.nome, participante->dadosParticipante.ra);
        participante = participante->proximo;
    }
}

//implementação da função apagarListaParticipantes

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
