//print number from N to 0
void print_num(int n){
    if(n >= 0)
        return;
    printf("%d ", n);
    print_num(n-1);
}