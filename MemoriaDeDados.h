#ifndef MEMORIADEDADOS_H
#define MEMORIADEDADOS_H

#include "Dado.h"

class MemoriaDeDados {
    private:
        Dado* d;
        Dado** dados;
        int tamanho;
        int posicao;
    public:
        MemoriaDeDados(int tamanho);
        virtual ~MemoriaDeDados();
        int getTamanho();
        Dado* ler(int posicao);
        bool escrever(int posicao, Dado* d);
        void imprimir(); 
};

#endif