#ifndef LISTA_PARTICIPANTES_H
#define LISTA_PARTICIPANTES_H
#include "participantes/participantes.h"

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

#endif
