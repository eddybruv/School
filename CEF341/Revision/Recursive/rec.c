#include <stdio.h>

//prints 0 to N
void rec_print(n)
{
    if (n >= 0)
    {
        rec_print(n - 1);
        printf("%d ", n);
    }
    return;
}

//prints N to 0
void rec_print(n)
{
    if (n >= 0)
    {
        printf("%d ", n);
        rec_print(n - 1);
    }
    return;
}

int main(void)
{
    rec_print(8);
    printf("\n");
    return 0;
}