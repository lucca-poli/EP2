#include "GerenciadorDeMemoria.h"
#include "MemoriaRAM.h"
#include "Instrucao.h"
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

GerenciadorDeMemoria::GerenciadorDeMemoria() {}

GerenciadorDeMemoria::~GerenciadorDeMemoria() {}

void GerenciadorDeMemoria::load(string arquivo, MemoriaRAM* m) {
    ifstream input;
    input.open(arquivo);
    if (input.fail()) {
        throw new runtime_error("Arquivo nao encontrado");
    }
    int tamanho, posicao = 0;
    input >> tamanho;
    if (input.fail()) {
        throw new runtime_error("Erro de leitura no arquivo");
    }
    string s;
    input >> s;
    while (posicao < tamanho) {
        if (!input) {
        throw new runtime_error("Erro de leitura no arquivo");
        }
        if (s == "D") {
            int valor;
            input >> valor;
            Dado* d = new Dado(valor);
            m->escrever(posicao, d);
        }
        else {
            if (s == "-") {
                m->escrever(posicao, NULL);
            }
            if (s == "ADD") {
                int destino, origem1, origem2;
                input >> destino >> origem1 >> origem2;
                Instrucao* i = Instrucao::criarADD(destino, origem1, origem2);
                m->escrever(posicao, i);
            }
            if (s == "SUB") {
                int destino, origem1, origem2;
                input >> destino >> origem1 >> origem2;
                Instrucao* i = Instrucao::criarSUB(destino, origem1, origem2);
                m->escrever(posicao, i);
            }
            if (s == "MULT") {
                int origem1, origem2;
                input >> origem1 >> origem2;
                Instrucao* i = Instrucao::criarMULT(origem1, origem2);
                m->escrever(posicao, i);
            }
            if (s == "DIV") {
                int origem1, origem2;
                input >> origem1 >> origem2;
                Instrucao* i = Instrucao::criarDIV(origem1, origem2);
                m->escrever(posicao, i);
            }
            if (s == "BNE") {
                int origem1, origem2, imediato;
                input >> origem1 >> origem2 >> imediato;
                Instrucao* i = Instrucao::criarBNE(origem1, origem2, imediato);
                m->escrever(posicao, i);
            }
            if (s == "BEQ") {
                int origem1, origem2, imediato;
                input >> origem1 >> origem2 >> imediato;
                Instrucao* i = Instrucao::criarBEQ(origem1, origem2, imediato);
                m->escrever(posicao, i);
            }
            if (s == "LW") {
                int destino, imediato;
                input >> destino >> imediato;
                Instrucao* i = Instrucao::criarLW(destino, imediato);
                m->escrever(posicao, i);
            }
            if (s == "SW") {
                int destino, imediato;
                input >> destino >> imediato;
                Instrucao* i = Instrucao::criarSW(destino, imediato);
                m->escrever(posicao, i);
            }
            if (s == "J") {
                int imediato;
                input >> imediato;
                Instrucao* i = Instrucao::criarJ(imediato);
                m->escrever(posicao, i);
            }
        }
        posicao++;
        input >> s;
    }
    if (!input.eof()) {
        throw new runtime_error("Nao chegou ao fim do arquivo");
    }
    input.close();
}

void GerenciadorDeMemoria::dump(string arquivo, MemoriaRAM* m) {
    ofstream output;
    output.open(arquivo);
    if (output.fail()) {
        throw new runtime_error("Erro ao escrever");
    }

    const int TIPO_R = 0;
    const int FUNCAO_ADD = 32;
    const int FUNCAO_SUB = 34;
    const int FUNCAO_MULT = 24;
    const int FUNCAO_DIV = 26;
    const int J = 2;
    const int BNE = 5;
    const int BEQ = 4;
    const int LW = 35;
    const int SW = 43;

    int tamanho = m->getTamanho();
    output << tamanho << endl;
    for (int posicao = 0; posicao < tamanho; posicao++) {
        Instrucao* i = dynamic_cast<Instrucao*>(m->ler(posicao));
        if (i != NULL) {
            if (i->getOpcode() == 0) {
                if (i->getFuncao() == FUNCAO_ADD) {
                    output << "ADD" << " " << i->getDestino() << " " << i->getOrigem1() << " " << i->getOrigem2() << endl;
                }
                if (i->getFuncao() == FUNCAO_SUB) {
                    output << "SUB" << " " << i->getDestino() << " " << i->getOrigem1() << " " << i->getOrigem2() << endl;
                }
                if (i->getFuncao() == FUNCAO_MULT) {
                    output << "ADD" << " " << i->getOrigem1() << " " << i->getOrigem2() << endl;
                }
                if (i->getFuncao() == FUNCAO_DIV) {
                    output << "ADD" << " " << i->getOrigem1() << " " << i->getOrigem2() << endl;
                }
            }
            if (i->getOpcode() == BNE) {
                output << "BNE" << " " << i->getOrigem1() << " " << i->getOrigem2() << " " << i->getImediato() << endl;
            }
            if (i->getOpcode() == BEQ) {
                output << "BEQ" << " " << i->getOrigem1() << " " << i->getOrigem2() << " " << i->getImediato() << endl;
            }
            if (i->getOpcode() == LW) {
                output << "LW" << " " << i->getDestino() << " " << i->getImediato() << endl;
            }
            if (i->getOpcode() == SW) {
                output << "SW" << " " << i->getDestino() << " " << i->getImediato() << endl;
            }
            if (i->getOpcode() == J) {
                output << "J" << " " << i->getImediato() << endl;
            }
        }
        else if (m->ler(posicao) == NULL) {
            output << "-" << endl;
        }
        else {
            output << "D" << " " << m->ler(posicao)->getValor() << endl;
        }
        if (output.fail()) {
        throw new runtime_error("Erro ao escrever");
        }
    }
    output.close();
}
