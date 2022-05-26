#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include <string>

#include "EstruturaEncadeada.hpp"

/* A classe Lista é a representação da estrutura de dados Lista Duplamente Encadeada.*/
template <class T>
class Lista : public EstruturaEncadeada<T>
{
    friend class Escalonador;

    public:

        /* Construtor vazio*/
        Lista();

        /* Destrutor */
        ~Lista();

        /* Descrição: insere uma URL na lista, na posição correta dada as especificações do trabalho.
        Entrada: referência para string que representa a URL.
        Saída: não possui. */
        void insere(std::string& mURL);

        /* Descrição: procura a posição correta de inserção da URL na lista,
        de acordo com as especificações do trabalho. Auxilia o método insere().
        Entrada: inteiro representativo da quantidade de barras da URL.
        Saída: Ponteiro para uma Celula do tipo URL. */
        Celula<T>* procuraPosInsercao(int quantidadeBarras);

        /* Descrição: remove a URL no início da lista. 
        Entrada: não possui;
        Saída: não possui.*/
        void removeInicio();

        /* Descrição: remove URL da lista.
        Entrada: referência para a string que representa a URL que será removida da lista.
        Saída: não possui. */
        void remove(std::string& mURL);

        /* printa  */
        void print();
};

/* Declaração da lista que será usada. */
template class Lista<URL>;

#endif