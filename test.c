#include <stdio.h>

void print(int n)
{
    printf("%d\n", n);
}

void fun(int n, void (*show)(int))
{
    int i;
    for (i = 0; i < n; i++)
    {
        show(i);
    }
}

int main()
{
    fun(10, print);
    return 0;
}