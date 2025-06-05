# Compilador
CC = gcc

# Diretórios
EVENTOS_DIR = eventos
PARTICIPANTES_DIR = participantes
LISTA_DIR = lista-participantes

# Arquivos fonte
SRCS = main.c \
       $(EVENTOS_DIR)/eventos.c \
       $(PARTICIPANTES_DIR)/participantes.c \
       $(LISTA_DIR)/lista_participantes.c

# Arquivos objeto
OBJS = main.o \
       eventos.o \
       participantes.o \
       lista_participantes.o

# Executável
TARGET = eventos.exe

# Flags
CFLAGS = -Wall -Wextra -I. -I$(EVENTOS_DIR) -I$(PARTICIPANTES_DIR) -I$(LISTA_DIR)

# Regra padrão
all: $(TARGET)

# Como compilar o executável
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Como compilar cada .o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

eventos.o: $(EVENTOS_DIR)/eventos.c
	$(CC) $(CFLAGS) -c $(EVENTOS_DIR)/eventos.c -o eventos.o

participantes.o: $(PARTICIPANTES_DIR)/participantes.c
	$(CC) $(CFLAGS) -c $(PARTICIPANTES_DIR)/participantes.c -o participantes.o

lista_participantes.o: $(LISTA_DIR)/lista_participantes.c
	$(CC) $(CFLAGS) -c $(LISTA_DIR)/lista_participantes.c -o lista_participantes.o

# Limpar arquivos objeto e executável
clean:
	rm -f $(OBJS) $(TARGET)

# PHONY evita conflitos com arquivos chamados "all" ou "clean"
.PHONY: all clean
