#include <stdio.h>
#include <string.h>
#include <windows.h>

void cabecalho()
{
    system("cls");
    printf("*************************************************\n");
    printf("*************************************************\n");
    printf("*********BEM VINDO A GESTAO DE CLIENTES**********\n");
    printf("*************************************************\n");
    printf("*************************************************\n\n\n");

    printf("SELECIONE UMA OPCAO\n 1 - CADASTRAR CLIENTES\n\n 2 - LISTAR CLIENTES\n\n");
}
int anoAtual()
{
    SYSTEMTIME str_t;
    GetSystemTime(&str_t);
    int anoAtual = str_t.wYear;
    return anoAtual;
}
int diaAtual()
{
    SYSTEMTIME dia;
    GetSystemTime(&dia);
    int diaAtual = dia.wDay;
    return diaAtual;
}
int mesAtual()
{
    SYSTEMTIME mes;
    GetSystemTime(&mes);
    int mesAtual = mes.wMonth;
    return mesAtual;
}

struct dataNascimento
{
    int dia;
    int mes;
    int ano;
};
typedef struct dataNascimento data;

struct Cliente
{

    char nome[30];
    int idade;
    data dataNascimento;
    char sexo[1];

    Cliente()
    {
        strcpy(nome,"");
        idade = 0;
        dataNascimento.dia = 0;
        dataNascimento.mes = 0;
        dataNascimento.ano = 0;
        strcpy(nome,"");
    }

    void novoCliente()
    {
        printf("Novo Cliente\n*********************\n");
        printf("Digite o nome:\n");
        scanf("%s", nome);
        printf("Digite a data de nascimento: dd/mm/yyyy\n");
        scanf("%d/%d/%d", &dataNascimento.dia,&dataNascimento.mes,&dataNascimento.ano);
        idade = calculaIdade();
        printf("Digite o sexo: M ou F\n");
        scanf("%s",&sexo);
    }

    int calculaIdade()
    {

        idade = anoAtual() - dataNascimento.ano;
        if(dataNascimento.mes > mesAtual() && dataNascimento.dia > diaAtual())
        {
            idade--;
        }
        return idade;
    }
    void listaClientes()
    {
        printf("%s\n", nome);
        printf("%d\n",idade);
        printf("%s\n",sexo);
    }
};

int main()
{
    Cliente clientes[50];
    int nCadastros=0;
    int opcao;
    do
    {

        cabecalho();
        scanf(" %d",&opcao);
        switch(opcao)
        {
        case 1:
            system("cls");
            clientes[nCadastros].novoCliente();
            nCadastros ++;
            break;

        case 2:
            system("cls");
            for(int i=0; i<nCadastros; i++)
            {
                clientes[i].listaClientes();
            }
            break;
        }
    }
    while(opcao ==1 || opcao ==2);


    return 0;
}
