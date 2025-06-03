#include <stdio.h>
#include <stdlib.h>
#include "eventos.h"
#include "lista.h"
// #include "participantes.h"

// #include "eventos/eventos.h"
// #include "participantes/participantes.h"
// #include "eventos/eventos.h"
// #include "lista-participantes/lista.h"
// #include "participantes/participantes.h"


/*
menu:
    1 - criar evento cadastrarNovoEvento()
    2 - inscrever participante inscreverParticipante()
    3 - listar todos os participantes confirmados de todos os evento imprimirLista(evento)
    4 - remover participante bool removerParticipante(evento, participante)
    5 - emitir relatorio, emitirRelatorio(ra,)->buscarparticipante
    6 - emitir lista de presença de todos os participantes de um evento específico listaPresencaDeEvento()
    7 - finalizar evento //opcional
    8 - cancelar //opcional
*/
int main(){
    printf("Início do sistema");

    // ListaParticipantes* listaParticipantes;
    // Participante* participante;
    Evento* evento;


    GerenciadorEventos* listaEvento = inicializarGerenciadorEventos();
    cadastrarNovoEvento(listaEvento, 01, "Festa na casa do seu zé", 12, 06, 2029, 12, 40, "Casa do seu zé");
    evento = buscarEvento(listaEvento, 01);
    imprimirLista(evento->inscritos, evento->codigo, listaEvento);




}
