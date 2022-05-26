#ifndef URL_H
#define URL_H

#include <regex>
#include <string>
#include <sstream>

/* Expressão Regular utilizada para validação da URL. */
#define regexURL "(http://)(www)?[A-Za-z0-9@:%._/+~=!-]+[\\?[A-Za-z0-9@:%._/+~=?!-]+]?[#[A-Za-z0-9@:%._/+~=?!-]+]?"

/* Vetor com extensões inválidas para a URL. */
const std::string extensoesInvalidas[6] = {".jpg", ".gif", ".mp3", ".avi", ".doc", ".pdf"};

/* A estrutura URL representa uma URL de um site. */
struct URL
{   

    /* Descrição: acessa o elemento principal do tipo string que representa a URL.
    Entrada: não possui.
    Saída: string que representa a URL. */
    std::string getElemento();

    std::string mURL;

    int quantidadeDeBarras;

    /* Construtor vazio. */
    URL();

    /* Construtor com parâmetro de inicialização. */
    URL(std::string mURL);

    /* Destrutor. */
    ~URL();

    /* Descrição: método para contagem do número de barras na URL. Armazena o valor obtido
    no atributo quantidadeDeBarras.
    Entrada: não possui.
    Saída: não possui. */
    void contaBarras();
};

/* Descrição: essa função irá validar uma URL para as especificações desejadas para o trabalho.
Entrada: Referência para a string que representa a URL.
Saída: Verdadeiro caso a URL seja válida, falso caso contrário. */
bool validaURL(std::string& mURL);

/* Descrição: essa função irá reduzir uma URL de acordo com as especificações do trabalho.
Entrada: Referência para a string que representa a URL.
Saída: não tem */
void reduzURL(std::string& mURL);

/* Descrição: essa função irá obter o sítio de uma URL. Ela deve ser utilizado somente após
a redução da URL com a função reduzURL().
Entrada: referência para string que representa a URL.
Saída: string que representa o sítio. */
std::string URLparaSitio(std::string& mURL);

#endif