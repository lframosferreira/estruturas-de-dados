#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: Compilar o Trabalho Prático 2 - Disciplina de Estruturas de Dados
# Autor		: Luís Felipe Ramos Ferreira - Matrícula: 2019022553
#---------------------------------------------------------------------
# Opções	: make - compila tudo e gera o 'target' executável
#		: make clean - remove objetos, executável e rodadas geradas
#---------------------------------------------------------------------

CC = g++
CFLAGS = -Wall -c
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/Programa.o $(OBJ)/QuickSort.o $(OBJ)/Entidade.o $(OBJ)/Heap.o $(OBJ)/memlog.o
HDRS = $(INC)/Programa.hpp $(INC)/QuickSort.hpp $(INC)/Entidade.hpp $(INC)/Heap.hpp $(INC)/msgassert.hpp $(INC)/memlog.hpp
CFLAGS = -Wall -c -I$(INC)
RODADAS = rodadas/*

EXE = $(BIN)/programa

$(BIN)/programa: $(OBJS)
	$(CC) -o $(BIN)/programa $(OBJS) $(LIBS)

$(OBJ)/Entidade.o: $(HDRS) $(SRC)/Entidade.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Entidade.o $(SRC)/Entidade.cpp

$(OBJ)/Programa.o: $(HDRS) $(SRC)/Programa.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Programa.o $(SRC)/Programa.cpp 

$(OBJ)/QuickSort.o: $(HDRS) $(SRC)/QuickSort.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/QuickSort.o $(SRC)/QuickSort.cpp

$(OBJ)/Heap.o: $(HDRS) $(SRC)/Heap.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Heap.o $(SRC)/Heap.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.cpp

clean:
	rm $(EXE) $(OBJS) $(RODADAS)