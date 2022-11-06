#ifndef BANCODEREGISTRADORES_H
#define BANCODEREGISTRADORES_H

#define QUANTIDADE_REGISTRADORES 32

class BancoDeRegistradores {
    private:
        int* Registradores;
        int registrador;
        int valor;
    public:
        BancoDeRegistradores();
        virtual ~BancoDeRegistradores();
        int getValor(int registrador);
        void setValor(int registrador, int valor);
        void imprimir(); 
};

#endif