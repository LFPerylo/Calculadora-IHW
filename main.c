#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

    void transforma_binario(int n,int resultado[], int *tamanho) {

        int i = 0;

        while (n > 0) {
            resultado[i] = n % 2;
            n = n / 2;
            i++;
        }
        *tamanho = i;
    }

    void transforma_hexa(int n,char resultadohexa[], int *tamanho) {

        int i = 0;

        do {
            int resto = n % 16;

            if (resto >= 10) {
                resultadohexa[i] = 'A' + (resto - 10);
            } else {
                resultadohexa[i] = '0' + resto;
            }

            n = n/16;
            i++;
        }while (n > 0);

        *tamanho = i;
    }
int main(void) {

    int opcao,numero;
    int resultado[32];
    char resultadohexa[32];
    int tamanho = 0;

    do {
        printf("Escolha qual operacao deseja fazer: \n\nBase 10 para Binario: 1\n\nBase 10 para Octal: 2\n\nBase 10 para Hexadecimal: 3\n\nBase 10 para codigo BCD: 4\n\nBase 10 para base com sinal com 16 bits: 5\n\nreal em decimal para float e double: 6");
        scanf("%d",&opcao);

    }while (opcao>4 && opcao<1);

    switch (opcao) {
        case 1:
            printf("Digite um numero na Base 10: ");
            scanf("%d",&numero);

            transforma_binario(numero, resultado, &tamanho);

            printf("Resultado em binario: ");

            for (int i = tamanho - 1; i >= 0; i--) {
                printf("%d", resultado[i]);
            }

            break;

        case 2:
            printf("Digite um numero na Base 10: ");
            scanf("%d",&numero);

        case 3:
            printf("Digite um numero na Base 10: ");
            scanf("%d",&numero);

            transforma_hexa(numero, resultadohexa, &tamanho);

            printf("Resultado em hexadecimal: ");

            for (int i = tamanho - 1; i >= 0; i--) {
                printf("%c", resultadohexa[i]);
            }

            break;

        case 4:
            printf("Digite um numero na Base 10: ");
            scanf("%d",&numero);

        case 5:
            printf("Digite um numero na Base 10: ");
            scanf("%d",&numero);

        case 6:
            printf("Digite um numero real em decimal: ");
            scanf("%d",&numero);
    }

    return 0;
}


