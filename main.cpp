#include "UnidadeDeControle.h"
#include "BancoDeRegistradores.h"
#include "ESMapeadaNaMemoria.h"
#include "MemoriaRAM.h"
#include "Monitor.h"
#include "MonitorDeChar.h"
#include "Teclado.h"
#include "TecladoDeChar.h"
#include "Dado.h"
#include "Instrucao.h"
#include <stdexcept>
#include <iostream>
using namespace std;

void emulador(UnidadeDeControle* u); 
void proxInstrucao(UnidadeDeControle* u); 
void registrador(UnidadeDeControle* u); 
void alteraRegistrador(UnidadeDeControle* u); 
void ImprimeR(UnidadeDeControle* u); 
void memoria(UnidadeDeControle* u); 
void alteraMemoria(UnidadeDeControle* u); 
void imprimeM(UnidadeDeControle* u);
void exec(UnidadeDeControle* u); 
void ep();
void teste1(); 

void emulador(UnidadeDeControle* u) {
    int opcao;
    cout << "Emulador de MIPS" << endl;
    cout << "1) Memoria" << endl;
    cout << "2) Registradores" << endl;
    cout << "3) Executar proxima instrucao" << endl;
    cout << "4) Executar ate PC = 0" << endl;
    cout << "5) Load" << endl;
    cout << "6) Dump" << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha uma opcao: ";
    cin >> opcao;  
    if (opcao == 0) {
        return;
    }  
    if (opcao == 1) {
        memoria(u);
    }
    if (opcao == 2) {
        registrador(u);
    }
    if (opcao == 3) {
        proxInstrucao(u);
    }
    if (opcao == 4){
        exec(u);
    }
    if (opcao == 5){
    }
    if (opcao == 6){
    }
}

void proxInstrucao(UnidadeDeControle* u) {
    cout << "PC: " << u->getPC() << endl;
    u->executarInstrucao();
    cout << "Instrucao executada" << endl;
    cout << "PC: " << u->getPC() << endl;
    try {
        if (u->getPC() > u->getMemoria()->getTamanho() - 1) {
            throw new invalid_argument("PC tenta acessar memoria inexistente");
        }
    } catch (invalid_argument *e) {
        e->what();
        delete e;
    }
    emulador(u);
}

void exec(UnidadeDeControle* u){
    while (u->getPC() != 0){
        u->executarInstrucao();
        try {
            if (u->getPC() > u->getMemoria()->getTamanho() - 1) {
                throw new invalid_argument("PC tenta acessar memoria inexistente");
            }
        } catch (invalid_argument *e) {
            e->what();
            delete e;
            break;
        }
    }
    emulador(u);
}

void registrador(UnidadeDeControle* u) {
    int opcao;
    cout << "Registradores" << endl;
    cout << "1) Alterar valor" << endl;
    cout << "2) Imprimir" << endl;
    cout << "0) Voltar" << endl;
    cout << "Escolha uma opcao: ";
    cin >> opcao;  
    if (opcao == 0) {
        emulador(u);
    }  
    if (opcao == 1) {
        alteraRegistrador(u);
    }
    if (opcao == 2) {
        ImprimeR(u);
    }
}

void alteraRegistrador(UnidadeDeControle* u) {
    int posicao, newValor;
    cout << "Registrador a ser alterado: ";
    cin >> posicao;
    cout << "Novo valor: ";
    cin >> newValor;
    u->getBancoDeRegistradores()->setValor(posicao, newValor);
    registrador(u);
}

void ImprimeR(UnidadeDeControle* u) {
    u->getBancoDeRegistradores()->imprimir();
    registrador(u);
}

void memoria(UnidadeDeControle* u) {
    int opcao;
    cout << "Memoria" << endl;
    cout << "1) Alterar dado" << endl;
    cout << "2) Imprimir" << endl;
    cout << "0) Voltar" << endl;
    cout << "Escolha uma opcao: ";
    cin >> opcao;

    if (opcao == 1) {
        alteraMemoria(u);
    }
    if (opcao == 2) {
        imprimeM(u);
    }
    if (opcao == 0) {
        emulador(u);
    }
}

void alteraMemoria(UnidadeDeControle* u) {
    int memo, novoValor;
    cout << "Posicao a ser alterada: ";
    cin >> memo;
    cout << "Novo valor: ";
    cin >> novoValor;
    Dado* d = new Dado(novoValor);
    u->getMemoria()->escrever(memo, d);
    memoria(u);
}

void imprimeM(UnidadeDeControle* u) {
    u->getMemoria()->imprimir();
    memoria(u);
}

void ep() {
    BancoDeRegistradores* R = new BancoDeRegistradores();
    MemoriaRAM* RAM = new MemoriaRAM(64);
    ESMapeadaNaMemoria* ES = new ESMapeadaNaMemoria(RAM);
    Teclado* teclado = new Teclado();
    TecladoDeChar* tecladoChar = new TecladoDeChar();
    Monitor* monitor = new Monitor();
    MonitorDeChar* monitorChar = new MonitorDeChar();
    ES->adicionar(teclado);
    ES->adicionar(tecladoChar);
    ES->adicionar(monitor);
    ES->adicionar(monitorChar);
    UnidadeDeControle* U = new UnidadeDeControle(R, ES);
    emulador(U);
}
    
int main() {
    ep();
    return 0;
}
