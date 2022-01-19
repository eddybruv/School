//recursive function to print a string

//k is initially 0;
void reverse(char *str, int k){
    if(*(str + k) == '\0')  //end of string
        return;

    reverse(str, k + 1);    //rec for next character.
    printf("%c", str[k]);
}