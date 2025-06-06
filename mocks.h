#ifndef MOCKS_H
#define MOCKS_H
#include <stdio.h>
#include <windows.h>
#include "eventos/eventos.h"
#include "participantes/participantes.h"
#include "lista-participantes/lista_participantes.h"


void preencherEventosEParticipantes(GerenciadorEventos* listaEventos) {

    printf("\nInserindo pré eventos:");
    cadastrarNovoEvento(listaEventos, 1, "Festa Universitaria", 12, 10, 2025, 21, 30, "Bar");
    cadastrarNovoEvento(listaEventos, 2, "Chá das 8", 15, 06, 2025, 8, 00, "Casa da Judite");
    cadastrarNovoEvento(listaEventos, 3, "Agro-hackathon", 10, 10, 2025, 8, 00, "UFPR Agrárias");

    Evento* evento1 = buscarEvento(listaEventos, 1);
    Evento* evento2 = buscarEvento(listaEventos, 2);
    Evento* evento3 = buscarEvento(listaEventos, 3);
    // Adicionando 5 participantes para cada evento de exemplo

    // Evento 1
    inscreverParticipanteEmEvento("Ana Clara", "111", evento1);
    inscreverParticipanteEmEvento("Bruno Silva", "112", evento1);
    inscreverParticipanteEmEvento("Carlos Eduardo", "113", evento1);
    inscreverParticipanteEmEvento("Daniela Souza", "114", evento1);
    inscreverParticipanteEmEvento("Eduardo Lima", "115", evento1);

    // Evento 2
    inscreverParticipanteEmEvento("Fernanda Alves", "211", evento2);
    inscreverParticipanteEmEvento("Gabriel Costa", "212", evento2);
    inscreverParticipanteEmEvento("Helena Martins", "213", evento2);
    inscreverParticipanteEmEvento("Igor Rocha", "214", evento2);
    inscreverParticipanteEmEvento("Juliana Dias", "215", evento2);

    // Evento 3
    inscreverParticipanteEmEvento("Kleber Santos", "311", evento3);
    inscreverParticipanteEmEvento("Larissa Pires", "312", evento3);
    inscreverParticipanteEmEvento("Marcos Vinicius", "313", evento3);
    inscreverParticipanteEmEvento("Natália Ramos", "314", evento3);
    inscreverParticipanteEmEvento("Otávio Teixeira", "315", evento3);

    printf("\nEventos inseridos e participantes adicionados \nRedirecionando para a página inicial.");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(2000);
    system("cls");
}

#endif