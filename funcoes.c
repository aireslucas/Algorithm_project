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
           "(16) Sair\n\n"
           "DIGITE A OPCAO: ");
}

//funcao para gerar valores aleatorios para uma matriz
void matrizrand (float A[50][50], int lin, int col){
    int x,y;
    srand(time(0));
    printf("Digite a faixa de valores aleatorios [x,y]\n");
    printf("x= ");
    scanf("%d", &x);
    printf("y= ");
    scanf("%d", &y);
    for(int i=0;i<lin;i++){
        for(int j=0; j<col;j++){
            A[i][j]= x + (rand() % (y-x+1));
        }
    }
    printf("\n=========================================================================\n\n");
}

//funcao para preencher manualmente a matriz
void matriz (float A[50][50], int lin, int col){
    for(int i=0;i<lin;i++){
        for(int j=0; j<col;j++){
            printf("Digite o termo da linha %d e coluna %d: ", i+1, j+1);
            scanf("%f", &A[i][j]);
        }
    }
    printf("\n=======================================================================\n\n");
}

void soma(float A[50][50], int linA, int colA,float B[50][50], int linB, int colB, float C[50][50]){
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
    printf("=================================================================\n\n");
}

void subtracao(float A[50][50], int linA, int colA,float B[50][50], int linB, int colB, float C[50][50]){
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
    printf("===================================================================\n\n");
}

void multiplicacao(float A[50][50], int linA, int colA,float B[50][50], int linB, int colB, float C[50][50]){
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
    printf("======================================================================\n\n");
}

void printmatriz(float A[50][50], int lin, int col){
    for(int i=0;i<lin;i++){
        for(int j=0; j<col;j++){
            printf("%2.2f ", A[i][j]);

        }
        printf("\n");
    }
    printf("\n===============================================================\n\n");
}

//ler arquivo referente a A
void readAfile(float A[50][50], int *nl, int *nc){
    FILE *f;
    int i, j, nl1, nc1;
    float matriz [50][50];

    f = fopen("C:/Users/TaniaAires/Documents/Lucas/UFRN/Computacao/Algoritmo/Matriz_A.txt", "r");
    if(f==NULL){
        printf("nao abriu o arquivo\n");
        exit(0);
    }
    fscanf(f,"%d", &nl1);
    fscanf(f,"%d", &nc1);
    *nl=nl1;
    *nc=nc1;
    for(i=0; i<nl1; i++){
        for(j=0; j<nc1; j++){
            fscanf(f, "%f", &matriz[i][j]);
            A[i][j]=matriz[i][j];
        }
    }
    for(i=0; i<nl1; i++){
        for(j=0; j<nc1; j++){
            printf("%2.2f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n===========================================================================\n\n");
    fclose(f);
}

//ler arquivo referente a b
void readBfile(float A[50][50], int *nl, int *nc){
    FILE *f;
    int i, j, nl1, nc1;
    float matriz [50][50];

    f = fopen("C:/Users/TaniaAires/Documents/Lucas/UFRN/Computacao/Algoritmo/Matriz_B.txt", "r");
    if(f==NULL){
        printf("nao abriu o arquivo\n");
        exit(0);
    }
    fscanf(f,"%d", &nl1);
    fscanf(f,"%d", &nc1);
    *nl=nl1;
    *nc=nc1;
    for(i=0; i<nl1; i++){
        for(j=0; j<nc1; j++){
            fscanf(f, "%f", &matriz[i][j]);
            A[i][j]=matriz[i][j];
        }
    }
    for(i=0; i<nl1; i++){
        for(j=0; j<nc1; j++){
            printf("%2.2f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n==========================================================================\n\n");
    fclose(f);
}

//salva um arquivo da matriz c
void writeCfile(float A[50][50],int nl, int nc){
    int i,j;
    FILE *f;
    f = fopen("C:/Users/TaniaAires/Documents/Lucas/UFRN/Computacao/Algoritmo/Matriz_C.txt","w");

    for(i=0; i<nl; i++){
        for(j=0; j<nc-1; j++){
            fprintf(f, "%f,", A[i][j]);
        }
        fprintf(f, "%f", A[i][nc-1]);
        fprintf(f, "\n");
    }
    printf("==================================================================\n\n");
    fclose(f);
}
