#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "../eventos/eventos.h"
#include "../participantes/participantes.h"
#include "../lista-participantes/lista_participantes.h"

/**
 * @brief Exibe o menu de opções principais do sistema na tela.
 */
void menuEscolhas(){
    printf("\n1. Criar um evento");
    printf("\n2. Mostrar todos os eventos cadastrados");
    printf("\n3. Buscar evento específico");
    printf("\n4. Ver participantes de um evento");
    printf("\n5. Remover um evento");
    printf("\n6. Inserir um participante em um evento");
    printf("\n7. Remover um participante em um evento");
    printf("\n8. Emitir relatório de participação individual");
    printf("\n9. Confirmar presença de participante");
    printf("\n10. Emitir de Relatório de presença");
    printf("\n9. Apagar lista de eventos");
    printf("\n0. Sair");
}

/**
 * @brief Valida se a string recebida contém apenas caracteres numéricos.
 * @param input String a ser validada.
 * @return true se for numérica, false caso contrário.
 */
bool validarInputNumerico(const char* input) {
    if (input == NULL || strlen(input) == 0) {
        return false; // Retorna falso se a string for nula ou vazia
    }

    int i = 0;
    while (input[i] != '\0') {
        if (!isdigit(input[i])) {
            return false; // Encontrou um caractere que não é dígito
        }
        i++;
    }

    return true; // Todos os caracteres são dígitos
}

/**
 * @brief Pede ao usuário para digitar um número, valida a entrada e a retorna como inteiro.
 * Repete o pedido até que uma entrada numérica válida seja fornecida.
 * @param prompt A mensagem a ser exibida para o usuário (ex: "Digite o código: ").
 * @return O número inteiro validado.
 */

int lerInteiroValidado(const char* prompt) {
    char buffer[20]; // Um buffer para ler a entrada como string, 20 é suficiente para um int
    bool entradaValida = false;

    do {
        printf("%s", prompt); // Mostra a mensagem para o usuário

        // Lê a entrada do usuário de forma segura
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro ao ler a entrada. Saindo.\n");
            return -1; // Retorna um valor de erro
        }

        // Se a entrada foi muito longa, o '\n' não estará no buffer.
        // Neste caso, precisamos limpar o resto da linha do buffer de entrada.
        if (strchr(buffer, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        // Remove o caractere de nova linha '\n' do buffer, se ele existir
        buffer[strcspn(buffer, "\n")] = 0;

        // Usa a nossa função auxiliar para validar se o conteúdo é numérico e não vazio
        entradaValida = validarInputNumerico(buffer);

        if (!entradaValida) {
            printf("Entrada inválida. Por favor, digite apenas números.\n");
        }

    } while (!entradaValida);

    // Converte a string validada para inteiro e a retorna
    return atoi(buffer);
}

/**
 * @brief Exibe um efeito visual de delay com pontos na tela.
 * @param opcao Define o tempo do delay (1 para mais lento, 2 para mais rápido).
 */
void efeitoDelay(int opcao){
    int tempoDelay1 = 500;
    int tempoDelay2 = 300;

    if(opcao == 1 ){
        Sleep(tempoDelay1);
        printf(".");
        Sleep(tempoDelay1);
        printf(".");
        Sleep(tempoDelay1);
        printf(".");
    }
    if(opcao == 2 ){
        Sleep(tempoDelay2);
        printf(".");
        Sleep(tempoDelay2);
        printf(".");
        Sleep(tempoDelay2);
        printf(".");
    }
}

/**
 * @brief Exibe mensagem para o usuário pressionar uma tecla e retorna ao menu principal.
 */
void voltarAoMenu(){

    printf("\nPressione uma tecla para voltar à página inicial");
    getchar();
    printf("\nVoltando para a página inicial");
    efeitoDelay(2);
}

/**
 * @brief Fluxo para criar um novo evento, solicitando dados ao usuário e cadastrando na lista.
 * @param listaEventos Ponteiro para o gerenciador de eventos.
 */
void criarEvento(GerenciadorEventos* listaEventos){

    printf("\n\tOpcao 1: Criar um evento");

    int codigoEvento = lerInteiroValidado("\nDigite o codigo: ");

    Evento* evento = buscarEvento(listaEventos, codigoEvento);
    while(evento != NULL){
        printf("\nCodigo de evento já cadastrado");
        printf("\nCódigo %d pertece ao evento: %s",codigoEvento, evento->nome);
        codigoEvento = lerInteiroValidado("\nDigite um novo código: ");
        evento = buscarEvento(listaEventos, codigoEvento);
    }

    char nome[100];
    char local[100];

    printf("Digite o nome do evento: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0; // Remove o \n

    int dia = lerInteiroValidado("dia: ");
    int mes = lerInteiroValidado("mes: ");
    int ano = lerInteiroValidado("ano: ");
    int hora = lerInteiroValidado("hora: ");
    int minuto = lerInteiroValidado("minuto: ");

    printf("Local do evento:");
    fgets(local, sizeof(local), stdin);
    local[strcspn(local, "\n")] = 0; // Remove o \n

    printf("Criando o evento...\n");
    Sleep(2000);


    cadastrarNovoEvento(listaEventos, codigoEvento, nome, dia, mes, ano, hora, minuto, local);

    voltarAoMenu();
}

/**
 * @brief Mostra todos os eventos cadastrados no sistema.
 * @param listaEventos Ponteiro para o gerenciador de eventos.
 */
void mostrarTodosEventos(GerenciadorEventos* listaEventos){

    printf("\n\tOpcao 2: Mostrar todos os eventos cadastrados");
    system("cls");
    printf("Aqui estão todos os eventos: \n");
    mostrarTodosOsEventos(listaEventos);
    voltarAoMenu();


}

/**
 * @brief Busca e exibe um evento específico, com opção de mostrar participantes.
 * @param listaEventos Ponteiro para o gerenciador de eventos.
 */
void mostrarEventoEspecifico(GerenciadorEventos* listaEventos){
    printf("\n\tOpcao 3: Buscar evento específico ");

    char respostaOpcao;
    int codigoEvento = lerInteiroValidado("\nDigite o codigo do evento: ");
    Evento* evento = conferirCodigoEvento(listaEventos, codigoEvento);

    if(evento == NULL){
        return;
    }

    imprimirEvento(evento);
    printf("Deseja ver a lista de participantes?(S/N)");
    printf("\nResposta: ");
    scanf(" %c", &respostaOpcao);
    respostaOpcao = toupper(respostaOpcao);
    getchar();
    while(respostaOpcao != 'S' && respostaOpcao != 'N'){
        printf("\n Opcao inválida.");
        printf("\nDeseja ver a lista de participantes?(S/N)");
        printf("\nResposta: ");
        scanf(" %c", &respostaOpcao);
        respostaOpcao = toupper(respostaOpcao);
        getchar();
    }

    if(respostaOpcao == 'S' || respostaOpcao == 's'){
        imprimirLista(evento);
    }

    voltarAoMenu();
    return;
}

/**
 * @brief Exibe a lista de participantes de um evento específico.
 * @param listaEventos Ponteiro para o gerenciador de eventos.
 */
void verListaParticipantes(GerenciadorEventos* listaEventos){
    printf("\n\tOpcao 4: Ver participantes de um evento");
    int codigo = lerInteiroValidado("\nDigite o código do evento: ");
    Evento* evento = conferirCodigoEvento(listaEventos, codigo);

    if(evento != NULL){
        imprimirLista(evento);
    }

    voltarAoMenu();
    return;
}

/**
 * @brief Remove um evento do sistema após confirmação do usuário.
 * @param listaEventos Ponteiro para o gerenciador de eventos.
 */
void removerEvento(GerenciadorEventos* listaEventos){
    printf("\n\tOpcao 5: Remover um evento");
    int codigoEvento = lerInteiroValidado("Digite o código do evento: ");
    Evento* evento = conferirCodigoEvento(listaEventos, codigoEvento);
    char respostaOpcao;

    if(evento != NULL){
        printf("\nEvento encontrado");
        printf("\nCódigo: %d, Evento: %s", evento->codigo, evento->nome);
        printf("\nDeseja prosseguir com o cancelamento?(S/N)");
        printf("\nResposta: ");
        scanf(" %c", &respostaOpcao);
        respostaOpcao = toupper(respostaOpcao);
        getchar();
        while(respostaOpcao != 'S' && respostaOpcao != 'N'){
            printf("\nOpcao inválida.");
            printf("\nDeseja prosseguir com o cancelamento?(S/N)");
            printf("\nResposta: ");
            scanf(" %c", &respostaOpcao);
            respostaOpcao = toupper(respostaOpcao);
            getchar();
        }

        if(respostaOpcao == 'S'){
            printf("\nCancelando evento de código %02d (%s)", evento->codigo, evento->nome );
            efeitoDelay(1);
            cancelarEvento(listaEventos, evento->codigo);
        } else{
            printf("\n Evento de código %02d (%s) não foi cancelado", evento->codigo, evento->nome);
        }

    }
    voltarAoMenu();
    return;

}

/**
 * @brief Insere um participante em um evento, solicitando dados ao usuário.
 * @param listaEventos Ponteiro para o gerenciador de eventos.
 */
void inserirParticipante(GerenciadorEventos* listaEventos){
    printf("\n\tOpcao 6: Inserir um participante em um evento");
    // Procurar evento
    int codigoEvento = lerInteiroValidado("\n\nDigite o código do evento: ");
    Evento* evento = conferirCodigoEvento(listaEventos, codigoEvento);

    // Pedir parâmetros
    char nome[100], ra[20];

    printf("\nDigite o RA do participante: ");
    fgets(ra, sizeof(ra), stdin);
    ra[strcspn(ra, "\n")] = 0; // Remove o \n

    NodeParticipante* participanteExistente = buscarParticipante(evento->inscritos, ra);
    if(participanteExistente != NULL){
        printf("\nParticipante com RA %s já está inscrito no evento '%s'.\n", ra, evento->nome);

        voltarAoMenu();
        return;
    }

    printf("Digite o nome do participante: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0; // Remove o \n

    printf("\nProcessando inscrição\n");
    efeitoDelay(1);
    // Inscrever participantes
    bool sucessoInscricao = inscreverParticipanteEmEvento(nome, ra, evento);
    Sleep(2000);

    if(sucessoInscricao){
        printf("\nImprimindo lista de participantes do evento '%s'.\n", evento->nome);\
        imprimirLista(evento);
    } else {
        printf("\nErro ao inscrever participante. Verifique se o RA já está cadastrado ou se o evento existe.\n");
    }

    voltarAoMenu();


};

/**
 * @brief Remove um participante de um evento após confirmação do usuário.
 * @param listaEventos Ponteiro para o gerenciador de eventos.
 */
void removerParticipante(GerenciadorEventos* listaEventos){
    printf("\n\tOpcao 7: Remover um participante de um evento");

    char ra[20];
    char respostaOpcao;
    int codigo = lerInteiroValidado("\nDigite o código do evento: ");
    Evento* evento = conferirCodigoEvento(listaEventos, codigo);

    if(evento == NULL){
        voltarAoMenu();
        return;
    }

    printf("\nDigite o RA do participante: ");
    fgets(ra, sizeof(ra), stdin);
    ra[strcspn(ra, "\n")] = 0; // Remove o \n

    NodeParticipante* nodeParticipante = buscarParticipante(evento->inscritos, ra);

    if(nodeParticipante == NULL){
        voltarAoMenu();
        return;
    }

    Participante participante = nodeParticipante->dadosParticipante;


    printf("\nParticipante encontrado");
    printf("\nRA: %s, Nome: %s", participante.ra, participante.nome);
    printf("\nDeseja prosseguir com o cancelamento?(S/N)");
    printf("\nResposta: ");
    scanf(" %c", &respostaOpcao);
    respostaOpcao = toupper(respostaOpcao);
    getchar();
    while(respostaOpcao != 'S' && respostaOpcao != 'N'){
        printf("\nOpcao inválida.");
        printf("\nDeseja prosseguir com o cancelamento?(S/N)");
        printf("\nResposta: ");
        scanf(" %c", &respostaOpcao);
        respostaOpcao = toupper(respostaOpcao);
        getchar();
    }


    if(respostaOpcao == 'S'){
        printf("\nRemovendo o participante %s", participante.nome );
        efeitoDelay(1);
        removerParticipanteDeEvento(evento->inscritos, participante.ra);
    } else{
        printf("\n Partipante %s não foi removido do evento", participante.nome);
    }

    voltarAoMenu();


}

/**
 * @brief Gera e exibe o relatório de participação individual de um participante.
 * @param listaEventos Ponteiro para o gerenciador de eventos.
 */
void gerarRelatorioIndividual(GerenciadorEventos* listaEventos) {
    printf("\n\tOpcao 8: Emitir relatório de participação individual");
    char ra[20];
    printf("\nDigite o RA do participante para gerar o relatório: ");
    fgets(ra, sizeof(ra), stdin);
    ra[strcspn(ra, "\n")] = 0; // Remove o \n
    emitirRelatorioIndividual(ra, listaEventos);


    voltarAoMenu();

}


void preencherListaPresenca(GerenciadorEventos* listaEventos){
    char ra[20];
    int codigoEvento = lerInteiroValidado("\nDigite o código do evento:");
    Evento* evento = conferirCodigoEvento(listaEventos, codigoEvento);

    if(evento == NULL){
        voltarAoMenu();
        return;
    }

    printf("\nEvento encontrado: ");
    imprimirEvento(evento);

    printf("Lista de participantes: ");
    imprimirLista(evento);

    printf("\nDigite o RA do participante para registrar a presença: ");
    fgets(ra, sizeof(ra), stdin);
    ra[strcspn(ra, "\n")] = 0; // Remove o \n

    NodeParticipante* nodeParticipante = buscarParticipante(evento->inscritos, ra);

    if(nodeParticipante == NULL){
        printf("Participante não encontrado");
        voltarAoMenu();
        return;
    }


    confirmarPresencaParticipante(nodeParticipante);
    voltarAoMenu();
    return;
}

void gerarRelatorioPresenca(GerenciadorEventos* listaEventos){
    int codigoEvento = lerInteiroValidado("\nDigite o código do evento: ");
    Evento* evento = conferirCodigoEvento(listaEventos, codigoEvento);

    if(evento == NULL){
        voltarAoMenu();
        return;
    }

    printf("\nEvento encontrado: ");
    imprimirEvento(evento);

    emitirListaPresenca(evento);

    voltarAoMenu();
    return;
}

/**
 * @brief Apaga toda a lista de eventos do sistema após confirmação do usuário.
 * @param listaEventos Ponteiro duplo para o gerenciador de eventos.
 */
void apagarListaEventos(GerenciadorEventos** listaEventos){
    printf("\n\tOpcao 9: Apagar lista de eventos");
    char respostaOpcao;
    printf("\nDeseja mesmo apagar a lista de eventos?\n Todos os eventos e seus participantes serão deletados(S/N)");
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

    voltarAoMenu();
    return;
}

