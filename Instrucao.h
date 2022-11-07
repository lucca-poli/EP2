#ifndef INSTRUCAO_H
#define INSTRUCAO_H
#include "Dado.h"

class Instrucao: public Dado{
    private:
        int origem1;
        int origem2;
        int destino;
        int imediato;
        int funcao;
        static const int TIPO_R;
        static const int FUNCAO_ADD;
        static const int FUNCAO_SUB;
        static const int FUNCAO_MULT;
        static const int FUNCAO_DIV;
        static const int J;
        static const int BNE;
        static const int BEQ;
        static const int LW;
        static const int SW;
        Instrucao(int valor, int origem1, int origem2, int destino, int imediato, int funcao);
    public:
        static Instrucao* criarLW(int destino, int imediato);
        static Instrucao* criarSW(int destino, int imediato);
        static Instrucao* criarJ(int imediato);
        static Instrucao* criarBNE(int origem1, int origem2, int imediato);
        static Instrucao* criarBEQ(int origem1, int origem2, int imediato);
        static Instrucao* criarADD(int destino, int origem1, int origem2);
        static Instrucao* criarSUB(int destino, int origem1, int origem2);
        static Instrucao* criarMULT(int origem1, int origem2);
        static Instrucao* criarDIV(int origem1, int origem2); 
        virtual ~Instrucao();
        virtual int getOpcode();
        virtual int getOrigem1();
        virtual int getOrigem2();
        virtual int getDestino();
        virtual int getImediato();
        virtual int getFuncao();
        void imprimir();
};

#endif 