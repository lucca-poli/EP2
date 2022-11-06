#include "Instrucao.h"

Instrucao::Instrucao(int opcode, int origem1, int origem2, int destino, int imediato, int funcao):
opcode (opcode), origem1 (origem1), origem2 (origem2), destino (destino), imediato (imediato), funcao (funcao) {
}

Instrucao::~Instrucao(){
}

int Instrucao::getOpcode() {
    return this->opcode;
}

int Instrucao::getOrigem1() {
    return this->origem1;
}

int Instrucao::getOrigem2() {
    return this->origem2;
}

int Instrucao::getDestino() {
    return this->destino;
}

int Instrucao::getImediato() {
    return this->imediato;
}

int Instrucao::getFuncao() {
    return this->funcao;
}
