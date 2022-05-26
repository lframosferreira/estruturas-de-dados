#include "Celula.hpp"

template <class T>
Celula<T>::Celula()
{
    this->next = this->previous = nullptr;
}

template <class T>
Celula<T>::Celula(T* valor)
{
    this->next = this->previous = nullptr;
    this->valor = valor;
}

template <class T>
Celula<T>::~Celula()
{
    delete this->valor;
}
