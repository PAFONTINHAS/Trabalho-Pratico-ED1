#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "eventos/eventos.h"

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
void criarEvento(GerenciadorEventos* listaEventos);
void mostrarEventoEspecifico(GerenciadorEventos* listaEventos);

void menuEscolhas(){
    printf("\n1. Criar um evento");
    printf("\n2. Mostrar todos os eventos cadastrados");
    printf("\n3. Buscar evento específico");
    printf("\n4. Ver participantes de um evento");
    printf("\n5. Remover um evento");
    printf("\n6. Remover participantes de um evento");
    printf("\n7. Inserir participantes em um evento");
    printf("\n8. Emitir relatório de participacao individual");
    printf("\n9. Emitir relatório de presenca");
}

int main(){
    // variaveis locais
    int opcao;

    // inicialização de structs
    GerenciadorEventos* listaEventos = inicializarGerenciadorEventos();
    Evento* evento;


    printf("\nPágina Inicial");
    printf("\nEscolha uma opcao:");
    menuEscolhas();
    printf("\nOpcao: ");
    scanf("%d", &opcao);
    while(opcao != 0){

        switch (opcao){
            case 1:
                criarEvento(listaEventos);
            break;
            // case 2:
            //     mostrarTodosEventos(listaEventos);
            // break;
            case 3:
                mostrarEventoEspecifico(listaEventos);
            break;
            // case 4:
            // break;
            // case 5:
            // break;
            // case 6:
            // break;
            // case 7:
            // break;
            // case 8:
            // break;
            case 0:
                printf("Saindo do sistema...");
                Sleep(2000);
            break;
        }


    }

    printf("Sistema Finalizado");
    scanf("");


}

// funcao de criar evento
void criarEvento(GerenciadorEventos* listaEventos){
    int codigo;
    char nome[100];
    int dia, mes, ano;
    int hora, minuto;
    char local[100];

    printf("\n\tOpcao 1: Criar um evento");
    printf("\n\nDigite o codigo: ");
    scanf("%d", &codigo);
    printf("Digite o nome do evento: ");
    getchar(); // Limpa o '\n' deixado pelo scanf anterior
    fgets(nome, sizeof(nome), stdin);
    printf("dia:");
    scanf("%d", &dia);
    printf("mes:");
    scanf("%d", &mes);
    printf("ano:");
    scanf("%d", &ano);
    printf("hora:");
    scanf("%d", &hora);
    printf("minuto:");
    scanf("%d", &minuto);
    printf("Local do evento:");
    getchar(); // Limpa o '\n' deixado pelo scanf anterior
    fgets(local, sizeof(local), stdin);

    printf("Criando o evento...\n");
    Sleep(2000);


    cadastrarNovoEvento(listaEventos, codigo, nome, dia, mes, ano, hora, minuto, local);

    printf("\nVoltando para a página inicial...\n");
    Sleep(2000);
    printf("\n/-----------------------------------------------------------------------------/\n");
    main();
}

void mostrarTodosEventos(GerenciadorEventos* listaEventos){
    // CRIAR FUNÇÃO DE MOSTRAR TODOS OS EVENTOS DEPOIS
}

void mostrarEventoEspecifico(GerenciadorEventos* listaEventos){
    printf("\n\tOpcao 3: Buscar evento específico ");

    char opcao;
    int codigoEvento;
    printf("\n\nDigite o código do evento: ");
    scanf("%d", &codigoEvento);
    Evento* evento = buscarEvento(listaEventos, codigoEvento);
    if(evento == NULL){

        printf("\nVoltando para a página inicial...\n");
        Sleep(2000);
        printf("\n/-----------------------------------------------------------------------------/\n");
        main();
        return;
    }

    printf("Deseja ver a lista de participantes?(S/N)");
    printf("Resposta: ");
    scanf("%c", opcao);
    while(opcao != 'S' || opcao != 's' || opcao != 'N' || opcao != 'n'){
        printf("\nopcao inválida.");
        printf("\nDeseja ver a lista de participantes?(S/N)");
        printf("Resposta: ");
        scanf("%c", opcao);
    }

    if(opcao == 'S' || opcao == 's'){
        // FUNÇÃO DE BUSCAR A LISTA DE PARTICIPANTES(imprimirListaParticipante)
        // PARAMETROS: ListaParticipantes* lista, int codigoEvento, GerenciadorEvenos* listaEventos

    }

    return;
}
