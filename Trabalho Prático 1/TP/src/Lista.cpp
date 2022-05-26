#include "Lista.hpp"
#include "msgassert.hpp"

#include <iostream>

template <class T>
Lista<T>::Lista()
{
    EstruturaEncadeada<T>();
}

template <class T>
Lista<T>::~Lista()
{
    this->limpa();
    delete this->head;
}

template <class T>
void Lista<T>::insere(std::string& mURL)
{   
    T* novaURL = new T(mURL);
    erroAssert(novaURL, "O novo elemento da lista não foi alocado corretamente!");
    Celula<T>* novaCelula = new Celula<T>(novaURL);
    erroAssert(novaCelula, "A nova célula da lista não foi alocada corretamente!");
    Celula<T>* auxCelula = this->procuraPosInsercao(novaCelula->valor->quantidadeDeBarras);
    auxCelula->previous->next = novaCelula;
    novaCelula->previous = auxCelula->previous;
    auxCelula->previous = novaCelula;
    novaCelula->next = auxCelula;
    this->numElementos++;
    return;

}

template <class T>
void Lista<T>::remove(std::string& mURL)
{
    Celula<T>* auxCelula = this->head->next;
    while (auxCelula->next)
    {
        if (auxCelula->valor->getElemento() == mURL)
        {
            auxCelula->next->previous = auxCelula->previous;
            auxCelula->previous->next = auxCelula->next;
            delete auxCelula;
            this->numElementos--;
            return;
        }
        auxCelula = auxCelula->next;
    }
}

template <class T>
void Lista<T>::removeInicio(){
    if (this->estaVazia()) return;
    Celula<T>* auxCelula = this->head->next;
    this->head->next->next->previous = this->head;
    this->head->next = this->head->next->next;
    delete auxCelula;
    this->numElementos--;
}

template <class T>
void Lista<T>::print()
{
    std::cout << "A lista possui " << this->numElementos << " elementos.\n";
    Celula<T>* auxCelula = this->head->next;
    while (auxCelula->next)
    {
        std::cout << auxCelula->valor->mURL << "->";
        auxCelula = auxCelula->next;
    }
    std::cout << std::endl;
}

template <class T>
Celula<T>* Lista<T>::procuraPosInsercao(int quantidadeBarras)
{
    if (this->estaVazia()) return this->tail;
    Celula<T>* auxCelula = this->head->next;
    while (auxCelula->next)
    {
        if (quantidadeBarras < auxCelula->valor->quantidadeDeBarras)
        {
            return auxCelula;
        }
        auxCelula = auxCelula->next;
    }
    return this->tail;
}
