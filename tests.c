#include "stdio.h"
#include "header.h"


int testFloatSum(){
    Matrix a = createMatrix(2,2, 1);
    Matrix b = createMatrix(2, 2, 1);
    Matrix ans = createMatrix(2, 2, 1);
    int i, j;
    for (i = 0; i < 2; ++i){
        for (j = 0; j < 2; ++j) {
            Mr(b, i, j) = 1.03*i + j;
            Mr(a, i, j) = 4.46*i - 3*j;
            Mr(ans, i, j) = 5.49*i - 2*j;
        }
    }
    puts ("1st matrix: \n");
    printMatrix(&a);
    puts ("2nd matrix: \n");
    printMatrix(&b);
    puts ("Sum of matrices: \n");
    Matrix r = add(&a, &b);
    printMatrix(&r);
    for (i=0; i<2; i++){
        for (j=0; j<2; j++){
            if (Mr(ans, i, j) != Mr(r, i, j)) return 0;
        }
    }
    return 1;
}

int testComplexSum(){
    Matrix a = createMatrix(2,2, 2);
    Matrix b = createMatrix(2, 2, 2);
    Matrix ans = createMatrix(2, 2, 2);
    int i, j;
    for (i = 0; i < 2; ++i){
        for (j = 0; j < 2; ++j){
            Mrc(a, i, j).re = 4.46*i - 3*j;
            Mrc(a, i, j).im = 0.11*i + j*j;
            Mrc(b, i, j).re = i*1.00;
            Mrc(b, i, j).im = 2*j-1;
            Mrc(ans, i, j).re = 5.46*i - 3*j;
            Mrc(ans, i, j).im = 0.11*i + j*j + 2*j - 1;
        }
    }
    puts ("1st matrix: \n");
    printMatrix(&a);
    puts ("2nd matrix: \n");
    printMatrix(&b);
    puts ("Sum of matrices: \n");
    Matrix r = add(&a, &b);
    printMatrix(&r);
    for (i=0; i<2; i++){
        for (j=0; j<2; j++){
            if (Mrc(ans, i, j).re != Mrc(r, i, j).re && Mrc(ans, i, j).im != Mrc(r, i, j).im) return 0;
        }
    }
    return 1;
}

int testFloatTrans(){
    Matrix a = createMatrix(3,2, 1);
    Matrix ans = createMatrix(2, 3, 1);
    int i, j;
    for (i = 0; i < 3; ++i){
        for (j = 0; j < 2; ++j) Mr(a, i, j) = i*2.00-3;
    }
    puts ("Your matrix: \n");
    printMatrix(&a);
    for (i = 0; i < 2; ++i){
        for (j = 0; j < 3; ++j) Mr(ans, i, j) = j*2.00-3;
    }
    puts ("Transposed matrix: \n");
    Matrix r = trans(&a);
    printMatrix(&r);
    for (i=0; i<2; i++){
        for (j=0; j<3; j++){
            if (Mr(ans, i, j) != Mr(r, i, j)) return 0;
        }
    }
    return 1;
}

int testComplexTrans(){
    Matrix a = createMatrix(2,3, 2);
    Matrix ans = createMatrix(3, 2, 2);
    int i, j;
    for (i = 0; i < 2; ++i){
        for (j = 0; j < 3; ++j){
            Mrc(a, i, j).im = j*3.00-1;
            Mrc(a, i, j).re = i*2.00-3;
        }
    }
    puts ("Your matrix: \n");
    printMatrix(&a);
    for (i = 0; i < 3; ++i){
        for (j = 0; j < 2; ++j){
            Mrc(ans, i, j).im = i*3.00-1;
            Mrc(ans, i, j).re = j*2.00-3;
        }
    }
    puts ("Transposed matrix: \n");
    Matrix r = trans(&a);
    printMatrix(&r);
    for (i=0; i<3; i++){
        for (j=0; j<2; j++){
            if (Mrc(ans, i, j).re != Mrc(r, i, j).re || Mrc(ans, i, j).im != Mrc(r, i, j).im) return 0;
        }
    }
    return 1;
}

int testFloatMult(){
    Matrix a = createMatrix(2,2, 1);
    Matrix b = createMatrix(2, 2, 1);
    Matrix ans = createMatrix(2, 2, 1);
    int i, j;
    for (i = 0; i < 2; ++i){
        for (j = 0; j < 2; ++j) {
            Mr(a, i, j) = 1.1;
            Mr(b, i, j) = 2.2;
            Mr(ans, i, j) = 4.84;
        }
    }
    puts ("1st matrix: \n");
    printMatrix(&a);
    puts ("2nd matrix: \n");
    printMatrix(&b);
    puts ("Multiplication: \n");
    Matrix r = multiply(&a, &b);
    printMatrix(&r);
    for (i=0; i<2; i++){
        for (j=0; j<2; j++){
            if (Mr(ans, i, j) != Mr(r, i, j)) return 0;
        }
    }
    return 1;
}

int testComplexMult(){
    Matrix a = createMatrix(2,2, 2);
    Matrix b = createMatrix(2, 2, 2);
    Matrix ans = createMatrix(2, 2, 2);
    int i, j;
    for (i = 0; i < 2; ++i){
        for (j = 0; j < 2; ++j) {
            Mrc(a, i, j).re = 1.1;
            Mrc(a, i, j).im = -0.1;
            Mrc(b, i, j).re = 1.2;
            Mrc(b, i, j).im = 1.00;
            Mrc(ans, i, j).re = 2.84;
            Mrc(ans, i, j).im = 1.96;
        }
    }
    puts ("1st matrix: \n");
    printMatrix(&a);
    puts ("2nd matrix: \n");
    printMatrix(&b);
    puts ("Multiplication: \n");
    Matrix r = multiply(&a, &b);
    printMatrix(&r);
    for (i=0; i<2; i++){
        for (j=0; j<2; j++){
            if (Mrc(ans, i, j).re != Mrc(r, i, j).re && Mrc(ans, i, j).im != Mrc(r, i, j).im) return 0;
        }
    }
    return 1;
}

void test()
{
    int t = 0;
    if (testFloatSum() == 1) {
        t++;
        puts("Test Float Sum has passed! \n \n");
    }
    else puts("Test Float Sum has failed \n");
    if (testComplexSum() == 1) {
        t++;
        puts("Test Complex Sum has passed! \n \n");
    }
    else puts("Test Complex Sum has failed \n");
    if (testFloatTrans() == 1) {
        t++;
        puts("Test Float Trans has passed! \n \n");
    }
    else puts("Test Float Trans has failed \n");
    if (testComplexTrans() == 1) {
        t++;
        puts("Test Complex Trans has passed! \n \n");
    }
    else puts("Test Complex Trans has failed \n");
    if (testFloatMult() == 1) {
        t++;
        puts("Test Float Multiplication has passed! \n \n");
    }
    else puts("Test Float Multiplication has failed \n");
    if (testComplexMult() == 1) {
        t++;
        puts("Test Complex Multiplication has passed! \n \n");
    }
    else puts("Test Complex Multiplication has failed \n");
    puts ("\n");
    if (t == 6) puts("ALL TESTS ARE SUCCESSFUL");
}

int main()
{
    test();
    return 0;
}
