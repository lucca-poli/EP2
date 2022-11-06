#ifndef UNIDADEDECONTROLE_H
#define UNIDADEDECONTROLE_H
#include "BancoDeRegistradores.h"
#include "MemoriaDeDados.h"
#include "MemoriaDeInstrucoes.h"

class UnidadeDeControle {
    private:
        int pc;
        BancoDeRegistradores *registradores;
        MemoriaDeInstrucoes *instrucoes;
        MemoriaDeDados *dados;
    public:
        UnidadeDeControle(BancoDeRegistradores* registradores, MemoriaDeInstrucoes* instrucoes, MemoriaDeDados* dados);
        virtual ~UnidadeDeControle();
        BancoDeRegistradores* getBancoDeRegistradores();
        MemoriaDeDados* getMemoriaDeDados();
        MemoriaDeInstrucoes* getMemoriaDeInstrucoes();
        int getPC();
        void setPC(int pc);
        void executarInstrucao(); 
};

#endif