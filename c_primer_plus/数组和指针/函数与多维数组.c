//函数与多维数组,如何在形参里面表示二维数组

#include<stdio.h>

#define ROWS 3
#define COLS 4

//三种声明方法
void sum_rows(int ar[][COLS], int rows);
void sum_cols(int [][COLS], int);
//int sum(int (*ar)[COLS], int rows);

int main(void){

    int junk[ROWS][COLS]={
        {2,4,6,8},
        {3,5,6,7},
        {12,10,8,6}
    };
    sum_rows(junk,ROWS);
    sum_cols(junk, ROWS);
    //sum(junk,ROWS);
    return 0;
}

void sum_rows(int ar[][COLS], int rows){
    int i,j;
    int total;
    for (i=0; i<rows; i++){
        total=0;
        for (j=0; j<COLS; j++){
            total+=ar[i][j];
        }
        printf("row: %d, sim_row: %d\n", i, total);
    }
}

void sum_cols(int ar[][COLS], int rows){
    int i, j;
    int total;
    for (i = 0; i < COLS; i++)
    {
        total = 0;
        for (j = 0; j < rows; j++)
        {
            total += ar[j][i];
        }
        printf("col: %d, sim_col: %d\n", i, total);
    }
}