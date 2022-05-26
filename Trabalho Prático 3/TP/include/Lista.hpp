#pragma once

#include <string>

#include "msgassert.hpp"

/* A estrutura Celula representa cada célula que será utilizada na implementação da lista encadeada. */
template <class T>
struct Celula
{   
    /* Valor chave da célula. */
    T valor;
    
    /* Apontador para a próxima célula. */
    Celula<T>* proximo;

    /* Descrição: construtor vazio.
    Entrada: não possui.
    Saída: não possui. */
    Celula();

    /* Descrição: construtor com parâmetros de inicialização.
    Entrada: valor do tipo T que será a chave da celula.
    Saída: não possui. */
    Celula(T valor);
    
    /* Descrição: destrutor vazio.
    Entrada: não possui.
    Saída: não possui. */
    ~Celula();
};

/* A classe Lista é a representação da estrutura de dados Lista Duplamente Encadeada.*/
template <class T>
class Lista
{   
    private:

        /* Célula cabeça da lista. */
        Celula<T>* cabeca;

        /* Célula cauda da lista. */
        Celula<T>* cauda;

        /* Número de elementos da lista. */
        int numElementos;
    
    public:

        /* Construtor vazio*/
        Lista();

        /* Destrutor */
        ~Lista();

        /* Descrição: insere um elemento no final da lista.
        Entrada: referência para elemento que será inserido.
        Saída: não possui. */
        void insere(T& elemento);

        /* Descrição: remove primeira aparição do elemento passado como parâmetro da lista.
        Entrada: referência para elemento que será removida da lista.
        Saída: não possui. */
        void remove(T& elemento); /* POSSIVEIS ERROS */

        /* Descrição: checa se a lista contêm um elemento.
        Entrada: elemento que deve se checar se existe na lista.
        Saída: verdadeiro se o elemento estiver na lista, falso caso contrário. */
        bool contem(const T& elemento);

        /* Descrição: limpa todos os elementos da lista.
        Entrada: não possui.
        Saída: não possui. */
        void limpa();

        /* Descrição: retorna o número de elementos inclusos na lista.
        Entrada: não possui.
        Saída: número de elementos na lista. */
        int tamanho();

        /* Descrição: checa se a lista está vazia.
        Entrada: não possui;
        Saída: verdadeiro se a lista estiver vazia, falso caso contrário. */
        bool vazia();

        /* Descrição: conta quantas vezes um dado elemento está presente na lista.
        Entrada: referência para elemento que deve ser checado.
        Saída: inteiro que representa quantas vezes o elementos aparece na lista. */
        int conta(T& elemento);
};

/* Declarações. */

template class Celula<std::string>;

template class Lista<std::pair<int, int>>;
template class Lista<std::pair<int, double>>;
template class Lista<std::string>;
