#pragma once

#include <string>

#include "Indexador.hpp"

#include "QuickSort.hpp"

class Processador
{

    private:

        /* Indexador que será usado no processador. */
        Indexador indexador;

        /* Consulta a ser realizada com o processador. AVALIAR SE E NECESSARIO SER ATRIBUTO, CREIO QUE NAO */
        std::string consulta;

        /* Vetor que armazena a normalização de pesos para cada documento. */
        std::pair<int, double>* vetorDePesosNormalizado;

        /* Vetor que armazena o grau de similaridade entre cada documento e a consulta. */
        std::pair<int, double>* vetorDeGrausDeSimilaridade;

    public:

        /* Descrição: construtor vazio.
        Entrada: não possui.
        Saída: não possui. */
        Processador();

        /* Descrição: construtor com parâmetros de inicialização.
        Entrada: não possui.
        Saída: não possui. */
        Processador(const std::string& consulta, Indexador indexador);

        /* Descrição: calcula o peso de uma palavra em um determinado documento.
        Entrada: apontador para temro que representa a palavra e referência para o inteiro que representa o ID do documento.
        Saída: valor em ponto flutuante que representa o peso da palavra no documento. */
        double calculaPesoPalavra(Termo* termo, const int& IDDocumento);

        /* Descrição: calcula a normalização de cada vetor de pesos de cada arquivo.
        Entrada: não possui.
        Saída: não possui. */
        void normalizaVetorDePesos();

        /* Descrição: preenche a lista de graus de similaridade entre cada documento e a consulta.
        Entrada: não possui.
        Saída: não possui. */
        void preencheVetorDeGrausDeSimilaridade();

        /* Descrição: pega o valor de peso normalizado para o documento desejado.
        Entrada: referência para inteiro que representa o ID do documento.
        Saída: peso normalizado para o ID. */
        double getPesoNormalizado(const int& ID);

        /* Descrição: gera o arquivo de saída com os 10 documentos com maior similaridade com a consulta.
        Entrada: referência para arquivo ofstream em que deve ser escrito o resultado.
        Saída: não possui. */
        void geraArquivoDeSaida(std::ofstream& arqDeSaida);
};
