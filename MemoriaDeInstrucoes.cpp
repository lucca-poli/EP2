#include "MemoriaDeInstrucoes.h"
#include "Instrucao.h"
#include <iostream>
using namespace std;

MemoriaDeInstrucoes::MemoriaDeInstrucoes(int tamanho): tamanho (tamanho) {
    memoriaInstrucoes = new Instrucao*[tamanho];
    
    for (int i = 0; i < tamanho; i++) {
        memoriaInstrucoes[i] = NULL;
    }
}

MemoriaDeInstrucoes::~MemoriaDeInstrucoes() {
    for (int i = 0; i < tamanho; i++) {
        delete memoriaInstrucoes[i];
    }
    delete[] memoriaInstrucoes;
}

int MemoriaDeInstrucoes::getTamanho() {
    return this->tamanho;
}

Instrucao* MemoriaDeInstrucoes::ler(int posicao) {
    if (posicao < 0 || posicao >= tamanho) {
        return NULL;
    }
    return memoriaInstrucoes[posicao];
}

bool MemoriaDeInstrucoes::escrever(int posicao, Instrucao* d) {
    if (posicao < 0 || posicao >= tamanho) {
        return false;
    }
    if (memoriaInstrucoes[posicao] != NULL) {
        delete memoriaInstrucoes[posicao];
    }
    memoriaInstrucoes[posicao] = d;
    return true;
}