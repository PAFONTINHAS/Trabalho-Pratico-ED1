//implementação da função apagarListaParticipantes

void apagarListaParticipantes(ListaParticipantes* lista) {
    if (lista == NULL) return;   //verifica se a lista esta vazia, se sim então retorna fazendo nada

    NodeParticipante* atual = lista->head;  //caso nao, cria um ponteiro para começar pelo primeiro nó(head)     
    NodeParticipante* proximo; // Cria outro ponteiro para armazenar temporariamente o próximo nó antes de liberar o atual

    while (atual != NULL) {   //loop para percorrer todos os elementos                   
        proximo = atual->proximo; //Armazena o próximo nó antes de liberar o atual.       
        free(atual); //libera a memória para o nó atual                           
        atual = proximo;// vai para o próximo nó                 
    }

    lista->head = NULL; // quando terminar o loop(liberou a memoria de todos os nós), a lista é sinalizade como vazia                        
    lista->quantidade = 0;  //lista sem nenhum elemento, atualiza o campo quantidade                  
}
