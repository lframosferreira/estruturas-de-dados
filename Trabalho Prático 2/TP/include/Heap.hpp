#pragma once

#include "Entidade.hpp"

/* A classe Heap representa um heap, estrutura de dados utilizada no trabalho. */
class Heap
{
    private:

        int numElementos;

        Entidade* vetorDeEntidades;

    public:

        /* Descrição: construtor vazio.
        Entrada: não possui.
        Saída: não possui. */
        Heap();

        /* Descrição: construtor com um parâmetro de inicialização.
        Entrada: não possui.
        Saída: não possui. */
        Heap(int tamanho);

        /* Descrição: destrutor vazio.
        Entrada: não possui.
        Saída: não possui. */
        ~Heap();

        /* Descrição: adiciona uma nova entidade ao heap.
        Entrada: entidade que será adicionada.
        Saída: não possui. */
        void add(Entidade entidade);

        /* Descrição: retira a maior entidade do heap.
        Entrada: não possui.
        Saída: entidade que foi retirada. */
        Entidade pop(); /* retira max */

        /* Descrição: constroi o heap, ordenando os valores armazenados nele.
        Entrada: não possui.
        Saída: não possui. */
        void constroi();

        /* Descrição: método utilizado para auxiliar a construção do heap.
        Entrada: dois inteiros, que representam os limites esquerdo e direito de índices do heap.
        Saída: não possui. */
        void refaz(int esq, int dir);

        /* Descrição: checa se o heap está vazio.
        Entrada: não possui.
        Saída: verdadeiro se o heap está vazio, falso caso contrário. */
        bool vazio();

        /* Descrição: acessa o valor do atributo numElementos.
        Entrada: não possui.
        Saída: inteiro que representa o número de elementos no heap. */
        int getNumElementos();
};
