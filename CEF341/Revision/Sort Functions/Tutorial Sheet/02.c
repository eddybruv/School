// program to compute base(^exp) recursively

int raised_to(int base, int exp)
{
    if (exp == 0)
        return 1;
    else
        return base * raised_to(base, exp - 1);
}