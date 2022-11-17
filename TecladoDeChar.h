#ifndef TECLADODECHAR_H
#define TECLADODECHAR_H
#include "Teclado.h"
#include "Dado.h"

class TecladoDeChar: public Teclado {
    private:
    public:
        TecladoDeChar();
        virtual ~TecladoDeChar();
        virtual Dado* ler();
};

#endif