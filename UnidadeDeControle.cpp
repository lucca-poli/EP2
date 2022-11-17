#include "UnidadeDeControle.h" 
#include "BancoDeRegistradores.h"
#include "Memoria.h"
#include "Instrucao.h"
#include <iostream>
using namespace std;

UnidadeDeControle::UnidadeDeControle(BancoDeRegistradores* registradores, Memoria* memoria):
registradores (registradores), memoria (memoria) {
    this->pc = 0;
}

UnidadeDeControle::~UnidadeDeControle() {
    delete registradores;
    delete memoria;
}

BancoDeRegistradores* UnidadeDeControle::getBancoDeRegistradores() {
    return this->registradores;
}

Memoria* UnidadeDeControle::getMemoria() {
    return this->memoria;
}

int UnidadeDeControle::getPC() {
    return this->pc;
}

void UnidadeDeControle::setPC(int pc) {
    this->pc = pc;
}

void UnidadeDeControle::executarInstrucao() {
    Instrucao *i = dynamic_cast<Instrucao*>(memoria->ler(pc));
    if (i == NULL) {
        pc++;
        return;
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

    if (i->getOpcode() == 0) {
        if (i->getFuncao() == FUNCAO_ADD) {
            registradores->setValor(
                i->getDestino(), i->getOrigem1() + i->getOrigem2()
            );
        }

        if (i->getFuncao() == FUNCAO_DIV) {
            registradores->setValor(
                FUNCAO_MULT, registradores->getValor(i->getOrigem1()) / registradores->getValor(i->getOrigem2())
            );
            registradores->setValor(
                25, registradores->getValor(i->getOrigem1()) % registradores->getValor(i->getOrigem2())
            );
        }

        if (i->getFuncao() == FUNCAO_MULT) {
            registradores->setValor(
                FUNCAO_MULT, registradores->getValor(i->getOrigem1()) * registradores->getValor(i->getOrigem2())
            );
        }

        if (i->getFuncao() == FUNCAO_SUB) {
            registradores->setValor(
                i->getDestino(), registradores->getValor(i->getOrigem1()) - registradores->getValor(i->getOrigem2())
            );
        }
    }
    if (i->getOpcode() == J) {
        pc = i->getImediato();
        return;
    }
    if (i->getOpcode() == BNE) {
        if (registradores->getValor(i->getOrigem1()) != registradores->getValor(i->getOrigem2())) {
            pc = i->getImediato();
            return;
        }
    }
    if (i->getOpcode() == BEQ) {
        if (registradores->getValor(i->getOrigem1()) == registradores->getValor(i->getOrigem2())) {
            pc = i->getImediato();
            return;
        }
    }
    if (i->getOpcode() == LW) {
        if (memoria->ler(i->getImediato()) == NULL) {
            registradores->setValor(
            i->getDestino(), 0
        );
        pc++;
        return;
        }
        registradores->setValor(
            i->getDestino(), memoria->ler(i->getImediato())->getValor()
        );
    }
    if (i->getOpcode() == SW) {
        Dado* d = new Dado(registradores->getValor(i->getDestino()));
        memoria->escrever(
            i->getImediato(), d
        );
    }
    pc++;
} 
