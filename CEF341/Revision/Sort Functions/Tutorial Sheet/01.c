//recursive function to multiply two numbers
//I took this from a site

int mult(int num1, int num2){
    if(num1<num2)
        return mult(num2, num1);
    
    else if(num2 != 0)
        return (num1 + mult(num1, num2-1));
    
    else 
        return 0;
}