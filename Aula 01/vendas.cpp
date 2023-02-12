#include<stdio.h>
#include<string.h>

//classe produtos
struct produto {

    char nome[100];
    int qtd;
    double vu, vt;

    //construtor - zerar tudo
    produto() {
        strcpy(nome, "");
        qtd = 0;
        vu = 0;
        vt = 0;
    }

    //funcao para ler
    void ler() {
        scanf("%s %d %lf", nome, &qtd, &vu);
        calcularVT();
    }

    //printar na tela
    void imprimir() {
        printf("%s\n%d x %.2lf = %.2lf\n", nome, qtd, vu, vt);
    }

    //calcular o valor
    void calcularVT() {
        vt = qtd * vu;
    }

};

//classe
struct Venda {

    char cliente[100];
    produto itens[10];
    int qtdItens;
    double vt;

    //contrutor venda
    Venda() {

        strcpy(cliente, "");
        qtdItens = 0;
        vt = 0;

    }

    void ler() {

        scanf("%s %d", cliente, &qtdItens);

        for(int i = 0; i < qtdItens; i++) {

            itens[i].ler();

        }

    }

    void imprimir() {

        printf("%s  R$%.2lf\n", cliente, vt);

        for(int i = 0; i < qtdItens; i++){

            itens[i].imprimir();

        }

    }

    void calcularVT() {

        vt = 0;

        for(int i = 0; i < qtdItens; i++) {

            vt += itens[i].vt;

        }

    }

};

int main() {

    Venda v;

    v.ler();

    v.imprimir();

    return 0;
}
