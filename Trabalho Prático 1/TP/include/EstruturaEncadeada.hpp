#ifndef ESTRUTURAENCADEADA_H
#define ESTRUTURAENCADEADA_H

#include <string>

#include "Celula.hpp"

template <class T> 
class EstruturaEncadeada
{
    friend class Escalonador;

    protected:

        Celula<T>* head;

        Celula<T>* tail;

        int numElementos;

    public:

        /* Construtor vazio. */
        EstruturaEncadeada();

        /* Destrutor. */
        ~EstruturaEncadeada();

        /* Descrição: acessa o número de elementos na estrutura encadeada.
        Entrada: não possui.
        Saida: número de elementos na estrutura.*/
        int getNumElementos();

        /* Descrição: checa se a estrutura encadeada está vazia.
        Entrada: não possui.
        Saída: Verdadeiro se a estrutura está vazia, falso caso contrário. */
        bool estaVazia();

        /* Descrição: limpa a estrutura encadeada, removendo todas as suas células.
        Entrada: não possui.
        Saída: não possui. */
        void limpa();

        /* Descrição: checa se a estrutura encadeada contêm o elemento.
        Entrada: referência para string representativa do elemento que será checado.
        Saída: Verdadeiro se a estrutura contêm o Sitio, falso caso contrário. */
        bool contem(std::string& elemento);
};

/* Declaração das estruturas encadeadas que serão utilizadas. */
template class EstruturaEncadeada<URL>;
template class EstruturaEncadeada<Sitio>;

#endif