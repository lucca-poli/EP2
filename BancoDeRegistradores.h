#ifndef BANCODEREGISTRADORES_H
#define BANCODEREGISTRADORES_H

#define QUANTIDADE_REGISTRADORES 32

class BancoDeRegistradores {
    private:
        int* Registradores;
    public:
        BancoDeRegistradores();
        virtual ~BancoDeRegistradores();
        virtual int getValor(int registrador);
        virtual void setValor(int registrador, int valor);
        virtual void imprimir(); 
};

#endif