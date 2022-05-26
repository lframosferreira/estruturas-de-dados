#ifndef CELULA_H
#define CELULA_H

#include <Sitio.hpp>

/* A estrutura Celula tem como função auxiliar na construção das estruturas de dados Fila e Lista,
implementadaspara o trabalho. Ela é feita como um template, com o intuito de ser flexível para o tipo
de dado que cada estrutura será composta. */
template <class T>
struct Celula
{
    T* valor;

    Celula* previous;

    Celula* next;

    /* Construtor vazio. */
    Celula<T>();

    /* Construtor com parâmetro de inicialização. */
    Celula<T>(T* valor);

    /* Destrutor. */
    ~Celula<T>();
};

/* Declaração das células que serão usadas. */
template class Celula<URL>;
template class Celula<Sitio>;

#endif