#include "Termo.hpp"

Termo::Termo(){};

Termo::Termo(std::string& palavra, const int& tamanhoMaxPares)
{   
    erroAssert(!palavra.empty(), "A palavra esta vazia!");
    erroAssert(tamanhoMaxPares > 0, "O tamanho do vetor de pares deve ser maior que zero!");

    this->palavra = palavra;

    this->tamanhoMaxPares = tamanhoMaxPares;

    this->atualPosParesIDnumDeOcorrencias = 0;

    this->atualPosParesIDPeso = 0;

    this->paresIDnumDeOcorrencias = new std::pair<int, int>[tamanhoMaxPares];

    this->paresIDPeso = new std::pair<int, double>[tamanhoMaxPares];
};

Termo::~Termo(){};

std::string Termo::getPalavra()
{
    return this->palavra;
};

int Termo::getNumDeOcorrencias(const int& ID)
{   
    for (int i = 0; i < this->atualPosParesIDnumDeOcorrencias; i++)
    {   
        std::pair<int, int> par = this->paresIDnumDeOcorrencias[i];
        if (par.first == ID)
        {
            return par.second;
        }
    }
    return 0;
};

double Termo::getPeso(const int& ID)
{   
    for (int i = 0; i < this->atualPosParesIDPeso; i++)
    {   
        std::pair<int, double> par = this->paresIDPeso[i];
        if (par.first == ID)
        {   
            return par.second;
        }
    }
    return 0;
};

int Termo::getTamanhoParIDnumDeOcorrencias()
{
    return this->atualPosParesIDnumDeOcorrencias;
};

void Termo::insereParIDnumDeOcorrencias(const int& ID, const int& numDeOcorrencias)
{   
    erroAssert(numDeOcorrencias > 0, "O número de ocorrências a ser inserido deve ser positivo!");

    std::pair<int, int> par = {ID, numDeOcorrencias};
    this->paresIDnumDeOcorrencias[this->atualPosParesIDnumDeOcorrencias] = par;
    this->atualPosParesIDnumDeOcorrencias++;
}

bool Termo::contemParIDnumDeOcorrencias(const int& ID, const int& numDeOcorrencias)
{
    erroAssert(numDeOcorrencias >= 0, "O número de ocorrências procurado deve ser positivo!");
    for (int i = 0; i < this->atualPosParesIDnumDeOcorrencias; i++)
    {   
        std::pair<int, int> par1 = this->paresIDnumDeOcorrencias[i];
        std::pair<int, int> par2 = {ID, numDeOcorrencias};
        if (par1 == par2)
        {
            return true;
        }
    }
    return false;
};

void Termo::insereParIDPeso(const int& ID, const double& peso)
{   
    erroAssert(peso >= 0, "O peso a ser inserido deve ser positivo!");

    std::pair<int, double> par = {ID, peso};
    this->paresIDPeso[this->atualPosParesIDPeso] = par;
    this->atualPosParesIDPeso++;
};

bool Termo::contemID(const int& ID)
{
    for (int i = 0; i < this->atualPosParesIDnumDeOcorrencias; i++)
    {
        if (this->paresIDnumDeOcorrencias[i].first == ID)
        {
            return true;
        }
    }
    return false;
};
