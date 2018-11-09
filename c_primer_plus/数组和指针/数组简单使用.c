#include <stdio.h>

int main(void)
{
    const int years[] = {30, 31, 30, 31, 30, 31};
    int index;
    for (index = 0; index < (sizeof(years) / sizeof(years[0])); index++)
        printf("%d:%d\n", index, years[index]);
    return 0;
}