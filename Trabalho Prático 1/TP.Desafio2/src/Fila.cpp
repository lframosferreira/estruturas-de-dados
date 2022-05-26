#include "Fila.hpp"
#include "msgassert.hpp"

#include <iostream>

template <class T>
Fila<T>::Fila()
{   
    EstruturaEncadeada<T>();
}

template <class T>
Fila<T>::~Fila()
{
    this->limpa();
    delete this->head;
}

template <class T>
void Fila<T>::enfileira(std::string& mSitio)
{
    T* novoSitio = new T(mSitio);
    erroAssert(novoSitio, "Novo elemento da filanão foi alocada corretamente!");
    Celula<T>* novaCelula = new Celula<T>(novoSitio);
    erroAssert(novaCelula, "A célula auxiliar da fila não foi alocada corretamente!");
    this->tail->previous->next = novaCelula;
    novaCelula->previous = this->tail->previous;
    novaCelula->next = this->tail;
    this->tail->previous = novaCelula;
    this->numElementos++;
}

template <class T>
T Fila<T>::desenfileira()
{
    Celula<Sitio>* auxCelula = this->head->next;
    T* elementoDesenfileirado = this->head->next->valor;
    this->head->next->next->previous = this->head->next;
    this->head->next = this->head->next->next;
    delete auxCelula;
    this->numElementos--;
    return *elementoDesenfileirado;
}

template <class T>
void Fila<T>::print()
{
    std::cout << "A fila possui " << this->numElementos << " elementos.\n";
    Celula<T>* auxCelula = this->head->next;
    while (auxCelula->next)
    {
        std::cout << auxCelula->valor->mSitio << "->";
        auxCelula = auxCelula->next;
    }
    std::cout << std::endl;
}

template <class T>
Celula<T>* Fila<T>::getSitio(std::string& mSitio)
{
    if (this->estaVazia()) return nullptr;
    Celula<T>* auxCelula = this->head->next;
    while (auxCelula->next)
    {   
        if (auxCelula->valor->getElemento() == mSitio)
        {   
            return auxCelula;
        }
        auxCelula = auxCelula->next;
    }
    return nullptr;
}