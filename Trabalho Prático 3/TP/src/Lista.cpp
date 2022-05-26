#include "Lista.hpp"

/* Implementação da estrutura Celula. */

template <class T>
Celula<T>::Celula()
{
    this->proximo = nullptr;
};

template <class T>
Celula<T>::Celula(T valor)
{
    this->valor = valor;
    this->proximo = nullptr;
};

template <class T>
Celula<T>::~Celula()
{
    delete this->proximo;
};

/* Implementação da classe Lista. */

template <class T>
Lista<T>::Lista()
{   
    this->numElementos = 0;
    this->cabeca = nullptr;
    this->cauda = nullptr;
};

template <class T>
Lista<T>::~Lista()
{    /* checar isso */
    /* this->limpa(); */
};

template <class T>
void Lista<T>::insere(T& elemento)
{   

    /* Criação da nova célula  que será inserida. */
    Celula<T>* novaCelula = new Celula<T>(elemento);
    erroAssert(novaCelula != nullptr, "Nova célulanão foi alocada corretamente!");

    /* Caso em que a lista está vazia. */
    if (this->numElementos == 0)
    {   
        this->cabeca = novaCelula;
        this->cauda = novaCelula;
        this->numElementos++;
        return;
    }

    /* Caso em que a lista possui apenas um elemento. */
    if (this->numElementos == 1)
    {   
        this->cabeca->proximo = novaCelula;
        this->cauda = novaCelula;
        this->numElementos++;
        return;
    }

    /* Caso geral. */
    this->cauda->proximo = novaCelula;
    this->cauda = novaCelula;
    this->numElementos++;
    return;
};

template <class T>
void Lista<T>::remove(T& elemento)
{      

    if (this->cabeca->valor == elemento)
    {   
        Celula<T>* auxCelula = this->cabeca;
        this->cabeca = this->cabeca->proximo;
        delete auxCelula;
        this->numElementos--;
        return;
    }

    Celula<T>* prevCelula = this->cabeca;
    Celula<T>* currCelula = this->cabeca->proximo;

    while (currCelula != nullptr)
    {
        if (currCelula->valor == elemento)
        {
            if (currCelula == this->cauda)
            {
                prevCelula->proximo = currCelula->proximo;
                this->cauda = prevCelula;
                delete currCelula;
                this->numElementos--;
                return;
            }
            else
            {
                prevCelula->proximo = currCelula->proximo;
                delete currCelula;
                this->numElementos--;
                return;
            }
        }
        prevCelula = prevCelula->proximo;
        currCelula = currCelula->proximo;
    }
};

template <class T>
bool Lista<T>::contem(const T& elemento)
{   
    Celula<T>* auxCelula = this->cabeca;
    while (auxCelula != nullptr)
    {
        if (auxCelula->valor == elemento)
        {   
            return true;
        }
        auxCelula = auxCelula->proximo;
    }
    return false;
};

template <class T>
void Lista<T>::limpa()
{   
    /* Célula auxiliar para percorrer e deletar cada elemento da lista. */
    Celula<T>* auxCelula = this->cabeca;

    /* Percorre cada elemento da lista e os deleta, enquanto existirem. */
    while (auxCelula)
    {
        Celula<T>* celulaProxima = auxCelula->proximo;
        delete auxCelula;
        auxCelula = celulaProxima;
    }
    this->numElementos = 0;
    this->cabeca = nullptr;
    this->cauda = nullptr;
};

template <class T>
int Lista<T>::tamanho()
{
    return this->numElementos;
};

template <class T>
bool Lista<T>::vazia()
{
    return (this->numElementos == 0);
};

template <class T>
int Lista<T>::conta(T& elemento)
{
    int contador = 0;
    Celula<T>* auxCelula = this->cabeca;
    while (auxCelula)
    {
        if (auxCelula->valor == elemento)
        {
            contador++;
        }
        auxCelula = auxCelula->proximo;
    }
    return contador;
};


