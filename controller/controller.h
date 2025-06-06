
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../estruturas.h"
#include <stdbool.h>

// inicio
void menuEscolhas();
//auxiliares
bool validarInputNumerico(const char* input);
int lerInteiroValidado(const char* prompt);
void efeitoDelay(int opcao);
void voltarAoMenu();
// opções
void criarEvento(GerenciadorEventos* listaEventos); // 1
void mostrarTodosEventos(GerenciadorEventos* listaEventos);  // 2
void mostrarEventoEspecifico(GerenciadorEventos* listaEventos); // 3
void verListaParticipantes(GerenciadorEventos* listaEventos); // 4
void removerEvento(GerenciadorEventos* listaEventos);// 5
void inserirParticipante(GerenciadorEventos* listaEventos); // 6
void removerParticipante(GerenciadorEventos* listaEventos); // 7
void gerarRelatorioIndividual(GerenciadorEventos* listaEventos);// 8
void apagarListaEventos(GerenciadorEventos** listaEventos); // 9


#endif
