#ifndef SITIO_H
#define SITIO_H

#include <string>

#include "URL.hpp"

template <class T>
class Lista;

/* A estrutura sitio representa os Hosts que serão trabalhados no trabalho. */
struct Sitio
{   

    /* Descrição: acessa o elemento principal do tipo string que representa o sítio.
    Entrada: não possui.
    Saída: string que representa o sítio. */
    std::string getElemento();

    std::string mSitio;

    Lista<URL>* listaDeURLs;

    /* Construtor vazio. */
    Sitio();

    /* Construtor com parâmetro de inicialização. */
    Sitio(std::string mSitio);

    /* Destrutor. */
    ~Sitio();
};

#endif