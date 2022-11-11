#include "ESMapeadaNaMemoria.h"
#include "MemoriaRAM.h"
#include "Dispositivo.h"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m): Memoria (m) {
    Dispositivos = NULL;
}

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos): Memoria (m) {
    Dispositivos = new vector<Dispositivo*>();
    for(unsigned int i = 0; i < dispositivos->size(); i++) {
        Dispositivos->push_back((dispositivos->at(i)));
    }
}

ESMapeadaNaMemoria::~ESMapeadaNaMemoria() {
    delete Memoria;
    while (!Dispositivos->empty()) {
    Dispositivo* u = Dispositivos->back();
    Dispositivos->pop_back();
    delete u;
    }
    delete Dispositivos;
}

MemoriaRAM* ESMapeadaNaMemoria::getMemoriaSubjacente() {
    return this->Memoria;
}

void ESMapeadaNaMemoria::adicionar(Dispositivo* d) {
    Dispositivos->push_back(d);
}

vector<Dispositivo*>* ESMapeadaNaMemoria::getDispositivos() {
    return this->Dispositivos;
}

int ESMapeadaNaMemoria::getTamanho() {
    return Memoria->getTamanho() + Dispositivos->size();
}

Dado* ESMapeadaNaMemoria::ler(int posicao) {
    if (posicao < 0 || posicao >= getTamanho() + Dispositivos->size()) {
        throw new logic_error("Erro logico - ESMapeadaNaMemoria::ler");
    }
    if (posicao < Memoria->getTamanho()) {
        return Memoria->ler(posicao);
    }
    else {
        posicao -= Memoria->getTamanho();
        return Dispositivos->at(posicao)->ler();
    }
}

void ESMapeadaNaMemoria::escrever(int posicao, Dado* d) {
    if (posicao < 0 || posicao >= getTamanho() + Dispositivos->size()) {
        throw new logic_error("Erro logico - ESMapeadaNaMemoria::escrever");
    }
    if (posicao < Memoria->getTamanho()) {
        Memoria->escrever(posicao, d);
    }
    else {
        posicao -= Memoria->getTamanho();
        Dispositivos->at(posicao)->ler();
    }
}

void ESMapeadaNaMemoria::imprimir() {
    Memoria->imprimir();
}
