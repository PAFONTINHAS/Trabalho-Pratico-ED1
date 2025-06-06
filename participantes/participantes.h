#ifndef PARTICIPANTES_H
#define PARTICIPANTES_H
#include <stdbool.h>
#include "../estruturas.h"



// NodeParticipante* buscarParticipante(struct ListaParticipantes* lista, const char* raProcurado);
bool inscreverParticipanteEmEvento(const char* nome, const char* ra, Evento* evento);
void emitirRelatorioIndividual(const char* RA,  GerenciadorEventos* ge); // todos os eventos que o participante se inscreveu
bool removerParticipanteDeEvento( ListaParticipantes* lista, const char* ra);
void confirmarPresencaParticipante(NodeParticipante* participante);

#endif

