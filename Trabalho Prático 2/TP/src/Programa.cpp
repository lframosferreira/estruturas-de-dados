#include <iostream>
#include <sstream>

#include "Programa.hpp"
#include "msgassert.hpp"

void geraRodadas(std::ifstream& arqEntrada, int numEntidades, int& numFitasDinamico)
{   
    Entidade vetorDeEntidades[numEntidades];
    int count = 0;
    int numRodada = 1;
    std::string URL;
    int numVisitas;
    std::string line;
    while (std::getline(arqEntrada, line))
    {   
        if (!line.empty())
        {
            std::istringstream iss(line);
            iss >> URL >> numVisitas; 
            Entidade entidade(URL, numVisitas);
            vetorDeEntidades[count] = entidade;
            count++;
        }
        if (count == numEntidades || arqEntrada.peek() == EOF)
        {    
            std::string arqSaidaFitaOrdenada = "rodadas/rodada-" + std::to_string(numRodada) + ".txt";
            quickSort(vetorDeEntidades, count);
            escreveFitaOrdenada(arqSaidaFitaOrdenada, vetorDeEntidades, count);
            numFitasDinamico++;
            numRodada++;
            count = 0;
        }
    }
};

void escreveFitaOrdenada(std::string arqSaidaFitaOrdenada, Entidade* vetorDeEntidades, int numEntidadesEscrever)
{
    std::ofstream arq(arqSaidaFitaOrdenada);
    erroAssert(arq.is_open(), "Erro na abertura do arquivo de escrita da fita!");  
    for (int i = 0; i < numEntidadesEscrever; i++)
    {   
        arq << vetorDeEntidades[i].getURL() << " " << vetorDeEntidades[i].getNumVisitas() << std::endl;
    }
    arq.close();
};

void intercalaFitas(int numFitasDinamico, std::string& nomeArqSaida)
{   
    erroAssert(numFitasDinamico > 0, "O número de fitas deve ser maior que zero.");
    std::ifstream* vetorDeFitas = getFitas(numFitasDinamico);

    /* Cenário onde existe apenas uma fita, ou seja, não é necessário intercalar. */
    if (numFitasDinamico == 1)
    {   
        rename("rodadas/rodada-1.txt", nomeArqSaida.c_str());
        return;
    }

    std::ofstream arqSaida(nomeArqSaida);
    erroAssert(arqSaida.is_open(), "Erro na abertura do arquivo de saída!");
    Heap heap(numFitasDinamico);
    std::string auxURL;
    int auxNumVisitas;
    Entidade auxEntidade;
    for (int i = 0; i < numFitasDinamico; i++)
    {      
        vetorDeFitas[i] >> auxURL >> auxNumVisitas;
        auxEntidade = Entidade(auxURL, auxNumVisitas, i + 1);
        heap.add(auxEntidade);
    }
    
    heap.constroi();
    while (!heap.vazio())
    {   
        auxEntidade = heap.pop();
        arqSaida << auxEntidade.getURL() << " " << auxEntidade.getNumVisitas() << std::endl;
        int numArqOrigem = auxEntidade.getNumArqOrigem();
        if (vetorDeFitas[numArqOrigem - 1] >> auxURL >> auxNumVisitas)
        {   
            auxEntidade = Entidade(auxURL, auxNumVisitas, numArqOrigem);
            heap.add(auxEntidade);
        }
    }

    delete[] vetorDeFitas;
    arqSaida.close();
};

std::ifstream* getFitas(int numFitas)
{   
    erroAssert(numFitas >= 0, "O número de fitas deve ser maior que zero.");
    std::ifstream* vetorDeFitas = new std::ifstream[numFitas];
    for (int i = 0; i < numFitas; i++)
    {
        vetorDeFitas[i].open("rodadas/rodada-" + std::to_string(i + 1) + ".txt");
    }
    return vetorDeFitas;
};
