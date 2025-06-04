#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "eventos.h"
// #include "lista.h"
// #include "participantes.h"
// #include "../Trabalho-Pratico-ED1/eventos/eventos.h"
// #include "../Trabalho-Pratico-ED1/lista-participantes/lista.h"
// #include "../Trabalho-Pratico-ED1/participantes/participantes.h"


//Procedimento para inicializar lista de participantes
void inicializarLista(ListaParticipantes* lista){
    Participante* inicio = (Participante*) malloc(sizeof(Participante));

    lista->head = inicio;
    lista->head->proximo = NULL;
    lista->quantidade = 0;
}

void imprimirLista(ListaParticipantes* lista, int codigoEvento, GerenciadorEventos* listaEventos){
    Evento* evento = buscarEvento(listaEventos, codigoEvento);
    ListaParticipantes* listaEvento = selecionarLista(lista, codigoEvento);

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
