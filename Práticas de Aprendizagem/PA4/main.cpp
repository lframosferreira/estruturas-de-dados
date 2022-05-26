#include <iostream>
#include <vector>
#include <string>

int getIndexMaiorElementoVetor(std::vector<double> v, int tamanho)
{
    double maior = v.at(0);
    int indexMaior = 0;
    for (int i = 1; i < tamanho; i++)
    {
        if (v.at(i) > maior)
        {
            maior = v.at(i);
            indexMaior = i;
        }
    }
    return indexMaior;
}

int main(int argc, char* argv[])
{   
    std::string password = "";
    std::vector<double> oleosidadeDasChaves;
    int numberOfDigits;
    int caso = 0;
    while(std::cin >> numberOfDigits)
    {   
        caso++;
        for (int i = 0; i < 10; i++)
        {   
            double oleosidade;
            std::cin >> oleosidade;
            oleosidadeDasChaves.push_back(oleosidade);
        }
        
        for (int i = 0; i < numberOfDigits; i++)
        {
            int indexMaior = getIndexMaiorElementoVetor(oleosidadeDasChaves, oleosidadeDasChaves.size());
            password += std::to_string(indexMaior);
            oleosidadeDasChaves.at(indexMaior) = -1;
        }
        std::cout << "Caso " << caso << ": " << password << std::endl; 
        oleosidadeDasChaves.clear();
        password.clear();
    }

    return 0;
}