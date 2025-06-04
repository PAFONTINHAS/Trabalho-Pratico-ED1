#ifndef PARTICIPANTES_H
#define PARTICIPANTES_H
#include "./lista-participantes/lista.h"
#include <stdbool.h>
#include "lista.h"
#include "eventos.h"

#include <stdbool.h>


// ESTRUTURA DOS PARTICIPANTES
typedef struct {
    char ra[20];
    char nome[100];
    int presente; // rand() % 1: entre 0 e 1. OPCIONAL(talvez)
} Participante;


NodeParticipante* buscarParticipante(ListaParticipantes* lista, const char* raProcurado);
bool inscreverParticipantes(ListaParticipantes* lista, Participante* participante);
bool removerParticipantes(ListaParticipantes* lista, const char* ra);
void emitirRelatorioIndividual(const char* RA, GerenciadorEventos* ge); // todos os eventos que o participante se inscreveu

#endif
