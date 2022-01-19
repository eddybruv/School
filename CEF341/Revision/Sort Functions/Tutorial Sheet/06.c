//check if number is prime
#include <stdbool.h>
 
//n -> number to check
//d -> numbers below n
bool isPrime(int n, int d){
    if (d == 1)
        return true;
    else {
        if (n % d == 0)
            return false;
        else    
            return isPrime(n, d-1);
    }
}