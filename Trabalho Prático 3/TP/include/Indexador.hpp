#pragma once

#include "Hash_EA.hpp"

#include <string>
#include <fstream>
#include <filesystem>

/* forward declaration Processador; */
class Processador;

/* Classe que representa o indexadr de memória, que lê os documentos e constrói o índice invertido. */
class Indexador
{

    friend class Processador;

    private:

        /* Armazena o número total de documentos no corpus que está sendo analisado. */
        int numeroTotalDeDocumentos;

        /* Vetor que armazena os IDs de todos os documentos presentes no corpus. */
        int* vetorDeIDsDocumentos;

        /* Lista de stopwords. */
        Lista<std::string> listaDeStopWords;

        /* Índices invertidos dos documentos do corpus. */
        Hash_EA indicesInvertidos;

        /* Vetor de palavras do vocabulário do corpus. */
        std::string vocabulario[80000]; 

        /* Tamanho do vocabulário do corpus analisado. */
        int tamanhoVocabulario;

    public:

        /* Descrição: Construtor vazio.
        Entrada: não possui.
        Saída: não possui. */
        Indexador();

        /* Descrição: Construtor com parâmetros.
        Entrada: strings que representam os nomes do corpus e do arquivo de stopwords, respectivamente.
        Saída: não possui. */
        Indexador(const std::string& corpus, const std::string& stopwords);

        /* Descrição: destrutor vazio.
        Entrada: não possui.
        Saída: não possui. */
        ~Indexador();

        /* Descrição: armazena as stopwords utilizadas no programas em uma lista.
        Entrada: referência para string que representa nome do arquivo de texto que contêm as stopwords.
        Saída: não possui. CHECAR AQUI FIM DE LINHA*/
        void getStopWords(const std::string& StopWords);

        /* Descrição: checa se uma palavra é uma stopword.
        Entrada: referência para string que representa a palavra que deve ser checada.
        Saída: verdadeiro se a palavra for uma stopword, falso caso contrário. */
        bool isStopWord(const std::string& palavra);

        /* Descrição: armazena todas as palavras do vocabulário presentes no diretório corpus.
        Entrada: referência para a string que representa o nome da pasta corpus onde os documentos estão armazenados.
        Saída: não possui. */
        void getVocabulario(const std::string& corpus);

        /* Descrição: método principal da classe, que armazena em uma estrutura map os índices
        invertidos de cada termo presente nos documentos.
        Entrada: referência para a string que representa o nome da pasta corpus onde os documentos estão armazenados.
        Saída: não possui.*/ 
        void getIndicesInvertidos(std::string& corpus);
};

/* Descrição: função auxiliar que remove os caracteres separados de um texto e o transformam em um espaço em branco.
Entrada: referência para string que representa o texto que deve ser modificado.
Saída: não possui. */
void removeCaracteresSeparadoresTexto(std::string& texto);

/* Descrição: função auxiliar que transforma todo o texto em caixa baixa.
Entrada: referência para string que representa o texto que deve ser modificado.
Saída: não possui. */
void textoCaixaBaixa(std::string& texto);

/* Descrição: função auxiliar para pegar o ID de um documento a partir do seu nome.
Entrada: referência para string que representa o nome do documento.
Saída: inteiro que represneta o ID do documento. */
int getIDDocumento(std::string& nomeArquivo);

/* Descrição: conta quantas vezes uma palavra aparece em um texto.
Entrada: referência para strings que representam a palavra e o texto.
Saída: inteiro que representa quantas vezes a palavra aparece no texto. */
int contaPalavraTexto(const std::string& palavra, const std::string& texto);
