#include <fstream>
#include "Escalonador.hpp"
#include <iostream>
#include <sstream>

int main(int argc, char* argv[])
{
    std::string nomeArqEntrada = argv[1];
    std::ifstream arqEntrada;
    arqEntrada.open(nomeArqEntrada);
    erroAssert(arqEntrada.is_open(), "Erro na abertura do arquivo de entrada!");
  
    std::string nomeArqSaida;
    std::istringstream str(nomeArqEntrada);
    std::getline(str, nomeArqSaida, '.');
    nomeArqSaida = nomeArqSaida + "-out.txt";

    std::ofstream arqSaida;
    arqSaida.open(nomeArqSaida);
    erroAssert(arqSaida.is_open(), "Erro na abertura do arquivo de saída!");

    Escalonador escalonador;

    while (!arqEntrada.eof())
    {
        escalonador.realizaComando(arqEntrada, arqSaida);
    }

    arqEntrada.close();
    arqSaida.close();
    return 0;
};