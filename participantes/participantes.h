#ifndef PARTICIPANTES_H
#define PARTICIPANTES_H

#include <stdbool.h>
#include "lista.h"
#include "eventos.h"

// ESTRUTURA DOS PARTICIPANTES
typedef struct {
    char ra[20];
    char nome[100];
    int presente; // rand() % 1: entre 0 e 1. OPCIONAL(talvez)
} Participante;


// bool buscarParticipante(char RA);
// bool inscreverParticipantes(ListaParticipantes* lista, Participante* participante);
// bool removerParticipantes(ListaParticipantes* lista, char RA);
// void emitirRelatorioIndividual(char RA, GerenciadorEventos* ge); // todos os eventos que o participante se inscreveu

#endif
