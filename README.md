#  Sistema de Controle de Participação em Eventos Estudantis

![C](https://img.shields.io/badge/language-C-blue.svg) ![GCC](https://img.shields.io/badge/compiler-GCC-orange.svg) ![Make](https://img.shields.io/badge/build-Make-brightgreen.svg)

Repositório dedicado ao Trabalho Prático I da matéria de Estrutura de Dados I (DS130) do curso de Tecnologia em Análise e Desenvolvimento de Sistemas (TADS) da UFPR.

---

## 🎯 Objetivo

O objetivo deste projeto é desenvolver uma aplicação em linguagem C que utiliza o conceito de estruturas de dados (neste caso, listas encadeadas com nó sentinela) para gerenciar dados de eventos e participantes de forma funcional e eficiente, aplicando os conceitos teóricos da disciplina em um cenário prático. 

---

## 📋 Funcionalidades

O sistema implementa as seguintes funcionalidades essenciais para o gerenciamento de eventos acadêmicos: 

* **Gestão de Eventos:**
    * Cadastrar novos eventos (com código, nome, data/hora e local). 
    * Cancelar (remover) eventos existentes.
    * Buscar e exibir detalhes de um evento específico.
    * Listar todos os eventos cadastrados.
* **Gestão de Participantes:**
    * Inscrever participantes em um evento específico, com verificação para impedir inscrições duplicadas (mesmo RA no mesmo evento). 
    * Remover um participante de um evento. 
    * Listar todos os participantes de um evento específico. 
* **Relatórios:**
    * Emitir um relatório de participação individual, mostrando todos os eventos em que um aluno (identificado pelo RA) está inscrito. 
    * Emitir uma lista de presença formatada para um evento. 

---

## 🛠️ Estrutura do Projeto

O projeto é organizado de forma modular para separar as responsabilidades, facilitando a manutenção e o desenvolvimento em equipe.

```
/
├── controller/
│   ├── controller.c
│   └── controller.h
├── eventos/
│   ├── eventos.c
│   └── eventos.h
├── lista-participantes/
│   ├── lista_participantes.c
│   └── lista_participantes.h
├── participantes/
│   ├── participantes.c
│   └── participantes.h
├── obj/
│   └── (Arquivos objeto .o são gerados aqui)
├── estruturas.h
├── main.c
├── makefile
└── README.md
```

* **`main.c`**: Ponto de entrada e loop principal do menu. 
* **`controller/`**: Camada responsável pela interação com o usuário e orquestração das chamadas para os outros módulos.
* **`eventos/`**: Lógica de negócio para criar, buscar, cancelar e gerenciar a lista principal de eventos. 
* **`participantes/`**: Lógica de negócio para inscrever, remover e gerar relatórios de participantes. 
* **`lista-participantes/`**: Implementação de baixo nível da estrutura de dados de lista encadeada para os participantes de cada evento. 
* **`estruturas.h`**: Arquivo central com a definição de todas as `structs` do projeto para garantir consistência e evitar dependências circulares de inclusão.

---

## 🚀 Como Compilar e Executar

Este projeto utiliza `make` para automatizar o processo de compilação.

1.  **Pré-requisitos:**
    * Compilador C (como o `GCC`, parte do `MinGW` ou `MSYS2` no Windows).
    * Ferramenta `make`.

2.  **Compilação:**
    * Navegue até o diretório raiz do projeto no seu terminal.
    * Execute o comando:
        ```bash
        make
        ```
    * Isso compilará todos os arquivos fonte, colocará os arquivos objeto (`.o`) na pasta `obj/` e gerará o executável `eventos.exe` no diretório raiz.

3.  **Execução:**
    * No mesmo diretório, execute o programa:
        ```bash
        ./eventos.exe
        ```
    * (No Windows, pode ser apenas `eventos.exe`).

4.  **Limpeza:**
    * Para remover o executável e todos os arquivos objeto da pasta `obj/`, use o comando:
        ```bash
        make clean
        ```

---

## 👨‍💻 Equipe e Autoria

Este projeto foi desenvolvido por:

* **Clarissa Morita** (atuou em `ListaParticipante` criando funções de controle)
* **Giovana Dornelles** (atuou em `ListaParticipante` criando funções de controle)
* **João Victor** (atuou em `Participantes` criando funções de controle)
* **Isabella Vicente** (atuou em `Participantes` criando funções de controle)
* **Peterson Fontinhas** (atuou na estrutura de `Eventos`, criando funções de controle)
* Todos os integrantes atuaram na implementação da interface do usuário, criando funcionalidades na camada de controle que se relacionavam diretamente com as funções implementadas nas estruturas de Listas Encadeadas.
---

## 📜 Licença
Este projeto é acadêmico e livre para fins educacionais.
