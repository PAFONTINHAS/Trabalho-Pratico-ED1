#ifndef LISTA_PARTICIPANTES_H
#define LISTA_PARTICIPANTES_H
#include <stdbool.h>
#include "../estruturas.h"



ListaParticipantes* inicializarLista();
// ListaParticipantes* selecionarLista(ListaParticipantes* lista, int codigoEvento);
void imprimirLista(Evento* evento);
NodeParticipante* buscarParticipante(ListaParticipantes* lista, const char* raProcurado); // FEITO POR ISABELLA VICENTE
void apagarListaParticipantes(ListaParticipantes* lista);


// aqui não possuímos uma lista que possui várias listas de eventos, e sim uma lista para cada evento
// então ao liberar a lista de participantes, quer dizer que estamos liberando a lista de participantes
// de um único evento

#endif
