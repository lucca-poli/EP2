#include "Instrucao.h"
#include <iostream>
using namespace std;

Instrucao::Instrucao(int valor, int origem1, int origem2, int destino, int imediato, int funcao):
Dado (valor), origem1 (origem1), origem2 (origem2), destino (destino), imediato (imediato), funcao (funcao) {
}

Instrucao::~Instrucao(){
}

int Instrucao::getOpcode() {
    return this->valor;
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

void Instrucao::imprimir() {
    cout << "Instrucao " << valor;
}

Instrucao* Instrucao::criarLW(int destino, int imediato) {
    Instrucao* i = new Instrucao(Instrucao::LW, 0, 0, destino, imediato, 0);
    return i;
}

Instrucao* Instrucao::criarSW(int destino, int imediato) {
    Instrucao* i = new Instrucao(Instrucao::SW, 0, 0, destino, imediato, 0);
    return i;
}

Instrucao* Instrucao::criarJ(int imediato) {
    Instrucao* i = new Instrucao(Instrucao::J, 0, 0, 0, imediato, 0);
    return i;
}

Instrucao* Instrucao::criarBNE(int origem1, int origem2, int imediato) {
    Instrucao* i = new Instrucao(Instrucao::BNE, origem1, origem2, 0, imediato, 0);
    return i;
}

Instrucao* Instrucao::criarBEQ(int origem1, int origem2, int imediato) {
    Instrucao* i = new Instrucao(Instrucao::BEQ, origem1, origem2, 0, imediato, 0);
    return i;
}

Instrucao* Instrucao::criarADD(int destino, int origem1, int origem2) {
    Instrucao* i = new Instrucao(Instrucao::TIPO_R, origem1, origem2, destino, 0, Instrucao::FUNCAO_ADD);
    return i;
}

Instrucao* Instrucao::criarSUB(int destino, int origem1, int origem2) {
    Instrucao* i = new Instrucao(Instrucao::TIPO_R, origem1, origem2, destino, 0, Instrucao::FUNCAO_SUB);
    return i;
}

Instrucao* Instrucao::criarMULT(int origem1, int origem2) {
    Instrucao* i = new Instrucao(Instrucao::TIPO_R, origem1, origem2, 0, 0, Instrucao::FUNCAO_MULT);
    return i;
}

Instrucao* Instrucao::criarDIV(int origem1, int origem2) {
    Instrucao* i = new Instrucao(Instrucao::TIPO_R, origem1, origem2, 0, 0, Instrucao::FUNCAO_DIV);
    return i;
} 

