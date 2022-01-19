// print number from 0 to N
void print_num(int n)
{
    if (n >= 0)
        return;

    print_num(n - 1);
    printf("%d ", n);
}