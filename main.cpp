#include "UnidadeDeControle.h"
#include "BancoDeRegistradores.h"
#include "ESMapeadaNaMemoria.h"
#include "GerenciadorDeMemoria.h"
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
void executarAteZero(UnidadeDeControle* u);
void load(UnidadeDeControle* u);
void dump(UnidadeDeControle* u);
void preDados1(UnidadeDeControle* u);
void preInstrucoes1(UnidadeDeControle* u); 

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
    cout << endl;
    if (opcao == 0) {
        delete u;
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
        executarAteZero(u);
    }
    if (opcao == 5) {
        load(u);
    }
    if (opcao == 6){
        dump(u);
    }
}

void proxInstrucao(UnidadeDeControle* u) {
    cout << "PC: " << u->getPC() << endl;
    try {
        u->executarInstrucao();
    } catch (exception *e) {
        cout << e->what() << endl;
        delete e;
    }
    cout << "Instrucao executada" << endl;
    cout << "PC: " << u->getPC() << endl;
    cout << endl;
    emulador(u);
}

void executarAteZero(UnidadeDeControle* u){
    if (u->getPC() == 0) u->executarInstrucao();
    while (u->getPC() != 0){
        try {
            u->executarInstrucao();
        } catch (exception *e) {
            cout << e->what() << endl;
            delete e;
        }
    }
    cout << endl;
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
    cout << endl; 
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
    cout << endl;
    registrador(u);
}

void ImprimeR(UnidadeDeControle* u) {
    u->getBancoDeRegistradores()->imprimir();
    cout << endl;
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
    cout << endl;
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
    cout << endl;
    memoria(u);
}

void imprimeM(UnidadeDeControle* u) {
    u->getMemoria()->imprimir();
    cout << endl;
    memoria(u);
}

void load(UnidadeDeControle* u) {
    string arquivoOrigem;
    cout << "Arquivo origem: ";
    cin >> arquivoOrigem;
    ESMapeadaNaMemoria* m = dynamic_cast<ESMapeadaNaMemoria*>(u->getMemoria());
    GerenciadorDeMemoria* g = new GerenciadorDeMemoria();
    try {
        g->load(arquivoOrigem, m->getMemoriaSubjacente());
    } catch (exception* e) {
        cout << e->what();
        delete e;
    }
    delete g;
    cout << endl;
    emulador(u);
}

void dump(UnidadeDeControle* u) {
    string arquivoDestino;
    cout << "Arquivo destino: ";
    cin >> arquivoDestino;
    ESMapeadaNaMemoria* m = dynamic_cast<ESMapeadaNaMemoria*>(u->getMemoria());
    GerenciadorDeMemoria* g = new GerenciadorDeMemoria();
    try {
        g->dump(arquivoDestino, m->getMemoriaSubjacente());
    } catch (exception* e) {
        cout << e->what();
        delete e;
    }
    delete g;
    cout << endl;
    emulador(u);
}

int main() {
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
    return 0;
}
