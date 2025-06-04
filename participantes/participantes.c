#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "participantes.h"

// bool buscarParticipante(char RA){
/////Implementação da busca de participante
// };
// bool inscreverParticipantes(ListaParticipantes* lista, Participante* participante){
/////Implementação da inscrição de participante
// };

bool removerParticipantes(ListaParticipantes* lista, const char* RA) {
    if (lista == NULL || lista->head == NULL || RA == NULL) {
        return false; // Lista inválida, vazia ou RA nulo
    }

    NodeParticipante* atual = lista->head;
    NodeParticipante* anterior = NULL;

    // Percorre a lista para encontrar o participante (**possível troca com buscaParticipante)
    while (atual != NULL) {
        if (strcmp(atual->dadosParticipante.ra, RA) == 0) {
            // Participante encontrado
            if (anterior == NULL) {
                // É o primeiro nó da lista
                lista->head = atual->proximo;
            } else {
                // É um nó no meio ou no fim da lista
                anterior->proximo = atual->proximo;
            }
            free(atual); // Libera a memória do nó removido
            if (lista->quantidade > 0) {
                lista->quantidade--;
            }
            printf("Participante de RA %s removido com sucesso.\n", RA);
            return true; // Remoção bem-sucedida
        }
        // Move para o próximo nó
        anterior = atual;
        atual = atual->proximo;


    }
    return false; // Participante não encontrado
}

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

    NodeEvento* eventoAtualNode = ge->head;
    bool participanteEncontradoEmAlgumEvento = false;
    char nomeParticipante[100] = ""; 
    bool nomeJaImpresso = false;

    printf("--- Relatório Individual para RA: %s ---\n", RA);

    if (ge->head == NULL) {
        printf("Nenhum evento cadastrado no sistema.\n");
    }

    while (eventoAtualNode != NULL) {
        if (eventoAtualNode->evento != NULL) {
            // Verifica se o participante está inscrito neste evento
            NodeParticipante* participanteNode = eventoAtualNode->evento->inscritos.head;
            while (participanteNode != NULL) {
                if (strcmp(participanteNode->dadosParticipante.ra, RA) == 0) {
                    // Participante encontrado neste evento
                    if (!nomeJaImpresso) {                        
                        printf("Participante: %s\n", nomeParticipante);
                        printf("Eventos inscritos:\n");
                        nomeJaImpresso = true;
                    }
                    
                    printf("  - Evento: %s (Código: %d)\n", eventoAtualNode->evento->nome, eventoAtualNode->evento->codigo);           
                    participanteEncontradoEmAlgumEvento = true;
                    break; // Participante encontrado neste evento, pode ir para o próximo evento
                }
                participanteNode = participanteNode->proximo;
            }
        }
        eventoAtualNode = eventoAtualNode->proximo;
    }

    if (!participanteEncontradoEmAlgumEvento) {
        if (!nomeJaImpresso) { // Se o nome não foi impresso, significa que o RA não foi encontrado em nenhum evento.
             printf("Participante de RA %s não está inscrito em nenhum evento ou não foi encontrado.\n", RA);
        } else { // Esse participante foi encontrado, mas não está inscrito em nenhum evento.
            printf("Participante %s (RA: %s) encontrado, mas não parece estar inscrito em nenhum evento .\n", nomeParticipante, RA);
        }
    }
    printf("--- Fim do Relatório ---\n");
}