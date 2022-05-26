#include <iostream>
#include <string>

struct Camiseta
{   
    Camiseta(){}
    Camiseta(std::string nomeEstudante, std::string cor, std::string tamanho)
    {
        this->nomeEstudante = nomeEstudante;
        this->cor = cor;
        this->tamanho = tamanho;
    }
    std::string nomeEstudante;
    std::string cor;
    std::string tamanho;   
};

bool operator < (Camiseta& lhs, Camiseta& rhs)
{
    if (lhs.cor == rhs.cor && lhs.tamanho == rhs.tamanho)
    {
        return lhs.nomeEstudante < rhs.nomeEstudante;
    }
    if (lhs.cor == rhs.cor)
    {
        return lhs.tamanho > rhs.tamanho;
    }
    return lhs.cor < rhs.cor;
}

bool operator > (Camiseta& lhs, Camiseta& rhs)
{
    if (lhs.cor == rhs.cor && lhs.tamanho == rhs.tamanho)
    {
        return lhs.nomeEstudante > rhs.nomeEstudante;
    }
    if (lhs.cor == rhs.cor)
    {
        return lhs.tamanho < rhs.tamanho;
    }
    return lhs.cor > rhs.cor;
}

template <class T>
void swap(T& a, T& b)
{
    T aux = a;
    a = b;
    b = aux;
}

void particao(int esq, int dir, int *i, int *j, Camiseta* vetorDeCamisetas)
{
    *i = esq;
    *j = dir;
    Camiseta pivo = vetorDeCamisetas[(*i + *j) / 2];
    do
    {
        while (pivo > vetorDeCamisetas[*i]) (*i)++;
        while (pivo < vetorDeCamisetas[*j]) (*j)--;
        if (*i <= *j)
        {
            swap(vetorDeCamisetas[*i], vetorDeCamisetas[*j]);
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void ordena(int esq, int dir, Camiseta* vetorDeCamisetas)
{
    int i, j;
    particao(esq, dir, &i, &j, vetorDeCamisetas);
    if (esq < j) ordena(esq, j, vetorDeCamisetas);
    if (i < dir) ordena(i, dir, vetorDeCamisetas);
}

void quicksort(Camiseta* vetorDeCamisetas, int tamanho)
{
    ordena(0, tamanho - 1, vetorDeCamisetas);
}


int main(int argc, char* argv[])
{
    int n;
    std::string nomeEstudante;
    std::string cor;
    std::string tamanho;
    std::cin >> n;
    while (n != 0)
    {   
        getchar();
        if (n == 0) break; /* Condição de parada. */
        Camiseta vetorDeCamisetas[n];

        for (int i = 0; i < n; i++)
        {   
            std::getline(std::cin, nomeEstudante);
            std::cin >> cor >> tamanho;
            getchar();
            vetorDeCamisetas[i] = Camiseta(nomeEstudante, cor, tamanho);
        }
        quicksort(vetorDeCamisetas, n);
        for (int i = 0; i < n; i++)
        {
            std::cout << vetorDeCamisetas[i].cor << " " << vetorDeCamisetas[i].tamanho << " " << vetorDeCamisetas[i].nomeEstudante << std::endl;
        }
        std::cin >> n;
        if ( n != 0) std::cout << std::endl;
    }
    return 0;
}