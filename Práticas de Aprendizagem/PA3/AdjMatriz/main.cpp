#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define WARD 1001

int treeBeauty = 0;

std::vector<int> galhosCortados;

std::map<int, int> parPaiFilho;

std::map<int, int> everySubTreeBeauty;

int getFatherBranchBeauty(int** matriz, int numeroDeNos, int index)
{   
    if (index == 0) return 0;
    int fatherBranchBeauty = matriz[(*parPaiFilho.find(index)).second][index];
    return fatherBranchBeauty;
};

int getSubTreeBeauty(int index, int** matriz, int numeroDeNos)
{   
    if (index == numeroDeNos) return 0;
    if (everySubTreeBeauty.count(index))
    {   
        return (*everySubTreeBeauty.find(index)).second;
    }
    int subTreeBeauty = getFatherBranchBeauty(matriz, numeroDeNos, index);
    for (int j = index + 1; j < numeroDeNos; j++)
    {   
        if (matriz[index][j] != WARD)
        {      
            subTreeBeauty += getSubTreeBeauty(j, matriz, numeroDeNos);
        }
    }
    if (!everySubTreeBeauty.count(index))
        {
            everySubTreeBeauty.insert({index, subTreeBeauty});
        }
    return subTreeBeauty;
};

int optimizeTree(int** matriz, int numeroDeNos)
{
    int numCortes = 0;
    for (int i = numeroDeNos - 1; i >= 0; i--)
    {   
        if (!everySubTreeBeauty.count(i))
        {
            everySubTreeBeauty.insert({i, getSubTreeBeauty(i, matriz, numeroDeNos)});
        }
        if ((*everySubTreeBeauty.find(i)).second < 0)
        {       
            int fatherNode = (*parPaiFilho.find(i)).second;
            galhosCortados.push_back(fatherNode);
            treeBeauty -= (*everySubTreeBeauty.find(i)).second;
            everySubTreeBeauty.erase(i);
            numCortes++;
        }
    }
    return numCortes;
};

int main(int argc, char* argv[])
{

    int numeroDeNos;

    scanf("%d", &numeroDeNos);

    int** matriz = new int*[numeroDeNos];
    for (int i = 0; i < numeroDeNos; i++)
    {
        matriz[i] = new int[numeroDeNos];
    }

    for (int i = 0; i < numeroDeNos; i++)
    {
        for (int j = 0; j < numeroDeNos; j++)
        {
            matriz[i][j] = WARD;
        }
    }

    int di, ai, bi, wi;

    for (int i = 0; i < numeroDeNos - 1; i++)
    {
        scanf("%d%d%d%d", &di, &ai, &bi, &wi);
        if (ai < bi)
        {
            matriz[ai][bi] = wi;
            parPaiFilho.insert({bi, ai});
        }
        else{
            matriz[bi][ai] = wi;
            parPaiFilho.insert({ai, bi});
        }
        treeBeauty += wi;
    }

    int numCortes = optimizeTree(matriz, numeroDeNos);

    std::cout << treeBeauty << " " << numCortes << std::endl;

    sort(galhosCortados.begin(), galhosCortados.end());

    for (auto e: galhosCortados)
    {
        std::cout << e << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < numeroDeNos;i++)
    {
        delete[] matriz[i];
    }

    return 0;
};