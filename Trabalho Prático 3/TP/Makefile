#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: Compilar o Trabalho Prático 3 - Disciplina de Estruturas de Dados
# Autor		: Luís Felipe Ramos Ferreira - Matrícula: 2019022553
#---------------------------------------------------------------------
# Opções	: make - compila tudo e gera o 'target' executável
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
CFLAGS = -Wall -c
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/Indexador.o $(OBJ)/Processador.o $(OBJ)/Lista.o $(OBJ)/Termo.o $(OBJ)/Hash_EA.o $(OBJ)/QuickSort.o
HDRS = $(INC)/Indexador.hpp $(INC)/Processador.hpp $(INC)/Lista.hpp $(INC)/Termo.hpp $(INC)/Hash_EA.hpp $(INC)/QuickSort.hpp
CFLAGS = -Wall -c -I$(INC) -std=c++17

EXE = $(BIN)/buscar

$(BIN)/buscar: $(OBJS)
	$(CC) -o $(BIN)/buscar $(OBJS) $(LIBS)

$(OBJ)/Indexador.o: $(HDRS) $(SRC)/Indexador.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Indexador.o $(SRC)/Indexador.cpp

$(OBJ)/Processador.o: $(HDRS) $(SRC)/Processador.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Processador.o $(SRC)/Processador.cpp

$(OBJ)/Lista.o: $(HDRS) $(SRC)/Lista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Lista.o $(SRC)/Lista.cpp

$(OBJ)/Termo.o: $(HDRS) $(SRC)/Termo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Termo.o $(SRC)/Termo.cpp

$(OBJ)/Hash_EA.o: $(HDRS) $(SRC)/Hash_EA.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Hash_EA.o $(SRC)/Hash_EA.cpp

$(OBJ)/QuickSort.o: $(HDRS) $(SRC)/QuickSort.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/QuickSort.o $(SRC)/QuickSort.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

clean:
	rm  $(EXE) $(OBJS)