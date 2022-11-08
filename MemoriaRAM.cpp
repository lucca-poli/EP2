#include "MemoriaRAM.h"

MemoriaRAM::MemoriaRAM(int tamanho): tamanho (tamanho) {
    dados = new list<Dado*>();
}