#include "Indexador.hpp"

#include <iostream>

#include <sstream>

#include <algorithm>

Indexador::Indexador(){};

Indexador::Indexador(const std::string& corpus, const std::string& stopwords)
{   
    /* Inicializa o número de documentos como  0. */
    this->numeroTotalDeDocumentos = 0;
    
    /* Inicializa a lista que armazenará stopwords. */
    this->listaDeStopWords = Lista<std::string>();

    /* Chama o método getStopWords. */
    this->getStopWords(stopwords);

    /* Chama o método getVocabulario. */
    this->getVocabulario(corpus);
    
    /* Constroi o índice invertido com base no tamanho do vocabulário. */
    this->indicesInvertidos = Hash_EA(this->tamanhoVocabulario);
    
    /* Inicializa o vetor que armazena os IDs dos documentos. */
    this->vetorDeIDsDocumentos = new int[this->numeroTotalDeDocumentos];

};

Indexador::~Indexador(){};

void Indexador::getStopWords(const std::string& StopWords)
{   
    std::string stopword;

    /* Criação do arquivo ifstream para ler as stopwords. */
    std::ifstream arquivoDeStopWords(StopWords);

    /* Cada palavra no arquivo stopwords é armazenada na lista auxiliar. */
    while (arquivoDeStopWords >> stopword)
    {      
        this->listaDeStopWords.insere(stopword);
    }
};

bool Indexador::isStopWord(const std::string& palavra)
{   
    /* Uso do método 'contem' da classe Lista. */
    return this->listaDeStopWords.contem(palavra);
};

void Indexador::getVocabulario(const std::string& corpus)
{   
    /* Contador que mantêm controle sobre posição em que palavra será escrita no vocabulário. */
    int contador = 0;

    /* Uso da biblioteca <filesystem> para percorrer todos os arquivos do corpus. */
    for (const auto& dirArq : std::filesystem::directory_iterator(corpus))
    {   
        /* Incremento na contagem do número de documentos no corpus. */
        this->numeroTotalDeDocumentos++;

        /* Nome no arquivo acessado é registrado em uma variável. */
        std::string nomeArquivo = dirArq.path().string();

        /* Criação do arquivo ifstream para leitura dos arquivos. */
        std::ifstream arq(nomeArquivo);

        if (!arq.is_open())
        {
            std::cout << "Erro na abertura do arquivo com filesystem!" << std::endl;
        }

        /* Armazena o texto do documento em uma string auxiliar. */
        std::string textoDocumento;
        std::getline(arq, textoDocumento);
        
        /* Chamada das funções auxiliares para passar o texto para os padrões desejados. */
        removeCaracteresSeparadoresTexto(textoDocumento); 
        textoCaixaBaixa(textoDocumento); 
        
        /* Com uma istringstream, o texto é percorrido e cada palavra é armazenada no vocabulário, seguindo os padrões. */
        std::istringstream iss(textoDocumento);
        std::string palavra;
        while (iss >> palavra)
        {   
            /* Se a palavra for uma stopword, ela não é armazenada no vocabulário. */
            if (this->isStopWord(palavra))
            {   
                continue;
            }

            /* Se a palavra já está no vocabulário, ela é ignorada. Para isso , utiliza uma sentinela booleana. */
            bool estaNoVocabulario = false;

            for (int i = 0; i < contador; i++)
            {
                if (this->vocabulario[i] == palavra)
                {
                    estaNoVocabulario = true;
                }
            }

            if (estaNoVocabulario)
            {
                continue;
            }

            /* Inserção da palavra no vocabulário. */
            this->vocabulario[contador] = palavra;
            contador++;
        }  
    }

    this->tamanhoVocabulario = contador;
};



void Indexador::getIndicesInvertidos(std::string& corpus)
{   
    /* Inicialização de uma variável auxiliar para controlar o índice de inserção
    do ID de um documento no vetor auxilar. */
    int indexVetorDeIDs = 0;

    /* Uso da biblioteca <filesystem> para percorrer todos os arquivos do corpus. */
    for (const auto& dirArq : std::filesystem::directory_iterator(corpus))
    {
        /* Nome no arquivo acessado é registrado em uma variável. */
        std::string nomeArquivo = dirArq.path().string();

        /* Nome no arquivo acessado é registrado em uma variável. */
        std::ifstream arq(nomeArquivo);
        if (!arq.is_open())
        {
            std::cout << "Erro na abertura do arquivo com filesystem!" << std::endl;
        }

        /* Uso da função auxiliar para armazenar o ID do documento em uma variável. */
        int IDDocumento = getIDDocumento(nomeArquivo);

        /* Armazenamento do ID no vetor auxiliar. */
        this->vetorDeIDsDocumentos[indexVetorDeIDs] = IDDocumento;
        indexVetorDeIDs++;

        /* Armazena o texto do documento em uma string auxiliar. */
        std::string textoDocumento;
        std::getline(arq, textoDocumento);

        /* Chamada das funções auxiliares para passar o texto para os padrões desejados. */
        removeCaracteresSeparadoresTexto(textoDocumento);
        textoCaixaBaixa(textoDocumento);

        std::istringstream iss(textoDocumento);
        std::string palavra;

        /* Percorre cada palavra do texto no documento. */
        while (iss >> palavra)
        {   

            if (this->isStopWord(palavra)) continue;

            /* Armazenamento em uma variável do número de ocorrências da palavra no ID. */
            int numDeOcorrenciasNoDocumento = contaPalavraTexto(palavra, textoDocumento);

            /* Criação de variável auxiliar do tipo abstrato Termo. */
            Termo novoTermo(palavra, this->numeroTotalDeDocumentos);

            /* Checa se a palavra ja está inserida nos índices invertidos. */
            if (!this->indicesInvertidos.contem(palavra))
            {   
                /* Inserção do novo termo nos índices invertidos. */
                novoTermo.insereParIDnumDeOcorrencias(IDDocumento, numDeOcorrenciasNoDocumento);
                this->indicesInvertidos.insere(novoTermo);  
                
            }
            /* Checa se a palavra já foi inserida nos índices invertidos para esse documento. */
            else if (!this->indicesInvertidos.pesquisa(palavra)->contemParIDnumDeOcorrencias(IDDocumento, numDeOcorrenciasNoDocumento))
            {   
                /* Inserção do par. */
                this->indicesInvertidos.pesquisa(palavra)->insereParIDnumDeOcorrencias(IDDocumento, numDeOcorrenciasNoDocumento);
            }
        }
    }
};

void removeCaracteresSeparadoresTexto(std::string& texto)
{
    /* Declara vetor de caracteres que devem ser considerados separadores no texto. */
    const std::string caracteresSeparadores = {'.', '!', '?', ',', ';', ':', '~', ']', '[', '-', '\n', '\r'};
    /* Para cada caracter, quando encontrados, são transformados em espaço em branco. */
    for (int i = 0; i < 12; i++)
    {
        std::replace(texto.begin(), texto.end(), caracteresSeparadores[i], ' '), texto.end();
    }
};

void textoCaixaBaixa(std::string& texto)
{
    /* Usa a função transform para colocar todo o texto em caixa baixa. */
    std::transform(texto.begin(), texto.end(), texto.begin(), ::tolower);
};

int getIDDocumento(std::string& nomeArquivo)
{
    /* Encontra posição da barra mais a direita. */
    std::size_t posBarra = nomeArquivo.rfind('/');

    /* Caso a bara não seja encontrado, o caminho do arquivo está sem a barra, ou seja, é apenas seu nome
    e sua extensão. Nesse caso, posBarra recebe -1, para que quando se percorra a string, seja começado
    pela posição 0. */
    if (posBarra == std::string::npos)
    {
        posBarra = -1;
    }
   
    /* Encontra a posição do ponto antes da extensão do arquivo. */
    std::size_t posPonto = nomeArquivo.rfind('.');
    
    std::string IDDocumento = "";
    
    /* Coloca em uma string auxiliar apenas o nome do documento, no caso, seu ID. */
    for (std::size_t i = posBarra + 1; i < posPonto; i++ )
    {
        IDDocumento += nomeArquivo.at(i);
    }

    /* Retorna o valor como um inteiro. */
    return std::stoi(IDDocumento);
};

int contaPalavraTexto(const std::string& palavra, const std::string& texto)
{
    /* Com uma istringstream, percorre o texto palavra por palavra. */
    std::istringstream iss(texto);

    /* Contador para armazenar o número de aparecimentos da palavra desejada. */
    int contador = 0;

    std::string auxPalavra;

    /* Percorre cada palavra. */
    while (std::getline(iss, auxPalavra, ' '))
    {
        /* Se for igual à palavra desejada, o contador é incrementado. */
        if (auxPalavra == palavra)
        {
            contador++;
        }
    }
    /* Retorna o contador. */
    return contador;
};