#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "../eventos/eventos.h"
#include "../participantes/participantes.h"
#include "../lista-participantes/lista_participantes.h"

void menuEscolhas(){
    printf("\n1. Criar um evento"); // Completo - Já implementado na main
    printf("\n2. Mostrar todos os eventos cadastrados"); // Completo (Peter)
    printf("\n3. Buscar evento específico"); // Completo - Já implementado na main
    printf("\n4. Ver participantes de um evento"); // Completo
    printf("\n5. Remover um evento"); // Completo (Peter)
    printf("\n6. Inserir participantes em um evento"); // Completo (?)
    printf("\n7. Remover participantes de um evento"); // Completo (?)
    printf("\n8. Emitir relatório de participacao individual"); // Completo (?)
    printf("\n9. Apagar lista de eventos"); // Completo
    printf("\n0. Sair");
}

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

    printf("\nPressione uma tecla para voltar à página inicial");
    getchar();
    printf("\nVoltando para a página inicial...\n");
    Sleep(2000);

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
    printf("\nResposta: ");
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


    printf("\nPressione uma tecla para voltar à página inicial");
    getchar();
    printf("\nVoltando para a página inicial...\n");
    Sleep(2000);

    return;
}

void verListaParticipantes(GerenciadorEventos* listaEventos){
    int codigo;

    printf("Digite o código do evento: ");
    scanf("%d", &codigo);
    getchar();
    Evento* evento = buscarEvento(listaEventos, codigo);

    if (evento != NULL){
        imprimirLista(evento);
    }

    printf("\nPressione uma tecla para voltar à página inicial");
    getchar();
    printf("\nVoltando para a página inicial...\n");
    Sleep(2000);


}

void removerParticipante(GerenciadorEventos* listaEventos){
    int codigo;
    char ra[20];

    printf("Digite o código do evento: ");
    scanf("%d", &codigo);
    getchar();

    Evento* evento = buscarEvento(listaEventos, codigo);

    if(evento == NULL){
        return;
    }

    printf("Digite o RA do participante: ");
    fgets(ra, sizeof(ra), stdin);
    ra[strcspn(ra, "\n")] = 0; // Remove o \n

    removerParticipantes(evento->inscritos, ra);

    printf("\nPressione uma tecla para voltar à página inicial");
    getchar();
    printf("\nVoltando para a página inicial...\n");
    Sleep(2000);

}

void inserirParticipante(GerenciadorEventos* listaEventos){

    // Procurar evento
    int codigoEvento;
    printf("\n\nDigite o código do evento: ");
    scanf("%d", &codigoEvento);
    getchar();

    //Busca o evento
    Evento* evento = buscarEvento(listaEventos, codigoEvento);

    if(evento == NULL){
        printf("\nPressione uma tecla para voltar à tela inicial");
        getchar();
        return;
    }

    // Pedir parâmetros
    char nome[100], ra[20];

    printf("Digite o RA do participante: ");
    fgets(ra, sizeof(ra), stdin);
    ra[strcspn(ra, "\n")] = 0; // Remove o \n

    NodeParticipante* participanteExistente = buscarParticipante(evento->inscritos, ra);
    if(participanteExistente != NULL){
        printf("\nParticipante com RA %s já está inscrito no evento '%s'.\n", ra, evento->nome);
        printf("Pressione uma tecla para voltar à tela inicial");
        getchar();
        return;
    }
    
    printf("Digite o nome do participante: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0; // Remove o \n

    printf("\nProcessando inscrição...\n");
    // Inscrever participantes
    bool sucessoInscricao = inscreverParticipanteEmEvento(nome, ra, evento);
    Sleep(2000);

    if(sucessoInscricao){
        printf("\nImprimindo lista de participantes do evento '%s'.\n", evento->nome);\
        imprimirLista(evento);
        printf("\nPressione uma tecla para voltar à tela inicial");
        getchar();
        return;
    } else {
        printf("\nErro ao inscrever participante. Verifique se o RA já está cadastrado ou se o evento existe.\n");
    }


    printf("\nPressione uma tecla para voltar à página inicial");
    getchar();
    printf("\nVoltando para a página inicial...\n");
    Sleep(2000);

};

void gerarRelatorioIndividual(GerenciadorEventos* listaEventos) {
    char ra[20];
    printf("\nDigite o RA do participante para gerar o relatório: ");
    getchar(); // Limpa o '\n' deixado pelo scanf anterior
    fgets(ra, sizeof(ra), stdin);
    ra[strcspn(ra, "\n")] = 0; // Remove o \n
    emitirRelatorioIndividual(ra, listaEventos);

    printf("\nPressione uma tecla para voltar à página inicial");
    getchar();
    printf("\nVoltando para a página inicial...\n");
    Sleep(2000);

}

void mostrarTodosEventos(GerenciadorEventos* listaEventos){
    system("cls");
    printf("Aqui estão todos os eventos: \n");
    mostrarTodosOsEventos(listaEventos);

    printf("\nPressione uma tecla para voltar à página inicial");
    getchar();
    getchar();
    printf("\nVoltando para a página inicial...\n");
    Sleep(2000);

}

void removerEvento(GerenciadorEventos* listaEventos){
    int codigoEvento;
    printf("Digite o código do evento:");
    scanf("%d",&codigoEvento);
    getchar();
//add destruir lista
    Evento* evento= buscarEvento(listaEventos, codigoEvento);
    if(evento==NULL){
        printf("Evento não encontrado");
        return; //evento nao encontrado
    }
    cancelarEvento(listaEventos, codigoEvento);


    printf("\nPressione uma tecla para voltar à página inicial");
    getchar();
    printf("\nVoltando para a página inicial...\n");
    Sleep(2000);

}

void apagarListaEventos(GerenciadorEventos** listaEventos){
    char respostaOpcao;
    printf("Deseja mesmo apagar a lista de eventos?\n Todos os eventos e seus participantes serão deletados(S/N)");
    printf("\nResposta: ");
    scanf(" %c", &respostaOpcao);
    respostaOpcao = toupper(respostaOpcao);
    getchar();
    while(respostaOpcao != 'S' && respostaOpcao != 'N'){
        printf("\n Opcao inválida.");
        printf("\nDeseja mesmo apagar a lista de eventos?(S/N)");
        printf("Resposta: ");
        scanf(" %c", &respostaOpcao);
        respostaOpcao = toupper(respostaOpcao);
        getchar();
    }

    if(respostaOpcao == 'S'){
        destruirListaEventos(*listaEventos); // Libera a lista antiga

        *listaEventos = inicializarGerenciadorEventos(); // Inicializa uma nova lista

    } else {
        printf("Solicitação para apagar lista de eventos cancelada");
    }

    printf("\nPressione uma tecla para voltar à página inicial");
    getchar();
    printf("\nVoltando para a página inicial...\n");
    Sleep(2000);
    return;
}

