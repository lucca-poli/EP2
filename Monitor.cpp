#include "Monitor.h"
#include <stdexcept>
#include <iostream>
using namespace std;

Monitor::Monitor() {}

Monitor::~Monitor() {}

void Monitor::escrever(Dado* d) {
    cout << d->getValor();
}

Dado* Monitor::ler() {
    throw new logic_error("Monitor aceita apenas saidas");
}

