#include "QuickSort.hpp"
#include "msgassert.hpp"

void swap(Entidade& a, Entidade& b)
{
    Entidade aux = a;
    a = b;
    b = aux;
};

void particao(int esq, int dir, int* i, int* j, Entidade* vetorDeEntidades)
{   
    erroAssert(esq >= 0, "Localizador esquerdo deve ser maior ou igual a zero.");
    erroAssert(dir >= 0, "Localizador direito deve ser maior ou igual a zero.");
    Entidade pivo;
    *i = esq, *j = dir;
    pivo = vetorDeEntidades[(*i + *j)/2]; 
    do
    {
        while (pivo < vetorDeEntidades[*i]) (*i)++;
        while (pivo > vetorDeEntidades[*j]) (*j)--;
        if (*i <= *j)
        {
            swap(vetorDeEntidades[*i], vetorDeEntidades[*j]);
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
};

void ordena(int esq, int dir, Entidade* vetorDeEntidades)
{   
    erroAssert(esq >= 0, "Localizador esquerdo deve ser maior ou igual a zero.");
    erroAssert(dir >= 0, "Localizador direito deve ser maior ou igual a zero.");
    int i, j;
    particao(esq, dir, &i, &j, vetorDeEntidades);
    if (esq < j) ordena(esq, j, vetorDeEntidades);
    if (i < dir) ordena(i, dir, vetorDeEntidades);
};

void quickSort(Entidade* vetorDeEntidades, int tamanhoVetor)
{   
    erroAssert(tamanhoVetor > 0, "O tamanho do vetor deve ser maior que zero.");
    ordena(0, tamanhoVetor - 1, vetorDeEntidades);
};
