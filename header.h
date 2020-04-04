//
// Created by Michael Pavlov on 11.03.2020.
//

#ifndef Lab1_HEADER_H
#define Lab1_HEADER_H
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

typedef struct Matrix {
    int     rowSize;
    int     columnSize;
    void**    matrix;
    int     flag;           // 1 for real and 2 for complex
} Matrix;


void err(){
    fprintf(stderr, "Error!");
    exit(0);
}

Matrix createMatrix(int r, int c, int f){
    int vtf;
    if (f == 1) vtf = sizeof(float);
    else vtf = sizeof(complex);
    Matrix temp = {r, c, calloc(r, sizeof(void*))};
    temp.flag = f;
    if (temp.matrix == NULL) {
        err();
    }

    for (int i = 0; i < r; i++) {
        temp.matrix[i] = calloc(c, sizeof vtf);

        if (temp.matrix[i] == NULL) {
            err();
        }
    }
    return temp;
}

void printMatrix(Matrix *m){

    int i,j;
    for(i = 0; i < m->rowSize ; i++){
        for(j = 0; j < m->columnSize; j++){
            if (m->flag == 1) printf("%.2f\t", M(m, i, j));
            else printfc(&Mc(m, i, j));
        }
        printf("\n");
    }
}

Matrix Assignment(Matrix *m){
    int i, j;
    float f;
    complex com;
    int r = m->rowSize;
    int c = m->columnSize;
    int que = m->flag;
    Matrix result = createMatrix(r,c, que);
    for (i = 0; i < r; ++i){
        for (j = 0; j < c; ++j){
            printf ( "Enter the element of line %d column %d: \n", i+1, j+1);
            if (m->flag == 1) scanf("%f", &Mr(result, i, j));
            else Mrc(result, i, j) = assc();
        }
    }
    puts ("Your Matrix: \n");
    return result;
}

Matrix add(Matrix *a, Matrix *b){
    if(a->rowSize != b->rowSize || a->columnSize != b->columnSize) err();
    int r = a->rowSize;
    int c = a->columnSize;
    int que = a->flag;
    Matrix result = createMatrix(r,c, que);
    int i,j;
    for(i = 0; i < r ; i++){
        for(j = 0; j < c; j++){
            if (que == 1) Mr(result, i, j) = M(a, i, j) + M(b, i, j);
            else Mrc(result, i, j) = sumc(&Mc(a, i, j), &Mc(b, i, j));
            //printf ("%d \t", Mr(result, i, j));
        }
    }
    return result;
}

Matrix multiply(Matrix *a, Matrix *b){
    if(a->columnSize != b->rowSize ) err();
    int r = a->rowSize;
    int c = b->columnSize;
    int que = a->flag;
    Matrix result = createMatrix(r, c, que);

    int i,j;
    for(i = 0; i < r ; i++){
        for(j = 0; j < c; j++){
            float sum = 0;
            complex suc, succ;
            succ.re = 0; succ.im = 0;
            int k;
            for(k = 0; k < a->columnSize; k++){
                if (a->flag == 1) {
                    sum = sum + M(a, i, k) * M(b, k, j);
                }
                else {
                    suc = multc(&Mc(a, i, k), &Mc(b, k, j));
                    succ = sumc(&succ, &suc);
                }
            }
            if (a->flag == 1) Mr(result, i, j) = sum;
            else Mrc(result, i, j) = succ;
        }
    }
    return result;
}

Matrix trans(Matrix *a){
    int r = a->columnSize;
    int c = a->rowSize;
    int que = a->flag;
    Matrix result = createMatrix(r, c, que);

    int i, j;
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            if (a->flag == 1) Mr(result, i, j) = M(a, j, i);
            else Mrc(result, i, j) = Mc(a, j, i);
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
    matrix->flag = 0;
}

#endif //Lab1_HEADER_H
