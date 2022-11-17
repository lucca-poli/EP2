#ifndef MONITORDECHAR_H
#define MONITORDECHAR_H
#include "Monitor.h"
#include "Dado.h"

class MonitorDeChar: public Monitor {
    private:
    public:
        MonitorDeChar();
        virtual ~MonitorDeChar();
        virtual void escrever(Dado* d);
};

#endif