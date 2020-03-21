//
// Created by Michael Pavlov on 11.03.2020.
//

#ifndef NEWLAB1NEW_HEADER_H
#define NEWLAB1NEW_HEADER_H

#include <stdio.h>
#include <stdlib.h>

#define M(m, i, j)  (((float**)m->matrix)[i][j])
#define Mr(m, i, j)  (((float**)m.matrix)[i][j])
#define Mc(m, i, j)  (((complex**)m->matrix)[i][j])
#define Mrc(m, i, j)  (((complex**)m.matrix)[i][j])

typedef struct complex
{
    float re;
    float im;
} complex;

void printfc(complex *a)
{
    if (a->im < 0) printf("%.2f%.2fi\t", a->re, a->im);
    else printf("%.2f+%.2fi\t", a->re, a->im);
}

complex sumc (complex *a, complex *b)
{
    complex ans;
    ans.re = a->re + b->re;
    ans.im = a->im + b->im;
    return ans;
}

complex assc ()
{
    complex result;
    printf("Enter the real part of the number: ");
    scanf("%f", &result.re);
    printf("Enter the imaginary part of the number: ");
    scanf("%f", &result.im);
    return result;
}

complex multc (complex *a, complex *b)
{
    complex ans;
    ans.re = a->re * b->re - a->im * b->im;
    ans.im = a->im * b->re + a->re * b->im;
    return (ans);
}

typedef struct Matrixc {
    int     rowSize;
    int     columnSize;
    complex** matrix;
} Matrixc;

typedef struct Matrix {
    int     rowSize;
    int     columnSize;
    float**    matrix;
} Matrix;


void err(){
    fprintf(stderr, "Error!");
    exit(0);
}

Matrix createMatrix(int r, int c){
    Matrix temp = {r, c, calloc(r, sizeof(float *))};

    if (temp.matrix == NULL) {
        err();
    }

    for (int i = 0; i < r; i++) {
        temp.matrix[i] = calloc(c, sizeof temp.matrix[i][0]);

        if (temp.matrix[i] == NULL) {
            err();
        }
    }
    return temp;
}

Matrixc createMatrixc(int r, int c){
    Matrixc temp = {r, c, calloc(r, sizeof(complex *))};

    if (temp.matrix == NULL) {
        err();
    }

    for (int i = 0; i < r; i++) {
        temp.matrix[i] = calloc(c, sizeof temp.matrix[i][0]);

        if (temp.matrix[i] == NULL) {
            err();
        }
    }
    return temp;
}

Matrix Assignment(Matrix *m){
    int i, j;
    int r = m->rowSize;
    int c = m->columnSize;
    Matrix result = createMatrix(r,c);
    for (i = 0; i < r; ++i){
        for (j = 0; j < c; ++j){
            printf ( "Enter the element of line %d column %d: \n", i+1, j+1);
            scanf("%f", &Mr(result, i, j));
        }
    }
    return result;
}

Matrixc Assignmentc(Matrixc *m){
    int i, j;
    int r = m->rowSize;
    int c = m->columnSize;
    Matrixc result = createMatrixc(r,c);
    for (i = 0; i < r; ++i){
        for (j = 0; j < c; ++j){
            printf ( "Enter the element of line %d column %d: \n", i+1, j+1);
            Mrc(result, i, j) = assc();
        }
    }
    return result;
}

void printMatrix(Matrix *m){

    int i,j;
    for(i = 0; i < m->rowSize ; i++){
        for(j = 0; j < m->columnSize; j++){
            printf("%.2f\t", M(m, i, j));
        }
        printf("\n");
    }
}

void printMatrixc(Matrixc *m){

    int i,j;
    for(i = 0; i < m->rowSize ; i++){
        for(j = 0; j < m->columnSize; j++){
            printfc(&Mc(m, i, j));
        }
        printf("\n");
    }
}

Matrix add(Matrix *a, Matrix *b){
    if(a->rowSize != b->rowSize || a->columnSize != b->columnSize) err();
    int r = a->rowSize;
    int c = a->columnSize;
    Matrix result = createMatrix(r,c);
    int i,j;
    for(i = 0; i < r ; i++){
        for(j = 0; j < c; j++){
            Mr(result, i, j) = M(a, i, j) + M(b, i, j);
            //printf ("%d \t", Mr(result, i, j));
        }
    }
    return result;
}

Matrixc addc(Matrixc *a, Matrixc *b){
    if(a->rowSize != b->rowSize || a->columnSize != b->columnSize) err();
    int r = a->rowSize;
    int c = a->columnSize;
    Matrixc result = createMatrixc(r,c);
    int i,j;
    for(i = 0; i < r ; i++){
        for(j = 0; j < c; j++){
            //Mrc(result, i, j) = Mc(a, i, j) + Mc(b, i, j);
            Mrc(result, i, j) = sumc(&Mc(a, i, j), &Mc(b, i, j));
            //printf ("%d \t", Mr(result, i, j));
        }
    }
    return result;
}

Matrix multiply(Matrix *a, Matrix *b){
    if(a->columnSize != b->rowSize ) err();
    int r = a->rowSize;
    int c = b->columnSize;
    Matrix result = createMatrix(r, c);

    int i,j;
    for(i = 0; i < r ; i++){
        for(j = 0; j < c; j++){
            float sum = 0;
            int k;
            for(k = 0; k < a->columnSize; k++){
                sum = sum + M(a, i, k) * M(b, k, j);
            }
            Mr(result, i, j) = sum;
        }
    }
    return result;
}

Matrixc multiplyc(Matrixc *a, Matrixc *b){
    if(a->columnSize != b->rowSize ) err();

    int r = a->rowSize;
    int c = b->columnSize;
    Matrixc result = createMatrixc(r, c);

    int i,j;
    complex mlt;
    for(i = 0; i < r ; i++){
        for(j = 0; j < c; j++){
            complex sum;
            sum.re = 0;
            sum.im = 0;
            int k;
            for(k = 0; k < a->columnSize; k++){
                mlt.re = 0;
                mlt.im = 0;
                mlt = multc(&Mc(a, i, k), &Mc(b, k, j));
                sum = sumc(&sum, &mlt);
            }
            Mrc(result, i, j) = sum;
        }
    }
    return result;
}

Matrix trans(Matrix *a){
    int r = a->columnSize;
    int c = a->rowSize;
    Matrix result = createMatrix(r, c);

    int i, j;
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            Mr(result, i, j) = M(a, j, i);
        }
    }
    return result;
}

Matrixc transc(Matrixc *a){
    int r = a->columnSize;
    int c = a->rowSize;
    Matrixc result = createMatrixc(r, c);

    int i, j;
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            Mrc(result, i, j) = Mc(a, j, i);
        }
    }
    return result;
}

void destroyMatrix(Matrix* matrix){
    if(matrix->rowSize * matrix->columnSize == 0) return;
    for(int i = 0; i < matrix->rowSize * matrix->columnSize; i++) free(matrix->matrix[i]);
    free(matrix->matrix);
    matrix->rowSize = 0;
    matrix->columnSize = 0;
}

void destroyMatrixc(Matrixc* matrix){
    if(matrix->rowSize * matrix->columnSize == 0) return;
    for(int i = 0; i < matrix->rowSize * matrix->columnSize; i++) free(matrix->matrix[i]);
    free(matrix->matrix);
    matrix->rowSize = 0;
    matrix->columnSize = 0;
}

#endif //NEWLAB1NEW_HEADER_H
