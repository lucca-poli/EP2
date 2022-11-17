#include "TecladoDeChar.h"
#include "Dado.h"
#include <iostream>
using namespace std;

Dado* TecladoDeChar::ler() {
    cout << "Digite um caractere: ";
    char c;
    cin >> c;
    int x = static_cast<int>(c);
    Dado* d = new Dado(x);
    return d;
}