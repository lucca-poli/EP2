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

    if (i->getOpcode() == 0) {
        if (i->getFuncao() == Instrucao::FUNCAO_ADD) {
            registradores->setValor(
                i->getDestino(), registradores->getValor(i->getOrigem1()) + registradores->getValor(i->getOrigem2())
            );
        }

        if (i->getFuncao() == Instrucao::FUNCAO_DIV) {
            registradores->setValor(
                Instrucao::FUNCAO_MULT, registradores->getValor(i->getOrigem1()) / registradores->getValor(i->getOrigem2())
            );
            registradores->setValor(
                25, registradores->getValor(i->getOrigem1()) % registradores->getValor(i->getOrigem2())
            );
        }

        if (i->getFuncao() == Instrucao::FUNCAO_MULT) {
            registradores->setValor(
                Instrucao::FUNCAO_MULT, registradores->getValor(i->getOrigem1()) * registradores->getValor(i->getOrigem2())
            );
        }

        if (i->getFuncao() == Instrucao::FUNCAO_SUB) {
            registradores->setValor(
                i->getDestino(), registradores->getValor(i->getOrigem1()) - registradores->getValor(i->getOrigem2())
            );
        }
    }
    
    if (i->getOpcode() == Instrucao::J) {
        pc = i->getImediato();
        return;
    }

    if (i->getOpcode() == Instrucao::BNE) {
        if (registradores->getValor(i->getOrigem1()) != registradores->getValor(i->getOrigem2())) {
            pc = i->getImediato();
            return;
        }
    }

    if (i->getOpcode() == Instrucao::BEQ) {
        if (registradores->getValor(i->getOrigem1()) == registradores->getValor(i->getOrigem2())) {
            pc = i->getImediato();
            return;
        }
    }

    if (i->getOpcode() == Instrucao::LW) {
        Dado* d = memoria->ler(i->getImediato());
        if (d == NULL) {
            registradores->setValor(
            i->getDestino(), 0
            );
            pc++;
            return;
        }
        registradores->setValor(
            i->getDestino(), d->getValor()
        );
    }

    if (i->getOpcode() == Instrucao::SW) {
        Dado* d = new Dado(registradores->getValor(i->getDestino()));
        memoria->escrever(
            i->getImediato(), d
        );
    }
    pc++;
} 
