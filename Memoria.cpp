#include <Memoria.h>
#include <Dado.h>
#include <stdexcept>
using namespace std;

void Memoria::escrever(int posicao, Dado* d) {
    if (posicao < 0 || posicao >= getTamanho()) {
        throw new logic_error("Erro logico - Memoria::escrever");
    }
    if (Dados[posicao] != NULL) {
        delete Dados[posicao];
    }
    Dados[posicao] = d;
}

Dado* Memoria::ler(int posicao) {
    if (posicao < 0 || posicao >= getTamanho()) {
        throw new logic_error("Erro logico - Memoria::ler");
    }
    return Dados[posicao];
}