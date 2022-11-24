#ifndef GERENCIADORDEMEMORIA_H
#define GERENCIADORDEMEMORIA_H

#include "MemoriaRAM.h"
#include <string>
using namespace std;

class GerenciadorDeMemoria {
    private:
    public:
        GerenciadorDeMemoria();
        virtual ~GerenciadorDeMemoria();
        virtual void load(string arquivo, MemoriaRAM* m);
        virtual void dump(string arquivo, MemoriaRAM* m); 
};

#endif