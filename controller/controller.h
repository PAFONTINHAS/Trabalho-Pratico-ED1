
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../estruturas.h"



void menuEscolhas();
void criarEvento(GerenciadorEventos* listaEventos);
void mostrarEventoEspecifico(GerenciadorEventos* listaEventos);
void verListaParticipantes(GerenciadorEventos* listaEventos);
void removerParticipante(GerenciadorEventos* listaEventos);
void inserirParticipante(GerenciadorEventos* listaEventos);
void gerarRelatorioIndividual(GerenciadorEventos* listaEventos);
void mostrarTodosEventos(GerenciadorEventos* listaEventos);
void removerEvento(GerenciadorEventos* listaEventos);
void apagarListaEventos(GerenciadorEventos** listaEventos);


#endif