#include "EstruturaEncadeada.hpp"
#include "msgassert.hpp"

#include <iostream>

template <class T>
EstruturaEncadeada<T>::EstruturaEncadeada()
{
    this->numElementos = 0;
    this->head = new Celula<T>();
    this->tail = new Celula<T>();
    this->head->next = this->tail;
    this->tail->previous = this->head;
    erroAssert(this->head, "A célula cabeça não foi alocada corretamente!");
    erroAssert(this->tail, "A célula cauda não foi alocada corretamente!");
}

template <class T>
EstruturaEncadeada<T>::~EstruturaEncadeada(){}

template <class T>
int EstruturaEncadeada<T>::getNumElementos()
{
    return this->numElementos;
}

template <class T>
bool EstruturaEncadeada<T>::estaVazia()
{
    return (this->numElementos == 0);
}

template <class T>
void EstruturaEncadeada<T>::limpa()
{
    Celula<T>* auxCelula = this->head->next;
    while (auxCelula->next)
    {
        this->head->next = auxCelula->next;
        delete auxCelula;
        auxCelula = this->head->next;
    }
    this->numElementos = 0;
    this->head->next = this->tail;
    this->tail->previous = this->head;
}

template <class T>
bool EstruturaEncadeada<T>::contem(std::string& elemento)
{
    if (this->estaVazia()) return false;
    Celula<T>* auxCelula = this->head->next;
    while (auxCelula && auxCelula != this->tail)
    {
        if (auxCelula->valor->getElemento() == elemento)
        {
            return true;
        }
        auxCelula = auxCelula->next;
    }
    return false;
}