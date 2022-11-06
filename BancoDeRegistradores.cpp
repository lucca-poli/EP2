#include "BancoDeRegistradores.h"
#include <iostream>
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
    if (registrador <= 0 || registrador > 31) {
        return 0;
    }
    return this->Registradores[registrador];
}

void BancoDeRegistradores::setValor(int registrador, int valor) {
    if (registrador < 0 || registrador > 31) {
        return;
    }
    Registradores[registrador] = valor;
}

void BancoDeRegistradores::imprimir() {
    for (int i = 0; i < QUANTIDADE_REGISTRADORES; i++) {
        cout << i << ": " << Registradores[i] << endl;
    }
}