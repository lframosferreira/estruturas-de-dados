#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa matop
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2021-10-18 - arquivo criado
#		: 2021-10-21 - estrutura de diretórios
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
CFLAGS = -Wall -c
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/matriz.o $(OBJ)/memlog.o
HDRS = $(INC)/matriz.h $(INC)/memlog.h $(INC)/msgassert.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/programa

$(BIN)/programa: $(OBJS)
	$(CC) -o $(BIN)/programa $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/matriz.o: $(HDRS) $(SRC)/matriz.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/matriz.o $(SRC)/matriz.cpp

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c 
	
clean:
	rm $(EXE) $(OBJS) 