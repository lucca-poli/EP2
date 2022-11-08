#ifndef MEMORIARAM_H
#define MEMORIARAM_H
#include <list>
#include "Dado.h"
#include "Memoria.h"
using namespace std;

class MemoriaRAM: public Memoria {
    private:
        list<Dado*>* dados;
        int tamanho;
    public:
        MemoriaRAM(int tamanho);
        virtual ~MemoriaRAM();
        virtual void escrever(list<Dado*>* dados);
        // virtual int getTamanho();
        // virtual Dado* ler(int posicao);
        // virtual void escrever(int posicao, Dado* d);
        // virtual void imprimir();
};

#endif