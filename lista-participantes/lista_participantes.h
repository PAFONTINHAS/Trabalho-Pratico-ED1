#ifndef LISTA_PARTICIPANTES_H
#define LISTA_PARTICIPANTES_H
#include <stdbool.h>
#include "../estruturas.h"



ListaParticipantes* inicializarLista();
// ListaParticipantes* selecionarLista(ListaParticipantes* lista, int codigoEvento);
void imprimirLista(Evento* evento);
NodeParticipante* buscarParticipante(ListaParticipantes* lista, const char* raProcurado); // FEITO POR ISABELLA VICENTE
void apagarListaParticipantes(ListaParticipantes* lista);
void emitirListaPresenca(Evento* evento);
#endif
