#ifndef TECLADO_H
#define TECLADO_H
#include "Dispositivo.h"
#include "Dado.h"

class Teclado: public Dispositivo {
    private:
    public:
        Teclado();
        virtual ~Teclado();
        virtual Dado* ler();
        virtual void escrever(Dado* d);
};

#endif