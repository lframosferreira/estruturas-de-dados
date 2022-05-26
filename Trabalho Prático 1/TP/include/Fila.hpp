#ifndef FILA_H
#define FILA_H

#include <string>

#include "Lista.hpp"

/* A classe Fila é a representação da estrutura de dados Fila. */
template <class T>
class Fila: private EstruturaEncadeada<T>
{
    friend class Escalonador;

    public:

        /* Construtor vazio. */
        Fila();

        /* Destrutor. */
        ~Fila();

        /* Descrição: enfileira um Sitio na fila.
        Entrada: referência para string que representa o Sitio.
        Saída: não possui. */
        void enfileira(std::string& mSitio);

        /* Descrição: desefileira um Sitio na fila.
        Entrada: não possui.
        Saída: Sitio que foi desenfileirado. */
        T desenfileira();

        void print();

        /* Descrição: acessa um Sitio desejado na fila.
        Entrada: referência para string que representa o Sitio que se deseja ter acesso.
        Saída: ponteiro para o Sitio procurado. */
        Celula<T>* getSitio(std::string& mSitio);
};

/* Declaração da fila que será usada. */
template class Fila<Sitio>;

#endif