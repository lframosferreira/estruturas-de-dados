#include "URL.hpp"

#include <iostream>

URL::URL(){}

URL::URL(std::string mURL)
{
    this->mURL = mURL;
    this->contaBarras();
}

URL::~URL(){}

std::string URL::getElemento()
{
    return this->mURL;
}

void URL::contaBarras()
{
    int count = 0;
    for (std::string::iterator it = this->mURL.begin(); it != this->mURL.end(); it++){
        if (*it == '/'){
            count++;
        }
    }
    this->quantidadeDeBarras = count;
}

bool validaURL(std::string& mURL)
{      
    std::regex regularExpr(regexURL);
    for (int i = 0; i < 6; i++)
    {
        if (mURL.find(extensoesInvalidas[i]) != std::string::npos) return false;
    }
    return std::regex_match(mURL, regularExpr);
}

void reduzURL(std::string& mURL)
{
    if (mURL.back() == '/') mURL.pop_back();
    std::size_t pos = mURL.find("www.");
    if (pos != std::string::npos)
    {
        mURL.erase(pos, 4);
    }
    pos = mURL.find('#');
    if (pos != std::string::npos)
    {
        mURL.erase(pos);
    }
}

std::string URLparaSitio(std::string& mURL)
{
    std::istringstream str(mURL);
    str.seekg(7); //Tamanho do protocolo (http://)
    std::string sitio;
    std::getline(str, sitio, '/');
    return sitio;
}