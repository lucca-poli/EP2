#include "BancoDeRegistradores.h"
#include <iostream>
#include <stdexcept>
using namespace std;

BancoDeRegistradores::BancoDeRegistradores() {
    Registradores = new int[QUANTIDADE_REGISTRADORES];
    for (int i = 0; i < QUANTIDADE_REGISTRADORES; i++) {
        Registradores[i] = 0;
    }
}

BancoDeRegistradores::~BancoDeRegistradores() {
    delete[] Registradores;
}

int BancoDeRegistradores::getValor(int registrador) {
    if (registrador < 0 || registrador > 31) {
        throw new logic_error("Erro logico - getValor");
    }
    if (registrador == 0) {
        return 0;
    }
    return this->Registradores[registrador];
}

void BancoDeRegistradores::setValor(int registrador, int valor) {
    if (registrador < 0 || registrador > 31) {
        throw new logic_error("Erro logico - setValor");
    }
    if (registrador == 0) {
        return;
    }
    Registradores[registrador] = valor;
}

void BancoDeRegistradores::imprimir() {
    for (int i = 0; i < QUANTIDADE_REGISTRADORES; i++) {
        cout << "\t" << i << ": " << Registradores[i] << endl;
    }
}