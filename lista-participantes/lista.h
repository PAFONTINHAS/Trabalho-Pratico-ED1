#ifndef LISTA_PARTICIPANTES_H
#define LISTA_PARTICIPANTES_H
#include "eventos.h"
#include "participantes.h"
// #include "../Trabalho-Pratico-ED1/eventos/eventos.h"
// #include "../Trabalho-Pratico-ED1/participantes/participantes.h"

// NÓ QUE LIGA TODOS OS PARTICIPANTES A UMA SÓ LISTA (LISTA DINÂMICA)
typedef struct NodeParticipante
{
    // UTILIZA A ESTRUTRUA DENTRO DE participantes/participantes.h
    Participante dadosParticipante;
    struct NodeParticipante* proximo;
} NodeParticipante;

// ESTRUTURA DA LISTA QUE VAI ARMAZENAR OS PARTICIPANTES
typedef struct{
    NodeParticipante* head;
    int quantidade;
} ListaParticipantes; // Controla UMA lista de participantes para UM evento

void inicializarLista(ListaParticipantes* lista);
ListaParticipantes* selecionarLista(ListaParticipantes* lista, int codigoEvento);
void imprimirLista(ListaParticipantes* lista, int codigoEvento, GerenciadorEventos* listaEventos);

void apagarListaParticipantes(ListaParticipantes* lista);

// aqui não possuímos uma lista que possui várias listas de eventos, e sim uma lista para cada evento
// então ao liberar a lista de participantes, quer dizer que estamos liberando a lista de participantes
// de um único evento

#endif
