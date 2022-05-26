#pragma once

#include <utility>

/* Descrição: função para realizar a troca de valores entre dois pares, utilizada
no algoritmo de ordenação quicksort.
Entrada: dois ponteiros para variáveis do tipo par(int, double).
Saída: não possui. */
void swap(std::pair<int, double>* a, std::pair<int, double>* b);

/* Descrição: função de particionamento, utilizada no algoritmo de ordenação quicksort.
Entrada: dois inteiros, representando os índices inicial e final do vetor, dois
ponteiros para inteiros, que representam os índices que vão percorrer o vetor, assim
como o próprio vetor. 
Saída: não possui. */ 
void particao(int esq, int dir, int* i, int* j, std::pair<int, double>* vetor);

/* Descrição: função recursiva que será utilizada no algoritmo de ordenação quicksort.
Entrada: dois inteiros que representam o intervalo do vetor a ser ordenado e o vetor 
de std::pair<int, double> que deve ser ordenado. 
Saída: não possui. */
void ordena(int esq, int dir, std::pair<int, double>* vetor);

/* Descrição: função principal do algoritmo de ordenação quicksort.
Entrada: vetor que deve ser ordenado e um inteiro que representa
o tamanho do vetor.
Saída: não possui. */ 
void quickSort(std::pair<int, double>* vetor, int tamanhoVetor);

/* Descrição: função para comparação de um par (ID do documento, Grau de similaridade), específico
para este trabalho.
Entrada: referências para os pares que devem ser comparados.
Saída: verdadeiro caso a comparação seja verdadeira, falso caso contrário. */
bool compare(const std::pair<int, double>& p1, const std::pair<int, double> p2);