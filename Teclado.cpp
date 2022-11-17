#include "Teclado.h"
#include <stdexcept>
#include <iostream>
using namespace std;

void Teclado::escrever(Dado* d) {
    throw new logic_error("Teclado aceita apenas entradas");
}

Dado* Teclado::ler() {
    cout << "Digite um numero: ";
    int x;
    cin >> x;
    Dado* d = new Dado(x);
    return d;
}

