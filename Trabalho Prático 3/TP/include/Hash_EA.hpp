#pragma once

#include "Lista.hpp"

#include "Termo.hpp"

/* Classe para criação do hashing de palavras (strings) utilizando endereçamento aberto. */
class Hash_EA
{

    private:

        /* Vetor tabela que armazenará os termos. */
        Termo* tabela;

        /* Vetor que armazena quais posições da tabela possuem status de 'retirado' */
        bool* retirado;

        /* Vetor que armazena quais posições da tabela possuem status de 'vazio' */
        bool* vazio;

        /* Tamanho da tabela. */
        int tamanho;

        /* Descrição: função para calcular o valor de hash da palavra desejada.
        Entrada: referência para string que representa a palavra a ser transformada em hash.
        Saída: inteiro que representa o valor de hash da palavra. */
        int Hash(const std::string& palavra);

    public:

        /* Descrição: construtor vazio.
        Entrada: não possui.
        Saída: não possui. */
        Hash_EA();

        /* Descrição: construtor com parâmetros de inicialização.
        Entrada: inteiro que representa o tamanho da tabela.
        Saída: não possui. */
        Hash_EA(int tamanho);

        /* Descrição: destrutor vazio.
        Entrada: não possui.
        Saída: não possui. */
        ~Hash_EA();

        /* Descrição: insere um termo na tabela, de acordo com a posição estabelecida pela estrutura de hashing.
        Entrada: termo que deve ser inserido.
        Saída: não possui. */
        void insere(Termo termo);

        /* Descrição: remove um termo na tabela, de acordo com a posição estabelecida pela estrutura de hashing.
        Entrada: termo que deve ser removido.
        Saída: não possui. */
        void remove(Termo& termo);

        /* Descrição: checa se uma palavra chave está presente na tabela.
        Entrada: referência para string que representa a palavra chave a ser comparada.
        Saída: verdadeiro caso a palavra esteja presente, falso caso contrário. */
        bool contem(const std::string& palavra);

        /* Descrição: pesquisa por uma palavra chave na tabela.
        Entrada: referência para string que representa a palavra chave a ser pesquisada.
        Saída: apontador para o termo da tabela que contêm a palavra pesquisada como chave. */
        Termo* pesquisa(const std::string& palavra);

        /* Descrição: retorna o termo presente na posição desejado da tabela.
        Entrada: referência para inteiro que representa a posição desejada.
        Saída: apontador para o termo presente na posição desejada. */
        Termo* at(const int& posicao);

        /* Descrição: acesso ao valor do tamanho da tabela de hashing.
        Entrada: não possui.
        Saída: tamanho da tabela de hashing. */
        int getTamanho();

};
