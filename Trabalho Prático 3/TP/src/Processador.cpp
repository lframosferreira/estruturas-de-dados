#include "Processador.hpp"

#include <cmath>
#include <sstream>
#include <iostream>

Processador::Processador(){};

Processador::Processador(const std::string& consulta, Indexador indexador)
{   
    /* Atribui o valor da consulta ao atributo. */
    this->consulta = consulta;
    
    /* Atribui o Indexador ao atributo. */
    this->indexador = indexador;
    
    /* Inicializa vetor de pesos normalizado. */
    this->vetorDePesosNormalizado = new std::pair<int, double>[this->indexador.numeroTotalDeDocumentos];

    /* Inicializa vetor de graus de similaridade. */
    this->vetorDeGrausDeSimilaridade = new std::pair<int, double>[this->indexador.numeroTotalDeDocumentos];

};

double Processador::calculaPesoPalavra(Termo* termo, const int& IDDocumento)
{   
    /* Apontador auxiliar que recebe o termo. */
    Termo* auxTermo = termo;

    /* Calcula a frequência do termo no documento. */
    int frequenciaTermoNoDocumento = auxTermo->getNumDeOcorrencias(IDDocumento);

    /* Calcula o número de documentos com a palavra. */
    int numDeDocumentosComPalavra = auxTermo->getTamanhoParIDnumDeOcorrencias();

    /* Calcula o número total de documentos. */
    int numTotalDeDocumentos = this->indexador.numeroTotalDeDocumentos;

    /* Se nenhum documento conter a palavra, retorna 0. */
    if (numDeDocumentosComPalavra == 0) return 0;    

    /* Se não houverem documentos, retorna 0. */
    if (numTotalDeDocumentos == 0) return 0;

    /* Calcula o peso da palavra através da fórmula fornecida. */
    double pesoPalavra = frequenciaTermoNoDocumento * log(numTotalDeDocumentos / numDeDocumentosComPalavra);

    /* Retorna o peso da palavra. */
    return pesoPalavra;
};

void Processador::normalizaVetorDePesos()
{   
    /* Percorre cada um dos IDs presentes no vetor de IDs de documentos. */
    for (int i = 0; i < this->indexador.numeroTotalDeDocumentos; i++)
    {   
        /* Inicializa uma variável soma. */
        double soma = 0;

        /* Atribuição do atual valor de ID. */
        int ID = this->indexador.vetorDeIDsDocumentos[i];

        /* Percorre cada Termo presente nos índices invertidos. */
        for (int j = 0; j < this->indexador.indicesInvertidos.getTamanho(); j++)
        {   
            /* Variável auxiliar do termo atual é criada. */
            Termo* auxTermo = this->indexador.indicesInvertidos.at(j);

            /* Calcula peso da palavra no documento. */
            double pesoPalavraNoDocumento = calculaPesoPalavra(auxTermo, ID);

            /* Insere o par na lista do Termo. */
            auxTermo->insereParIDPeso(ID, pesoPalavraNoDocumento);

            /* Adiciona o valor na soma. */
            soma += powf(pesoPalavraNoDocumento, 2);  
        }

        /* Resultado recebe a raiz quadrada da soma. */
        double res = sqrt(soma);

        /* Criação do par que deve ser inserido. */
        std::pair<int, double> par = {ID, res};

        /* Inserção do par no vetor de pesos normalizado. */
        this->vetorDePesosNormalizado[i] = par;
    }
};


void Processador::preencheVetorDeGrausDeSimilaridade()
{   
    /* Percorre cada um dos IDs presentes no vetor de IDs de documentos. */
    for (int i = 0; i < this->indexador.numeroTotalDeDocumentos; i++)
    {   
        /* Atribuição do atual valor de ID. */
        int ID = this->indexador.vetorDeIDsDocumentos[i];

        /* Inicializa uma variável soma. */
        double soma = 0;

        /* Inicializa uma variável res. */
        double res;

        /* Criação de istringstream, que percorre cada palavra da consulta. */
        std::istringstream iss(this->consulta);
        std::string palavra;

        /* O peso de cada palavra da consulta no documento de ID atual é adicionado na soma. */
        while (iss >> palavra)
        {   
            soma += this->indexador.indicesInvertidos.pesquisa(palavra)->getPeso(ID);
        }  

        /* Atribuição à uma variável da normalização do vetor de pesos do ID atual. */
        double pesoNormalizado = this->getPesoNormalizado(ID);

        /* Se a normalização for 0, res recebe 0. */
        if (pesoNormalizado == 0)
        {
            res = 0;
        }

        /* Caso contrário, res recebe a divisão da soma pela normalização do vetor de pesos do ID. */
        else
        {   
            res = soma / pesoNormalizado;
        }

        /* Criação do par que deve ser inserido. */
        std::pair<int, double> par = {ID, res};

        /* Inserção do par no vetor de pesos normalizado. */
        this->vetorDeGrausDeSimilaridade[i] = par;
    }
};

double Processador::getPesoNormalizado(const int& ID)
{
    /* Percorre cada um dos IDs presentes no vetor de IDs de documentos. */
    for (int i = 0; i < this->indexador.numeroTotalDeDocumentos; i++)
    {   
        /* Se o ID desejado for encontrado, retorna o valor da normalização de ser vetor de pesos. */
        if (this->vetorDePesosNormalizado[i].first == ID)
        {
            return this->vetorDePesosNormalizado[i].second;
        }
    }

    /* Retorna 0 se ID não for encontrado. */
    return 0;
};

void Processador::geraArquivoDeSaida(std::ofstream& arqDeSaida)
{
    /* Ordena, com o algoritmo QuickSort, o vetor de graus de similaridade. */
    quickSort(this->vetorDeGrausDeSimilaridade, this->indexador.numeroTotalDeDocumentos);

    /* Percorre os 10 primeiros elementos do vetor ordenado. */
    for (int i = 0; i < 10; i++)
    {   
        /* Se o número de documentos for menor que 10, imprime todos os IDs. */
        if (i == this->indexador.numeroTotalDeDocumentos)
        {
            break;
        }

        /* Se os IDs passarem a não conter similaridade com a consulta (grau = 0), não são imprimidos mais IDs. */
        if (this->vetorDeGrausDeSimilaridade[i].second == 0)
        {
            break;
        }

        /* Imprime no arquivo de saída o ID do documento. */
        arqDeSaida << this->vetorDeGrausDeSimilaridade[i].first << " ";
    }
};
