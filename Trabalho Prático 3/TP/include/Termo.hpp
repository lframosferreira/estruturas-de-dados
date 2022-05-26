#pragma once

#include <string>

#include "Lista.hpp"


/* Estrutura para representar um termo, que é formado por uma palavra chave 
, sua lista de pares (ID do documento, Número de ocorrências no documento) 
e sua lista de pares (ID do documento, Peso da palavra no documento) */
struct Termo
{   
    private:

        /* Palavra que representa o termo. */
        std::string palavra;

        /* Tamanho máximo dos vetores de pares. */
        int tamanhoMaxPares;

        /* Mantêm controle sobre em qual posição deve ser inserido um novo par
        (ID do documento, Número de ocorrências no documento). */
        int atualPosParesIDnumDeOcorrencias;

         /* Mantêm controle sobre em qual posição deve ser inserido um novo par
        (ID do documento, Peso da palavra no documento). */
        int atualPosParesIDPeso;

        /* Lista de pares de (ID do documento, Número de ocorrências no documento). */
        std::pair<int, int>* paresIDnumDeOcorrencias;

        /* Lista de pares de (ID do documento, Peso da palavra no documento). */
        std::pair<int, double>* paresIDPeso;

    public: 
        
        /* Descrição: construtor vazio.
        Entrada: não tem.
        Saída: não tem. */
        Termo();

        /* Descrição: construtor vazio.
        Entrada: referência para a string da palavra e para o inteiro do tamanho dos pares.
        Saída: não tem. */
        Termo(std::string& palavra, const int& tamanhoPares);

        /* Descrição: destrutor vazio.
        Entrada: não tem.
        Saída: não tem. */
        ~Termo();

        /* Descrição: pega o valor da palavra do termo.
        Entrada: não possui.
        Saída: string que representa a palavra. */
        std::string getPalavra();

        /* Descrição: pega o número de ocorrências da palavra no ID.
        Entrada: referência para inteiro que representa o ID do documento.
        Saída: número de ocorrências da palavra no documento. */
        int getNumDeOcorrencias(const int& ID);

        /* Descrição: pega o valor de peso da palavra no ID.
        Entrada: referência para inteiro que representa o ID do documento.
        Saída: peso da palavra no documento. */
        double getPeso(const int& ID);

        /* Descrição: pega o tamanho da lista de pares de (ID do documento, Número de ocorrências no documento).
        Entrada: não possui.
        Saída: inteiro que representa o tamanho a lista. */
        int getTamanhoParIDnumDeOcorrencias();

        /* Descrição: insere par de (ID do documento, Número de ocorrências no documento) na lista referente.
        Entrada: referência para os inteiros que representam o ID do documento e o número de ocorrências no documento. 
        Saída: não possui. */
        void insereParIDnumDeOcorrencias(const int& ID, const int& numDeOcorrencias);

        /* Descrição: checa se o par de (ID do documento, Número de ocorrências no documento) está presente na lista 
        referente.
        Entrada: referência para os inteiros que representam o ID do documento e o número de ocorrências no documento.
        Saída: verdadeiro se o par está presente, falso caso contrário. */
        bool contemParIDnumDeOcorrencias(const int& ID, const int& numDeOcorrencias);

        /* Descrição: insere par de (ID do documento, Peso do elemento no documento) na lista referente.
        Entrada: referência para o inteiro que representa o ID do documento e para o valor em 
        ponto flutuante que representa o peso da palavra no documento.
        Saída: não possui. */
        void insereParIDPeso(const int& ID, const double& peso);

        /* Descrição: checa se a palavra está presente no documento com ID desejado.
        Entrada: referência para inteiro que representa o ID do documento.
        Saída: verdadeiro se o ID está presente, falso caso contrário. */
        bool contemID(const int& ID);
};
