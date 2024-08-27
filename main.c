//Aluno: Luis Felipe Perylo Benicio, 3 periodo, Turma A
//transformar base 10 para bcd: 16:30 23/08/2024
//transformar base 10 para binario: 12:00 23/08/2024
//transformar base 10 para hexadecimal: 15:30 23/08/2024
//transformar base 10 para octal: 15:45 23/08/2024
//transformar em complemento de 2: 15:33 26/08/2024
//Questão 03: 9:46 27/08/2024

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

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

    void transforma_complemento2(int n,int resultado[], int *tamanho) {

        int negativo = (n < 0);

        if (negativo) {
            n = -n;
        }

        int i = 0;
        while (n > 0) {
            resultado[i] = n % 2;
            n = n / 2;
            i++;
        }

        *tamanho = i;

        if (negativo) {

            for (int j = 0; j < *tamanho; j++) {
                resultado[j] = (resultado[j] == 1) ? 0 : 1;
            }

            int carry = 1;
            for (int j = 0; j < *tamanho; j++) {
                int soma = resultado[j] + carry;
                resultado[j] = soma % 2;
                carry = soma / 2;
            }

            if (carry == 1) {
                resultado[*tamanho] = 1;
                (*tamanho)++;
            }

            resultado[*tamanho] = 1;
        } else {
            resultado[*tamanho] = 0;
        }

        (*tamanho)++;
    }

    void print_bits(uint64_t n, int bits) {
            for (int i = bits - 1; i >= 0; i--) {
                printf("%d", (n >> i) & 1);
                if (i % 4 == 0 && i != 0) printf(" ");
            }
            printf("\n");
    }

    void converte_float(float f) {
            union {
                float f;
                uint32_t u;
            } converter;

            converter.f = f;
            uint32_t bits = converter.u;

            uint32_t sinal = (bits >> 31) & 1;
            uint32_t expoente = (bits >> 23) & 0xFF;
            uint32_t mantissa = bits & 0x7FFFFF;

            printf("Float:\n");
            printf("Sinal: %u\n", sinal);
            printf("Expoente (com viés): ");
            print_bits(expoente, 8);
            printf("Mantissa: ");
            print_bits(mantissa, 23);
        }


    void converte_double(double d) {
            union {
                double d;
                uint64_t u;
            } converter;

            converter.d = d;
            uint64_t bits = converter.u;

            uint64_t sinal = (bits >> 63) & 1;
            uint64_t expoente = (bits >> 52) & 0x7FF;
            uint64_t mantissa = bits & 0xFFFFFFFFFFFFF;

            printf("\nDouble:\n");
            printf("Sinal: %llu\n", sinal);
            printf("Expoente (com vies): ");
            print_bits(expoente, 11);
            printf("Mantissa: ");
            print_bits(mantissa, 52);
        }

int main(void) {

    int opcao,numero,resultado[32],tamanho=0;
    char resultadohexa[32],resultadoBCD[40];

    do {
        printf("Escolha qual operacao deseja fazer: \n\nBase 10 para Binario: 1\n\nBase 10 para Octal: 2\n\nBase 10 para Hexadecimal: 3\n\nBase 10 para codigo BCD: 4\n\nBase 10 para base com sinal com 16 bits: 5\n\nreal em decimal para float e double: 6");
        scanf("%d",&opcao);

    }while (opcao>6 || opcao<1);

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

            transforma_complemento2(numero,resultado, &tamanho);

            printf("Resultado em complemento de 2: ");

            for (int i = tamanho - 1; i >= 0; i--) {
                printf("%d", resultado[i]);
            }

            break;

        case 6:
            float num_float;
            double num_double;

            printf("Digite um numero real em decimal: ");
            scanf("%f",&num_float);

            num_double = (double) num_float;

            converte_float(num_float);
            converte_double(num_double);

            break;
    }

    return 0;
}


