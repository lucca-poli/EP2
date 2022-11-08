#ifndef ESMAPEADANAMEMORIA_H
#define ESMAPEADANAMEMORIA_H
#include "Memoria.h"
#include "MemoriaRAM.h"
#include "Dispositivo.h"
#include <vector>

class ESMapeadaNaMemoria: public Memoria {
    private:
        MemoriaRAM* Memoria;
        vector<Dispositivo*>* Dispositivos;
    public:
        ESMapeadaNaMemoria(MemoriaRAM* m);
        ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos);
        virtual ~ESMapeadaNaMemoria();
        virtual MemoriaRAM* getMemoriaSubjacente();
        virtual void adicionar(Dispositivo* d);
        virtual vector<Dispositivo*>* getDispositivos(); 
        int getTamanho();
        Dado* ler(int posicao);
        void escrever(int posicao, Dado* d);
        void imprimir();
};

#endif