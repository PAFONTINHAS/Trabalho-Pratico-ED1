#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "participantes.h"
#include "../estruturas.h"
#include "../eventos/eventos.h"
#include "../lista-participantes/lista_participantes.h"

//funçao que inscreve participante em evento, feito por Jv
bool inscreverParticipanteEmEvento(const char* nome, const char* ra, Evento* evento) {

    // // Buscando o evento pelo código através da função buscarEvento
    // Evento* evento = buscarEvento(ge, codigoEvento);
    // if (evento == NULL) {
    //     printf("Evento com código %d não encontrado.\n", codigoEvento);
    //     return false;
    // }

    // Verificando se o participante já está inscrito no evento
    NodeParticipante* participanteNode = evento->inscritos->head->proximo;
    while (participanteNode != NULL) {
        if (strcmp(participanteNode->dadosParticipante.ra, ra) == 0) {
            printf("Participante já inscrito no evento.\n");
            return false; // retorna false pois o participante já está inscrito
        }
        participanteNode = participanteNode->proximo; // avança para o próximo participante
    }

    // Criando novo nó para o participante
    NodeParticipante* novoParticipante = (NodeParticipante*)malloc(sizeof(NodeParticipante));
    if (novoParticipante == NULL) {
        printf("Erro ao alocar memória para novo participante.\n");
        return false;
    }

    // Preenche os dados do participante
    strcpy(novoParticipante->dadosParticipante.ra, ra);
    strcpy(novoParticipante->dadosParticipante.nome, nome);
    novoParticipante->proximo = NULL;

    // Insere o novo participante na lista de inscritos do evento
    if (evento->inscritos->head == NULL) {
        evento->inscritos->head = (NodeParticipante*)malloc(sizeof(NodeParticipante));
        if (evento->inscritos->head == NULL) {
            printf("Erro ao alocar memória para a cabeçalho da lista de participantes.\n");
            free(novoParticipante);
            return false;
        }
        evento->inscritos->head->proximo = novoParticipante;
    } else {
        NodeParticipante* ultimo = evento->inscritos->head;
        while (ultimo->proximo != NULL) {
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = novoParticipante;
    }

    evento->inscritos->quantidade++;
    printf("Participante %s (RA: %s) inscrito com sucesso no evento %s (Código: %d).\n", nome, ra, evento->nome, evento->codigo);
    return true; // Inscrição de participante foi bem-sucedida
}

//FUNÇÃO QUE EMITE RELATÓRIO INDIVIDUAL, FEITO POR Jv
void emitirRelatorioIndividual(const char* RA, GerenciadorEventos* ge) {
    // Verifica se o RA e o gerenciador de eventos são válidos
    if (RA == NULL) {
        printf("Erro: RA do participante não pode ser nulo.\n");
        return;
    }
    if (ge == NULL) {
        printf("Erro: Gerenciador de eventos não pode ser nulo.\n");
        return;
    }
    if (ge->head == NULL) {
        printf("Erro: Não há eventos cadastrados no sistema.\n");
        return;
    }

    //criando variáveis auxiliares para percorrer a lista de eventos
    // e verificar se o participante está inscrito em algum evento
    NodeEvento* eventoAtualNode = ge->head->proximo;
    bool participanteEncontradoEmAlgumEvento = false;
    char nomeParticipante[100] = "";
    bool nomeJaImpresso = false;

    printf("--- Relatório Individual para RA: %s ---\n", RA);

    if (ge->head->proximo == NULL) { // Verifica se a lista de eventos está vazia
        printf("Nenhum evento cadastrado no sistema.\n");
    }

    while (eventoAtualNode != NULL) {
        if (eventoAtualNode->evento != NULL && eventoAtualNode->evento->inscritos != NULL) {
            NodeParticipante* participanteNode = eventoAtualNode->evento->inscritos->head->proximo; // Inicia do primeiro participante da lista de inscritos
            // Percorre a lista de participantes inscritos no evento atual
            while (participanteNode != NULL) {
                if (strcmp(participanteNode->dadosParticipante.ra, RA) == 0) {
                    if (!nomeJaImpresso) {
                        strncpy(nomeParticipante, participanteNode->dadosParticipante.nome, sizeof(nomeParticipante) - 1); // copia o nome do participante
                        nomeParticipante[sizeof(nomeParticipante) - 1] = '\0';
                        printf("Participante: %s\n", nomeParticipante);
                        printf("Eventos inscritos:\n");
                        nomeJaImpresso = true;
                    }
                    printf("- Evento: %s (Código: %d)\n", eventoAtualNode->evento->nome, eventoAtualNode->evento->codigo);
                    participanteEncontradoEmAlgumEvento = true;
                    break;
                }
                participanteNode = participanteNode->proximo; // Move para o próximo participante
            }
        }
        eventoAtualNode = eventoAtualNode->proximo; // Move para o próximo evento
    }

    if (!participanteEncontradoEmAlgumEvento) {
        if (!nomeJaImpresso) { // Se o nome não foi impresso, significa que o RA não foi encontrado em nenhum evento.
             printf("Participante de RA %s não está inscrito em nenhum evento ou não foi encontrado.\n", RA);
        }
    }

}



//1. declara as variaveis q eu vou usar
//2. vai procurar enquanto o que
//3. como vai andar na lista
//4. se nao encontrar, vai fazer o que
//5. se encontrar, vai fazer o que

//--------------FUNÇÃO QUE REMOVE PARTICIPANTE, FEITO POR ISABELLA VICENTE --------------------
bool removerParticipantes(ListaParticipantes* lista, const char* raProcurado) {
//procura e retorna true se achar e remover, e false se não achar
    NodeParticipante* atual=lista->head->proximo;
    //declaro atual do tipo NodeParticipante dizendo para ele começar em uma valor real do começo da lista
    NodeParticipante* anterior= lista->head;
    //declaro anterior do tipo NodeParticipante dizendo para ele começar em 1 posicao antes do valor real
    //do começo da lista, mas como nao tem pq nao começou a andar ainda, é null
    NodeParticipante* raEncontrado = buscarParticipante(lista, raProcurado);
    //declara raEcontrado do tipo ListaParticipantes aplicando buscarParticipante
    if(raEncontrado == NULL){
        printf("\nParticipante não encontrado\n");
        return false;
    }
    while(atual!=NULL && strcmp(atual->dadosParticipante.ra, raEncontrado->dadosParticipante.ra)!=0){
    //atual vai andar e passar o dado para anterior até achar o que quer
        anterior=atual;
        //atual passa o dado que ele acabou de ver para anterior, salvando o dado
        atual=atual->proximo;
        //atual anda para o proximo elemento, e ler o dado
    }
    if (atual == NULL) {
        return false; // Participant not found, nothing to remove.
    }
    anterior->proximo=atual->proximo;
    //atual vai dizer quem é o proximo para o anterior, para ele nao ficar perdido
    free(atual);
    //libera ra da memoria
    printf("\nparticipante removido com sucesso!\n");
    return true;
    //retorna que deu certo

}

//lista=head,1,2,3,4,5,6,7
//lista=head,atual/proximo
//lista=anterior/head,atual/proximo
