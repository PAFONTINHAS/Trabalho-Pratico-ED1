#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
// ESTRUTURA DOS PARTICIPANTES
typedef struct {
    char ra[20];
    char nome[100];
    int presente; // rand() % 1: entre 0 e 1. OPCIONAL(talvez)
} Participante;

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

struct ListaParticipantes;

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
    ListaParticipantes* inscritos; // cada evento tem uma ListaParticipantes
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
