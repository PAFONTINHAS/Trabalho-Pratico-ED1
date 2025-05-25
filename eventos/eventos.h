#ifndef EVENTOS_H
#define EVENTOS_H
#include "lista-participantes/lista.h"

// ESTRUTURA DE DATA E HORA PARA CADA EVENTO
typedef struct{
    int dia, mes, ano;
    int hora, minuto;

} DataEvento;

// ESTRUTURA DO EVENTO
typedef struct {
    int codigo;
    char nome[100];
    DataEvento dataEvento;
    char localEvento[100];
    ListaParticipantes inscritos; // cada evento tem uma ListaParticipantes

} Evento;


//NÓ LISTA DE EVENTOS
typedef struct NodeEvento{
    Evento* evento; // PONTEIRO PARA UM OBJETO EVENTO
    struct NodeEvento* proximo;

} NodeEvento;

// ESTRUTURA DE CONTROLE PARA A LISTA PRINCIPAL DE TODOS OS EVENTOS
// LISTA COM CABEÇALHO
typedef struct{
    NodeEvento* head; // NodeEvento aponta para um Evento
    int quantidadeEventos;
} GerenciadorEventos;
#endif
