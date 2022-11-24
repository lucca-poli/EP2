#include "MemoriaRAM.h"
#include <iostream>
#include <stdexcept>
using namespace std;

MemoriaRAM::MemoriaRAM(int tamanho): tamanho (tamanho) {
    Dados = new Dado*[tamanho];
    for (int i = 0; i < tamanho; i++) {
        Dados[i] = NULL;
    }
}

MemoriaRAM::~MemoriaRAM() {
    for (int i = 0; i < tamanho; i++) {
        delete Dados[i];
    }
    delete[] Dados;
}

void MemoriaRAM::escrever(list<Dado*>* dados) {
    if (dados->size() > tamanho) {
        throw new logic_error("Erro logico - MemoriaRAM::escrever");
    }
    int j = 0;
    for (list<Dado*>::iterator i = dados->begin(); i != dados->end(); i++) {
        if (Dados[j] != NULL) {
            delete Dados[j];
        }
        Dados[j++] = (*i);
    }
}

void MemoriaRAM::escrever(int posicao, Dado* d) {
    if (posicao < 0 || posicao >= getTamanho()) {
        throw new logic_error("Erro logico - Memoria::escrever");
    }
    if (Dados[posicao] != NULL) {
        delete Dados[posicao];
    }
    Dados[posicao] = d;
}

Dado* MemoriaRAM::ler(int posicao) {
    if (posicao < 0 || posicao >= getTamanho()) {
        throw new logic_error("Erro logico - Memoria::ler");
    }
    return Dados[posicao];
}

int MemoriaRAM::getTamanho() {
    return this->tamanho;
}

void MemoriaRAM::imprimir() {
    for (int i = 0; i < tamanho; i++) {
        if (Dados[i] == NULL) {
            cout << i << ": -" << endl;
        }
        else {
            cout << i << ": ";
            Dados[i]->imprimir();
            cout << endl;
        }
    }
}
