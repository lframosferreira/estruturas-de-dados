#include <fstream>

#include "Heap.hpp"
#include "msgassert.hpp"

Heap::Heap(){};

Heap::Heap(int tamanho)
{   
    erroAssert(tamanho > 0, "O tamanho do heap deve ser maior que zero.");
    this->numElementos = 0;
    this->vetorDeEntidades = new Entidade[tamanho + 1];
};

Heap::~Heap()
{
    delete[] this->vetorDeEntidades;
};

void Heap::add(Entidade entidade)
{   
    this->numElementos++;
    this->vetorDeEntidades[this->numElementos] = entidade; 
    this->constroi(); 
}

Entidade Heap::pop()
{   
    Entidade maxEntidade;
    if (this->vazio()) return Entidade();
    maxEntidade = this->vetorDeEntidades[1];
    this->vetorDeEntidades[1] = this->vetorDeEntidades[this->numElementos];
    this->numElementos--;
    this->refaz(1, this->numElementos);
    return maxEntidade;
}

void Heap::constroi()
{   
    int tamanho = this->numElementos;
    int esq = (tamanho / 2) + 1;
    while (esq > 1)
    {
        esq--;
        this->refaz(esq, tamanho);
    }
};

void Heap::refaz(int esq, int dir)
{   
    erroAssert(esq >= 1, "Localizar esquerdo deve ser maior que um.");
    erroAssert(dir >= 0, "Localizar direito deve ser maior que zero.");
    int i = esq;
    int j = i * 2;
    Entidade auxEntidade = this->vetorDeEntidades[i];
    while (j <= dir)
    {
        if (j < dir)
        {
            if (this->vetorDeEntidades[j] < this->vetorDeEntidades[j + 1])
            {
                j++;
            }
        }
        if (auxEntidade >= this->vetorDeEntidades[j]) break;
        this->vetorDeEntidades[i] = this->vetorDeEntidades[j];
        i = j;
        j = i * 2;
    }
    this->vetorDeEntidades[i] = auxEntidade;
};

bool Heap::vazio()
{
    return (this->numElementos == 0);
};

int Heap::getNumElementos()
{
    return this->numElementos;
};
