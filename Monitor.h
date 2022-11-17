#ifndef MONITOR_H
#define MONITOR_H
#include "Dispositivo.h"
#include "Dado.h"

class Monitor: public Dispositivo {
    private:
    public:
        Monitor();
        virtual ~Monitor();
        virtual Dado* ler();
        virtual void escrever(Dado* d);
};

#endif