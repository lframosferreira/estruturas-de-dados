#include "Entidade.hpp"
#include "msgassert.hpp"

Entidade::Entidade(){}

Entidade::~Entidade(){}

Entidade::Entidade(std::string URL, int numVisitas)
{   
    erroAssert(numVisitas >= 0, "O número de visitas da entidade deve ser maior que zero.");
    erroAssert(URL != "", "A URL não deve ser vazia.");
    this->URL = URL;
    this->numVisitas = numVisitas;
}

Entidade::Entidade(std::string URL, int numVisitas, int numArqOrigem)
{   
    erroAssert(numVisitas >= 0, "O número de visitas da entidade deve ser maior ou igual a zero.");
    erroAssert(URL != "", "A URL não deve ser vazia.");
    erroAssert(numArqOrigem > 0, "O número do arquivo de origem da entidade deve ser maior que zero.");
    this->URL = URL;
    this->numVisitas = numVisitas;
    this->numArqOrigem = numArqOrigem;
}

const std::string Entidade::getURL()
{
    return this->URL;
}

const int Entidade::getNumVisitas()
{
    return this->numVisitas;
}

const int Entidade::getNumArqOrigem()
{
    return this->numArqOrigem;
}

const bool operator<(const Entidade& entidade1, const Entidade& entidade2)
{   
    if (entidade1.numVisitas == entidade2.numVisitas)
    {
        return entidade1.URL > entidade2.URL;
    }
    return entidade1.numVisitas < entidade2.numVisitas;
};

const bool operator>(const Entidade& entidade1, const Entidade& entidade2)
{   
    if (entidade1.numVisitas == entidade2.numVisitas)
    {
        return entidade1.URL < entidade2.URL;
    }
    return entidade1.numVisitas > entidade2.numVisitas;
};

const bool operator<=(const Entidade& entidade1, const Entidade& entidade2)
{   
    if (entidade1.numVisitas == entidade2.numVisitas)
    {
        return entidade1.URL >= entidade2.URL;
    }
    return entidade1.numVisitas <= entidade2.numVisitas;
};

const bool operator>=(const Entidade& entidade1, const Entidade& entidade2)
{   
    if (entidade1.numVisitas == entidade2.numVisitas)
    {
        return entidade1.URL <= entidade2.URL;
    }
    return entidade1.numVisitas >= entidade2.numVisitas;
};
