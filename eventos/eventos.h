#ifndef EVENTOS_H
#define EVENTOS_H
#include <stdbool.h>
#include "../estruturas.h"


GerenciadorEventos* inicializarGerenciadorEventos();
void cadastrarNovoEvento(GerenciadorEventos* listaEventos, int codigo, const char* nome, int dia, int mes, int ano, int hora, int minuto, const char* local);
bool validarEvento(GerenciadorEventos* listaEventos, Evento* evento);
Evento* buscarEvento(GerenciadorEventos* listaEventos, int codigoEvento);
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

