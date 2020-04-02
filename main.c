#include <stdio.h>
#include "header.h"

int main(){
    int r, c, que, lapre = 1;
    puts("Hello, User!\n");
    puts("Firstly, you have to create your own matrix\n");
    puts("Enter the number of lines: ");
    scanf("%d", &r);
    puts("Enter the number of columns: ");
    scanf("%d", &c);
    puts("Select type of matrix:\n 1 - Matrix of real numbers\n 2 - Matrix of complex numbers\n");
    scanf ("%d", &que);

    Matrix mymatrix = createMatrix(r, c);
    Matrixc mymatrixc = createMatrixc(r, c);

    if (que == 1)       mymatrix = Assignment(&mymatrix);
    if (que == 2)       mymatrixc = Assignmentc(&mymatrixc);

    if (que != 1 && que != 2) err();

    while (lapre != 4){
        if (lapre < 1 || lapre > 4) err();
        puts ("Available actions:\n 1 - Perform matrix addition operation\n 2 - Perform matrix multiplication operation\n 3 - Matrix Transpose \n 4 - Exit\n");
        scanf ("%d", &lapre);
        if(lapre == 1 && que == 1)
        {
            Matrix secmatrix1 = createMatrix(r, c);
            secmatrix1 = Assignment(&secmatrix1);

            Matrix result1 = add(&secmatrix1, &mymatrix);
            puts ("Sum of 2 matrices:\n");
            printMatrix(&result1);

            destroyMatrix(&secmatrix1);
            destroyMatrix(&result1);
        }
        if(lapre == 2 && que == 1){
            int x;
            puts("How many columns will be in matrix you want to multiply by? ");
            scanf("%d ", &x);

            Matrix secmatrix2 = createMatrix(c,x);
            secmatrix2 = Assignment(&secmatrix2);

            Matrix result2 = multiply(&mymatrix, &secmatrix2);
            puts ("Multiplication of 2 matrices:\n");
            printMatrix(&result2);

            destroyMatrix(&secmatrix2);
            destroyMatrix(&result2);
        }
        if (lapre == 3 && que == 1){
            Matrix result3 = trans(&mymatrix);

            puts ("Transposed matrix:\n");
            printMatrix(&result3);

            destroyMatrix(&result3);
        }

        if(lapre == 1 && que == 2){
            Matrixc secmatrixc1 = createMatrixc(r, c);
            secmatrixc1 = Assignmentc(&secmatrixc1);

            Matrixc resultc1 = addc(&secmatrixc1, &mymatrixc);
            puts ("Sum of 2 matrices:\n");
            printMatrixc(&resultc1);

            destroyMatrixc(&secmatrixc1);
            destroyMatrixc(&resultc1);
        }
        if(lapre == 2 && que == 2){
            int x;
            puts("How many columns will be in matrix you want to multiply by? ");
            scanf("%d ", &x);

            Matrixc secmatrixc2 = createMatrixc(c,x);
            secmatrixc2 = Assignmentc(&secmatrixc2);

            Matrixc resultc2 = multiplyc(&mymatrixc, &secmatrixc2);
            puts ("Multiplication of 2 matrices:\n");
            printMatrixc(&resultc2);

            destroyMatrixc(&secmatrixc2);
            destroyMatrixc(&resultc2);
        }
        if (lapre == 3 && que == 2){
            Matrixc resultc3 = transc(&mymatrixc);

            puts ("Transposed matrix:\n");
            printMatrixc(&resultc3);
        }
        puts ("\n");

    }
    puts("\n");
    return 0;
}
