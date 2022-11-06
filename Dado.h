#ifndef DADO_H
#define DADO_H

class Dado {
    private:
        int valor;
    public:
        Dado(int valor);
        virtual ~Dado();
        int getValor();
        void imprimir();
};

#endif