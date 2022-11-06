#include "UnidadeDeControle.h"
#include "BancoDeRegistradores.h"
#include "MemoriaDeDados.h"
#include "MemoriaDeInstrucoes.h"
#include "Instrucao.h"
#include <iostream>
using namespace std;

void emulador(UnidadeDeControle* u); 
void proxInst(UnidadeDeControle* u); 
void regis(UnidadeDeControle* u); 
void altValor(UnidadeDeControle* u); 
void Imprimir(UnidadeDeControle* u); 
void memoDados(UnidadeDeControle* u); 
void alteraValor(UnidadeDeControle* u); 
void imprime(UnidadeDeControle* u); 
void teste(); 

void emulador(UnidadeDeControle* u) {
    int opcao;
    cout << "Emulador de MIPS" << endl;
    cout << "1) Memoria de Dados" << endl;
    cout << "2) Registradores" << endl;
    cout << "3) Executar proxima instrucao" << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha uma opcao: ";
    cin >> opcao;  
    if (opcao == 0) {
        return;
    }  
    if (opcao == 1) {
        memoDados(u);
    }
    if (opcao == 2) {
        regis(u);
    }
    if (opcao == 3) {
        proxInst(u);
    }
}

void proxInst(UnidadeDeControle* u) {
    cout << "PC: " << u->getPC() << endl;
    u->executarInstrucao();
    cout << "Instrucao executada" << endl;
    cout << "PC: " << u->getPC() << endl;
    emulador(u);
}

void regis(UnidadeDeControle* u) {
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
        altValor(u);
    }
    if (opcao == 2) {
        Imprimir(u);
    }
}

void altValor(UnidadeDeControle* u) {
    int Regis, newValor;
    cout << "Registrador a ser alterado: ";
    cin >> Regis;
    cout << "Novo valor: ";
    cin >> newValor;
    u->getBancoDeRegistradores()->setValor(Regis, newValor);
    regis(u);
}

void Imprimir(UnidadeDeControle* u) {
    u->getBancoDeRegistradores()->imprimir();
    regis(u);
}

void memoDados(UnidadeDeControle* u) {
    cout << "Memoria de Dados" << endl;
    cout << "1) Alterar valor" << endl;
    cout << "2) Imprimir" << endl;
    cout << "0) Voltar" << endl;
    cout << "Escolha uma opcao: ";
    int opcao;
    cin >> opcao;

    if (opcao == 1) {
        alteraValor(u);
    }
    if (opcao == 2) {
        imprime(u);
    }
    if (opcao == 0) {
        emulador(u);
    }
}

void alteraValor(UnidadeDeControle* u) {
    int memo, novoValor;
    cout << "Posicao a ser alterada: ";
    cin >> memo;
    cout << "Novo valor: ";
    cin >> novoValor;
    Dado* d = new Dado(novoValor);
    u->getMemoriaDeDados()->escrever(memo, d);
    memoDados(u);
}

void imprime(UnidadeDeControle* u) {
    u->getMemoriaDeDados()->imprimir();
    memoDados(u);
}

void teste() {
    BancoDeRegistradores* R1 = new BancoDeRegistradores();
    MemoriaDeDados *D1 = new MemoriaDeDados(16);
    MemoriaDeInstrucoes* I1 = new MemoriaDeInstrucoes(16);
    UnidadeDeControle* U1 = new UnidadeDeControle(R1, I1, D1);
    Instrucao* i0 = new Instrucao(LW, 0, 0, 8, 0, 0);
    Instrucao* i1 = new Instrucao(LW, 0, 0, 9, 1, 0);
    Instrucao* i2 = new Instrucao(LW, 0, 0, 10, 2, 0);
    Instrucao* i3 = new Instrucao(BNE, 9, 10, 0, 7, 0);
    Instrucao* i4 = new Instrucao(0, 8, 10, 0, 0, FUNCAO_MULT);
    Instrucao* i5 = new Instrucao(SW, 0, 0, 24, 3, 0);
    Instrucao* i6 = new Instrucao(J, 0, 0, 0, 0, 0);
    Instrucao* i7 = new Instrucao(0, 10, 8, 9, 0, FUNCAO_ADD);
    Instrucao* i8 = new Instrucao(SW, 0, 0, 9, 3, 0);
    Instrucao* i9 = new Instrucao(J, 0, 0, 0, 10, 0);
    I1->escrever(0, i0);
    I1->escrever(1, i1);
    I1->escrever(2, i2);
    I1->escrever(3, i3);
    I1->escrever(4, i4);
    I1->escrever(5, i5);
    I1->escrever(6, i6);
    I1->escrever(7, i7);
    I1->escrever(8, i8);
    I1->escrever(9, i9);
    emulador(U1);
}
    
int main() {
    teste();
    return 0;
}