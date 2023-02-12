#include <stdio.h>
#include <string.h>

struct cliente{
        char nome[20];
        char telefone[20];
};
int main(){

    cliente novo;

    scanf("%s", novo.nome);

    printf("%s", novo.nome);
}
