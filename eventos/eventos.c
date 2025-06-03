#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "eventos.h"
#include "lista-participantes/lista.h"

GerenciadorEventos* inicializarGerenciadorEventos(){

    // ALOCO UM ESPAÇO NA MEMÓRIA PARA A LISTA DE EVENTOS
    GerenciadorEventos* listaEventos = (GerenciadorEventos*) malloc(sizeof(GerenciadorEventos));

    // VERIFICO SE A LISTA DE EVENTOS FOI CRIADA
    if(listaEventos == NULL){
        perror("Falha ao alocar memoria para o objeto GerenciadorEventos");
        return NULL;
    };

    // ALOCO UM ESPAÇO DE MEMÓRIA PARA UM NÓ DE EVENTO
    //E O LINKO À CABEÇA DO GERENCIADOR DE EVENTOS (LISTA COM CABEÇALHO)
    listaEventos->head = (NodeEvento*) malloc(sizeof(NodeEvento));

    // VERIFICO SE O NÓ FOI ALOCADO CORRETAMENTE
    if(listaEventos->head == NULL) {
        free(listaEventos);
        return NULL;
    }

    // APONTO O PRÓXIMO NÓ COMO NULO
    listaEventos->head->proximo = NULL;

    // RETORNO A LISTA DE EVENTOS CRIADA
    return listaEventos;

}

void cadastrarNovoEvento(GerenciadorEventos* listaEventos, int codigo, const char* nome, int dia, int mes, int ano, int hora, int minuto, const char* local){

    // PRIMEIRO ESTOU ALOCANDO UM ESPAÇO NA MEMÓRIA PARA O NOVO EVENTO
    Evento* evento = (Evento*) malloc(sizeof(Evento));

    // VERIFICANDO SE O ESPAÇO FOI RESERVADO
    if(evento == NULL) {
        perror("Falha ao alocar memoria para o objeto Evento");
        return;
    };

    // ATRIBUINDO O CÓDIGO AO EVENTO
    evento->codigo = codigo;

    // ATRIBUINDO O NOME AO EVENTO
    strncpy(evento->nome, nome, sizeof(evento->nome) - 1);
    evento->nome[sizeof(evento->nome) - 1] = '\0'; // Garante terminação nula

    // ATRIBUINDO O LOCAL AO EVENTO
    strncpy(evento->localEvento, local, sizeof(evento->localEvento) - 1);
    evento->localEvento[sizeof(evento->localEvento) - 1] = '\0'; // Garante terminação nula

    // É FEITA UMA VERIFICAÇÃO PARA A DATA
    if(!validarData(dia, mes, ano, hora, minuto)){
        printf("Data e/ou hora do evento são inválidas. Evento não cadastrado");
        free(evento);
        return;
    }

    // ATRIBUINDO A DATA E HORA(VALIDADAS) AO EVENTO
    evento->dataEvento.dia = dia;
    evento->dataEvento.mes = mes;
    evento->dataEvento.ano = ano;
    evento->dataEvento.hora = hora;
    evento->dataEvento.minuto = minuto;

    // VERIFICA SE O LOCAL E DATA DO EVENTO SÃO VÁLIDOS
    if(!validarEvento(listaEventos, evento)){
        free(evento);
        return;
    }

    // INICIALIZANDO A LISTA DE INSCRITOS PARA O EVENTO
    evento->inscritos.head = NULL;
    evento->inscritos.quantidade = 0;

    // ALOCANDO UM ESPAÇO NA MEMÓRIA PARA O NÓ DE EVENTOS
    NodeEvento* node = (NodeEvento*) malloc(sizeof(NodeEvento));

    // VERIFICANDO SE O ESPAÇO FOI RESERVADO
    if(node == NULL) return;

    // ATRIBUINDO O EVENTO AO NÓ DE EVENTOS
    node->evento = evento;

    // APONTANDO O PRÓXIMO NÓ DE EVENTOS AO PRIMEIRO NÓ REAL DA LISTA DE EVENTOS
    node->proximo = listaEventos->head->proximo; // O novo nó aponta para o que era o primeiro evento real

    // ATRIBUINDO O NÓ DE EVENTOS À LISTA DE EVENTOS
    listaEventos->head->proximo = node; // O nó sentinela agora aponta para o novo nó como o primeiro evento real

    // ATUALIZANDO A QUANTIDADE DE EVENTOS CADASTRADOS
    listaEventos->quantidadeEventos++;

    printf("Evento %s (codigo %d) cadastrado com sucesso", nome, codigo);


}


bool validarData(int dia, int mes, int ano, int hora, int minuto){

    // VERIFICAÇÕES ÓBIVIAS SOBRE AS DATAS
    if(mes < 1 || mes > 12){
        return false;
    }

    if(hora < 0 || hora > 23){
        return false;
    }

    if(minuto < 0 || minuto > 59){
        return false;
    }

    if(dia < 1){
        return false;
    }

    // ELENCA TODOS OS DIAS FINAIS DOS MESES
    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // ATRIBUI UM DIA A MAIS A FEVEREIRO
    if(mes == 2 && ehAnoBissexto){
        diasNoMes[2] == 29;
    }

    // VERIFICA SE O DIA É MAIOR QUE O MES RESPECTIVO
    if(dia > diasNoMes[mes]){
        return false;
    }

    return true;

}

bool ehAnoBissexto(int ano){
    // ANOS NEGATIVOS OU ZEROS NÃO SÃO BISSEXTOS
    if(ano <= 0) return false;

    // SE UM ANO É DIVISÍVEL POR 400, ELE É BISSEXTO
    if(ano % 400 == 0) return true;

    // SE UM ANO É DIVISIVEL POR 100, MAS NÃO POR 400, ELE NÃO É BISSEXTO
    if(ano % 100 == 0) return false;

    // SE UM ANO É DIVISÍVEL POR 4, ELE É BISSEXTO
    return ano % 4 == 0;
}

Evento* buscarEvento(GerenciadorEventos* listaEventos, int codigoEvento){
    // VERIFICA SE A LISTA POSSUI CONTEÚDOS
    if(listaEventos == NULL){
        perror("Lista de eventos vazia");
        return;
    }

    // PEGA O PRIMEIRO NÓ A PARTIR DO CABEÇALHO
    NodeEvento* atual = listaEventos->head->proximo;

    // PERCORRE A LISTA DE EVENTOS PARA VER SE ELE EXISTE
    while(atual != NULL && atual->evento->codigo != codigoEvento){
        atual = atual->proximo;
    }

    // AVISA QUE O EVENTO NÃO FOI ENCONTRADO
    if(atual == NULL){
        perror("Evento não encontrado");
        return;
    }

    // ARMAZENA A DATA DO EVENTO EM UMA STRUCT DATA
    DataEvento data = atual->evento->dataEvento;

    // MOSTRA O EVENTO NA TELA
    printf("Codigo: %d", atual->evento->codigo);
    printf("\nNome do evento: %s", atual->evento->nome);
    printf("\nLocal: %s", atual->evento->localEvento);
    printf( "\nData: %02d/%02d/%d às %02d:%02d.", data.dia, data.mes, data.ano, data.hora, data.minuto);
    printf("-------------------------\n");

}


bool validarEvento(GerenciadorEventos* listaEventos, Evento* novoEvento){

    if (listaEventos == NULL || listaEventos->head == NULL) {
        fprintf(stderr, "Erro: Gerenciador de eventos ou seu cabeçalho não inicializado.\n");
        return false; // Não é possível validar com uma lista inválida
    }

    if (novoEvento == NULL) {
        fprintf(stderr, "Erro: Tentativa de validar um novo evento nulo.\n");
        return false;
    }

    // ARMAZENA O PRIMEIRO EVENTO DA LISTA
    NodeEvento* eventoCadastrado = listaEventos->head->proximo;

    // PERCORRE TODA A LISTA PROCURANDO POR VALORES PARECIDOS
    while(eventoCadastrado != NULL){

        // VERIFICA SE EXISTE UM EVENTO CADASTRADO NO NÓ ATUAL
        if(eventoCadastrado->evento == NULL){
            eventoCadastrado = eventoCadastrado->proximo;
            continue; // reinicia o loop
        }


        // VERIFICA SE O CÓDIGO DE EVENTO JÁ EXISTE
        if(eventoCadastrado->evento->codigo == novoEvento->codigo){
            printf("ERRO: Já existe um evento cadastrado com o código %d  (%s).\n",
                novoEvento->codigo, eventoCadastrado->evento->nome);
            return false;
        }

        // COMPARA OS LOCAIS DOS EVENTOS
        if(strcmp(eventoCadastrado->evento->localEvento, novoEvento->localEvento) == 0){

            // ARMAZENA AS DATAS EM UMA VARIÁVEL LOCAL
            DataEvento dataExistente = eventoCadastrado->evento->dataEvento;
            DataEvento dataNova = novoEvento->dataEvento;

            // VERIFICA SE JÁ EXISTE UM EVENTO CADASTRADO NA MESMA DATA E LOCAL
            if(
                dataExistente.dia == dataNova.dia &&
                dataExistente.mes == dataNova.mes &&
                dataExistente.ano == dataNova.ano &&
                dataExistente.hora == dataNova.hora &&
                dataExistente.minuto == dataNova.minuto
            ){
                printf("ERRO: Já existe um evento (%s, codigo %d) no local '%s', na data %02d/%02d/%d às %02d:%02d.",
                    eventoCadastrado->evento->nome,
                    eventoCadastrado->evento->codigo,
                    novoEvento->localEvento,
                    dataNova.dia, dataNova.mes, dataNova.ano,
                    dataNova.hora, dataNova.minuto
                );

                return false;
            }
        }

        eventoCadastrado = eventoCadastrado->proximo; // próximo evento a ser verificado
    }

    // SE PASSOU PELO LOOP, NÃO HOUVE CONFLITOS
    return true; // novo evento é válido para o cadastro


}


bool cancelarEvento(GerenciadorEventos* listaEventos, int codigoEvento){

    // VERIFICA SE A LISTA POSSUI CONTEÚDOS
    if(listaEventos == NULL){
        perror("Lista de eventos já está vazia.");
        return false;
    }

    // PEGA O PRIMEIRO NÓ A PARTIR DO CABEÇALHO
    NodeEvento* atual = listaEventos->head->proximo;

    // PEGA O NÓ ANTERIOR(CABEÇALHO)
    NodeEvento* anterior = listaEventos->head;

    // PERCORRE A LISTA DE EVENTOS PARA VER SE ELE EXISTE
    while(atual != NULL && atual->evento->codigo != codigoEvento){
        // PEGA O EVENTO ATUAL E ARMAZENA NA AUXILIAR
        anterior = atual;
        // PEGA O PRÓXIMO EVENTO E ARMAZENA NA ATUAL
        atual= atual->proximo;
    }

    // AVISA QUE O EVENTO NÃO FOI ENCONTRADO
    if(atual == NULL){
        printf("Evento de código %02d não encontrado na lista\n", codigoEvento);
        return false;
    }

    // VERIFICA SE EXISTE UM EVENTO CADASTRADO NAQUELE NÓ
    if(atual->evento == NULL){
        printf(stderr, "Erro: Nó da lista encontrado, mas o evento dentro dele é nulo.\n");

        // LIBERA O NÓ MESMO SE NÃO POSSUIR NENHUM EVENTO CADASTRADO
        anterior->proximo = atual->proximo;
        free(atual);

        return false;
    }

    // ARMAZENA O NOME EM UMA AUXILIAR
    const char* nomeEvento[100];
    strcpy(nomeEvento, atual->evento->nome);

    printf("Cancelando evento de código %02d (%s)", codigoEvento, nomeEvento);

    // ARMAZENA O PONTEIRO DO PRÓXIMO EVENTO DEPOIS DO ATUAL NA AUXILIAR
    anterior->proximo = atual->proximo;

    // LIBERA O EVENTO DA MEMÓRIA
    free(atual->evento);
    // LIBERA O NÓ DO EVENTO DA MEMÓRIA
    free(atual);

    listaEventos->quantidadeEventos--;
    printf("Evento de código %02d cancelado com sucesso", codigoEvento);

    return true;
}


void destruirListaEventos(GerenciadorEventos* listaEventos){
 // VERIFICA SE A LISTA POSSUI CONTEÚDOS
    if(listaEventos == NULL){
        perror("Lista de eventos já está vazia.");
        free(listaEventos);
        return;
    }

    // PEGA O PRIMEIRO NÓ A PARTIR DO CABEÇALHO
    NodeEvento* atual = listaEventos->head->proximo;

    // PEGA O NÓ ANTERIOR(CABEÇALHO)
    NodeEvento* proximo;

    // PERCORRE A LISTA DE EVENTOS PARA VER SE ELE EXISTE
    while(atual != NULL){
        // ARMAZENA O PRÓXIMO EVENTO NA AUXILIAR
        proximo = atual->proximo;

        if(atual->evento != NULL){
            // LIBERA A LISTA DE INSCRITOS NO EVENTO
            liberarListaParticipantes(&(atual->evento->inscritos));

            // LIBERA O EVENTO
            free(atual->evento);
        }

        // LIBERA O NÓ DO EVENTO
        free(atual);

        // ARMAZENA O PRÓXIMO NÓ DE EVENTO
        atual = proximo;

    }

    // LIBERANDO O CABEÇALHO
    free(listaEventos->head);

    // LIBERA A LISTA DE EVENTOS
    free(listaEventos);

    printf("Lista de Eventos e gerenciador destruídos com sucesso");

}
