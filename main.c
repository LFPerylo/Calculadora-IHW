//Aluno: Luis Felipe Perylo Benicio, 3 periodo, Turma A
//transformar base 10 para bcd: 16:30 23/08/2024
//transformar base 10 para binario: 12:00 23/08/2024
//transformar base 10 para hexadecimal: 15:30 23/08/2024
//transformar base 10 para octal: 15:45 23/08/2024


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

    void transforma_octal(int n,int resultado[], int *tamanho) {

        int i = 0;

        while (n > 0) {
            resultado[i] = n % 8;
            n = n / 8;
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

    void transforma_bcd(int n,char resultadoBCD[], int *tamanho) {

        int i = 0;
        int digits[10];
        int num_digits = 0;

        while (n > 0) {
            digits[num_digits++] = n % 10;
            n /= 10;
        }

        for (int j = num_digits - 1; j >= 0; j--) {
            int digito = digits[j];

            for (int k = 3; k >= 0; k--) {
                resultadoBCD[i + k] = (digito % 2) + '0';
                digito /= 2;
            }
            i += 4;
        }

        *tamanho = i;
    }

int main(void) {

    int opcao,numero,resultado[32],tamanho=0;
    char resultadohexa[32],resultadoBCD[40];

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

            transforma_octal(numero, resultado, &tamanho);

            printf("Resultado em octal: ");

            for (int i = tamanho - 1; i >= 0; i--) {
                printf("%d", resultado[i]);
            }

            break;

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

            transforma_bcd(numero,resultadoBCD, &tamanho);

            printf("Resultado em BCD: ");

            for (int i = 0; i < tamanho; i++) {
                if (i > 0 && i % 4 == 0) {
                    printf(" ");
                }
                printf("%c", resultadoBCD[i]);
            }

            break;

        case 5:
            printf("Digite um numero na Base 10: ");
            scanf("%d",&numero);

        case 6:
            printf("Digite um numero real em decimal: ");
            scanf("%d",&numero);
    }

    return 0;
}


