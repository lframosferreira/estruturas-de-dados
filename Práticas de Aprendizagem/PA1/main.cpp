#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

/* Variáveis auxiliares para as ações do corvo de três olhos. */
const std::string crowScream = "caw caw";
const char closedEye = '-';
const char openEye = '*';

/* Descrição: Essa função transforma a string que representa o piscar do corvo de três olhos
em uma string com sua representação binária, de acordo com o enunciado.
line: Referência para a string que será transformada.
Saída: Não tem.*/
void blinkToBinary(std::string& blinkLine){
    std::replace(blinkLine.begin(), blinkLine.end(), closedEye, '0');
    std::replace(blinkLine.begin(), blinkLine.end(), openEye, '1');
}

/* Descrição: Essa função retorna o valor decimal de um número binário representado em uma string.
line: string que contêm a representação do valor binário.
Saída: Inteiro da representação decimal.*/
int binaryStringToDecimal(std::string binaryString){
    int sum = 0;
    int aux = binaryString.size() - 1;
    for (int i = 0; i < binaryString.size(); i++){
        int auxValue = (int) binaryString.at(i) - 48;
        sum += auxValue * pow(2, aux);
        aux--;
    }
    return sum;
}

int main(){
    int crowScreamCount = 0;
    std::string inputLine;
    int sum = 0;
    while (crowScreamCount < 3){
        std::getline(std::cin, inputLine);
        if (inputLine == crowScream){
            crowScreamCount++;
            std::cout << sum << std:: endl;
            sum = 0;
        }
        else {
            blinkToBinary(inputLine);
            sum += binaryStringToDecimal(inputLine);
        }
    }
    return 0;
}