#include "UnidadeDeControle.h" 
#include "BancoDeRegistradores.h"
#include "MemoriaDeDados.h"
#include "MemoriaDeInstrucoes.h"
#include <iostream>
using namespace std;

UnidadeDeControle::UnidadeDeControle(BancoDeRegistradores* registradores, MemoriaDeInstrucoes* instrucoes, MemoriaDeDados* dados):
registradores (registradores), instrucoes (instrucoes), dados (dados) {
    this->pc = 0;
}

UnidadeDeControle::~UnidadeDeControle() {
    delete registradores;
    delete instrucoes;
    delete dados;
}

BancoDeRegistradores* UnidadeDeControle::getBancoDeRegistradores() {
    return this->registradores;
}

MemoriaDeDados* UnidadeDeControle::getMemoriaDeDados() {
    return this->dados;
}

MemoriaDeInstrucoes* UnidadeDeControle::getMemoriaDeInstrucoes() {
    return this->instrucoes;
}

int UnidadeDeControle::getPC() {
    return this->pc;
}

void UnidadeDeControle::setPC(int pc) {
    this->pc = pc;
}

void UnidadeDeControle::executarInstrucao() {
    if (instrucoes->ler(pc) == NULL) {
        pc++;
        return;
    }
    if (instrucoes->ler(pc)->getOpcode() == 0) {
        if (instrucoes->ler(pc)->getFuncao() == FUNCAO_ADD) {
            registradores->setValor(
                instrucoes->ler(pc)->getDestino(), instrucoes->ler(pc)->getOrigem1() + instrucoes->ler(pc)->getOrigem2()
            );
        }

        if (instrucoes->ler(pc)->getFuncao() == FUNCAO_DIV) {
            registradores->setValor(
                FUNCAO_MULT, registradores->getValor(instrucoes->ler(pc)->getOrigem1()) / registradores->getValor(instrucoes->ler(pc)->getOrigem2())
            );
            registradores->setValor(
                25, registradores->getValor(instrucoes->ler(pc)->getOrigem1()) % registradores->getValor(instrucoes->ler(pc)->getOrigem2())
            );
        }

        if (instrucoes->ler(pc)->getFuncao() == FUNCAO_MULT) {
            registradores->setValor(
                FUNCAO_MULT, registradores->getValor(instrucoes->ler(pc)->getOrigem1()) * registradores->getValor(instrucoes->ler(pc)->getOrigem2())
            );
        }

        if (instrucoes->ler(pc)->getFuncao() == FUNCAO_SUB) {
            registradores->setValor(
                instrucoes->ler(pc)->getDestino(), registradores->getValor(instrucoes->ler(pc)->getOrigem1()) - registradores->getValor(instrucoes->ler(pc)->getOrigem2())
            );
        }
    }
    if (instrucoes->ler(pc)->getOpcode() == J) {
        pc = instrucoes->ler(pc)->getImediato();
        return;
    }
    if (instrucoes->ler(pc)->getOpcode() == BNE) {
        if (registradores->getValor(instrucoes->ler(pc)->getOrigem1()) != registradores->getValor(instrucoes->ler(pc)->getOrigem2())) {
            pc = instrucoes->ler(pc)->getImediato();
            return;
        }
    }
    if (instrucoes->ler(pc)->getOpcode() == BEQ) {
        if (registradores->getValor(instrucoes->ler(pc)->getOrigem1()) == registradores->getValor(instrucoes->ler(pc)->getOrigem2())) {
            pc = instrucoes->ler(pc)->getImediato();
            return;
        }
    }
    if (instrucoes->ler(pc)->getOpcode() == LW) {
        if (dados->ler(pc) == NULL) {
            registradores->setValor(
            instrucoes->ler(pc)->getDestino(), 0
        );
        pc++;
        return;
        }
        registradores->setValor(
            instrucoes->ler(pc)->getDestino(), dados->ler(instrucoes->ler(pc)->getImediato())->getValor()
        );
    }
    if (instrucoes->ler(pc)->getOpcode() == SW) {
        Dado* d = new Dado(registradores->getValor(instrucoes->ler(pc)->getDestino()));
        dados->escrever(
            instrucoes->ler(pc)->getImediato(), d
        );
    }
    pc++;
} 
