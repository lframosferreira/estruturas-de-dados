#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: Compilar o Trabalho Prático 1 - Disciplina de Estruturas de Dados
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
OBJS = $(OBJ)/main.o $(OBJ)/Lista.o $(OBJ)/Fila.o $(OBJ)/Escalonador.o $(OBJ)/Celula.o $(OBJ)/URL.o $(OBJ)/Sitio.o $(OBJ)/EstruturaEncadeada.o
HDRS = $(INC)/Lista.hpp $(INC)/Fila.hpp $(INC)/Escalonador.hpp $(INC)/Celula.hpp $(INC)/URL.hpp $(INC)/Sitio.hpp $(INC)/EstruturaEncadeada.hpp $(INC)/msgassert.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/programa

$(BIN)/programa: $(OBJS)
	$(CC) -o $(BIN)/programa $(OBJS) $(LIBS)

$(OBJ)/Escalonador.o: $(HDRS) $(SRC)/Escalonador.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Escalonador.o $(SRC)/Escalonador.cpp

$(OBJ)/Lista.o: $(HDRS) $(SRC)/Lista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Lista.o $(SRC)/Lista.cpp 

$(OBJ)/Fila.o: $(HDRS) $(SRC)/Fila.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Fila.o $(SRC)/Fila.cpp

$(OBJ)/URL.o: $(HDRS) $(SRC)/URL.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/URL.o $(SRC)/URL.cpp

$(OBJ)/Sitio.o: $(HDRS) $(SRC)/Sitio.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Sitio.o $(SRC)/Sitio.cpp

$(OBJ)/Celula.o: $(HDRS) $(SRC)/Celula.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Celula.o $(SRC)/Celula.cpp

$(OBJ)/EstruturaEncadeada.o: $(HDRS) $(SRC)/EstruturaEncadeada.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/EstruturaEncadeada.o $(SRC)/EstruturaEncadeada.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp
	
clean:
	rm $(EXE) $(OBJS) 