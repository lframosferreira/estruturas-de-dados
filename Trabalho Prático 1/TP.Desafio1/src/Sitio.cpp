#include "Sitio.hpp"
#include "Lista.hpp"

Sitio::Sitio(){}

Sitio::Sitio(std::string mSitio)
{
    this->mSitio = mSitio;
    this->listaDeURLs = new Lista<URL>();
}

Sitio::~Sitio()
{
    delete this->listaDeURLs;
}

std::string Sitio::getElemento()
{
    return this->mSitio;
}