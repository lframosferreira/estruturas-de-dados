#include "QuickSort.hpp"

#include <iostream>
#include <cmath>

void swap(std::pair<int, double>& a, std::pair<int, double>& b)
{   
    std::pair<int, double> aux = a;
    a = b;
    b = aux;
};

void particao(int esq, int dir, int* i, int* j, std::pair<int, double>* vetor)
{   
    std::pair<int, double> pivo;
    *i = esq, *j = dir;
    pivo = vetor[(*i + *j)/2]; 
    do
    {
        while (compare(vetor[*i], pivo)) (*i)++;
        while (compare(pivo, vetor[*j])) (*j)--;
        if (*i <= *j)
        {
            swap(vetor[*i], vetor[*j]);
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
};

void ordena(int esq, int dir, std::pair<int, double>* vetor)
{   
    int i, j;
    particao(esq, dir, &i, &j, vetor);
    if (esq < j) ordena(esq, j, vetor);
    if (i < dir) ordena(i, dir, vetor);
};

void quickSort(std::pair<int, double>* vetor, int tamanhoVetor)
{   
    ordena(0, tamanhoVetor - 1, vetor);
};

bool compare(const std::pair<int, double>& p1, const std::pair<int, double> p2)
{   
    const double EPSILON = 3e-08;
    if (fabs(p1.second - p2.second) < EPSILON)
    {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
};