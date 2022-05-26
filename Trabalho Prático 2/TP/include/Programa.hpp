#pragma once

#include <fstream>

#include "Entidade.hpp"
#include "QuickSort.hpp"
#include "Heap.hpp"

/* Descrição: função utilizada para a leitura do arquivo de entrada e organização das entidades lidas
em fitas.
Entrada: referência para o arquivo ifstream que contêm a entrada do programa, um inteiro que representa
o número de entidades que o arquivo possui e uma referência para o número de fitas usadas para armazenar as
entidades.
Saida: não possui. */ 
void geraRodadas(std::ifstream& arq, int numEntidades, int& numFitasDinamico);

/* Descrição: função utilizada para escrever os valores de entidade obtidos no arquivo
em uma fita.
Entrada: nome da fita (arquivo) em que as entidades serão escritas, o vetor de entidades que deve ser
escrito na fita e um inteiro que representa o número de entidades que devem ser escritas na fita.
Saída: não possui. */
void escreveFitaOrdenada(std::string arqSaidaFitaOrdenada, Entidade* vetorDeEntidades, int numEntidadesEscrever);

/* Descrição: função utilizada para a intercalar as fitas armazenadas após a leitura inicial do arquivo
de entrada.
Entrada: inteiro que representa o número de fitas e uma referência para o arquivo de saída ofstream
onde serão escritas as entidades.
Saída: não possui. */
void intercalaFitas(int numFitas, std::string& nomeArqSaida);

/* Descrição: função utilizada para abertura e acesso das fitas (arquivos) que contêm as entidades do
trabalho.
Entrada: inteiro que representa o número de fitas.
Saída: vetor que armazena as fitas do tipo ifstream. */ 
std::ifstream* getFitas(int numFitas);
