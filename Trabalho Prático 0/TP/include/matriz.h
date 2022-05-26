#ifndef MATRIZ_H
#define MATRIZ_H

#include <string>

/* Classe representativa do tipo abstrato de dado matriz. Como o enunciado do TP explicíta, sem perdermos
a generalidade, todas as matrizes do trabalho serão bidimensionais. */

class Matriz{
    private:
        /* Cada matriz bidimensional possui um número de linhas e um número de colunas. */
        int numLinhas, numColunas;
        
        /* O atributo matriz é a representação da matriz feita em alocação dinâmica. */
        double** matriz;

        /* Identificador da matriz. */
        int ID;
    public:
        /* Descrição: Construtor vazio da classe Matriz.
        Entrada: não tem.
        Saída: não tem. */
        Matriz();

        /* Descrição: Construtor da classe Matriz. 
        Entrada: Número de linhas e número de colunas da matriz.
        Saída: Não tem. */
        Matriz(int numLinhas, int numColunas, int ID);

        /* Descrição: Destrutor da classe Matriz. 
        Entrada: não tem.
        Saída: não tem. */
        ~Matriz();

        /* Descrição: Função utilizada para atribuir um valor para o número de linhas da matriz.
        Entrada: Número de linhas.
        Saída: Não tem. */
        void setNumLinhas(int numLinhas);

        /* Descrição: Função utilizada para atribuir um valor para o número de colunas da matriz. 
        Entrada: Número de colunas.
        Saída: não tem. */ 
        void setNumColunas(int numColunas);

        /* Descrição: Função utilizada para atribuir um valor para certa posição da matriz. 
        Entrada: Número da linha i, número da coluna j, valor. 
        Saída: Não tem. */
        void setValorMatriz(int i, int j, double valor);

        /* Descrição: Função utilizada para acessar o atributo privado numLinhas.
        Entrada: não tem.
        Saída: Número de linhas da matriz. */
        int getNumLinhas() const;

        /* Descrição: Função utilizada para acessar o atributo privado numColunas.
        Entrada: não tem.
        Saída: Número de colunas da matriz. */
        int getNumColunas() const;

        /* Descrição: Função utilizada para acessar o valor de certa posição na matriz.
        Entrada: Número da linha i, número da coluna j.
        Saída: Valor contido na matriz na posição [i][j]. */
        double getValorMatriz(int i, int j) const;

        /* Descrição: Função utilizada para acessar o valor da ID da matriz.
        Entrada: não tem.
        Saída: ID da matriz. */
        int getID() const;

        /* Descrição: Função utilizada para acessar o atributo privado matriz.
        Entrada: não tem.
        Saída: matriz. */
        double** getMatriz() const;

};

/* Descrição: Essa função realiza o acesso de uma matriz para fins de registrar o acesso.
Entrada: Referência para objeto do tipo Matriz que deve ser acessado.
Saída: Valor 'double' não importante, apenas para evitar que o acesso seja eliminado. */
double acessaMatriz(const Matriz& matriz);

/* Descrição: Essa função irá receber um inteiro e um arquivo de texto como parâmetro e irá retornar um objeto
da classe Matriz, que será criado a partir dos valores contidos no arquivo.
Entrada: Nome do arquivo de texto que contêm a matriz e ID da matriz.
Saída: Ponteiro para uma instância da classe Matriz. */
Matriz* inicializaMatriz(std::string nomeArquivoTexto, int ID);

/* Descrição: Esta função realiza a operação de soma entre dois objetos da classe Matriz, e retorna um ponteiro para
a nova instância da classe que representa a soma das duas matrizes.
Entrada: Objeto da classe Matriz matriz1, Objeto da classe Matriz m2.
Saída: Ponteiro para uma instância da classe Matriz que representa a soma das duas entradas. */
Matriz* somaMatriz(const Matriz& matriz1, const Matriz& matriz2);

/* Descrição: Esta função realiza a operação de multiplicação entre dois objetos da classe Matriz, e retorna um ponteiro para
a nova instância da classe que representa o produto das duas matrizes.
Entrada: Objeto da classe Matriz matriz1, Objeto da classe Matriz m2.
Saída: Ponteiro para uma instância da classe Matriz que representa o produto das duas entradas. */
Matriz* multiplicacaoMatriz(const Matriz& matriz1, const Matriz& matriz2);

/* Descrição: Esta funcão realiza a operação de transposição de um objeto da classe matriz, e retorna um ponteiro para
a nova instância da classe que representa a transposta da matriz.
Entrada: Objeto da classe Matriz matriz.
Saída: Ponteiro para uma instância da classe Matriz que representa a transposta da entrada. */
Matriz* transposicaoMatriz(const Matriz& matriz);

/* Descrição: Esta função irá escrever em um novo arquivo de texto uma matriz passada como parâmetro. 
Entrada: Objeto da classe Matriz matriz, nome do arquivo texto onde deve ser escrita a nova matriz. 
Saída: não tem. */
void escreveMatriz(const Matriz& matriz, std::string nomeArquivoTexto);

/* Descrição: Esta função irá checar se o arquivo texto passado como argumento para uma matriz possui
inconsistências.
Entrada: Arquivo ifstream para leitura.
Saída: Não tem. */
void validaEntrada(std::ifstream& arq);

#endif