#include <stdio.h>
#define ROWS 3
#define COLS 4
int sum(int rows, int cols, int ar[rows][cols]);

int main(void)
{
    int i, j;
    int ra = 3;
    int cs = 10;
    int junk[ROWS][COLS] = {
        {2, 3, 4, 5},
        {3, 5, 8, 9},
        {5, 9, 7, 5}};
    int var[ra][cs];
    for (i = 0; i < ra; i++)
    {
        for (j = 0; j < cs; j++)
        {
            var[i][j] = i * j + j;
        }
    }
    printf("sum of junk: %d\n", sum(ROWS, COLS, junk));
    printf("sum of var: %d\n", sum(ra, cs, var));
    return 0;
}

int sum(int rows, int cols, int ar[rows][cols])
{
    int i, j;
    int total=0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            total += ar[i][j];
        }
    }
    return total;
}