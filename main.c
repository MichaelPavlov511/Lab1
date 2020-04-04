#include <stdio.h>
#include "header2.h"

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

    Matrix mymatrix = createMatrix(r, c, que);
    mymatrix = Assignment(&mymatrix);
    puts ("Your Matrix: \n");
    printMatrix(&mymatrix);

    if (que != 1 && que != 2) err();

    while (lapre != 4){
        if (lapre < 1 || lapre > 4) err();
        puts ("Available actions:\n 1 - Perform matrix addition operation\n 2 - Perform matrix multiplication operation\n 3 - Matrix Transpose \n 4 - Exit\n");
        scanf ("%d", &lapre);
        if(lapre == 1)
        {
            Matrix secmatrix1 = createMatrix(r, c, que);
            puts ("a");
            secmatrix1 = Assignment(&secmatrix1);
            Matrix result1 = createMatrix(r, c, que);
            result1 = add(&secmatrix1, &mymatrix);
            puts ("Sum of 2 matrices:\n");
            printMatrix(&result1);
        }
        if(lapre == 2){
            int x;
            puts("How many columns will be in matrix you want to multiply by? ");
            scanf("%d ", &x);

            Matrix secmatrix2 = createMatrix(c,x, que);
            secmatrix2 = Assignment(&secmatrix2);

            Matrix result2 = multiply(&mymatrix, &secmatrix2);
            puts ("Multiplication of 2 matrices:\n");
            printMatrix(&result2);
        }
        if (lapre == 3){
            Matrix result3 = createMatrix(c, r, que);
            result3 = trans(&mymatrix);

            puts ("Transposed matrix:\n");
            printMatrix(&result3);
        }
    }

    puts("\n Have a nice day!\n");
    return 0;
}
