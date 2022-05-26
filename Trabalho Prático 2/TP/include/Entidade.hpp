#pragma once

#include <string>
#include <iostream>

/* A classe Entidade representa uma entidade, tipo de item utilizado no programa. */
class Entidade
{
    private:

        std::string URL;

        int numVisitas;
        
        int numArqOrigem;

    public:

        /* Descrição: construtor vazio.
        Entrada: não possui.
        Saída: não possui. */
        Entidade();

        /* Descrição: construtor com dois parâmetros de inicialização.
        Entrada: string que representa a URL e inteiro que representa seu número de visitas.
        Saída: não possui. */
        Entidade(std::string URL, int numVisitas);

        /* Descrição: construtor vazio.
        Entrada: string que representa a URL, inteiro que representa seu número de visitas
        e inteiro que representa o número do arquivo de origem da entidade.
        Saída: não possui. */
        Entidade(std::string URL, int numVisitas, int numArqOrigem);

        /* Descrição: destrutor vazio.
        Entrada: não possui.
        Saída: não possui. */
        ~Entidade();

        /* Descrição: acessa o valor do atributo URL.
        Entrada: não possui.
        Saída: string que representa a URL. */
        const std::string getURL();

        /* Descrição: acessa o valor do atributo numVisitas.
        Entrada: não possui.
        Saída: inteiro que representa o número de visitas. */
        const int getNumVisitas();

        /* Descrição: acessa o valor do atributo numArqOrigem.
        Entrada: não possui.
        Saída: inteiro que representa o númerp do arquivo de origem. */
        const int getNumArqOrigem();

        /* Descrição: função amiga da classe, que é a sobrecarga do operador < para
        funcionar sobre variáveis do tipo entidade.
        Entrada: Duas variáveis do tipo entidade. 
        Saída: verdadeiro se a primeira for menor que a segunda, falso caso contrário. */
        friend const bool operator<(const Entidade& entidade1, const Entidade& entidade2);

        /* Descrição: função amiga da classe, que é a sobrecarga do operador > para
        funcionar sobre variáveis do tipo entidade.
        Entrada: Duas variáveis do tipo entidade. 
        Saída: verdadeiro se a primeira for maior que a segunda, falso caso contrário. */
        friend const bool operator>(const Entidade& entidade1, const Entidade& entidade2);

        /* Descrição: função amiga da classe, que é a sobrecarga do operador <= para
        funcionar sobre variáveis do tipo entidade.
        Entrada: Duas variáveis do tipo entidade. 
        Saída: verdadeiro se a primeira for menor ou igual que a segunda, falso caso contrário. */
        friend const bool operator<=(const Entidade& entidade1, const Entidade& entidade2);

        /* Descrição: função amiga da classe, que é a sobrecarga do operador >= para
        funcionar sobre variáveis do tipo entidade.
        Entrada: Duas variáveis do tipo entidade. 
        Saída: verdadeiro se a primeira for maior ou igual que a segunda, falso caso contrário. */
        friend const bool operator>=(const Entidade& entidade1, const Entidade& entidade2);
};
