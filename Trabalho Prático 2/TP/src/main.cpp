#include <iostream>
#include <fstream>

#include "Entidade.hpp"
#include "Programa.hpp"
#include "msgassert.hpp"
#include "Heap.hpp"
#include "memlog.hpp"

int main(int argc, char* argv[])
{   
    /* Abertura do arquivo de entrada, cujo nome é dado pelo primeiro parãmetro de linha de comando.*/
    std::string nomeArqEntrada = argv[1];
    std::ifstream arqEntrada(nomeArqEntrada);
    erroAssert(arqEntrada.is_open(), "Erro na abertura do arquivo de entrada!");

    /* Atribuição da variável que representa o nome do arquivo de saída do programa. */
    std::string nomeArqSaida = argv[2];

    /* Atribuição da variável que representa o número de entidades máximo por
    fita, cujo valor é dado pelo terceito parâmetro de linha de comando. */
    int numEntidades = std::stoi(argv[3]);

    /* Atribuição da variável que representa o número de fitas esperadas na execução
    do trabalho. Caso esse número seja menor do que o número necessário, o algoritmo de intercalação
    sofrerá mudanças. */
    if (argc == 5) 
    {   
        int numFitas = std::stoi(argv[4]);
    }

    /* Váriavel global que irá monitorar o número de fitas que foram criadas. */
    int numFitasDinamico = 0;

    geraRodadas(arqEntrada, numEntidades, numFitasDinamico);

    intercalaFitas(numFitasDinamico, nomeArqSaida);

    arqEntrada.close();

    return 0;
};
