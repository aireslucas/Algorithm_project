#include <stdio.h>
#include "funcoes.h"

enum matriz {zero, sizeA, sizeB, randA, randB, preencheA, preencheB, AplusB, AminusB, AxB, printA, printB, printC, readtxtA, readtxtB, txtC};
//enumerate para definicao dos cases

int main()
{   int num, linA=1, colA=1, linB=1, colB=1;
    float A[50][50], B[50][50], C[50][50];
    do{
        menu();

        scanf("%d",&num);
        printf("\n");

        switch (num) {
        case sizeA:
            printf("===================== TAMANHO DA MATRIZ A =============================\n\n");
            printf("Digite a quantidade de linhas da matriz A, nao excedendo 50: ");
            scanf("%d", &linA);
            printf("Digite a quantidade de colunas da matriz A, nao excedendo 50: ");
            scanf("%d", &colA);
            printf("A = %dx%d\n", linA, colA);
            printf("\n=======================================================================\n\n");
            break;

        case sizeB:
            printf("===================== TAMANHO DA MATRIZ B ============================\n\n");
            printf("Digite a quantidade de linhas da matriz B, nao excedendo 50: ");
            scanf("%d", &linB);
            printf("Digite a quantidade de colunas da matriz B, nao excedendo 50: ");
            scanf("%d", &colB);
            printf("B = %dx%d\n", linB, colB);
            printf("\n=======================================================================\n\n");
            break;

        case randA:
            printf("====================== RANDOMIZA A MATRIZ A ============================\n\n");
            matrizrand(A, linA, colA);
            break;
        case randB:
            printf("====================== RANDOMIZA A MATRIZ B ===========================\n\n");
            matrizrand(B, linB, colB);
            break;
        case preencheA:
            printf("====================== PREENCHE A MATRIZ A ===========================\n\n");
            matriz(A, linA, colA);
            break;
        case preencheB:
            printf("====================== PREENCHE A MATRIZ B ===========================\n\n");
            matriz(B, linB, colB);
            break;
        case AplusB:
            printf("======================== SOMA (A+B) =============================\n\n");
            soma(A, linA, colA, B, linB, colB, C);
            break;
        case AminusB:
            printf("====================== SUBTRACAO (A-B) ===========================\n\n");
            subtracao(A, linA, colA, B, linB, colB, C);
            break;
        case AxB:
            printf("====================== MULTIPLICACAO (AxB) ===========================\n\n");
            multiplicacao(A, linA, colA, B, linB, colB, C);
            break;
        case printA:
            printf("======================== MATRIZ A =============================\n\n");
            printmatriz(A, linA, colA);
            break;
        case printB:
            printf("======================== MATRIZ B =============================\n\n");
            printmatriz(B, linB, colB);
            break;
        case printC:
            printf("======================== MATRIZ C =============================\n\n");
            printmatriz(C, linA, colB);
            break;
        case readtxtA:
            printf("====================== LER ARQUIVO DA MATRIZ A ===========================\n\n");
            readAfile(A, &linA, &colA);
            break;
        case readtxtB:
            printf("====================== LER ARQUIVO DA MATRIZ B ===========================\n\n");
            readBfile(B, &linB, &colB);
            break;
        case txtC:
            printf("====================== SALVAR MATRIZ C ===========================\n\n");
             writeCfile(C, linA, colB);
            break;
        default:
            break;
        }
    }while(num<16);

    //do-while, para ficar gerando o menu
    return 0;
}
