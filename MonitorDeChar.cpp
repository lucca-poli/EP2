#include "MonitorDeChar.h"
#include "Dado.h"
#include <iostream>
using namespace std;

MonitorDeChar::MonitorDeChar() {}

MonitorDeChar::~MonitorDeChar() {}

void MonitorDeChar::escrever(Dado* d) {
    char c = static_cast<char>(d->getValor());
    cout << c << endl;
}

