#ifndef DADO_H
#define DADO_H

class Dado {
    protected:
        int valor;
    public:
        Dado(int valor);
        virtual ~Dado();
        virtual int getValor();
        virtual void imprimir();
};

#endif