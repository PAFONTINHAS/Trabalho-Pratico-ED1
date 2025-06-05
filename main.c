#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "estruturas.h"
#include "eventos/eventos.h"
#include "participantes/participantes.h"
#include "lista-participantes/lista_participantes.h"
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

// ANTES DE CRIAR A FUNÇÃO, MENCIONE ELA AQUI.
void removerParticipante(GerenciadorEventos* listaEventos);
void criarEvento(GerenciadorEventos* listaEventos);
void mostrarEventoEspecifico(GerenciadorEventos* listaEventos);
void inserirParticipante(GerenciadorEventos* listaEventos);

void menuEscolhas(){
    printf("\n1. Criar um evento"); // Completo
    printf("\n2. Mostrar todos os eventos cadastrados"); // Incompleto (Peter)
    printf("\n3. Buscar evento específico"); // Completo
    printf("\n4. Ver participantes de um evento"); // Completo
    printf("\n5. Remover um evento"); // Incompleto (Peter)
    printf("\n6. Remover participantes de um evento"); // Incompleto (?)
    printf("\n7. Inserir participantes em um evento"); // Incompleto (?)
    printf("\n8. Emitir relatório de participacao individual"); // Incompleto (?)
    printf("\n9. Emitir relatório de presenca"); // Incompleto
}

int main(){
    // variaveis locais
    int opcao;

    // inicialização de structs
    GerenciadorEventos* listaEventos = inicializarGerenciadorEventos();

    printf("\nInserindo pré eventos:");
    cadastrarNovoEvento(listaEventos, 1, "Festa Universitária", 12, 10, 2025, 21, 30, "Bar do Pedrão");
    cadastrarNovoEvento(listaEventos, 2, "Chá das 8", 15, 06, 2025, 8, 00, "Casa da Judite");
    cadastrarNovoEvento(listaEventos, 3, "Hackathon", 10, 10, 2025, 8, 00, "UFPR Agrárias");
    printf("\nEventos inseridos\nRedirecionando para a página inicial.");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(2000);
    system("cls");

    printf("\n\n\tPágina Inicial");
    printf("\nEscolha uma opcao:");
    menuEscolhas();
    printf("\nOpcao: ");
    scanf("%d", &opcao);

    while(opcao != 0){
        // ADICIONEM SUAS FUNÇÕES NOS CASES
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
            case 6:
                removerParticipante(listaEventos);
            break;
            case 7:
                inserirParticipante(listaEventos);
            break;
            // case 8:
            // break;
            case 0:
                printf("Saindo do sistema...");
                Sleep(2000);
            break;
        }
        // system("cls");
        // Exemplo de correção no final do loop while:
        printf("\nEscolha uma opcao:");
        menuEscolhas();
        printf("\nOpcao: ");
        scanf("%d", &opcao);

    }

    printf("Sistema Finalizado.\nPressione para sair...");
    getchar(); // Consome o newline do último scanf
    getchar(); // Espera pelo Enter do usuário


}
// CONTINUEM SUAS FUNÇÕES AQUI

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
    getchar(); // Limpa o '\n' deixado pelo scanf anterior
    printf("Digite o nome do evento: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0; // Remove o \n
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
    local[strcspn(local, "\n")] = 0; // Remove o \n

    printf("Criando o evento...\n");
    Sleep(2000);


    cadastrarNovoEvento(listaEventos, codigo, nome, dia, mes, ano, hora, minuto, local);

    printf("\nVoltando para a página inicial...\n");
    Sleep(2000);
    printf("\n/-----------------------------------------------------------------------------/\n");

}


void mostrarEventoEspecifico(GerenciadorEventos* listaEventos){
    printf("\n\tOpcao 3: Buscar evento específico ");

    char respostaOpcao;
    int codigoEvento;
    printf("\n\nDigite o código do evento: ");
    scanf("%d", &codigoEvento);
    getchar();
    Evento* evento = buscarEvento(listaEventos, codigoEvento);
    if(evento == NULL){

        printf("\nVoltando para a página inicial...\n");
        Sleep(2000);
        printf("\n/-----------------------------------------------------------------------------/\n");
        return;
    }

    printf("Deseja ver a lista de participantes?(S/N)");
    printf("Resposta: ");
    scanf(" %c", &respostaOpcao);
    respostaOpcao = toupper(respostaOpcao);
    getchar();
    while(respostaOpcao != 'S' && respostaOpcao != 'N'){
        printf("\n Opcao inválida.");
        printf("\nDeseja ver a lista de participantes?(S/N)");
        printf("Resposta: ");
        scanf(" %c", &respostaOpcao);
        respostaOpcao = toupper(respostaOpcao);
        getchar();
    }

    if(respostaOpcao == 'S' || respostaOpcao == 's'){
        imprimirLista(evento);
        // FUNÇÃO DE BUSCAR A LISTA DE PARTICIPANTES(imprimirListaParticipante)
        // PARAMETROS: ListaParticipantes* lista, int codigoEvento, GerenciadorEventos* listaEventos

    }

    printf("\nPressione uma tecla para voltar à tela inicial");
    getchar();

    return;
}

void removerParticipante(GerenciadorEventos* listaEventos){
    int codigo;
    char ra[20];

    printf("Digite o código do evento: ");
    scanf("%d", &codigo);
    getchar();

    Evento* evento = buscarEvento(listaEventos, codigo);

    if(evento != NULL){

        printf("Digite o RA do participante: ");
        fgets(ra, sizeof(ra), stdin);
        ra[strcspn(ra, "\n")] = 0; // Remove o \n

        ListaParticipantes* lista = evento->inscritos;

        bool removido = removerParticipantes(lista, ra);
    }

    printf("\nVoltando para a página inicial...\n");
    Sleep(2000);
    printf("\n/-----------------------------------------------------------------------------/\n");
}

void inserirParticipante(GerenciadorEventos* listaEventos){

    // Procurar evento
    int codigoEvento;
    printf("\n\nDigite o código do evento: ");
    scanf("%d", &codigoEvento);
    getchar();
    Evento* evento = buscarEvento(listaEventos, codigoEvento);

    if(evento == NULL){
        printf("Evento não encontrado");
        return;
    }

    // Pedir parâmetros
    char nome[100], ra[20];
    printf("Digite o nome do participante: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0; // Remove o \n

    printf("Digite o RA do participante: ");
    fgets(ra, sizeof(ra), stdin);
    ra[strcspn(ra, "\n")] = 0; // Remove o \n

    // Inscrever participantes
    inscreverParticipanteEmEvento(nome, ra, evento);
    Sleep(2000);

    // Imprimir a lista com o participante
    imprimirLista(evento);
    printf("\nPressione uma tecla para voltar à tela inicial");
    getchar();
    return;
}
