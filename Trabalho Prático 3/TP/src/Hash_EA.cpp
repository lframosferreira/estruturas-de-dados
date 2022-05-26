#include "Hash_EA.hpp"

#include <iostream>

#include <cmath>


Hash_EA::Hash_EA(){};

Hash_EA::Hash_EA(int tamanho)
{   
    erroAssert(tamanho > 0, "O tamanho da tabela de hashing deve ser maior que zero!");
    
    this->tamanho = tamanho;

    this->tabela = new Termo[tamanho];

    this->retirado = new bool[tamanho];

    for (int i = 0; i < tamanho; i++) this->retirado[i] = false;

    this->vazio = new bool[tamanho];

    for (int i = 0; i < tamanho; i++) this->vazio[i] = true;

};


Hash_EA::~Hash_EA(){};

int Hash_EA::Hash(const std::string& palavra)
{
    int soma = 0;

    for (std::size_t i = 0; i < palavra.size(); i++)
    {
        int valorCaractere = fabs(palavra.at(i) - '0' - 49);  /* Valor inteiro de caracter */
        soma += valorCaractere * i;
    }   
    return soma % this->tamanho;
};  

void Hash_EA::insere(Termo termo)
{   
    
    Termo* aux = this->pesquisa(termo.getPalavra());

    erroAssert(aux == nullptr, "Erro: item já está presente na tabela de hashing!");

    int pos = this->Hash(termo.getPalavra());

    int i = 0;

    while (i < this->tamanho && !this->vazio[(pos + i) % this->tamanho] && !this->retirado[(pos + i) % this->tamanho])
    {
        i++;
    }

    erroAssert(i != this->tamanho, "Erro: a tabela está cheia!");
   
    this->tabela[(pos + i) % this->tamanho] = termo;
    this->vazio[(pos + i) % this->tamanho] = false;
    this->retirado[(pos + i) % this->tamanho] = false;

};

void Hash_EA::remove(Termo& termo)
{
    int pos = this->Hash(termo.getPalavra());

    int i = 0;

    while (i < this->tamanho && !this->vazio[(pos + i) % this->tamanho] &&
    (this->tabela[(pos + i) % this->tamanho].getPalavra() != termo.getPalavra()))
    {
        i++;
    }

    bool condicao = (this->tabela[(pos + i) % this->tamanho].getPalavra() == termo.getPalavra()) && 
    !this->retirado[(pos + i) % this->tamanho];

    erroAssert(condicao, "Erro: item não está presente!");
   
    this->retirado[(pos + i) % this->tamanho] = true;
  
};

bool Hash_EA::contem(const std::string& palavra)
{
    
    int pos = this->Hash(palavra);

    int i = 0;

    while (i < this->tamanho && !this->vazio[(pos + i) % this->tamanho] &&
    (this->tabela[(pos + i) % this->tamanho].getPalavra() != palavra))
    {
        i++;
    }

    if ((this->tabela[(pos + i) % this->tamanho].getPalavra() == palavra) && 
    !this->retirado[(pos + i) % this->tamanho])
    {
        return true;
    }   

    return false;
};

Termo* Hash_EA::pesquisa(const std::string& palavra)
{
    Termo* aux = nullptr;

    int pos = this->Hash(palavra);

    int i = 0;

    while (i < this->tamanho && !this->vazio[(pos + i) % this->tamanho] &&
    (this->tabela[(pos + i) % this->tamanho].getPalavra() != palavra))
    {
        i++;
    }

    if ((this->tabela[(pos + i) % this->tamanho].getPalavra() == palavra) && 
    !this->retirado[(pos + i) % this->tamanho])
    {   
       
        aux = &this->tabela[(pos + i) % this->tamanho];
    }   

    return aux;
};

Termo* Hash_EA::at(const int& posicao)
{   
    erroAssert(posicao < this->tamanho && posicao >= 0, "Erro: posição requisitada está fora do tamanho da tabela!");
    if (this->vazio[posicao] || this->retirado[posicao])
    {
        return nullptr;
    }
    return &this->tabela[posicao];
};

int Hash_EA::getTamanho()
{
    return this->tamanho;
};
