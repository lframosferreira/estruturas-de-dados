#include "matriz.h"
#include "msgassert.h"
#include "memlog.h"
#include <string.h>
#include <string>
#include <iostream>
#include <getopt.h>

#define OPERACAOSOMAR 1
#define OPERACAOMULTIPLICAR 2
#define OPERACAOTRANSPOR 3

static int opcaoEscolhida;
int regmem;
std::string nomeArq1, nomeArq2, nomeArqRes;
char nomeArqRegistraAcesso[100];

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
  fprintf(stderr,"Opções de linha de comando:\n");
  fprintf(stderr,"\t-s \t(somar matrizes)\n");
  fprintf(stderr,"\t-m \t(multiplicar matrizes)\n");
  fprintf(stderr,"\t-t \t(transpor matriz)\n");
  fprintf(stderr,"\t-p <arquivo>\t(arquivo de registro de acesso)\n");
  fprintf(stderr,"\t-l \t(registrar acessos a memoria)\n");
  fprintf(stderr,"\t-1 <arquivo>\t(Arquivo da primeira matriz.)\n");
  fprintf(stderr,"\t-2 <arquivo>\t(Arquivo da segunda matriz.)\n");
  fprintf(stderr, "\t-o <arquivo>\t(arquivo para escrita da matriz resultante.)\n");
}

void parse_args(int argc,char ** argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida, optx, opty, regmem, lognome
{
    

    // variavel auxiliar
    int c;

    // inicializacao variaveis globais para opcoes
    opcaoEscolhida = -1;
    regmem = 0;

    // getopt - letra indica a opcao, : junto a letra indica parametro
    // no caso de escolher mais de uma operacao, vale a ultima
    while ((c = getopt(argc, argv, "smtp:o:1:2:lh")) != EOF)
        switch(c) {
            case 'm':
		        avisoAssert(opcaoEscolhida==-1,"Mais de uma operacao escolhida");
	            opcaoEscolhida = OPERACAOMULTIPLICAR;
                break;
            case 's':
		        avisoAssert(opcaoEscolhida==-1,"Mais de uma operacao escolhida");
	            opcaoEscolhida = OPERACAOSOMAR;
                break;
            case 't':
		        avisoAssert(opcaoEscolhida==-1,"Mais de uma operacao escolhida");
	            opcaoEscolhida = OPERACAOTRANSPOR;
                break;
            case 'l': 
	            regmem = 1;
		        break;
            case '1':
                nomeArq1 = optarg;
                break;
            case '2':
                nomeArq2 = optarg;
                break;
            case 'o':
                nomeArqRes = optarg;
                break;
            case 'p':
                strcpy(nomeArqRegistraAcesso, optarg);
                break;
            default:
                  uso();
                  exit(1);
}   
    /* Verificação da consistência das opções. */
    erroAssert(opcaoEscolhida > 0, "Necessário escolher operação.");
    erroAssert(!nomeArq1.empty(), "Nome de arquivo da matriz 1 tem que ser definido");
    if (opcaoEscolhida != OPERACAOTRANSPOR) erroAssert(!nomeArq2.empty(), "Nome de arquivo da matriz 2 tem que ser definido");
    
}

int main(int argc, char* argv[]){
    /* Até 3 matrizes vão ser utilizadas. */
    Matriz *matriz1, *matriz2, *matrizResultante;

    /* Avalia linha de comando. */
    parse_args(argc,argv);

    /* Inicia registro de acesso. */
    iniciaMemLog(nomeArqRegistraAcesso);

    /* Ativa registro de acesso. */
    ativaMemLog();

    switch (opcaoEscolhida){
        case OPERACAOSOMAR:
            defineFaseMemLog(0);
            matriz1 = inicializaMatriz(nomeArq1, 0);
            matriz2 = inicializaMatriz(nomeArq2, 1);
            defineFaseMemLog(1);
            acessaMatriz(*matriz1);
            acessaMatriz(*matriz2);
            matrizResultante = somaMatriz(*matriz1, *matriz2);
            defineFaseMemLog(2);
            acessaMatriz(*matrizResultante);
            escreveMatriz(*matrizResultante, nomeArqRes);
            delete matriz1;
            delete matriz2;
            delete matrizResultante;
            break;
        case OPERACAOMULTIPLICAR:
            defineFaseMemLog(0);
            matriz1 = inicializaMatriz(nomeArq1, 0);
            matriz2 = inicializaMatriz(nomeArq2, 1);
            defineFaseMemLog(1);
            acessaMatriz(*matriz1);
            acessaMatriz(*matriz2);
            matrizResultante = multiplicacaoMatriz(*matriz1, *matriz2);
            defineFaseMemLog(2);
            acessaMatriz(*matrizResultante);
            escreveMatriz(*matrizResultante, nomeArqRes);
            delete matriz1;
            delete matriz2;
            delete matrizResultante;
            break;
        case OPERACAOTRANSPOR:
            defineFaseMemLog(0);
            matriz1 = inicializaMatriz(nomeArq1, 0);
            acessaMatriz(*matriz1);
            defineFaseMemLog(1);
            matrizResultante = transposicaoMatriz(*matriz1);
            defineFaseMemLog(2);
            acessaMatriz(*matrizResultante);
            escreveMatriz(*matrizResultante, nomeArqRes);
            delete matriz1;
            delete matrizResultante;
            break;
        default:
        /* Não deve ser utilizado, uma vez que existe um assert na avaliação da linha de comando. */
            uso();
            exit(1);
    }
    return finalizaMemLog();
}
