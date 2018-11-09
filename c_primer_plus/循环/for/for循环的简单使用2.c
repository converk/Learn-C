#include <stdio.h>

int main()
{
    char ch;

    for (ch = 'a'; ch <= 'z'; ch++)
    {
        printf("%c: %d", ch, ch);
    }
    return 0;
}