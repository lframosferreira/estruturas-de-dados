#include "matriz.h"
#include "msgassert.h"
#include "memlog.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>

Matriz::Matriz(){}

Matriz::Matriz(int numLinhas, int numColunas, int ID){
    erroAssert(numLinhas > 0, "O número de linhas deve ser maior que zero.");
    erroAssert(numColunas > 0, " O número de colunas deve ser maior que zero.");
    this->ID = ID;
    this->numLinhas = numLinhas;
    this->numColunas = numColunas;
    this->matriz = new double* [this->numLinhas];
    for (int i = 0; i < this->numLinhas; i++){
        matriz[i] = new double[this->numColunas];
    }
}

Matriz::~Matriz(){
    for (int i = 0; i < this->numLinhas; i++){
        delete[] this->matriz[i];
    }
    delete[] this->matriz;
}

void Matriz::setNumLinhas(int numLinhas){
    erroAssert(numLinhas > 0, "O número de linhas deve ser maior que zero.");
    this->numLinhas = numLinhas;
    ESCREVEMEMLOG((long int)(&(this->numLinhas)), sizeof(int), this->ID);
}

void Matriz::setNumColunas(int numColunas){
    erroAssert(numColunas > 0, " O número de colunas deve ser maior que zero.");
    this->numColunas = numColunas;
    ESCREVEMEMLOG((long int)(&(this->numColunas)), sizeof(int), this->ID);
}

void Matriz::setValorMatriz(int i, int j, double valor){
    erroAssert(i >= 0 && i < this->numLinhas, "i deve estar entre 0 e o número de linhas da matriz");
    erroAssert(j >= 0 && j < this->numColunas, "j deve estar entre 0 e o número de colunas da matriz.");
    this->matriz[i][j] = valor;
    ESCREVEMEMLOG((long int) (&(this->matriz[i][j])), sizeof(double), this->ID);
}

int Matriz::getNumLinhas() const {
    LEMEMLOG((long int)(&(this->numLinhas)),sizeof(int), this->ID);
    return this->numLinhas;
}

int Matriz::getNumColunas() const{
    LEMEMLOG((long int)(&(this->numColunas)),sizeof(int),this-> ID);
    return this->numColunas;
}

double Matriz::getValorMatriz(int i, int j) const{
    erroAssert(i >= 0 && i < this->numLinhas, "i deve estar entre 0 e o número de linhas da matriz");
    erroAssert(j >= 0 && j < this->numColunas, "j deve estar entre 0 e o número de colunas damatriz.");
    LEMEMLOG((long int)(&(this->matriz[i][j])), sizeof(double), this->ID);
    return this->matriz[i][j];
}

int Matriz::getID() const{
    LEMEMLOG((long int)(&(this->ID)), sizeof(int), this->ID);
    return this->ID;
}


double** Matriz::getMatriz() const {
    LEMEMLOG((long int)(&(this->matriz)),sizeof(double **), this->ID);
    return this->matriz;
}

double acessaMatriz(const Matriz& matriz){
    int i, j;
    double aux, s = 0.0;
    for (i = 0; i < matriz.getNumLinhas(); i++){
        for(j = 0; j < matriz.getNumColunas(); j++){
            aux = matriz.getMatriz()[i][j];
            s+=aux;
            LEMEMLOG((long int)(&(matriz.getMatriz()[i][j])),sizeof(double), matriz.getID());
        }
    }
    return s; // apenas para evitar que acesso seja eliminado
}


Matriz* somaMatriz(const Matriz& matriz1, const Matriz& matriz2){
    erroAssert(matriz1.getNumLinhas() == matriz2.getNumLinhas() && matriz1.getNumColunas() == matriz2.getNumColunas(),
    "Dimensões incompatíveis.");
    Matriz* matrizResultante = new Matriz(matriz1.getNumLinhas(), matriz1.getNumColunas(), 2);
    for (int i = 0; i < matrizResultante->getNumLinhas(); i++){
        for (int j = 0; j < matrizResultante->getNumColunas(); j++){
            double valorAuxiliar = matriz1.getMatriz()[i][j] + matriz2.getMatriz()[i][j];
            matrizResultante->setValorMatriz(i, j, valorAuxiliar);
            LEMEMLOG((long int)(&(matriz1.getMatriz()[i][j])),sizeof(double), matriz1.getID());
            LEMEMLOG((long int)(&(matriz2.getMatriz()[i][j])),sizeof(double), matriz2.getID());
            ESCREVEMEMLOG((long int)(&(matrizResultante->getMatriz()[i][j])),sizeof(double), matrizResultante->getID());
        }
    }
    return matrizResultante;
}

Matriz* multiplicacaoMatriz(const Matriz& matriz1, const Matriz& matriz2){
    erroAssert(matriz1.getNumColunas() == matriz2.getNumLinhas(), "Dimensões incompatíveis.");
    Matriz* matrizResultante = new Matriz(matriz1.getNumLinhas(), matriz2.getNumColunas(), 2);
    for (int i = 0; i < matrizResultante->getNumLinhas(); i++){
        for(int j = 0; j < matrizResultante->getNumColunas(); j++){
            matrizResultante->setValorMatriz(i, j, 0);
            for (int k = 0; k < matriz2.getNumLinhas(); k++){
                matrizResultante->getMatriz()[i][j] += matriz1.getMatriz()[i][k] * matriz2.getMatriz()[k][j];
                LEMEMLOG((long int)(&(matriz1.getMatriz()[i][k])),sizeof(double), matriz1.getID());
                LEMEMLOG((long int)(&(matriz2.getMatriz()[k][j])),sizeof(double), matriz2.getID());
                ESCREVEMEMLOG((long int)(&(matrizResultante->getMatriz()[i][j])),sizeof(double), matrizResultante->getID());
            }
        }
    }
    return matrizResultante;
}

Matriz* transposicaoMatriz(const Matriz& matriz){
    Matriz* matrizResultante = new Matriz(matriz.getNumColunas(), matriz.getNumLinhas(), 2);
    for (int i = 0; i < matriz.getNumLinhas(); i++){
        for (int j = 0; j < matriz.getNumColunas(); j++){
            matrizResultante->setValorMatriz(j, i, matriz.getMatriz()[i][j]);
            LEMEMLOG((long int)(&(matriz.getMatriz()[i][j])), sizeof(double), matriz.getID());
            ESCREVEMEMLOG((long int)(&(matrizResultante->getMatriz()[j][i])), sizeof(double), matrizResultante->getID());
        }
    }
    return matrizResultante;
}

Matriz* inicializaMatriz(std::string nomeArquivoTexto, int ID){
    std::ifstream arq;
    arq.open(nomeArquivoTexto);
    if (!arq.is_open()){
        std::cout << "Erro na abertura do arquivo de inicialização!" << std::endl;
        exit(EXIT_FAILURE);
    }
    validaEntrada(arq);
    std::string auxStrNumLinhas, auxStrNumColunas, auxStrValorMatriz;
    arq >> auxStrNumLinhas;
    arq >> auxStrNumColunas;
    Matriz* matriz = new Matriz(std::stoi(auxStrNumLinhas), std::stoi(auxStrNumColunas), ID);
    for (int i = 0; i < matriz->getNumLinhas(); i++){
        for (int j = 0; j < matriz->getNumColunas(); j++){
            arq >> auxStrValorMatriz;
            matriz->setValorMatriz(i, j , std::stod(auxStrValorMatriz));
            ESCREVEMEMLOG((long int)(&(matriz->getMatriz()[i][j])), sizeof(double), matriz->getID());
        }
    }
    arq.close();
    return matriz;
} 

void escreveMatriz(const Matriz& matriz, std::string nomeArquivoTexto){
    std::ofstream arq;
    arq.open(nomeArquivoTexto);
    if (!arq.is_open()){
        std::cout << "Erro na abertura do arquivo de escrita!"<< std::endl;
        exit(EXIT_FAILURE);
    }
    arq << matriz.getNumLinhas() << " " << matriz.getNumColunas() << std::endl;
    for (int i = 0; i < matriz.getNumLinhas(); i++){
        for (int j = 0; j < matriz.getNumColunas(); j++){
            arq << matriz.getValorMatriz(i, j);
            if (j != matriz.getNumColunas() - 1) arq << " ";
            LEMEMLOG((long int)(&(matriz.getMatriz()[i][j])), sizeof(double), matriz.getID());
        }
        if (i != matriz.getNumLinhas() - 1) arq << std::endl;
    }
    arq.close();
}

void validaEntrada(std::ifstream& arq){
    std::string stringAuxiliar;
    std::getline(arq, stringAuxiliar);
    std::regex regularExpr1("\\d+\\s\\d+");
    erroAssert(std::regex_match(stringAuxiliar, regularExpr1), "O arquivo de entrada apresenta inconsistências!");
    std::istringstream iss(stringAuxiliar);
    std::string auxStrNumLinhas, auxStrNumColunas;
    iss >> auxStrNumLinhas >> auxStrNumColunas;
    int countValuesPerLine = 0;
    int countLines = 0;
    std::regex regularExpr2("[+-]?([0-9]*[.])?[0-9]+");
    std::string auxDoubleStr;
    while (!arq.eof()){
        std::getline(arq, stringAuxiliar);
        countLines++;
        std::istringstream line(stringAuxiliar);
        while (!line.eof()){
            line >> auxDoubleStr;
            countValuesPerLine++;
            erroAssert(std::regex_match(auxDoubleStr, regularExpr2), "O arquivo de entrada apresenta inconsistências!");
        }       
        erroAssert(countValuesPerLine == std::stoi(auxStrNumColunas), "O arquivo de entrada apresenta inconsistências!");
        countValuesPerLine = 0;
    }
    erroAssert(countLines == std::stoi(auxStrNumLinhas), "O arquivo de entrada apresenta inconsistências!");
    arq.clear();
    arq.seekg(0, arq.beg);
}