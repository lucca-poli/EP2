#ifndef MEMORIA_H
#define MEMORIA_H
#include "Dado.h"

class Memoria {
    protected:
        Dado** Dados;
    public:
        Memoria();
        virtual ~Memoria();
        virtual int getTamanho() = 0;
        virtual Dado* ler(int posicao);
        virtual void escrever(int posicao, Dado* d);
        virtual void imprimir() = 0;
};

#endif