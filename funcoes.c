#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

void menu (void){
    printf("PROGRAMA DE MANIPULACAO DE MATRIZES\n"
           "(1) Definir o tamanho da matriz A\n"
           "(2) Definir o tamanho da matriz B\n"
           "(3) Preencher a matriz A com valores aleatorios\n"
           "(4) Preencher a matriz B com valores aleatorios\n"
           "(5) Atribuir valores manualmente para os elementos da matriz A\n"
           "(6) Atribuir valores manualmente para os elementos da matriz B\n"
           "(7) Calcular A+B\n"
           "(8) Calcular A-B\n"
           "(9) Calcular A*B\n"
           "(10) Imprimir matriz A\n"
           "(11) Imprimir matriz B\n"
           "(12) Imprimir matriz C\n"
           "(13) Ler a matriz A de um arquivo\n"
           "(14) Ler a matriz B de um arquivo\n"
           "(15) Escrever a matriz C em um arquivo\n"
           "(16) Sair\n");
}

void matrizrand (float A[20][20], int lin, int col){
    int x,y;
    srand(time(0));
    printf("Digite a faixa dos numeros aleatorios (x,y) para a matriz\n");
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);
    for(int i=0;i<lin;i++){
        for(int j=0; j<col;j++){
            A[i][j]= x + (rand() % (y-x+1));
        }
    }
}

void matriz (float A[20][20], int lin, int col){
    for(int i=0;i<lin;i++){
        for(int j=0; j<col;j++){
            printf("Digite o termo da linha %d e coluna %d: ", i+1, j+1);
            scanf("%f", &A[i][j]);
        }
    }
    printf("\n");
}

void soma(float A[20][20], int linA, int colA,float B[20][20], int linB, int colB, float C[20][20]){
    if(linA==linB && colA==colB){
        for(int i=0;i<linA;i++){
            for(int j=0; j<colA;j++){
                C[i][j]=A[i][j]+B[i][j];
            }
        }
    }
    else{
        printf("Nao eh possivel realizar a operacao.\n\n");
    }
}

void subtracao(float A[20][20], int linA, int colA,float B[20][20], int linB, int colB, float C[20][20]){
    if(linA==linB && colA==colB){
        for(int i=0;i<linA;i++){
            for(int j=0; j<colA;j++){
                C[i][j]=A[i][j]-B[i][j];
            }
        }
    }
    else{
        printf("Nao eh possivel realizar a operacao.\n\n");
    }
}

void multiplicacao(float A[20][20], int linA, int colA,float B[20][20], int linB, int colB, float C[20][20]){
    if(colA==linB){
        for(int i=0;i<linA;i++){
            for(int j=0; j<colB;j++){
                for(int k=0;k<colA;k++){
                    C[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
    }
    else{
        printf("Nao eh possivel realizar a operacao.\n\n");
    }
}

void printmatriz(float A[20][20], int lin, int col){
    printf("A = ");
    for(int i=0;i<lin;i++){
        for(int j=0; j<col;j++){
            printf("%2.2f ", A[i][j]);

        }
        printf("\n    ");
    }
    printf("\n");
}

