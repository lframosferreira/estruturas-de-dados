#include <fstream>
#include <getopt.h>
#include <string>
#include <iostream>

#include "Processador.hpp"
#include "msgassert.hpp"

/* Declaração das variáveis globais que serão utilizadas no programa. */
std::string nomeArqDeEntrada;
std::string nomeArqDeSaida;
std::string corpus;
std::string stopwords;

/* Descrição: lê as opções da linha de comando e inicializa as variáveis.
Entrada: o inteiro argc, que representa o número de argumentos passados na linha
de comando, e um vetor de char argv que armazena cada um dos argumentos passados pela linha de comando.
Saída: não possui. */
void parseArgs(int argc, char* argv[])
{
    int c;

    while ((c = getopt(argc, argv, "i:o:c:s:")) != EOF)
    {
        switch (c)
        {
            case 'i':
                nomeArqDeEntrada = optarg;
                break;

            case 'o':
                nomeArqDeSaida = optarg;
                break;

            case 'c':
                corpus = optarg;   
                break;
            
            case 's':
                stopwords = optarg;
                break;

            default:
                exit(1);
        }
    }
};

int main(int argc, char* argv[])
{
    /* Avaliação da linha de comando. */
    parseArgs(argc, argv);

    /* Abertura do arquivo de entrada no modo ifstream. */
    std::ifstream arqDeEntrada(nomeArqDeEntrada);
    erroAssert(arqDeEntrada.is_open(), "Erro na abertura do arquivo de entrada!");

    /* Abertura do arquivo de saída no modo ofstream. */
    std::ofstream arqDeSaida(nomeArqDeSaida);
    erroAssert(arqDeSaida.is_open(), "Erro na abertura do arquivo de saída!");

    /* Atribuição da consulta presente no arquivo de entrada à uma variável string. */
    std::string consulta;
    std::getline(arqDeEntrada, consulta);

    /* Criação do indexador, que recebe o nome do diretório corpus e o nome do arquivo de stopwords. */
    Indexador indexador(corpus, stopwords);

    /* Cálculo dos índices invertidos. */
    indexador.getIndicesInvertidos(corpus);

    /* Criação do processador, a partir da consulta desejada e do indexador. */
    Processador processador(consulta, indexador);

    /* Normalização do vetor de pesos. */
    processador.normalizaVetorDePesos();

    /* Cálculo dos graus de similaridade. */
    processador.preencheVetorDeGrausDeSimilaridade();

    /* Geração do arquivo de saída. */
    processador.geraArquivoDeSaida(arqDeSaida);

    /* Fechamento dos arquivos utilizados. */
    arqDeEntrada.close();
    arqDeSaida.close();

    return 0;
};
