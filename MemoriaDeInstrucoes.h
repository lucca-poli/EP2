#ifndef MemoriaDeIntrucoes_H
#define MemoriaDeIntrucoes_H

#include "Instrucao.h"

class MemoriaDeInstrucoes {
    private:
        Instrucao** memoriaInstrucoes;
        int tamanho;
        int posicao;
    public:
        MemoriaDeInstrucoes(int tamanho);
        virtual ~MemoriaDeInstrucoes();
        int getTamanho();
        Instrucao* ler(int posicao);
        bool escrever(int posicao, Instrucao* d);
};

#endif