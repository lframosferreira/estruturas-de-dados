#ifndef ESCALONADOR_H
#define ESCALONADOR_H

#include <iostream>
#include <fstream>

#include "msgassert.hpp"
#include "Fila.hpp"

#define ADD_URLS 1
#define ESCALONA_TUDO 2
#define ESCALONA 3
#define ESCALONA_HOST 4
#define VER_HOST 5
#define LISTA_HOSTS 6
#define LIMPA_HOST 7
#define LIMPA_TUDO 8

class Escalonador
{

    private:

        Fila<Sitio>* filaDeSitios;
    
    public:

        /* Construtor vazio. */
        Escalonador();

        /* Destrutor. */
        ~Escalonador();

        /* Descrição: le uma linha do arquivo de entrada.
        Entrada: referência para o arquivo de entrada ifstream.
        Saída: string representativa da linha do arquivo. */
        std::string leArquivo(std::ifstream& arqEntrada);

        /* Descrição: essa função irá ler o arquivo e realizar o comando desejado por cada linha.
        Entrada: referências para os arquivos de entrada (ifstream) e saída (ofstream).
        Saída: não possui. */
        void realizaComando(std::ifstream& arqEntrada, std::ofstream& arqSaida);

        /* Descrição: realiza o comando ADD_URLS <quantidade>, isto é, adiciona ao escalonador as URLs 
        informadas nas N linhas seguintes do arquivo, onde N é o parâmetro <quantidade>. 
        Entrada: inteiro que representa o número de URLs que devem ser analisadas para adição
        e referência para o arquivo de entrada (ifstream). 
        Saída: não possui. */
        void addURLs(int numURLsAdd, std::ifstream& arqEntrada);

        /* Descrição: realiza o comando ESCALONA_TUDO, isto é, escalona todas as URLs 
        seguindo as regras estabelecidas previamente. Quando escalonadas, as URLs são 
        exibidas e removidas da lista. 
        Entrada: referência para o arquivo de saída (ofstream). 
        Saída: não possui.*/
        void escalonaTudo(std::ofstream& arqSaida);

        /* Descrição: realiza o comando ESCALONA <quantidade>, isto é, limita a quantidade
        de URLs que serão escalonadas.
        Entrada: inteiro que representa o número de URLs que devem ser escalonadas e
        referência para o arquivo de saída (ofstream).
        Saída: não possui. */
        void escalona(int qtdURLsEscalonar, std::ofstream& arqSaida);

        /* Descrição: realiza o comando ESCALONA_HOST <host> <quantidade>, isto é, são
        escalonados <quantidade> URLs do sítio <host>. 
        Entrada: referência para string representativa do sítio, inteiro que representa
        o número de URLs do sítio que devem ser escalonadas e referência para o arquivo
        de saída (ofstream).
        Saída: não possui. */
        void escalonaHost(std::string& sitio, int qtdURLsHostEscalonar, std::ofstream& arqSaida);

        /* Descrição: realiza o comando VER_HOST <host>, isto é, exibe todas as URLs
        do host <host>, na ordem de prioridade.
        Entrada: referência para string representativa do sítio e referência para o arquivo
        de saída (ofstream).
        Saída: não possui. */
        void verHost(std::string& sitio, std::ofstream& arqSaida);
        
        /* Descrição: realiza o comando LISTA_HOSTS, isto é, exibe todos os hosts,
        seguindo a ordem em que foram conhecidos.
        Entrada: referência para o arquivo de saída (ofstream).
        Saída: não possui. */
        void listaHosts(std::ofstream& arqSaida);
        
        /* Descrição: realiza o comando LIMPA_HOST <host>, isto é, limpa a lista
        de URLs do host <host>.
        Entrada: referência para a string representativa do sítio.
        Saída: não possui. */
        void limpaHost(std::string& sitio);
        
        /* Descrição: realiza o comando LIMPA_TUDO, isto é, limpa todas as URLs e seus sítios
        do escalonador.
        Entrada: não possui.
        Saída: não possui. */
        void limpaTudo();

        /* Descrição: encontra o melhor sítio, isto é, o sítio que contêm a maior quantidade
        de URLs armazenadas em sua lista.
        Entrada: não possui.
        Saída: Celula que armazena o melhor sitio desejado. */
        Celula<Sitio>* encontraMelhorSitio();

        /* Descrição: retorna o número total de URLs armazenadas na fila de sítios.
        Entrada: não possui.
        Saída: número total de URLs armazenadas. */
        int numTotalURLsArmazenadas();
};

/* Descrição: essa função auxiliar irá retornar o número inteiro que representa um comando.
Entrada: referência para a string que representa o comando.
Saída: inteiro que representa o comando. */
int getComando(std::string& comando);
    
#endif