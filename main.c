#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "eventos/eventos.h"
#include "participantes/participantes.h"
#include "lista-participantes/lista_participantes.h"
#include "controller/controller.h"
#include "mocks.h"

int main(){
    // variaveis locais
    int opcao;

    // inicialização de structs
    GerenciadorEventos* listaEventos = inicializarGerenciadorEventos();

    //funcao de mock
    preencherEventosEParticipantes(listaEventos);
    system("cls");

    printf("\n\n\tPágina Inicial");
    printf("\nEscolha uma opcao");
    menuEscolhas();
    opcao = lerInteiroValidado("\nOpcao: ");
    while(opcao != 0){
        // ADICIONEM SUAS FUNÇÕES NOS CASES
        switch (opcao){
            case 1:
                criarEvento(listaEventos);
            break;
            case 2:
                mostrarTodosEventos(listaEventos);
            break;
            case 3:
                mostrarEventoEspecifico(listaEventos);
            break;
            case 4:
                verListaParticipantes(listaEventos);
            break;
            case 5:
                removerEvento(listaEventos);
            break;
            case 6:
                inserirParticipante(listaEventos);
            break;
            case 7:
                removerParticipante(listaEventos);
            break;
            case 8:
                gerarRelatorioIndividual(listaEventos);
            break;
            case 9:
                preencherListaPresenca(listaEventos);
            break;
            case 10:
                gerarRelatorioPresenca(listaEventos);
            break;
            case 11:
                apagarListaEventos(&listaEventos);
            break;
            case 0:
                printf("Saindo do sistema...");
                Sleep(2000);
            break;
        }
        system("cls");
        // Exemplo de correção no final do loop while:
        printf("\nEscolha uma opcao:");
        menuEscolhas();
        opcao = lerInteiroValidado("\nOpcao: ");


    }

    printf("Sistema Finalizado.\nPressione para sair...");
    getchar(); // Espera pelo Enter do usuário


}

