#include <stdio.h>
#include "funcoes.h"

enum matriz {zero, sizeA, sizeB, randA, randB, preencheA, preencheB, AplusB, AminusB, AxB, printA, printB, printC, readtxtA, readtxtB, txtC};

int main()
{   int num, linA, colA, linB, colB;
    float A[20][20], B[20][20], C[20][20];
    do{
        menu();

        scanf("%d",&num);
        printf("\n");

        switch (num) {
        case sizeA:
            printf("Digite a quantidade de linhas da matriz A: ");
            scanf("%d", &linA);
            printf("Digite a quantidade de colunas da matriz A: ");
            scanf("%d", &colA);
            printf("A = %dx%d\n\n", linA, colA);
            break;

        case sizeB:
            printf("Digite a quantidade de linhas da matriz B: ");
            scanf("%d", &linB);
            printf("Digite a quantidade de colunas da matriz B: ");
            scanf("%d", &colB);
            printf("B = %dx%d\n\n", linB, colB);
            break;

        case randA:
            matrizrand(A, linA, colA);
            break;
        case randB:
            matrizrand(B, linB, colB);
            break;
        case preencheA:
            matriz(A, linA, colA);
                    break;
        case preencheB:
            matriz(B, linB, colB);
            break;
        case AplusB:
            soma(A, linA, colA, B, linB, colB, C);
            break;
        case AminusB:
            subtracao(A, linA, colA, B, linB, colB, C);
            break;
        case AxB:
            multiplicacao(A, linA, colA, B, linB, colB, C);
            break;
        case printA:
            printmatriz(A, linA, colA);
            break;
        case printB:
            printmatriz(B, linB, colB);
            break;
        case printC:
            printmatriz(C, linA, colB);
            break;
        case readtxtA:
            break;
        case readtxtB:
            break;
        case txtC:
            break;
        default:
            break;

        }}while(num<16);
    return 0;
}
