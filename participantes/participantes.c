#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "participantes.h"
#include "../estruturas.h"
#include "../eventos/eventos.h"
#include "../lista-participantes/lista_participantes.h"

//Funçao que inscreve participante em evento, feito por Jv
bool inscreverParticipanteEmEvento(const char* nome, const char* ra, Evento* evento) {
    // Verificando se o participante já está inscrito no evento
    NodeParticipante* atual = evento->inscritos->head->proximo;
    while (atual != NULL) {
        if (strcmp(atual->dadosParticipante.ra, ra) == 0) {
            printf("Participante com RA '%s' já está inscrito no evento '%s'.\n", ra, evento->nome);
            return false;
        }
        atual = atual->proximo;
    }

    // Criando novo nó para o participante
    NodeParticipante* novoParticipante = (NodeParticipante*)malloc(sizeof(NodeParticipante));
    if (novoParticipante == NULL) {
        printf("Erro ao alocar memória para novo participante.\n");
        return false;
    }

    // Preenche os dados do participante
    // O strncpy é usado para evitar buffer overflow
    strncpy(novoParticipante->dadosParticipante.ra, ra, sizeof(novoParticipante->dadosParticipante.ra) - 1);
    novoParticipante->dadosParticipante.ra[sizeof(novoParticipante->dadosParticipante.ra) - 1] = '\0';

    strncpy(novoParticipante->dadosParticipante.nome, nome, sizeof(novoParticipante->dadosParticipante.nome) - 1);
    novoParticipante->dadosParticipante.nome[sizeof(novoParticipante->dadosParticipante.nome) - 1] = '\0';
    
    novoParticipante->proximo = NULL;

    // Inserindo o participitante na lista de inscritos do evento
    NodeParticipante* ultimo = evento->inscritos->head; 
    while (ultimo->proximo != NULL) { // Encontra o último nó real
        ultimo = ultimo->proximo;
    }
    ultimo->proximo = novoParticipante; // adiciona o novo participante

    evento->inscritos->quantidade++;
    printf("Participante %s (RA: %s) inscrito com sucesso no evento %s (Código: %d).\n",
           novoParticipante->dadosParticipante.nome, // Usar o nome copiado para segurança e
           novoParticipante->dadosParticipante.ra,   // usar o RA copiado também
           evento->nome, evento->codigo);
    return true; // Inscrição de participante foi bem-sucedida
}

//FUNÇÃO QUE EMITE RELATÓRIO INDIVIDUAL, FEITO POR Jv
void emitirRelatorioIndividual(const char* RA, GerenciadorEventos* ge) {
    // Verifica se o RA e o gerenciador de eventos são válidos
    if (RA == NULL) {
        printf("\nErro: RA do participante não pode ser nulo.\n");
        return;
    }
    if (ge->head == NULL) {
        printf("\nErro: Não há eventos cadastrados no sistema.\n");
        return;
    }
    
    printf("\nRelatório Individual para RA %s: \n", RA);

    //criando variáveis auxiliares para percorrer a lista de eventos
    // e verificar se o participante está inscrito em algum evento
    NodeEvento* eventoAtualNode = ge->head->proximo;
    bool participanteEncontrado = false;
    
    //verifica se o primeiro nó de evento é nulo
    // se for, significa que não há eventos cadastrados
    if (eventoAtualNode == NULL) {
        printf("Nenhum evento cadastrado no sistema.\n");
    }
    
    //aqui começa a percorrer a lista de eventos
    //enquanto o nó atual de evento não for nulo
    while (eventoAtualNode != NULL) {
        if (eventoAtualNode->evento != NULL) { // Verifica se o evento atual não é nulo
            // Verifica se a lista de inscritos do evento atual existe e tem um cabeçalho
            if (eventoAtualNode->evento->inscritos != NULL && eventoAtualNode->evento->inscritos->head != NULL) {
                NodeParticipante* participanteNode = eventoAtualNode->evento->inscritos->head->proximo; // Atribui o primeiro nó real da lista de inscritos
                while (participanteNode != NULL) { //enquanto o nó atual de participante não for nulo 
                    //compara o RA do participante atual com o RA fornecido
                    //se forem iguais, significa que o participante está inscrito neste evento
                    if (strcmp(participanteNode->dadosParticipante.ra, RA) == 0) { //compara o RA do participante atual com o RA fornecido                       
                        //mostra os eventos em que o participante está inscrito
                        printf(" - Evento: %s (Código: %d)\n", eventoAtualNode->evento->nome, eventoAtualNode->evento->codigo);
                        participanteEncontrado = true;
                    }
                    participanteNode = participanteNode->proximo;
                }
            }
        }
        // Avança para o próximo evento na lista
        eventoAtualNode = eventoAtualNode->proximo;
    }

    if (!participanteEncontrado) {
        printf("Participante de RA '%s' não encontrado em nenhum evento.\n", RA);
    }
    
    printf("--- Fim do Relatório ---\n");
    printf("\nPressione uma tecla para voltar à tela inicial");
    getchar();
    return;
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
        //verificação de segurança, caso nao encontre ra
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
        return false; // participante nao encontrado
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
