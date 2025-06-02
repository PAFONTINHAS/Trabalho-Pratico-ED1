#ifndef EVENTOS_H
#define EVENTOS_H
#include "lista-participantes/lista.h"
#include <stdbool.h>

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


GerenciadorEventos* inicializarGerenciadorEventos();
void cadastrarNovoEvento(GerenciadorEventos* listaEventos, int codigo, const char* nome, int dia, int mes, int ano, int hora, int minuto, const char* local);
bool validarEvento(GerenciadorEventos* listaEventos, Evento* evento);
void buscarEvento(GerenciadorEventos* listaEventos, int codigoEvento);
bool cancelarEvento(GerenciadorEventos* listaEventos, int codigoEvento);
void destruirListaEventos(GerenciadorEventos* listaEventos);

// MANIPULADORES DE DATA
bool ehAnoBissexto(int ano);
bool validarData(int dia, int mes, int ano, int hora, int minuto);

#endif


// buscarEventosPorData()
// buscarEventosPorLocal()
// alterarDataEvento()
// realizarEvento()
// finalizarEvento() : gerar lista de presença?

