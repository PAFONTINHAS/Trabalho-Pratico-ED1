#include <stdio.h>
#include <stdlib.h>
#include "eventos/eventos.h"
// #include "lista-participantes/lista_participantes.h"



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
    printf("\nInício do sistema\n");

    // ListaParticipantes* listaParticipantes;
    // Participante* participante;
    Evento* evento;


    GerenciadorEventos* listaEvento = inicializarGerenciadorEventos();
    cadastrarNovoEvento(listaEvento, 01, "Festa na casa do seu zé", 12, 06, 2029, 12, 40, "Casa do seu zé");
    cadastrarNovoEvento(listaEvento, 02, "Festa na casa da maria", 12, 06, 2029, 12, 40, "Casa da Maria");
    evento = buscarEvento(listaEvento, 01);
    evento = buscarEvento(listaEvento, 02);
    cancelarEvento(listaEvento, 02);
    evento = buscarEvento(listaEvento, 02);

    // imprimirLista(evento->inscritos, evento->codigo, listaEvento);




}
