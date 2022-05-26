#include "Escalonador.hpp"

#include <iostream>

Escalonador::Escalonador(){
    this->filaDeSitios = new Fila<Sitio>();

}

Escalonador::~Escalonador(){
    delete this->filaDeSitios;
}

std::string Escalonador::leArquivo(std::ifstream& arqEntrada)
{
    std::string linha;
    std::getline(arqEntrada, linha);
    return linha;
}

void Escalonador::realizaComando(std::ifstream& arqEntrada, std::ofstream& arqSaida)
{
    std::string linha = this->leArquivo(arqEntrada);
    erroAssert(!linha.empty() , "Linha lida está vazia!");
    std::istringstream str(linha);
    std::string comando;
    str >> comando;
    switch(getComando(comando))
    {

        case ADD_URLS:
        {
            std::string quantidade;
            str >> quantidade;
            int numURLsAdd = std::stoi(quantidade);
            this->addURLs(numURLsAdd, arqEntrada);
            break;
        }

        case ESCALONA_TUDO:
        {
            this->escalonaTudo(arqSaida);
            break;
        }  

        case ESCALONA:
        {
            std::string quantidade;
            str >> quantidade;
            int numURLsEscalonadas = std::stoi(quantidade);
            this->escalona(numURLsEscalonadas, arqSaida);
            break;
        }  

        case ESCALONA_HOST:
        {
            std::string sitio;
            std::string quantidade;
            str >> sitio;
            str >> quantidade;
            int numURLsHostEscalonadas = std::stoi(quantidade);
            this->escalonaHost(sitio, numURLsHostEscalonadas, arqSaida);
            break;
        }

        case VER_HOST:
        {
            std::string sitio;
            str >> sitio;
            this->verHost(sitio, arqSaida);
            break;
        }

        case LISTA_HOSTS:
        {
            this->listaHosts(arqSaida);
            break;
        }

        case LIMPA_HOST:
        {
            std::string sitio;
            str >> sitio;
            this->limpaHost(sitio);
            break;
        }

        case LIMPA_TUDO:
        {
            this->limpaTudo();
            break;
        }
        
        default:
        {   
            std::cout << "Nenhum caso foi lido." << std::endl;
            exit(1);
        }
    }
}

void Escalonador::addURLs(int numURLsAdd, std::ifstream& arqEntrada)
{   
    std::string mURL;
    for (int i = 0; i < numURLsAdd; i++)
    {
        mURL = this->leArquivo(arqEntrada);
        if (validaURL(mURL)){
            reduzURL(mURL);
            std::string sitio = URLparaSitio(mURL);
            if (!this->filaDeSitios->contem(sitio))
            {   
                this->filaDeSitios->enfileira(sitio);
                this->filaDeSitios->getSitio(sitio)->valor->listaDeURLs->insere(mURL);
            }
            if (!this->filaDeSitios->getSitio(sitio)->valor->listaDeURLs->contem(mURL))
            {   
                this->filaDeSitios->getSitio(sitio)->valor->listaDeURLs->insere(mURL);
            }          
        }
    }
}

void Escalonador::escalonaTudo(std::ofstream& arqSaida)
{

    if (this->filaDeSitios->estaVazia()) return;

    int numTotalDeURLs = this->numTotalURLsArmazenadas();
    int numURLsEscalonadas = 0;

    while (numURLsEscalonadas < numTotalDeURLs)
    {
        Celula<Sitio>* melhorSitio = this->encontraMelhorSitio();
        Celula<URL>* auxURL = melhorSitio->valor->listaDeURLs->head->next;    
        arqSaida << auxURL->valor->getElemento() << std::endl;
        melhorSitio->valor->listaDeURLs->removeInicio();
        numURLsEscalonadas++;     
    }
}

void Escalonador::escalona(int qtdURLsEscalonar, std::ofstream& arqSaida)
{   
    if (this->filaDeSitios->estaVazia()) return;
    int numURLsEscalonadas = 0;
    int numTotalDeURLs = this->numTotalURLsArmazenadas();
    while (numURLsEscalonadas < numTotalDeURLs)
    {   
        Celula<Sitio>* melhorSitio = this->encontraMelhorSitio();
        Celula<URL>* auxURL = melhorSitio->valor->listaDeURLs->head->next;
        arqSaida << auxURL->valor->getElemento() << std::endl;
        melhorSitio->valor->listaDeURLs->removeInicio();
        numURLsEscalonadas++;    
        if (numURLsEscalonadas == qtdURLsEscalonar) return;
    }
}

void Escalonador::escalonaHost(std::string& sitio, int qtdURLsHostEscalonar, std::ofstream& arqSaida)
{   
    Celula<Sitio>* auxSitio = this->filaDeSitios->getSitio(sitio);
    if (auxSitio == nullptr) return;
    if (auxSitio->valor->listaDeURLs->estaVazia()) return;
    Celula<URL>* auxURL = auxSitio->valor->listaDeURLs->head->next;
    int numURLsEscalonadas = 0;
    while (auxURL->next)
    {
        arqSaida << auxURL->valor->getElemento() << std::endl;
        auxSitio->valor->listaDeURLs->removeInicio();
        numURLsEscalonadas++;
        if (numURLsEscalonadas == qtdURLsHostEscalonar) return;
        auxURL = auxURL->next;
    }
}

void Escalonador::verHost(std::string& sitio, std::ofstream& arqSaida)
{
    Celula<Sitio>* auxSitio = this->filaDeSitios->getSitio(sitio);
    if (auxSitio == nullptr) return;
    if (auxSitio->valor->listaDeURLs->estaVazia()) return;
    Celula<URL>* auxURL = auxSitio->valor->listaDeURLs->head->next;
    while (auxURL->next)
    {
        arqSaida << auxURL->valor->getElemento() << std::endl;
        auxURL = auxURL->next;
    }
}

void Escalonador::listaHosts(std::ofstream& arqSaida)
{   
    if (this->filaDeSitios->estaVazia()) return;
    Celula<Sitio>* auxSitio = this->filaDeSitios->head->next;
    while (auxSitio->next)
    {
        arqSaida << auxSitio->valor->getElemento() << std::endl;
        auxSitio = auxSitio->next;
    }
}

void Escalonador::limpaHost(std::string& sitio)
{
    Celula<Sitio>* auxSitio = this->filaDeSitios->getSitio(sitio);
    if (auxSitio == nullptr) return;
    auxSitio->valor->listaDeURLs->limpa();
}

void Escalonador::limpaTudo()
{   
    this->filaDeSitios->limpa();
}

Celula<Sitio>* Escalonador::encontraMelhorSitio()
{
    Celula<Sitio>* melhorSitio = this->filaDeSitios->head->next;
    Celula<Sitio>* auxSitio = melhorSitio->next;
    while (auxSitio->next)
    {
        if (auxSitio->valor->listaDeURLs->getNumElementos() > 
        melhorSitio->valor->listaDeURLs->getNumElementos())
        {
            melhorSitio = auxSitio;
            break;
        }
        auxSitio = auxSitio->next;
    }
    return melhorSitio;
}

int Escalonador::numTotalURLsArmazenadas()
{
    int numTotalDeURLs = 0;
    Celula<Sitio>* auxSitio = this->filaDeSitios->head->next;
    while (auxSitio->next)
    {
        numTotalDeURLs += auxSitio->valor->listaDeURLs->getNumElementos();
        auxSitio = auxSitio->next;
    }
    return numTotalDeURLs;
}

int getComando(std::string& comando){
    if (comando == "ADD_URLS") return ADD_URLS;
    if (comando == "ESCALONA_TUDO") return ESCALONA_TUDO;
    if (comando == "ESCALONA") return ESCALONA;
    if (comando == "ESCALONA_HOST") return ESCALONA_HOST;
    if (comando == "VER_HOST") return VER_HOST;
    if (comando == "LISTA_HOSTS") return LISTA_HOSTS;
    if (comando == "LIMPA_HOST") return LIMPA_HOST;
    if (comando == "LIMPA_TUDO") return LIMPA_TUDO;
    return 0;
}