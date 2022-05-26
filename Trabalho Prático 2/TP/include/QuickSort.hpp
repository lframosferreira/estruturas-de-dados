#pragma once

#include "Entidade.hpp"

/* Descrição: função para realizar a troca de valores entre duas entidades, utilizada
no algoritmo de ordenação quicksort.
Entrada: dois ponteiros para variáveis do tipo entidades.
Saída: não possui. */
void swap(Entidade* a, Entidade* b);

/* Descrição: função de particionamento, utilizada no algoritmo de ordenação quicksort.
Entrada: dois inteiros, representando os índices inicial e final do vetor, dois
ponteiros para inteiros, que representam os índices que vão percorrer o vetor, assim
como o próprio vetor de entidades. 
Saída: não possui. */ 
void particao(int esq, int dir, int* i, int* j, Entidade* vetorDeEntidades);

/* Descrição: função recursiva que será utilizada no algoritmo de ordenação quicksort.
Entrada: dois inteiros que representam o intervalo do vetor a ser ordenado e o vetor 
de entidade que deve ser ordenado. 
Saída: mão possui. */
void ordena(int esq, int dir, Entidade* vetorDeEntidades);

/* Descrição: função principal do algoritmo de ordenação quicksort.
Entrada: vetor de entidades que deve ser ordenado e um inteiro que representa
o tamanho do vetor.
Saída: não possui. */ 
void quickSort(Entidade* vetorDeEntidades, int tamanhoVetor);
